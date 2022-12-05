#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

struct  lista {
    int valor;
    struct lista *prox;
    struct lista *ant;
};

void inserirNoInicio(Lista *l, int num){
    Lista *aux = (Lista *) malloc(sizeof(Lista));
    aux->valor = num;
    aux->prox = l;
    aux->ant = NULL;
    if(l != NULL){
        l->ant = aux;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
    l = aux;
}

void inserirNoFim(Lista *l, int num){
    Lista *aux = malloc(sizeof(Lista)); 
    Lista *novo = malloc(sizeof(Lista));
    aux->valor = num;
    aux->prox = NULL;

    if(l == NULL){
        l = aux;
        aux->ant = NULL;
    }else {
        novo = l;
        while(novo->prox != NULL){
            novo = novo->prox;
        }
        novo->prox = aux;
        aux->ant = novo;
    }
}

void inserirNoMeio(Lista *l, int num, int ant){
    Lista *novo = malloc(sizeof(Lista));
    Lista *aux = malloc(sizeof(Lista));
    novo->valor = num;

    if(l == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        l = novo;
    } else {
        aux = l;
        while(aux->valor != ant && aux->prox != NULL){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox->ant = novo;
        novo->ant = aux;
        aux->prox = novo;
    }
}


void inserirOrdenado(Lista *l, int num){
    Lista *novo = malloc(sizeof(Lista));
    Lista *aux = malloc(sizeof(Lista));
    novo->prox = num;

    if(l == NULL){
        novo->prox = NULL;
        novo->ant = NULL;
        l = novo;
    } else if(novo->valor < (l)->valor){
        novo->prox = l;
        l->ant = novo;
        l = novo;
    } else {
        aux = aux->prox;
        while((aux->prox != NULL) && novo->valor > aux->prox->valor){
            aux = aux->prox;
        }
    novo->prox = aux->prox;
    aux->prox->ant = novo;
    novo->ant = aux;
    aux->prox = novo;
    }
}

Lista* remover(Lista *l, int num){
    Lista *aux = NULL;
    Lista *execlui = NULL;
    if(l != NULL){
        if(l->valor == num){
            execlui = l;
            l = execlui->prox;
            if(l->ant != NULL){
                l->ant = NULL;
            }
        } else {
            aux = l;
            while(aux->prox != NULL && aux->prox->valor != num){
                aux = aux->prox;
            }
            if(aux->prox ){
                execlui = aux->prox;
                aux->prox = execlui->prox;
                if(aux->prox != NULL){
                    aux->prox->ant = aux;

                }
            }
        }
    }
    return execlui;
}

