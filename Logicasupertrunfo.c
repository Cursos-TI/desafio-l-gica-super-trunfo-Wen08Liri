#include <stdio.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

float calcularDensidadePopulacional(Carta c) {
    return c.populacao / c.area;
}

float calcularPIBPerCapita(Carta c) {
    return c.pib / c.populacao;
}

void compararCartas(Carta c1, Carta c2) {
    // Escolher um atributo para comparação
    float atributo1 = calcularPIBPerCapita(c1);
    float atributo2 = calcularPIBPerCapita(c2);
    
    // Determinar o vencedor
    if (atributo1 > atributo2) {
        printf("Comparação de cartas (Atributo: PIB per capita):\n");
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, atributo1);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, atributo2);
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
    } else if (atributo2 > atributo1) {
        printf("Comparação de cartas (Atributo: PIB per capita):\n");
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, atributo1);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, atributo2);
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    } else {
        printf("Comparação de cartas (Atributo: PIB per capita):\n");
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, atributo1);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, atributo2);
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Definição das cartas
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 230000000000.00, 50};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.27, 180000000000.00, 45};

    compararCartas(carta1, carta2);

    return 0;
}
