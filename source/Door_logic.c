
#include <stdio.h>
#include "hardware.h"
#include "door_logic.h"
#include "timer.h"



//int door_state(state tilstand){
//    return tilstand;
//}


void door_logic(){

     start_timer();
     hardware_command_door_open(1);

     while (read_timer(3) || hardware_read_obstruction_signal() || hardware_read_stop_signal()){};
     //noe som holder døren oppe hvis obstruction er på
     hardware_command_door_open(0);
}




//bool Check_obstruction(bool obstruction){
//  return obstruction;
//}
