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
* @param[in] b An int that indicate the spot of the number we want to change>
*/
void swap(int *next_order_queue, int a, int b);

/**
*@brief A function made to record the orders that we give via the buttons and record *them in the corresponding array
*
* @param[in,out] inside The array of the orders from inside the elevator
*
* @param[in,out] up The array of the orders from outside the elevator going up
* 
* @param[in,out] down The array of the orders from outside the elevator going down
*/
void order_record(int *inside, int *up, int *down);


/**
*@brief A function made to delete all the orders from the arrays. Used with the stop button
*
* @param[in,out] inside The array of the orders from inside the elevator
*
* @param[in,out] up The array of orders from outside the elevator going up
* 
* @param[in,out] down The array of orders from outside the elevator going down
*
* @param[in,out] next The array that contains the next orders
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
*@brief A function made to delete the current_floor from the list of next orders, so the elevator doesn't go to the same floor twice. It sets the first number to 0, then it shifts all number except the first one spot to the left.
*
* @param[in] current_floor The floor we are currently at
*
* @param[in,out] queue The array that contains the next orders 
*/
void update_queue(int *queue, int current_floor);

/**
*@brief A function made to set all order lights when the corresponding button is pushed. If i is one it will cycle through all button and lights the button if it is pushed. If i is 0 (used with the stop button) all the lights will be set low.
*
* @param[in] i This int decides if the lights should be set as normal(1) or reset at turned off(0)
*/
void set_order_lights(int i);


/**
@brief A function that decides the priority of the orders. It useds the following steps:
- It checks if the direction is Up, Down or Stop. e.g. If the direction is up, it will only care about orders that are going up or from inside the elevator.
-
The first for-loop is used to cycle through all the orders and it will only proceed if there is an order which is the job of the if-statement.
-
The second for-loop is used to cycle through the next_order_queue to add the new orders, if an order to the same floor doesn't already exit. Uesd to avoid duplicate orders.   
-
The secret sauce is the third if statement. It prioritises the orders to make the execution more streamlined. e.g. if the 3. floor inside is pushed and the 2. floor up afterwards, and the elevator is below the 2. floor, it will take the 2. floor before the 3. it compares the first order in the next_order_queue and with the other orders at swaps them if it will come to another floor first.
*
* @param[in] current_floor The floor we are currently at
*
* @param[in] state The state we are currently in(Stationary_f, Up ...)
*
* @param[in] last_direction The direction the elevator is travelling. 1= up, 2 = down, 0 = stop
*
* @param[in,out] inside The array of the orders from inside the elevator
*
* @param[in,out] up The array of the orders from outside the elevator going up
* 
* @param[in,out] down The array of the orders from outside the elevator going down
*
* @param[in,out] next_order_queue The array that contains the next orders
*/
void order_handler(int *inside, int *up, int *down, int last_direction, int *next_order_queue, int current_floor, int state);

