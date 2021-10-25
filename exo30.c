/*Pour positionner le curseur à un endroit specifique du fichier on utilise lseek (voir comment elle fonctionne).
lseek(num-dec,decalage,position) renvoit la position du curseur après décalage.
num-dec : numero du descripteur concerné
decalage : un Entier € Z
position : SEEK.SET commence à 0 et déplace le curseur de décalage(defini en haut)
           SEEK.CUR : position courante + décalage
           SEEK.END : fin + décalage
*/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){

   if(argc==2){ // Si on passe un unique argument en ligne de commande soit ici un caractere

      int f = open("exo30.txt",O_RDONLY); //on ouvre le fichier exo30 en lecture seul

      int debut = lseek(f,0,SEEK_SET); //on fait pointer la var debut sur le premier caractere et la var fin sur le dernier caractere du fichier
      int fin = lseek(f,0,SEEK_END);

      int b; // cette var contiendra le nombre ASCII du caractere pointer
      int milieu = (debut + fin)/2; // milieu pointe sur le caractere situer au milieu des vars debut et fin
      int caractere = (int) argv[1][0]; // ici caractere prend la valeur ASCII du caractere passer en commande.

      lseek(f,(milieu)*sizeof(char),SEEK_SET); //on fait pointer le "curseur" sur le milieu du fichier.
      read(f,&b,sizeof(char));// read() ici permet d'affecter la valeur ASCII du caractere pointer par le curseur.

      while(b!=caractere && fin>=debut){

         if(caractere<b){ //si la valeur ASCII de b et superieur à celle de caractere

            fin = milieu - 1; // cela nous permet de couper le fichier en deux et de chercher que dans la premiere moitier du fichier.
            printf("%i\n",milieu); // on printf pour verifier quel valeur prend milieu (ceci permet de verifier ce que l'on fait lorsque qu'on est entrain de coder).

         }else{ // donc si la val ASCII de b est inférieur à celle de caractere

            debut = milieu + 1; // faire ça nous permet de traiter que la deuxieme moitier du fichier.
            printf("%i\n",milieu);

         }

         milieu = (debut+fin)/2; 
         lseek(f,(milieu)*sizeof(char),SEEK_SET);
         read(f,&b,sizeof(char));

      }

      if(fin<debut){

            printf("Le caractère n'existe pas dans le fichier lu !");

         }else{

            printf("%c \n", b);

         }

   }else{

      printf("Veuillez indiquer un caractere en commande !");

   }

}