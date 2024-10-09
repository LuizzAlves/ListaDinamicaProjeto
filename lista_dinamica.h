#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

typedef struct Nodo {
    char nomeCompleto[100];
    char endereco[150];
    char cpf[12];
    char numeroContato[15];
    char email[100];
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *inicio;
} ListaDinamica;

void inicializarLista(ListaDinamica *lista);
void adicionarEntrada(ListaDinamica *lista, Nodo novoNodo);
void excluirEntrada(ListaDinamica *lista, const char *cpf);
void alterarEntrada(ListaDinamica *lista, const char *cpf);
void imprimirRegistro(ListaDinamica *lista, const char *cpf);
void imprimirTodosRegistros(ListaDinamica *lista);
void ordenarRegistros(ListaDinamica *lista);
void liberarLista(ListaDinamica *lista);

#endif
