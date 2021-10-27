/*fork() permet de dupliquer un processus :
    crée une ligne dans la table des processus pour le fils.
    duplique tous les élements de mémoire et ressource du père pour le fils;
     donc code,données statiques,la pile,et le tas.)

Le code de retour du fork() est le pid du fils dans le père*/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){

    int resultat = 0;
    int file = open("test.txt",O_WRONLY);
    int child_process = fork();

    if(child_process==0){

        int resultat_child = 4;
        resultat = 2;
        write(file,"Fils",sizeof(char)*4);
        printf("Je suis le printf du child, mon resultat est : %i son add est : %p\n",resultat,&resultat);

    }else{

        int resultat_fath = 5;
        write(file,"Pere",sizeof(char)*4);
        printf("Je suis le printf du fath, mon resultat est : %i son add est : %p\n",resultat,&resultat);

    }

}
