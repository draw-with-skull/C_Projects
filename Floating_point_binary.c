#include <stdio.h>

void Afisare_binar(int n, int i){
    int k;
    for (k = i - 1; k >= 0; k--)
        if ((n >> k) & 1)printf("1");else printf("0");
}

typedef union {

    float f;
    struct{
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int semn : 1;

    } binar;
} S_float;

void Afisare_IEEE(S_float var){
    printf("%d | ", var.binar.semn);
    Afisare_binar(var.binar.exponent, 8);
    printf(" | ");
    Afisare_binar(var.binar.mantissa, 23);
    printf("\n");
}

int main()
{
    S_float var;
    var.f = 11.23523;

    printf("%f:   ",var.f);
    Afisare_IEEE(var);

    return 0;
}

//funtii


