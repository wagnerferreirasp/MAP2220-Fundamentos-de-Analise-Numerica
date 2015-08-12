#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a0, b0, x0, e0;

// Função a encontrar a raiz
float f(float x) {
    return x * x * x + cosf(x);
}

// Função sgn usada no método da dicotomia
float sgn(float ai, float xi) {
    return f(ai) * f(xi);
}

// recebe o intervalo em que a raiz se encontra, para calculo por dicotomia
void recebeEntrada() {
    printf("Digite dois números, indicando o intervalo em que provavelmente a raiz se encontra: ");
    scanf("%f", &a0);
    scanf("%f", &b0);
    x0 = (a0 + b0) / 2;
    e0 = abs(x0 - a0);
}

// Método da dicotomia (incompleto)
float dicotomia() {
    float ai = a0, bi = b0, xi = x0, ei = e0;
    while (ei > 0.004f) {
        if (sgn(ai, xi) > 0) {
           ai = xi;
        } else {
            bi = xi;
        }
        xi = (ai + bi)/2;
        ei = abs(xi - ai);
    }
    return xi;
}

/* Recebe um numero na representação única e devolve o arredondamento com precisão precisao */
float round2(float numero, int expoente, int base, int precisao) {
    return (round(numero * pow(base, precisao)) / pow(base, precisao)) * pow(base, expoente);
}

int main (int argc, char *argv[]) {
    //recebeEntrada();
    //printf("A raiz é aproximadamente %f", dicotomia());
    printf("%.2f", round2(-0.838, 3, 10, 2));
    return 0;
}
