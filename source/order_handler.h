

void order_record(int *inside, int *up, int *down);

void order_delete(int *inside, int *up, int *down);

void update_lights_and_orders(int floor,int *inside, int *up, int *down);

void set_order_lights(int i);

void order_handler(int *inside, int *up, int *down, int last_direction, int *next_order_queue);

void insert_order(int *next_order_queue, int f);
