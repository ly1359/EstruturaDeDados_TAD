typedef struct contaBancaria Conta;

Conta *criarConta(int numConta, float saldo);
void deposito(Conta *cb, float valor);
void sacar(Conta *cb, float valor);
void saldo(Conta *cb, int numConta);
