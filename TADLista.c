#define MAX 5

typedef struct lista Lista;

Lista *criar();

void append(Lista *l, int valor);
void insert(Lista *l, int valor);
void insert_sorted(Lista *l, int valor);
void clear(Lista *l);
int get(Lista *l, int index);
int full(Lista *l);
int empty(Lista *l);
void remover(Lista *l, int index);
int size(Lista *l);
void print(Lista *l);
