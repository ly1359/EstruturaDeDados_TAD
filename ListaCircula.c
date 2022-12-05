#include <stdio.h>
#include <stdlib.h>
#include "ListaCircula.h"

struct  no{
    int valor;
    struct no *prox;
};

struct listaCircula{
    No *inicio;
    No *fim;
    int tam;
};

Lista* criarLista(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

void inserirNoInicio(Lista *l, int  num){
    No *novo = (No *) malloc(sizeof(No));

    novo->valor = num;
    novo->prox = l->inicio;
    l->inicio = novo;
    if(l->fim == NULL){
        l->fim =novo;
    }
    l->fim->prox = l->inicio;
    l->tam++;
}

void inserirNoFim(Lista *l, int num){
    No *novo = (No *) malloc(sizeof(No));
    
    novo->valor = num;
    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
        l->fim->prox = l->inicio;
    } else {
        l->fim->prox = novo;
        l->fim = novo;
        l->fim->prox = l->inicio;
    }
    l->tam++;
} 

void remover(Lista *l, int num){
    No *remover  = NULL;
    No *aux = NULL;

    if(l->inicio != NULL){
        if(l->inicio == l->fim && l->inicio->valor == num){
            remover = l->inicio;
            l->inicio = NULL;
            l->fim = NULL;
            l->tam--;
        }else if(l->inicio->valor == num){
            remover = l->inicio;
            l->inicio = remover->prox;
            l->fim->prox = l->inicio;
            l->tam--;
        }else{ 
            aux = l->inicio;
            while (aux->prox != l->inicio && aux->prox->valor != num){
                aux = aux->prox;
            }
            if(aux->prox->valor == num){
                if(l->fim == aux->prox){
                    remover = aux->prox;
                    aux->prox = remover->prox;
                    l->fim = aux;
                } else {
                    remover = aux->prox;
                    aux->prox = remover->prox;


                }
                l->tam--;
            }
        }
    }
}
void imprime(Lista *l){
    No *no = l->inicio;
    printf("\nLista tem tamanho: %d\n", l->tam);
    do{
        printf("%d ", no->valor);
        no = no->prox;
    } while (no->valor != l->inicio->valor);
    printf("\n");
}
