//#include "main.c"
#include "hardware.h"
#include "floors.h"
#include <stdio.h>


void read_floor(){
  if (hardware_read_floor_sensor(0)){
    current_floor = 1;
    at_floor = 1;
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  }
  else if (hardware_read_floor_sensor(1)){
    current_floor = 2;
    at_floor = 1;
  }
  else if (hardware_read_floor_sensor(2)){
    current_floor = 3;
    at_floor = 1;
  }
  else if (hardware_read_floor_sensor(3)){
    current_floor = 4;
    at_floor = 1;
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  }
  else {
    at_floor = 0;
  }
}

void read_stop(){
  while(hardware_read_stop_signal()){
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      //Slett kø
  }
}
