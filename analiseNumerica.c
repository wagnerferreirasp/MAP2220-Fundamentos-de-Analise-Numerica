#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*******************************************************************************************************
 * Dicotomia                                                                                           */
float a0, b0, x0, e0, casasPrecisao, sinal0;
// Função a encontrar a raiz
float f(float x) {
    return pow(2.71828182846f, x) - 4 * x;
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
    a0 = 2;
    b0 = 3;
    x0 = (a0 + b0) / 2;
    e0 = fabs(x0 - a0);
    sinal0 = sgn(a0, x0);
    casasPrecisao = 4;
    //printf("%f %f %f %f\n", a0, b0, x0, e0);
}
// Método da dicotomia (completo e com precisão)
float dicotomia() {
    recebeEntrada();
    printf("ai\t\t\tbi\t\t\txi\t\t\tei\t\t\tsgn\n");
    if (casasPrecisao > 6) casasPrecisao = 6;
    float precisao = pow(10, -casasPrecisao);
    float ai = a0, bi = b0, xi = x0, ei = e0;
    float sinal = sinal0;
    while (ei > precisao) {
    	if (sinal < 0) {
			printf("%f\t%f\t%f\t%f\t-\n", ai, bi, xi, ei);
			bi = xi;
    	}
    	else {
    		printf("%f\t%f\t%f\t%f\t+\n", ai, bi, xi, ei);
    		ai = xi;
    	}
        xi = (ai + bi)/2.0;
        ei = fabs(xi - ai);
        sinal = sgn(ai, xi);
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
