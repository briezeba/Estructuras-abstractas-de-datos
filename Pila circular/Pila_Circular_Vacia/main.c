#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *psig;
} t_nodo;

typedef t_nodo *t_pila;

void Crear_Pila_Circular(t_pila *pp)
{
    *pp=NULL;
}

int Cola_Pila_Vacia(const t_pila *pp)
{
    return *pp==NULL;
}

int main()
{
    t_pila pila;
    printf("\nCreamos la pila circular.");
    Crear_Pila_Circular(&pila);
    printf("\n\nVerificamos que la pila este vacia.");
    if(Cola_Pila_Vacia(&pila))
        printf("\n\nLa pila circular esta vacia.\n");
    return 0;
}
