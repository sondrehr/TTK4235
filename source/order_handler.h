/**
 * @file
 * @brief functions that record, change or delete orders and lights
 */

/**
@brief A function made to swap a number at index a with a number at index b in an array
*
* @param[in,out] next_order_queue The queue of orders that we want to change 
*
* @param[in] a An int that indicate the spot of the number we want to change
* 
* @param[in] b An int that indicate the spot of the number we want to change
*/
void swap(int *next_order_queue, int a, int b);

/**
@brief A function made to record the orders that we give via the buttons and record them in the corresponding array
*
* @param[in,out] inside The array of the orders from inside the elevator
*
* @param[in,out] up The array of the orders from outside the elevator going up
* 
* @param[in,out] down The array of the orders from outside the elevator going down
*/
void order_record(int *inside, int *up, int *down);


/**
@brief A function made to delete all the orders from the arrays. Used with the stop button
*
* @param[in,out] inside The array of the orders from inside the elevator
*
* @param[in,out] up The array of the orders from outside the elevator going up
* 
* @param[in,out] down The array of the orders from outside the elevator going down
*/
void order_delete(int *inside, int *up, int *down, int *next);


/**
@brief A function made to turn of the lights and orders when we arrive at a corresponding floor
*
* @param[in] floor The floor we are currently at
*
* @param[in,out] inside The array of the orders from inside the elevator
*
* @param[in,out] up The array of the orders from outside the elevator going up
* 
* @param[in,out] down The array of the orders from outside the elevator going down
*/
void update_lights_and_orders(int floor,int *inside, int *up, int *down);

/**
@brief A function made to turn of the lights and orders when we arrive at a corresponding floor
*
* @param[in] floor The floor we are currently at
*
* @param[in,out] inside The array of the orders from inside the elevator
*
* @param[in,out] up The array of the orders from outside the elevator going up
* 
* @param[in,out] down The array of the orders from outside the elevator going down
*/
void update_queue(int *queue, int current_floor);

void set_order_lights(int i);

void order_handler(int *inside, int *up, int *down, int last_direction, int *next_order_queue, int current_floor, int state);

