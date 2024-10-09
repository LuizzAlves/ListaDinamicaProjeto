#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dinamica.h"

void menu() {
    printf("1. Adicionar Entrada\n");
    printf("2. Excluir Entrada\n");
    printf("3. Alterar Entrada\n");
    printf("4. Imprimir um Registro\n");
    printf("5. Imprimir Todos os Registros\n");
    printf("6. Ordenar Registros\n");
    printf("7. Sair\n");
}

int main() {
    ListaDinamica lista;
    inicializarLista(&lista);
    int opcao;
    char cpf[12];

    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        Nodo novoNodo;
        switch (opcao) {
            case 1:
                printf("Nome Completo: ");
                fgets(novoNodo.nomeCompleto, 100, stdin);
                printf("Endereço Residencial: ");
                fgets(novoNodo.endereco, 150, stdin);
                printf("CPF: ");
                fgets(novoNodo.cpf, 12, stdin);
                printf("Número de Contato: ");
                fgets(novoNodo.numeroContato, 15, stdin);
                printf("E-mail: ");
                fgets(novoNodo.email, 100, stdin);
                adicionarEntrada(&lista, novoNodo);
                break;
            case 2:
                printf("CPF: ");
                fgets(cpf, 12, stdin);
                excluirEntrada(&lista, cpf);
                break;
            case 3:
                printf("CPF: ");
                fgets(cpf, 12, stdin);
                alterarEntrada(&lista, cpf);
                break;
            case 4:
                printf("CPF: ");
                fgets(cpf, 12, stdin);
                imprimirRegistro(&lista, cpf);
                break;
            case 5:
                imprimirTodosRegistros(&lista);
                break;
            case 6:
                ordenarRegistros(&lista);
                break;
            case 7:
                liberarLista(&lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 7);

    return 0;
}
