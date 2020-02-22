
#include "Timer.h"
#include <stdio.h>
#include <time.h>

int pre_value;

int end_value;

void start_timer(){
  time(&pre_value); //gir sekunder siden 1 jan 1970
}


int read_timer(int seconds) {

  time(&end_value);

  if (difftime(end_value, prevalue) <= seconds) {
  return 1}

  else {
    return 0;
  }
}
