#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//defines
#define clear() printf("\033[H\033[J")

//function definitions
void read_file_names(char name[],unsigned short file_number);       //reads the file name and determines whether there is a space
void concatenate(char file_name[],FILE *out_put);                     //creates the desired file

char concatenated_file_name[100];

//main funtion
int main(){
    FILE *out_put;
    out_put=fopen("output.txt","w+");

    unsigned int n,i;
    char file_name[20];

    printf("number of files to concatenate:");
    scanf("%d",&n);

    read_file_names(file_name,i);
    for(i=1;i<=n;i++){
        clear();
        printf("Name for file %d: ",i);
        read_file_names(file_name,i);
        strcat(concatenated_file_name,file_name);
        concatenate(file_name,out_put);
    }

    clear();
    printf("Finished");

}

//function's body
void read_file_names(char name[],unsigned short file_number){
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

void concatenate(char filename[],FILE *out_put){
    FILE *flux;
    int character;
    flux = fopen(filename,"r");
    while(1) {
        character = fgetc(flux);
        if(!feof(flux))fputc(character,out_put);
        if(feof(flux))break;
    }
    fclose(flux);
}
