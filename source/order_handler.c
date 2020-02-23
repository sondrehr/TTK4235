#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"


/*Lagrer alle ordre*/
void order_record(int *inside, int *up, int *down){
	for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
          	inside[f] = 1;
        }
    }

    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        if(hardware_read_order(f, HARDWARE_ORDER_UP)){
           	up[f] = 1;
        }
    }

    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
          	down[f] = 1;
        }
    }
}

/*Sletter alle ordre*/
void order_delete(int *inside, int *up, int *down){
	for (int i = 0; i < 4; i ++){
		inside[i] = 0;
		up[i] = 0;
		down[i] = 0;
	}
}

/*Setter og slår av alle ordrelys*/
void set_order_lights(int i){
    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){

        if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
            hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 1);
        }

        if(hardware_read_order(f, HARDWARE_ORDER_UP)){
            hardware_command_order_light(f, HARDWARE_ORDER_UP, 1);
        }

        if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
            hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 1);
        }

        if(!i){
        	hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 0);
        	hardware_command_order_light(f, HARDWARE_ORDER_UP, 0);
        	hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 0);
        }
    }
}

/*
Slår av lys når man stopper på korresponderende etasje for å vise at bestillingen er tatt
Fjerner også bestillingen
*/
void update_lights_and_orders(int floor, int *inside, int *up, int *down){
	hardware_command_order_light(floor, HARDWARE_ORDER_INSIDE, 0);
	hardware_command_order_light(floor, HARDWARE_ORDER_UP, 0);
	hardware_command_order_light(floor, HARDWARE_ORDER_DOWN, 0);
	inside[floor] = 0;
	up[floor] = 0;
	down[floor] = 0;
}



void insert_order(int *next_order_queue, int f){

}

/*
Tar inn alle ordre og returnerer en liste med de neste ordrene i rekkefølge
*/
void order_handler(int *inside, int *up, int *down, int last_direction, int *next_order_queue){
	if (last_direction == 0){
		for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
			if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
        	    insert_order(next_order_queue, f);
        	}

       		if(hardware_read_order(f, HARDWARE_ORDER_UP)){
        	    insert_order(next_order_queue, f);
        	}

        	if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
        	    insert_order(next_order_queue, f);
        	}
		}
	}

	if (last_direction == 1){
		for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){

		}
	}

	if (last_direction == 2){
		for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){

		}
	}
}
