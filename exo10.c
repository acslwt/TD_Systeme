#include <stdio.h> //contient printf et scanf
#include <stdlib.h> //contient malloc()
#include <string.h> // contient strlen
#include <stdbool.h> // pour utiliser le type bool

int atoiV2(char *nombre){

    int taille = strlen(nombre);
    int nombre_converti = 0;

    bool negatif = (nombre[0]=='-');

    int debut = negatif;

    for(debut;debut<taille;debut++){

        int chiffre = nombre[debut] - '0';

        nombre_converti = nombre_converti*10 + chiffre;

    }
    
    if(negatif){

        nombre_converti *= -1;

    }

    return nombre_converti;

}

int main(int argc, char *argv[]){

    int nombre = atoiV2("124");

    printf("%i",nombre);

}