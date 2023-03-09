#include <stdio.h>
#include <unistd.h>

void gd_putnbr(int nb) {
    write(1, &nb, 1);
}

void gd_putchar(char c) {
    write(1, &c, 1);
}

int gd_atoi(char *str) {
    /* 43 -> +
       45 -> -
       49 à 57 -> 1 à 9
    */
    int new_int;
    int i;
    i = 0;
    while(str[i]) {
        if (str[i] != 43 || str[i] != 45 || str[i] < 49 || str[i] > 57) {
            break;
        } else if (str[i] == 43) {
            break;
        } else if (str[i] == 45) {
            break;
        } else if (str[i] >= 49 && str[i] <= 57) {
            new_int = new_int + str[i]-48 ;
        }
        i++;
    }
    return new_int;
}

int main(void) {
    int nb = gd_atoi("5000");
    gd_putnbr(nb);
    gd_putchar('\n');
}
