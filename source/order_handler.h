
void swap(int *next_order_queue, int a, int b);

void order_record(int *inside, int *up, int *down);

void order_delete(int *inside, int *up, int *down, int *next);

void update_lights_and_orders(int floor,int *inside, int *up, int *down);

void update_queue(int *queue, int current_floor);

void set_order_lights(int i);

void order_handler(int *inside, int *up, int *down, int last_direction, int *next_order_queue, int current_floor, int state);

