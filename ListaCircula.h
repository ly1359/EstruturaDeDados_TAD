typedef struct listaCircula Lista;
typedef struct no No;

Lista* criarLista(Lista *l);
void inserirNoInicio(Lista *l, int  num);
void inserirNoFim(Lista *l, int num);
void remover(Lista *l, int num);
void imprime(Lista *l);
