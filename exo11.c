#include <stdio.h> //contient printf et scanf
#include <stdlib.h> //contient malloc()
#include <string.h> // contient strlen

char int_to_char(int nombre){

    return nombre + '0';

}

char *itoaV2(int nombre){

    char *nombre_converti;
    int taille_nombre=0;
    int multiplicateur=1;


    while(nombre/multiplicateur!=0){

        taille_nombre++;
        multiplicateur *= 10;

    }

    multiplicateur = multiplicateur/10;

    printf("multiplicateur : %i",multiplicateur);

    int debut_tab=0;

    if(nombre<0){

        taille_nombre++;
        debut_tab=1;
        nombre *= -1;
        
    }

    nombre_converti = malloc(sizeof(char)*taille_nombre+1);
    nombre_converti[taille_nombre]='\0';

    if(debut_tab==1){

        nombre_converti[0]='-';

    }

    for(int i=debut_tab;i<taille_nombre;i++){

        nombre_converti[i] = int_to_char(nombre/multiplicateur);
        nombre = nombre%multiplicateur;
        multiplicateur = multiplicateur/10;

    }

    return nombre_converti;

}

int main(int argc, char *argv[]){

    char *nombre = itoaV2(-200);
    printf("Le nombre converti en char est : %s",nombre);

    return 0;

}