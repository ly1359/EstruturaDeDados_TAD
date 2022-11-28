#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

struct  contaBancaria{
    int numConta;
    float saldo;
};
Conta* criarConta(int numConta, float saldo){
    Conta *cb = (Conta*) malloc(sizeof(Conta));
    if(cb == NULL){
        printf("Memoria Insuficiente\n");
		exit(1);
    }
    cb->numConta = numConta;
    cb->saldo = 0.0;
    return cb;
}

void deposito(Conta *cb, float valor){
    if(valor > 0){
        cb->saldo = cb->saldo + valor; 
        printf("Deposito realizada!\n");
    }else{
        printf("Nao foi possivel realizar a operacao.\n");
    }
}

void sacar(Conta *cb, float valor){
    if(valor > 0 && cb->saldo >= valor){
        cb->saldo = cb->saldo - valor;
        printf("Operacao realizada com sucesso\n");
    }else{
        printf("Nao foi possivel realizar a operacao\n");
    }
}

void saldo(Conta *cb, int numConta){
    if(cb->numConta == numConta){
        printf("O seu saldo e: %.2f \n", cb->saldo);
    }
}
