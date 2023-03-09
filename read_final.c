#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) { // argc = int qui va etre créé tout seul par le main argv = tableau de chaine de charactère
    char buf[91];
    char c = 'A';
    int n = 0;
    int m = 0;
    int j = 0;
    int **line;
    int i = 0;
    int compteur =0;
    
    line = (int **)malloc(sizeof(int *)*9); // aloue la mémoire pour les ligne

    while (i <= 8){
        line[i] = (int *)malloc(sizeof(int)*9); // aloue la mémoire pour les valeur de chaque ligne
        i++;
    }

    
    int fd = open(argv[1], O_RDONLY);
    int nb_read = read(fd, buf, 90); 
    printf("%i\n", argc);
    printf("%s\n" , buf);
    
    printf("%i\n" , nb_read);
    buf[nb_read] = '\0';

    n = 0;
    while (buf[j] != '\0'){   //remplit le tableau 2 dimentions(ligne(valeur int)) avec les donnée de buf(tableau une dimention(chaine de caractère))
        while (m < 9){
            line[n][m] = buf[j]-48;   
            m++;
            j++; 
            
        }
        m = 0;
        j++;
        n++;
    }

    n = 0;
    m = 0;
    while (n != 9 && m != 9){ // affiche les donnée du tableau line
        while (m < 9) {
            printf("%i   ", (line[n][m]));
            m++;
        }
        printf("%c\n", '\n');
        m = 0;
        n++;
    }
    
    
    m = 0;
    n = 0;
    while (n != 9){ // affiche le nombre de 0 dans le tableau line 
        while (m != 9){
            if(line[n][m] == 0){
                compteur++; 
            }
            m++;
           
        
        }
        n++;
        m = 0;
    }
    printf(" il y a : %i %s\n", compteur , "zeros" );



    
    

    while (i <= 8){
        free(line[i]);
        
        printf(" c bon = %c\n", c );
        i++;
    }
    
    free(line);

    close(fd);

}