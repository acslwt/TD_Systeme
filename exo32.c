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

int main(int argc, char* argv[]){

    int child_process = fork();
    int resultat = 0;
    int file = open("test.txt",O_RDONLY);
    int b;

    if(child_process==0){

        resultat = 2;
        read(file,&b,sizeof(char));
        printf("Je suis le printf du child, mon resultat est : %i ici file vaut %c",resultat,b);

    }else{

        read(file,&b,sizeof(char));
        printf("Je suis le printf du parent, mon resultat est : %i ici file vaut %c",resultat,b);

    }

}