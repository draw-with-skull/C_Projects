#include<stdio.h>

int factorial_recursiv(int F);
int factorial(int F);
float sin(int x);

int main()
{
    float n;
    scanf("%f", &n);
    printf("%f", factorial_recursiv(n));
    return 0;
}

int factorial_recursiv(int F){
if(F==0)
    return 1;
    else
    return F*factorial_recursiv(F-1);
}
int factorial(int F){}
float sin(int x){}
