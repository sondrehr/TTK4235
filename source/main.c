#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"

#include "Timer.h"
#include "order_handler.h"
#include "Door_logic.h"
#include "floors.h"


static void sigint_handler(int sig)
{
    (void)(sig);
    printf("Terminating elevator\n");
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    exit(0);
}


//Holder styr på hvilken etasje vi er i
int current_floor = 0;

/*
0 - under current_floor
1 - over current_floor
Holder styr på hvilke etasjer vi er mellom
*/
_Bool above_floor = 0;


//Sier om vi er på en etasje
_Bool at_floor;

//Holder styr på hvilken modus vi er i
int state = Init;

//Holder styr på siste retning (0 = stille, 1 = opp ,2 = ned)
int last_direction;

int main()
{
    int error = hardware_init();

    //Holder styr på ordrene
    int order_down[4] = {0,0,0,0};
    int order_up[4] = {0,0,0,0};
    int order_inside[4] = {0,0,0,0};

    int next_order_queue[4] = {0,0,0,0};

    if(error != 0)
    {
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    signal(SIGINT, sigint_handler);

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    //hardware_command_movement(HARDWARE_MOVEMENT_UP);

    while(1)
    {

        while (state == Init)
        {
          printf("Init\n");

          hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
          read_floor();
          if (at_floor)
          {
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            state = Stationary_f;
          }
        }

//////////////////////////////////////////////////

        while (state == Stationary_f)
        {
          printf("Stationary_f\n");

          ///////////////////////////////////

          for (int i = 0; i < 4; i ++){
          	printf("%d", next_order_queue[i]);

          }
          printf("\n");

          /////////////////////////////////

          //
          //read_floor();
          //



      	  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      	  last_direction = 0;



          set_order_lights(1);
          ////
          if (at_floor){
          	update_lights_and_orders(current_floor-1, order_inside, order_up, order_down);
          }
          ////

          order_record(order_inside, order_up, order_down);
          order_handler(order_inside, order_up, order_down, last_direction, next_order_queue, current_floor, state);

		      update_queue(next_order_queue, current_floor);


		      if (next_order_queue[0] > current_floor)
		      {
		  	       state = Up;
		  	       above_floor = 1;
		      }

		      if ((next_order_queue[0] < current_floor) && next_order_queue[0])
		      {
		  	       state = Down;
		  	       above_floor = 0;
		      }

          if (hardware_read_stop_signal())
          {
              state = Stop;
          }
        }

///////////////////////////////////////////////

        while (state == Stationary_n)
        {
        
          printf("Stationary_n\n");
          
          /*printf("next_order_queue[0]: %d\t", next_order_queue[0]);
          printf("current_floor: %d\t", current_floor);
          printf("state: %d\t", state);
          printf("last_direction: %d\n", last_direction);
*/
          //
          //read_floor();
          //

      	  hardware_command_movement(HARDWARE_MOVEMENT_STOP);

          set_order_lights(1);
          order_record(order_inside, order_up, order_down);
          order_handler(order_inside, order_up, order_down, last_direction, next_order_queue, current_floor, state);


          if (next_order_queue[0] == current_floor)
          {
            if (above_floor)
            {
              state = Down;
            }
            else
            {
              state = Up;
            }
          }
          else
          {
            if (next_order_queue[0] > current_floor)
            {
              state = Up;
            }
            else if (next_order_queue[0] < current_floor && next_order_queue[0])
            {
              state = Down;
            }
          }


          if (hardware_read_stop_signal())
          {
            state = Stop;
		      }
        }

//////////////////////////////////////////////

        while (state == Up)
        {
          printf("Up\n");

          ///////////////////////////////////
          for (int i = 0; i < 4; i ++){
          	printf("%d", next_order_queue[i]);
          }

          printf("\n");
          /////////////////////////////////

          if (at_floor && next_order_queue[0] == current_floor)
          {
          	update_queue(next_order_queue, current_floor);
          	update_lights_and_orders(current_floor-1, order_inside, order_up, order_down);

          	door_logic(order_inside, order_up, order_down, next_order_queue, current_floor, last_direction);
          	state = Stationary_f;
          }

		  if (current_floor != 3)
		  {
          	hardware_command_movement(HARDWARE_MOVEMENT_UP);
          }
          
          last_direction = 1;

          set_order_lights(1);
          order_record(order_inside, order_up, order_down);
          order_handler(order_inside, order_up, order_down, last_direction, next_order_queue, current_floor, state);

          read_floor();

          if (hardware_read_stop_signal())
          {
            state = Stop;
		  }
        }

/////////////////////////////////////////////

        while (state == Down)
        {
          printf("Down\n");

          ///////////////////////////////////
          for (int i = 0; i < 4; i ++){
          	printf("%d", next_order_queue[i]);
          }

          printf("\n");
          /////////////////////////////////

          if (at_floor && next_order_queue[0] == current_floor)
          {
          	update_queue(next_order_queue, current_floor);
          	update_lights_and_orders(current_floor-1, order_inside, order_up, order_down);

          	door_logic(order_inside, order_up, order_down, next_order_queue, current_floor, last_direction);
          	state = Stationary_f;
          }
          
          if (current_floor != 0)
		  {
          	hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
          }
          
          last_direction = 2;

          set_order_lights(1);
          order_record(order_inside, order_up, order_down);
          order_handler(order_inside, order_up, order_down, last_direction, next_order_queue, current_floor, state);

          read_floor();

          if (hardware_read_stop_signal())
          {
	        state = Stop;
		  }
        }

////////////////////////////////////////////

        while (state == Stop)
        {
          order_delete(order_inside, order_up, order_down, next_order_queue);
          set_order_lights(0);

          while(hardware_read_stop_signal())
          {
      		    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
              hardware_command_stop_light(1);
      	      if (at_floor)
      		    {
   			          door_logic(order_inside, order_up, order_down, next_order_queue, current_floor, last_direction);
   			      }
   	      }

 		      hardware_command_stop_light(0);

 	        if (at_floor)
 	        {
    	       state = Stationary_f;
  		    }
  		    else
  		    {
             state = Stationary_n;
  		    }
        };

    }
    return 0;
}
