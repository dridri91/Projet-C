#include <unistd.h>
#include <stdio.h>
//permet de print

int gd_putstr(char *str) {
    int i;
    i = 0;
    while(str[i] != '\0') {
        i++;
    }
    write(1,str, i); //le i permet de savoir ou on s'arrete d'ecrir 
    return i;

}

int main(void) {
    //gd_putchar('a');
    //gd_putchar('\n');
    int nb_put = gd_putstr("coucou");
    printf("%i\n", nb_put);
}