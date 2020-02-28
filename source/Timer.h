/*
@file
*brief Timer for the elevator

*/

/*
@brief Initializes a time with a set
value since a given date (1/1 - 1970)
*/

void start_timer();

/*
@brief Compares the difference between the time initizalized
by @c start_timer and the current time since the given date
1/1-1970 with @p seconds.
*
@param seconds Seconds to comapre time difference with
*
@retrun 1 if difference between times is smaller or equal than
3 seconds. Returns 0 otherwice
*/


int read_timer(int seconds);
