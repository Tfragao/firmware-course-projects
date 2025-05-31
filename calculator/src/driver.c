#include "../inc/driver.h"

int main(void)
{
    int choice, res;
    double n1, n2, result;
    bool isRunning = true;
    unsigned int other_answers = 0;
    
    show_welcome_message();
   
    while(isRunning) {
        if (other_answers > 0) {
            res = get_yes_no("Do you still want to keep calculating, enter (yes/no):");
            clear_screen();
            if (res == 0 || res == 1) other_answers = 0;
            if (res == -1)  printf("\xE2\x98\xB9 Please enter yes or no.\xE2\x98\xB9\n");
        } else {
            printf("Please enter two numbers: \n");
            
            if ((safe_float_input(&n1)) != 0) {
                printf("\xE2\x98\xB9 Please enter a valid number \xE2\x98\xB9\n");
                return -1;
            }
            if ((safe_float_input(&n2)) != 0) {
                printf("\xE2\x98\xB9 Please enter a valid number \xE2\x98\xB9\n");
                return -1;
            }
            
            printf("Select one of the operations below:\n");
            printf("0 : Addition [+]\n1 : Subtraction [-]\n2 : Multiplication [*]\n3 : Division [/]\n");
            if ((safe_int_input(&choice)) != 0) {
                printf("\xE2\x98\xB9 Please enter a valid choice\xE2\x98\xB9\n");
                return -1;
            }
            switch(choice) {
                case 0: 
                    result = add(n1, n2);
                    printf("%.2f + %.2f = %.2f\n", n1, n2, result);
                break;
                case 1: 
                    result = sub(n1, n2);
                    printf("%.2f - %.2f = %.2f\n", n1, n2, result);
                break;
                case 2: 
                    result = multiply(n1, n2);
                    printf("%.2f x %.2f = %.2f\n", n1, n2, result);
                break;
                case 3: 
                    result = divide(n1, n2);
                    if (result == -1) break;
                    printf("%.2f / %.2f = %.2f\n", n1, n2, result);
                break;
                default:
                    printf("\xE2\x98\xB9 Please enter a valid operation from the list above. \xE2\x98\xB9\n");
            }
            res = get_yes_no("Do you still want to keep calculating, enter (yes/no):");
            clear_screen();
            if (res == 0) {
                isRunning = false;
            } else if (res == 1) {
                isRunning = true;
            } else {
                printf("\xE2\x98\xB9 Please enter yes or no.\xE2\x98\xB9\n");
                other_answers++;
            }
        }
    }
    printf("Goodbye! \xF0\x9F\x91\x8B\n");
    return 0;
}