
/*Mastermind con repeticion y hsta 25 digitos, machaca primero los que estan en posicion
 y despues los que no, se aprovecha del paso por referencia de los arrays*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(void)
{
    //semilla para nums aleatorios
    unsigned seed = (unsigned)(time(NULL) *100000);
    srand(seed);

    //eleccion longitud en digitos del numero secreto
    int digit;
    printf("¡Bienvenido a Mastermind! con cuantos digitos quieres jugar?( Max25, es bastante)");
    while (1) {
        scanf(" %d", &digit);
        if (digit>0 && digit<= 25)
            break;
        printf( "elige entre 1 y 10,para seguir ");    
    }
    printf("vas a jugar con %d digitos, suerte",digit);
    
    // Generar la combinación secreta de digit dígitos (0-9)
    char secreto[digit+1]; // 4 dígitos + '\0'
    char secreto1[digit+1];
    for (int i = 0; i < digit; i++) {
        secreto[i] = '0' + rand() % 10; // Convertimos a char
        
    }
    secreto[digit] = '\0';//evita caract extraños e pantlla
    
    printf( "numero secreto %s\n", secreto);
    char intento[digit]; // declaracion array para leer intento del jugador
    int intentos = 0;
    int aciertos = 0;
    
    printf("¡Empezamos  el reto Mastermind! Adivina la combinación de %d  dígitos (0-9)\n", digit);

    while (1) {
        intentos++;//ciclo de intentos, cuando se acierte break
        
        aciertos =  0;
        printf("Intentos %d: ", intentos);
        scanf(" %s",intento);//el puto espacio ese me ha vuelto loco
        printf("y secreto es: %s\n",secreto);
        // Comprobar longitud del intento
        if (strlen(intento) != digit) {
            printf("Por favor, introduce exactamente %d dígitos.\n",digit);
            continue;
        }
        
        strcpy(secreto1, secreto);
        aciertos=acertarpos(secreto1,intento);

        if (aciertos == digit) {
            printf("¡Felicidades! Adivinaste la combinación en %d intentos.\n", intentos);
            break;
        } 
        else {
            printf(" aciertos num y pos   %d ,\n" , aciertos);
            printf(" aciertos solo num %d ,\n", acertarsinpos(secreto1,intento));
        }
    }

    printf("La combinación secreta era: %s\n", secreto);

    return 0;

}

int acertarpos(char secreto1[],char intento[]){
    int encontrado = 0;
    int leni = strlen(intento);
    int lenj = strlen(secreto1);
    //dos vueltas si hay acierto los dos numeros en intento y en secreto1, quedan reservados
    for (int i = 0; i < leni; i++) {  
        for (int j = 0; j < lenj; j++) {
            if (i==j && secreto1[j]==intento[i] ) {
                    
                    encontrado++;
                    secreto1[j]='x';
                    intento[i]='a';
                    //printf("en1 intento %s y secreto1 %s\n ",intento,secreto1); 
            }
        }
            
        
    }
    
return (encontrado)  ;              
}   

int acertarsinpos(char secreto1[],char intento[]){
    int encontrado = 0;
    int leni = strlen(intento);
    int lenj = strlen(secreto1);
    //dos vueltas si hay acierto los dos numeros en intento y en secreto1, quedan reservados
    for (int i = 0; i < leni; i++) {     
        for (int j=0;j<lenj;j++){
                        
            if(secreto1[j]==intento[i]){
                    
                encontrado++;
                secreto1[j]='x';
                intento[i]= 'p';
                //printf("en2 intento %s , y secreto1 %s \n",intento, secreto1);
                break;
            }

        }
       
    }
return (encontrado)  ;
}