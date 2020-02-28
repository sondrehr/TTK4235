/*
@file
@brief Logic for whenever the door would open. Uses timer.h
and stops for 3 seconds when the door would open.
As long as @c hardware_read_stop_signal
or @c hardware_read_obstruction_signal is active the door
will stay open. Door will also stay open for 3 seconds after
@c hardware_read_stop_signal goes low.
*/

void door_logic(int *inside, int *up, int *down, int *next, int current_floor, int last_direction);
