
#include "studio.h"
#include "hardware.h"
#include "door_logic.h"
#include "timer.h"


int door_state(int state){
    return state;
}



void doorlogic(int door_open, state door_state){
  if (door_open == 1 && door_state== closed) {
     start_timer();
     obstruction = true;
     door_state = open;
     void hardware_command_door_open(door_open);
     while (read_timer()){};
     door_open = 0;
     obstruction = false
     void hardware_command_door_open(door_open);
     door_state = closed
}



bool Check_obstruction{
  return obstruction;
}
