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

void compararCartas(Carta c1, Carta c2, int atributoEscolhido) {
    float valor1, valor2;
    char atributoNome[30];

    switch (atributoEscolhido) {
        case 1:
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            sprintf(atributoNome, "População");
            break;
        case 2:
            valor1 = c1.area;
            valor2 = c2.area;
            sprintf(atributoNome, "Área");
            break;
        case 3:
            valor1 = c1.pib;
            valor2 = c2.pib;
            sprintf(atributoNome, "PIB");
            break;
        case 4:
            valor1 = c1.pontos_turisticos;
            valor2 = c2.pontos_turisticos;
            sprintf(atributoNome, "Pontos Turísticos");
            break;
        case 5:
            valor1 = calcularDensidadeDemografica(c1);
            valor2 = calcularDensidadeDemografica(c2);
            sprintf(atributoNome, "Densidade Demográfica");
            break;
        default:
            printf("Opção inválida! Escolha um atributo de 1 a 5.\n");
            return;
    }

    printf("\nComparação de cartas (Atributo: %s):\n", atributoNome);
    printf("Carta 1 - %s: %.2f\n", c1.pais, valor1);
    printf("Carta 2 - %s: %.2f\n", c2.pais, valor2);

    if ((atributoEscolhido == 5 && valor1 < valor2) || (atributoEscolhido != 5 && valor1 > valor2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.pais);
    } else if ((atributoEscolhido == 5 && valor2 < valor1) || (atributoEscolhido != 5 && valor2 > valor1)) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.pais);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    Carta carta1 = {"Brasil", 214000000, 8515767, 2200000000000, 50};
    Carta carta2 = {"Estados Unidos", 331000000, 9833517, 23000000000000, 60};

    int escolha;
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    compararCartas(carta1, carta2, escolha);

    return 0;
}
