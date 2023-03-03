#ifndef __ex22_h
#define __ex22_h

/* make THE_SIZE in ex22.c available for other .c files */
extern int THE_SIZE;

/* gets and sets an internal static variable in ex22.c */
int get_age(void);
void set_age(int age);

/* updates a static variable that's inside update_ratio */
double update_ratio(double new_ratio);
void print_size(void);

#endif /* __ex22_h */
