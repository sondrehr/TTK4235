

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

void read_floor();

void read_stop();
