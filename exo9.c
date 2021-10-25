#include <stdio.h> //contient printf et scanf
#include <stdlib.h> //contient malloc()
#include <string.h> // contient strlen

char **strsplit(const char *s,char sep){

    int nombre_sep=0;
    int taille_chaine = strlen(s);

     for(int i=0;i<taille_chaine;i++){

        if(s[i]==sep){

            nombre_sep++;

        }

    }

    printf("Nombre de sep : %i \n",nombre_sep);

    char **mot_separe=(char **)malloc(sizeof(char*)*(nombre_sep+1));
    mot_separe[nombre_sep] = NULL;

    int taille_precedente = 0;

    for(int i=0;i<nombre_sep+1;i++){

        int taille_mot=0;

        while(s[taille_mot+taille_precedente]!=sep){

            taille_mot++;

        }

        char *mot=malloc(sizeof(char*)*(taille_mot+1));
        mot[taille_mot]='\0';

        for(int j=0;j<taille_mot;j++){

            mot[j]=s[taille_precedente+j];

        }

        mot_separe[i] = mot;
        taille_precedente += taille_mot+1;

    }

    return mot_separe;

}

int main(int argc, char *argv[]){

    char **copieTab = strsplit("Dossier/Ayoub/Asbou",'/');

    for(int i=0;i<strlen(*copieTab);i++){

        printf("%i : %s \n",i,copieTab[i]);

    }

    return 0;

}

// CORRECTION.

