//Refaire en argument systeme.

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

    char ligne[TAILLE_MAX]="";

    int nombreLigneSaute = -3;
    int ligneActuelle = 0;

    if(fichier!=NULL){

        if(nombreLigneSaute>0){

            while(fgets(ligne,TAILLE_MAX,fichier)!=NULL){

                if(ligneActuelle<nombreLigneSaute){

                    ligneActuelle++;

                }else{

                    printf("%s",ligne);

                }

            }

        }else{

            nombreLigneSaute = nombreLigneSaute * (-1);

            while(fgets(ligne,TAILLE_MAX,fichier)!=NULL && ligneActuelle<nombreLigneSaute){

                ligneActuelle++;
                printf("%s",ligne);

            }

        }

        fclose(fichier);

    }

}