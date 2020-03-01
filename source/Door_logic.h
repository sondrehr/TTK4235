
/**
 * @file
 * @brief Logic for whenever the door would open. 
 */

/**
*@brief Uses timer.h
and stops for 3 seconds when the door would open.
As long as @c hardware_read_stop_signal
or @c hardware_read_obstruction_signal is active the door
will stay open. Door will also stay open for 3 seconds after
@c hardware_read_stop_signal goes low.

*Opens the doors, then starts the timer. It will remain in the while loop as long as the timer is less than 3 seconds, and it will be reset every time the stop button or obstruction is activated. After 3 seconds it will close the doors, then return from the function.
*
* @param[in] current_floor The floor we are currently at
*
* @param[in] last_direction The direction the elevator is travelling. 1= up, 2 = down, 0 = stop
*
* @param[in,out] inside The array of the orders from inside the elevator
*
* @param[in,out] up The array of the orders from outside the elevator going up
* 
* @param[in,out] down The array of the orders from outside the elevator going down
*
* @param[in,out] next The array that contains the next orders
*/

void door_logic(int *inside, int *up, int *down, int *next, int current_floor, int last_direction);
