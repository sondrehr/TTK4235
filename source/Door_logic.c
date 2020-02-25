
#include <stdio.h>
#include "hardware.h"
#include "Door_logic.h"
#include "Timer.h"



void door_logic(int *inside, int *up, int *down, int *next, int current_floor, int last_direction){

	hardware_command_movement(HARDWARE_MOVEMENT_STOP);
	start_timer();

	hardware_command_door_open(1);
	while(read_timer(3))
	{
		while (hardware_read_stop_signal())
		{
			hardware_command_stop_light(1);
			start_timer();
		}

		hardware_command_stop_light(0);

		if (hardware_read_obstruction_signal())
		{
			start_timer();
		}

		//order_record(inside, up, down);
    	//order_handler(inside, up, down, last_direction, next, current_floor);
    	//update_queue(next, current_floor);
    	//update_lights_and_orders(current_floor-1, inside, up, down);
	};
	hardware_command_door_open(0);
}
