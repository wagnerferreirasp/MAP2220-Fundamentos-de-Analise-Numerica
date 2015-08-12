#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*******************************************************************************************************
 * Dicotomia                                                                                           */
float a0, b0, x0, e0, casasPrecisao;
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
    //printf("Digite dois números, indicando o intervalo em que provavelmente a raiz se encontra: ");
    //scanf("%f", &a0);
    //scanf("%f", &b0);
    a0 = -1;
    b0 = -0.75;
    x0 = (a0 + b0) / 2;
    e0 = fabs(x0 - a0);
    casasPrecisao = 4;
    //printf("%f %f %f %f\n", a0, b0, x0, e0);
}
// Método da dicotomia (completo e com precisão)
float dicotomia() {
    recebeEntrada();
    float sinal;
    printf("ai          bi       xi       ei       sgn\n");
    if (casasPrecisao > 6) casasPrecisao = 6;
    float precisao = pow(10, -casasPrecisao);
    float ai = a0, bi = b0, xi = x0, ei = e0;
    while (ei > precisao) {
        sinal = sgn(ai, xi);
        if (sinal > 0) {
           ai = xi;
        } else {
            bi = xi;
        }
        xi = (ai + bi)/2.0;
        ei = fabs(xi - ai);
        if (sinal < 0)
            printf("%f %f %f %f -\n", ai, bi, xi, ei);
        else printf("%f %f %f %f +\n", ai, bi, xi, ei);
    }
    return xi;
}
void exemploDicotomia() {
    printf("Raiz: %f", dicotomia());
}

/** Dicotomia - fim
 *******************************************************************************************************/


/*******************************************************************************************************
 * Arredondamento                                                                                      */
// Recebe um numero na representação única e devolve o arredondamento com precisão precisao
float round2(float numero, int expoente, int base, int precisao) {
    return (round(numero * pow(base, precisao)) / pow(base, precisao)) * pow(base, expoente);
}
void exemploArredondamento() {
    printf("%.2f", round2(-0.838, 3, 10, 2));

}
/** Arredondamento - fim
 *******************************************************************************************************/

int main (int argc, char *argv[]) {
    exemploDicotomia();
    //recebeEntrada();
    //printf("A raiz é aproximadamente %f", dicotomia());
    return 0;
}
