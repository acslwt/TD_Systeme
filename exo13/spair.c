#include <stdio.h> //contient printf et scanf
#include <stdlib.h> //contient atoi()
#include "pair.h"
#include "impair.h"

int main(int argc, char *argv[]){

    int nombre = atoi(argv[1]);

    if(pair(nombre)==1){

        printf("pair");

    }else{

        printf("impair");

    }

}