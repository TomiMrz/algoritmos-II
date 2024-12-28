#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int main(void) {
    char user_input[MAX_LENGTH];
    printf("Ingrese su nombre y apellido: ");
    //scanf("%s", user_input);
    fgets(user_input,MAX_LENGTH, stdin);
    size_t p = strlen(user_input);
    char xd[p];
    for (unsigned int i = 0; i <= p; i++)
    {
        if (user_input[i] != '\n' && user_input[i] != '\0')
        {
            xd[i] = user_input[i];
        }
    }    
    printf("Te damos la bienvenida %s a este maravilloso programa!\n", xd);

    return EXIT_SUCCESS;
}
