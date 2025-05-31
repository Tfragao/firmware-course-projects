#include "../inc/calculator.h"


void show_welcome_message(void)
{
    printf(" \xF0\x9F\x98\x80 Welcome to the basic calculator App \xF0\x9F\x98\x80\n");
    printf("  _________  \n");
    printf(" |  ___   | \n");
    printf(" | | 7 | 8 | 9 |\n");
    printf(" | | 4 | 5 | 6 |\n");
    printf(" | | 1 | 2 | 3 |\n");
    printf(" | | 0 | + | = |\n");
    printf(" |_________| \n");
}

float add(float n1, float n2)
{
    return n1 + n2;
}

float sub(float n1, float n2)
{
    return n1 - n2;
}

float multiply(float n1, float n2)
{
    return n1 * n2;
}

float divide(float n1, float n2)
{
    if ((int)n2 == 0) {
       printf("\xE2\x98\xB9 Oops! You tried to divide by zero, which isn't allowed. Please enter a non-zero divisor.\xE2\x98\xB9\n");
       return (int)-1;
    }
    return n1 / n2;
}

int safe_int_input(int *result)
{
    char buffer[BUFFER_SIZE];
    char *endptr;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return -1; 
    }

    errno = 0; //reset error flag
    long val = strtol(buffer, &endptr, 10);

    if (endptr == buffer || *endptr != '\n' || errno == ERANGE) {
        return -1; //invalid input or overflow
    }

    *result = (int)val;
    return 0;

}

int safe_float_input(double *result)
{
    char buffer[BUFFER_SIZE];
    char *endptr;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return -1;
    }

    errno = 0;
    double val = strtod(buffer, &endptr);

    if (endptr == buffer || *endptr != '\n' || errno == ERANGE) {
        return -1; // invalid input or overflow
    }

    *result = val;
    return 0;
}

void trim_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}


int get_yes_no(const char * answer)
{
    char input [10];

    printf("%s", answer);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return -1;
    }

    trim_newline(input);

    for (int i = 0; input[i]; i++) {
        input[i] = (char)tolower((unsigned char)input[i]);
    }

    if (strcmp(input, "yes") == 0) {
        return 1;
    } else if (strcmp(input, "no") == 0) {
        return 0;
    } else {
        return -1; //invalid input
    }
}

/* 
* system("clear") and system("cls") are simple but not always recommended for production
* code due to portability and security concerns. 
* For more robust solutions (especially in cross-platform or GUI applications), 
* consider using libraries like ncurses (for Unix-like systems) or Windows Console API functions.
*/
void clear_screen(void)
{
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}