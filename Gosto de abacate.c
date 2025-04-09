#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

void limparTela() {
    for (int i = 0; i < 50; i++) {
        printf("\n");
    }
}

void estacionar(int estacionamento1[], int estacionamento2[], int manobra[], int *pos1, int *pos2, int carro) {
    if (*pos1 < MAX) {
        estacionamento1[*pos1] = carro;
        (*pos1)++;
        printf("Carro estacionado no estacionamento 1.\n");
    } else if (*pos2 < 2 * MAX) {
        estacionamento2[*pos2 - MAX] = carro;
        (*pos2)++;
        printf("Carro estacionado no estacionamento 2.\n");
    } else {
        printf("Estacionamento cheio!\n");
    }
}

void retirar(int estacionamento1[], int estacionamento2[], int *pos1, int *pos2, int carro) {
    int encontrado = 0;
    int i = 0;
    
    while (i < *pos1) {
        if (estacionamento1[i] == carro) {
            estacionamento1[i] = 0;
            printf("Carro retirado do estacionamento 1.\n");
            encontrado = 1;
            break;
        }
        i++;
    }
    
    if (!encontrado) {
        i = MAX;
        while (i < *pos2) {
            if (estacionamento2[i - MAX] == carro) {
                estacionamento2[i - MAX] = 0;
                printf("Carro retirado do estacionamento 2.\n");
                encontrado = 1;
                break;
            }
            i++;
        }
    }
    
    if (!encontrado) {
        printf("Carro não encontrado!\n");
    }
}

void mostrarEstacionamento(int estacionamento1[], int estacionamento2[]) {
    limparTela();
    printf("Estacionamento 1: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", estacionamento1[i]);
    }
    printf("\nEstacionamento 2: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", estacionamento2[i]);
    }
    printf("\n");
    
    printf("\nPressione qualquer tecla para voltar ao menu...\n");
    getchar(); 
    getchar(); 
}

int lerNumero() {
    int numero;
    while (scanf("%d", &numero) != 1) {
        printf("Entrada inválida. Por favor, insira um número inteiro: ");
        while(getchar() != '\n');
    }
    return numero;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int estacionamento1[MAX] = {0};
    int estacionamento2[2 * MAX] = {0};
    int manobra[MAX] = {0};
    int pos1 = 0, pos2 = MAX;
    int opcao, carro;
    
    do {
    	
        printf("\nMenu:\n");
        printf("1. Estacionar\n");
        printf("2. Retirar Carro\n");
        printf("3. Mostrar Estado dos Estacionamentos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: "); 
        opcao = lerNumero();
        limparTela();
        switch(opcao) {
            case 1:
                printf("Digite o número do carro a estacionar: ");
                carro = lerNumero();
                estacionar(estacionamento1, estacionamento2, manobra, &pos1, &pos2, carro);
                break;
            case 2:
                printf("Digite o número do carro a retirar: ");
                carro = lerNumero();
                retirar(estacionamento1, estacionamento2, &pos1, &pos2, carro);
                break;
            case 3:
                mostrarEstacionamento(estacionamento1, estacionamento2);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
        
    } while (opcao != 4);
    
    return 0;
}






	



