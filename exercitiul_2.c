#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//defines
#define clear() printf("\033[H\033[J")

//function definitions
void read_file_names(char name[]);
int last_line(char file_name[]);
void print_lines(char file_name[], int number_of_lines);

//main funtion
int main(){

    unsigned int number_of_lines;
    char file_name[20];


        printf("Name of the file : ");
        read_file_names(file_name);
        number_of_lines=last_line(file_name);
        print_lines(file_name,number_of_lines);
    //clear();
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

int last_line(char file_name[]){
    FILE *flux;
    int character,lines=0;
    flux = fopen(file_name,"r");
    while(1) {
        character = fgetc(flux);
        if(feof(flux))break;
        if(character==10)lines=lines+1;
    }
    fclose(flux);
    return lines;
}

void print_lines(char file_name[], int number_of_lines){
    FILE *flux;
    int character,line_number=0;
    flux = fopen(file_name,"r");
    while(1) {
        character = fgetc(flux);
        if(feof(flux))break;
        if(character==10)line_number=line_number+1;

        if(number_of_lines-line_number<=10)printf("%c",character);
    }
    fclose(flux);
}
