#include <stdio.h>
#include <math.h>

void calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2, float* distancia);
float calcularPerimetro(float puntos[4][3], float* a, float* b, float* c, float* d, float* e, float* f);
float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
float calcularAreaSuperficial(float puntos[4][3]);
float calcularVolumen(float areaBase, float altura);

int main(int argc, char* argv[])
{
    float puntos[4][3] = {{3, 0, 0}, {0, 0, 3}, {0, 0, 0}, {1, 7, 1}};
    float a, b, c, d, e, f;

    float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f);
    printf("El perímetro de la pirámide es %f\n", perimetro);

    float areaSuperficial = calcularAreaSuperficial(puntos);
    printf("El área superficial de la pirámide es %f\n", areaSuperficial);

    float areaBase = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    float altura = a;
    float volumen = calcularVolumen(areaBase, altura);
    printf("El volumen de la pirámide es %f\n", volumen);

    return 0;
}

void calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2, float* distancia)
{
    *distancia = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

float calcularPerimetro(float puntos[4][3], float* a, float* b, float* c, float* d, float* e, float* f)
{
    calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], a);
    calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2], b);
    calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2], c);
    calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2], d);
    calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2], e);
    calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2], f);

    return *a + *b + *c + *d + *e + *f;
}

float calcularArea(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
    float a, b, c;
    calcularDistancia(x1, y1, z1, x2, y2, z2, &a);
    calcularDistancia(x1, y1, z1, x3, y3, z3, &b);
    calcularDistancia(x2, y2, z2, x3, y3, z3, &c);

    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

float calcularAreaSuperficial(float puntos[4][3])
{
    float areabase = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    float area1 = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    float area2 = calcularArea(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    float area3 = calcularArea(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    return areabase + area1 + area2 + area3;
}

float calcularVolumen(float areaBase, float altura)
{
    return (areaBase * altura) / 3;
}
