
#include "hardware.h"
#include "floors.h"
#include "Door_logic.h"
#include <stdio.h>


void read_floor(){
  if (hardware_read_floor_sensor(0)){
    current_floor = 1;
    at_floor = 1;
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
  }
  else {
    at_floor = 0;
  }
  hardware_command_floor_indicator_on(current_floor-1);
}

