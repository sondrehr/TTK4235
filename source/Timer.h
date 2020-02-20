#include <stdio.h>



//Funskjoner for timer

void start_timer(); //starter timer

int read_timer(int seconds); //sammenligner ti tider og ser om differansen
                             // er større enn opgitt sekunder
                             //returnerer 1 dersom oppfylt, 0 ellers
