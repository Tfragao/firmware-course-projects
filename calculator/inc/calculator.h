#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 128

void show_welcome_message(void);
float add(float, float);
float sub(float, float);
float multiply(float, float);
float divide(float, float);
void display(float);
int safe_int_input(int *);
int safe_float_input(double *);
void trim_newline(char *);
int get_yes_no(const char *);
void clear_screen(void);

#endif // CALCULATOR_H