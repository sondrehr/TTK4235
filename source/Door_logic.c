
#include <stdio.h>
#include "hardware.h"
#include "door_logic.h"
#include "timer.h"



int door_state(state tilstand){
    return tilstand;
}



void door_logic(state door_state){


  if (door_state== closed) {
     start_timer();
     void hardware_command_door_open(1);
     door_state = open;
     while (read_timer(3)){};
     void hardware_command_door_open(0);
     door_state = closed
}
}



//bool Check_obstruction(bool obstruction){
//  return obstruction;
//}
