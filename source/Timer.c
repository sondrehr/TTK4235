
#include "Timer.h"
#include <stdio.h>
#include <time.h>

//int pre_value;
time_t pre_value;

//int end_value;
time_t end_value;

void start_timer(){
  time(&pre_value); //gir sekunder siden 1 jan 1970
}


int read_timer(int seconds) {

  time(&end_value);

 if ((end_value-pre_value) <= seconds){
  //if (difftime(end_value, pre_value) <= seconds) {
  return 1;}

  else {
    return 0;
  }
}
