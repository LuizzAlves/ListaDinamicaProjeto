#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dinamica.h"

void inicializarLista(ListaDinamica *lista) {
    lista->inicio = NULL;
}

void adicionarEntrada(ListaDinamica *lista, Nodo novoNodo) {
    // Verifica se o CPF é único
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cpf, novoNodo.cpf) == 0) {
            printf("CPF já cadastrado.\n");
            return;
        }
        atual = atual->proximo;
    }
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));
    *novo = novoNodo;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void excluirEntrada(ListaDinamica *lista, const char *cpf) {
    Nodo *atual = lista->inicio;
    Nodo *anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            if (anterior == NULL) {
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("CPF não encontrado.\n");
}

void alterarEntrada(ListaDinamica *lista, const char *cpf) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            // Permitir ao usuário alterar as informações
            printf("Nome Completo (atual: %s): ", atual->nomeCompleto);
            fgets(atual->nomeCompleto, 100, stdin);
            printf("Endereço Residencial (atual: %s): ", atual->endereco);
            fgets(atual->endereco, 150, stdin);
            printf("Número de Contato (atual: %s): ", atual->numeroContato);
            fgets(atual->numeroContato, 15, stdin);
            printf("E-mail (atual: %s): ", atual->email);
            fgets(atual->email, 100, stdin);
            return;
        }
        atual = atual->proximo;
    }
    printf("CPF não encontrado.\n");
}

void imprimirRegistro(ListaDinamica *lista, const char *cpf) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            printf("Nome Completo: %s\n", atual->nomeCompleto);
            printf("Endereço Residencial: %s\n", atual->endereco);
            printf("CPF: %s\n", atual->cpf);
            printf("Número de Contato: %s\n", atual->numeroContato);
            printf("E-mail: %s\n", atual->email);
            return;
        }
        atual = atual->proximo;
    }
    printf("CPF não encontrado.\n");
}

void imprimirTodosRegistros(ListaDinamica *lista) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome Completo: %s\n", atual->nomeCompleto);
        printf("Endereço Residencial: %s\n", atual->endereco);
        printf("CPF: %s\n", atual->cpf);
        printf("Número de Contato: %s\n", atual->numeroContato);
        printf("E-mail: %s\n", atual->email);
        atual = atual->proximo;
    }
}

void ordenarRegistros(ListaDinamica *lista) {
    if (lista->inicio == NULL || lista->inicio->proximo == NULL) {
        return;
    }
    Nodo *atual, *proximo;
    int trocado;
    do {
        trocado = 0;
        atual = lista->inicio;
        while (atual->proximo != NULL) {
            proximo = atual->proximo;
            if (strcmp(atual->nomeCompleto, proximo->nomeCompleto) > 0) {
                Nodo temp = *atual;
                *atual = *proximo;
                *proximo = temp;
                trocado = 1;
            }
            atual = atual->proximo;
        }
    } while (trocado);
}

void liberarLista(ListaDinamica *lista) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
}
