#include <stdio.h>
#include <time.h>



//Funskjoner for timer

void start_timer(); //starter timer


//sammenligner ti tider og ser om differansen
// er større enn opgitt sekunder
//returnerer 1 dersom oppfylt, 0 ellers
int read_timer(int seconds);
