#include <stdio.h>
#include <stdlib.h>
#include "TADLista.h"

struct lista{
    int quant;
    int vet[MAX];
};

Lista *criar(){
    Lista *l;
    l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL){
        l->quant = 0;
    }
    return l;
}

void clear(Lista *l){
    free(l);
}

void append(Lista *l, int valor){
    l->vet[l->quant] = valor;
    l->quant++;
}

void insert(Lista *l, int valor){
    for(int i = l->quant -1; i >= 0; i--){
        l->vet[i + 1] = l->vet[i];
    }
    l->vet[0] = valor;
    l->quant++;
}
void insert_sorted(Lista *l, int valor){
    for(int i = l->quant -1; i>= 0; i--){
        l->vet[i+1] = l->vet[i];
    }
    l->vet[0] = valor;
    l->quant++;
    int aux;
    for(int i = 0; i < l->quant; i++){
         for(int j = 0; j < l->quant-1; j ++){
            if (l->vet[j] > l->vet[j+1]){
               aux = l->vet[j];
               l->vet[j] = l->vet[j+1];
               l->vet[j+1] = aux;
            }
         }
    }
}

int full(Lista *l){
    if(l->quant == 0){
        return 0;
    }else{
        return 1;
    }
}

int empty(Lista *l){
    if(l->quant == 0){
        return 1;
    }else{
        return 0;
    }
}
int get(Lista *l, int index){
    return l->vet[index];
}
void remover(Lista *l, int index) {
    for(int i = l->quant -1; i >= 0; i--){
        if(l->vet[index] == l->vet[i]){
            for(int j = i; j>= 0; j--){
                l->vet[i] = l->vet[i+1];
            }
        }
    }
    l->quant--;
}
int size(Lista *l){
    return l->quant;
}

void print(Lista *l){
    for(int i = 0; i < l->quant; i++){
        printf("%d ", l->vet[i]);
    }
} 
