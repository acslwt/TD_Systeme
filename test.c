#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){

    int file = 0;

    file = open("text.txt",O_CREAT);

    if(file!=EOF){

        printf("cou");

    }

}
