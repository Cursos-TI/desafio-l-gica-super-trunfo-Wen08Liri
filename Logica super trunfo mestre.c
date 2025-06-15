#include <stdio.h>

typedef struct {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

float calcularDensidadeDemografica(Carta c) {
    return c.populacao / c.area;
}

void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    float valores1[6] = {c1.populacao, c1.area, c1.pib, c1.pontos_turisticos, calcularDensidadeDemografica(c1)};
    float valores2[6] = {c2.populacao, c2.area, c2.pib, c2.pontos_turisticos, calcularDensidadeDemografica(c2)};
    char *atributos[] = {"População", "Área", "PIB", "Pontos Turísticos", "Densidade Demográfica"};

    printf("\nComparação de cartas:\n");

    for (int i = 0; i < 2; i++) {
        int atributo = (i == 0) ? atributo1 : atributo2;
        printf("Atributo: %s\n", atributos[atributo-1]);
        printf("Carta 1 - %s: %.2f\n", c1.pais, valores1[atributo-1]);
        printf("Carta 2 - %s: %.2f\n", c2.pais, valores2[atributo-1]);

        // Aplicação das regras de comparação
        if ((atributo == 5 && valores1[atributo-1] < valores2[atributo-1]) || 
            (atributo != 5 && valores1[atributo-1] > valores2[atributo-1])) {
            printf("Vencedor deste atributo: %s\n", c1.pais);
        } else if ((atributo == 5 && valores2[atributo-1] < valores1[atributo-1]) || 
                   (atributo != 5 && valores2[atributo-1] > valores1[atributo-1])) {
            printf("Vencedor deste atributo: %s\n", c2.pais);
        } else {
            printf("Empate neste atributo!\n");
        }
    }

    float soma1 = valores1[atributo1-1] + valores1[atributo2-1];
    float soma2 = valores2[atributo1-1] + valores2[atributo2-1];

    printf("\nSoma dos atributos:\n");
    printf("Carta 1 - %s: %.2f\n", c1.pais, soma1);
    printf("Carta 2 - %s: %.2f\n", c2.pais, soma2);

    printf("\nResultado Final:\n");
    (soma1 > soma2) ? printf("Vencedor: %s\n", c1.pais) :
    (soma2 > soma1) ? printf("Vencedor: %s\n", c2.pais) :
    printf("Empate!\n");
}

int main() {
    Carta carta1 = {"Brasil", 214000000, 8515767, 2200000000000, 50};
    Carta carta2 = {"Estados Unidos", 331000000, 9833517, 23000000000000, 60};

    int escolha1, escolha2;

    printf("Escolha dois atributos para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");

    do {
        printf("Digite o primeiro atributo: ");
        scanf("%d", &escolha1);
        printf("Digite o segundo atributo: ");
        scanf("%d", &escolha2);
        if (escolha1 == escolha2) {
            printf("Os atributos devem ser diferentes! Escolha novamente.\n");
        }
    } while (escolha1 == escolha2);

    compararCartas(carta1, carta2, escolha1, escolha2);

    return 0;
}
