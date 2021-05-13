#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//defines
#define clear() printf("\033[H\033[J")

//function definitions
void read_file_names(char name[]);       //reads the file name and determines whether there is a space
void counter(char file_name[]);

//main funtion
int main(){
    char file_name[20];

        printf("Name of the file : ");
        read_file_names(file_name);
        counter(file_name);
    printf("Finished");

}

//function's body
void read_file_names(char name[]){
    bool correct=false;
    int i;
    while(!correct){
        gets(name);
        i=0;
        while(i<=strlen(name)&&name[i]!=32&&name[i]!=NULL)i++;  //Finds if the name contains spaces
        if(i==strlen(name))correct=true;else correct=false;     //Determines if the there are no spaces in the name
        if(!correct)printf("The name contains spaces\n");
    }
    strcat(name,".txt");                                        //Cerates the name with extensions
}

void counter(char filename){
    FILE *flux;
    int character;
    int line_count=0,character_count=0,space_count=0;
    flux = fopen(filename,"r");
    while(1) {
        character = fgetc(flux);
        if(feof(flux))break;
        if(character==10)line_count++;
        if(character==32)space_count++;
        character_count++;
    }
    printf("Number of characters (without spaces): %d\n",character_count);
    printf("Number of characters (with spaces): %d\n",character_count+space_count);
    printf("Number of lines: %d\n",line_count);
    printf("Number of words: %d\n",space_count);
    fclose(flux);
}
