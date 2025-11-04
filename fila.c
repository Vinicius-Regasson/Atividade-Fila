#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

int filaCheia(Fila *f) {
    return f->fim == MAX - 1;
}

int filaVazia(Fila *f) {
    return f->inicio > f->fim;
}

void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("A fila esta cheia!\n");
    } else {
        f->fim++;
        f->itens[f->fim] = valor;
        printf("Elemento %d adicionado com sucesso!\n", valor);
    }
}

void desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila esta vazia!\n");
    } else {
        int removido = f->itens[f->inicio];
        f->inicio++;
        printf("Desenfileirado: %d\n", removido);
    }
}

void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila esta vazia!\n");
    } else {
        printf("Fila: ");
        for (int i = f->inicio; i <= f->fim; i++) {
            printf("%d ", f->itens[i]);
        }
        printf("\n");
    }
}

void encontrarElemento(Fila *f, int valor) {
    if (filaVazia(f)) {
        printf("A fila esta vazia!\n");
        return;
    }
    int cont = 0;
    for (int i = f->inicio; i <= f->fim; i++) {
        if (f->itens[i] == valor) cont++;
    }
    if (cont > 0)
        printf("O elemento %d aparece %d vez(es) na Fila.\n", valor, cont);
    else
        printf("O elemento %d nao foi encontrado na Fila.\n", valor);
}

int tamanhoFila(Fila *f) {
    if (filaVazia(f)) return 0;
    return (f->fim - f->inicio + 1);
}

int main() {
    Fila fila;
    int opcao, valor;

    iniciarFila(&fila);

    do {
        printf("\n===== MENU DA FILA =====\n");
        printf("1. Enfileirar elemento\n");
        printf("2. Desenfileirar elemento\n");
        printf("3. Mostrar conteudo da fila\n");
        printf("4. Encontrar elemento na fila\n");
        printf("0. Sair\n");
        printf("=========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para enfileirar: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                break;
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 4:
                printf("Digite o valor a procurar: ");
                scanf("%d", &valor);
                encontrarElemento(&fila, valor);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        printf("Quantidade atual de elementos: %d\n", tamanhoFila(&fila));

    } while (opcao != 0);

    return 0;
}
