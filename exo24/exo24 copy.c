#include <stdlib.h>
#include <stdio.h>
#define TAILLE_MAX  1000

int nombreLigneFichier(FILE* fichier){

    int nombreLigne=1;
    int caractereActuel=0;

    while((caractereActuel = fgetc(fichier))!=EOF){

            if(caractereActuel=='\n'){

                nombreLigne++;

            }

        }

    return nombreLigne;

}

int main(int argc, char *argv[]){

    FILE* fichier = NULL; //On intialise a NULL pour pouvoir tester par la suite si le fichier a bien été ouvert.
    fichier = fopen("exo24.txt","r");

    int nombreLigne=nombreLigneFichier(fichier);
    int nombreCaractereLigne=0;

    char *ligne;

    int nombreLigneSaute = 3;
    int ligneActuelle = 0;

    int caractereActuel;

    if(fichier!=NULL){

        for(int i=0;i<nombreLigne;i++){

            while(fgetc(fichier)!='\n'){

                nombreCaractereLigne++;

            }

            ligne = (char *) malloc(sizeof(char*)*(nombreCaractereLigne+2));
            ligne[nombreCaractereLigne+1]='\n';

            while(fgets(ligne,nombreCaractereLigne+2,fichier)!=NULL){

                if(ligneActuelle<nombreLigneSaute){

                    ligneActuelle++;

                }else{

                    printf("%s",ligne);

                }

            }

            nombreCaractereLigne=0;
            free(ligne);

        }

        fclose(fichier);

    }

}