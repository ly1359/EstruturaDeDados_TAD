typedef struct lista Lista;

void inserirNoInicio(Lista *l, int num);
void inserirNoFim(Lista *l, int num);
void inserirNoMeio(Lista *l, int num, int ant);
void inserirOrdenado(Lista *l, int num);
Lista* remover(Lista *l, int num);
