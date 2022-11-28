#include "operacoes.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Conta *cb;
    int opc;
    int num = rand() % 100;
    cb = criarConta(num, 0.0f);
    printf("Sua Conta foi Inicializada!\n");
    printf("Numero da conta: %d\n", cb->numConta);
    printf("Seu saldo incial: %.2f\n", cb->saldo);

    while(opc != 4){
        printf("----Menu Pricipal---\n");
        printf("1- Deposito \n");
        printf("2- Sacar   \n");
        printf("3- Saldo\n");
        printf("4- Sair\n");
        printf("Selecione uma Opcao:\n");
        scanf("%d", &opc);
        if(opc == 1){
            float valor;
            printf("Digite o valor:\n");
            scanf("%f", &valor);
            deposito(cb, valor);
        }else if(opc == 2){
            float valor;
            printf("Digite o valor:\n");
            scanf("%f", &valor);
            sacar(cb, valor);
        }else if(opc == 3){
            printf("Saldo da conta:\n");
            saldo(cb, num);
        }else{
            break;
        }
    }
    return 0;
}
