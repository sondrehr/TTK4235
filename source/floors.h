/**
 * @file
 * @brief function that set the global variables used in almost every function
 */

/**
*@brief The different states used by the FSM
*/
typedef enum {
    Init,
    Stationary_f,
    Stop,
    Down,
    Up,
    Stationary_n
} FSM_state;

int current_floor;
_Bool at_floor;

/**
*@brief Changes the global variables above. at_floor will be changed to 1 when it is at a floor and 0 when not on a floor. current_floor will be changed whenever it is at a floor
*/
void read_floor();
