
#include "Timer.h"
#include <stdio.h>
#include <time.h>


time_t pre_value;
time_t end_value;


void start_timer(){
  time(&pre_value);
}


int read_timer(int seconds) {

  time(&end_value);

  if ((end_value-pre_value) <= seconds)
  {
    return 1;
  }

  else {
    return 0;
  }
}
