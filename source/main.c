#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"

#include "Timer.h"
#include "Door_logic.h"
#include "floors.h"
#include "order_handler.h"



static void clear_all_order_lights(){
    HardwareOrder order_types[3] = {
        HARDWARE_ORDER_UP,
        HARDWARE_ORDER_INSIDE,
        HARDWARE_ORDER_DOWN
    };

    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        for(int i = 0; i < 3; i++){
            HardwareOrder type = order_types[i];
            hardware_command_order_light(f, type, 0);
        }
    }
}

static void sigint_handler(int sig){
    (void)(sig);
    printf("Terminating elevator\n");
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    exit(0);
}


//Holder styr på hvilken etasje vi er i
int current_floor = 0;
_Bool at_floor;

//Holder styr på hvilken modus vi er i
int state = Init;

//Holder styr på siste retning (0 = stille, 1 = opp ,2 = ned)
int last_direction;

int main(){
    int error = hardware_init();

    //Holder styr på ordrene
    int order_down[4] = {0,0,0,0};
    int order_up[4] = {0,0,0,0};
    int order_inside[4] = {0,0,0,0};

    int next_order_queue[4] = {0,0,0,0};

    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    signal(SIGINT, sigint_handler);

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    //hardware_command_movement(HARDWARE_MOVEMENT_UP);

    while(1){

        while (state == Init){
          printf("Init\n");

          hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
          read_floor();
          if (at_floor){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            state = Stationary_f;
          }
        }

//////////////////////////////////////////////////

        while (state == Stationary_f){
          printf("Stationary_f\n");

          //
          read_floor();
          //

      	  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      	  last_direction = 0;

          set_order_lights(1);
          ////
          if (at_floor){
          	update_lights(current_floor-1, order_inside, order_up, order_down);
          }
          ////
          order_record(order_inside, order_up, order_down);
          order_handler(order_inside, order_up, order_down, last_direction, next_order_queue);

          if (hardware_read_stop_signal()){
            state = Stop;
          }
        }

///////////////////////////////////////////////

        while (state == Stationary_n){
          printf("Stationary_n\n");

          //
          read_floor();
          //

      	  hardware_command_movement(HARDWARE_MOVEMENT_STOP);

          set_order_lights(1);
          order_record(order_inside, order_up, order_down);
          order_handler(order_inside, order_up, order_down, last_direction, next_order_queue);

          if (hardware_read_stop_signal()){
            state = Stop;
		  }
        }

//////////////////////////////////////////////

        while (state == Up){
          printf("Up\n");

          hardware_command_movement(HARDWARE_MOVEMENT_UP);
          last_direction = 1;

          set_order_lights(1);
          order_record(order_inside, order_up, order_down);
          order_handler(order_inside, order_up, order_down, last_direction, next_order_queue);

          read_floor();

          if (hardware_read_stop_signal()){
            state = Stop;
		  }
        }

/////////////////////////////////////////////

        while (state == Down){
          printf("Down\n");

          hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
          last_direction = 2;

          set_order_lights(1);
          order_record(order_inside, order_up, order_down);
          order_handler(order_inside, order_up, order_down, last_direction, next_order_queue);

          read_floor();

          if (hardware_read_stop_signal()){
	        state = Stop;
		  }
        }

////////////////////////////////////////////

        while (state == Stop){
        	order_delete(order_inside, order_up, order_down);
        	set_order_lights(0);

        	while(hardware_read_stop_signal()){
      			hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      			hardware_command_stop_light(1);
      			if (at_floor){
      			  door_logic();
     			}
 			}

 			hardware_command_stop_light(0);

 			if (at_floor){
    		  state = Stationary_f;
  			}
  			else{
    		  state = Stationary_n;
  			}
      };

/////////////////////////////////////////////



        if(hardware_read_obstruction_signal()){
            hardware_command_stop_light(1);
            clear_all_order_lights();
        }
        else{
            hardware_command_stop_light(0);
        }
    }

    return 0;
}
