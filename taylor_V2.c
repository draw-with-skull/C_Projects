#include<stdio.h>
//#include<iomanip>
#define MAX_RADIAN 6.283185
//NOTA!!! valoaera maxima pentru pentru factorial este valoarea maxima care poate sa fie stocata in int
float Citire_x(float x);//functia care citeste o valoare pentru x

float Valoare(float x,int iteratii);//functia care calculeaza valoarea pentru cos de x
int main(){//functia principala
    //declarare variabile
    float x,cos;//declararea variabilelor de tip float
    int n,i;//variabila pentru parcurgere
    //Citire valoare pentru x; valoarae in radian
    x=Citire_x(x);//citirea unei valori pentru x; valoarea in paramentrii
    cos=1;//atribuirea valori stocate in x variabilei cos;variabila cos o sa stocheze valoarea finala
    //citirea numarului de iterati
    printf("Numarul de iterati:");//afisare de text
    scanf("%d",&n);//citirea numarului de iteratii
    //parcurgerea iteratilor
    for(i=1;i<=n;i++)//parcurgerea iteratiilor
        if(i%2==0)//verifica daca suntem la un termen pozitiv sau negativ din sirul lui taylor
        {cos=cos+Valoare(x,2*i);}//creaste valoarea lui cos cu termenul curent din seria lui taylor
        else//caz alternativ
        {cos=cos-Valoare(x,2*i);}//creaste valoarea lui cos cu termenul curent din seria lui taylor
    printf("cos(%f):%.22f",x,cos);//afiseaza valoarea lui cos de x
}

float Citire_x(float x){//definitia functiei care citeste o valoarea pentru x
    do{//structura repetitiva  conditionata posterior ;pentru ca trebuie
        printf("Valoarea lui x:");//afiseaza text
        scanf("%f",&x);//citeste  o valoare pentru x
        if(x<0)printf("Valoarea e negativa!\a\n");//afiseaza text in cazul in care valoarea nu este buna
        if(x>MAX_RADIAN)printf("Valoarea e prea mare!\a\n");//afiseaza text in cazul in care valoarea nu este buna
    }while(x<0||x>MAX_RADIAN);//coditia structuri repetitive
    return x;//returneaza valoarea lui x
}

float Valoare(float x,int iteratii){ //definitia functiei care calculeaza termenul n din sirul lui taylor
    float rezultat=1;//initializeaza variabila cu unu in care o sa se stocheze valoarea n din sirul lui taylor
    for(int i=1;i<=iteratii;i++){//parcurgere de la i la n;n reprezinta valorea exponentului lui x valoarea factorialului
        rezultat=rezultat*(x/i);//calcule
    }
    return rezultat;//returneaza valoarea ternenumui n din sirul lui taylor

}



