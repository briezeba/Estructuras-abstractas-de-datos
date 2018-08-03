#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *pant, *psig;
} t_nodo;

typedef t_nodo *t_lista;

void Crear_Lista_Doble(t_lista *pl)
{
    *pl=NULL;
}

int Insertar_Al_Final_Lista(t_lista *pl,t_dato *pd)
{
    t_nodo *pact=*pl, *pnue;
    if(pact)
    {
        while(pact->psig)
            pact=pact->psig;
    }
    pnue=(t_nodo *)malloc(sizeof(t_nodo));
    if(pnue==NULL)
    {
        printf("\n\nLista llena.");
        return 0;
    }
    pnue->psig=NULL;
    pnue->dato=*pd;
    pnue->pant=pact;
    if(pact)
        pact->psig=pnue;
    else
        *pl=pnue;
    return 1;
}

void Mostrar_Lista_Doble(const t_lista *pl)
{
    if(*pl==NULL)
        printf("\n\nLa lista esta vacia.\n\n");
    else
    {
        while((*pl)->pant)
            pl=&(*pl)->pant;

        while(*pl)
        {
            printf("\n%d",(*pl)->dato.dato);
            pl=&(*pl)->psig;
        }
    }

}


int Sacar_Ultimo_Lista_Doble(t_lista *pl, t_dato *pd)
{
    t_nodo *pact=*pl;
    if(pact==NULL)
    {
        printf("\n\nLa lista esta vacia.");
        return 0;
    }
    while(pact->psig)
        pact=pact->psig;
    *pd=pact->dato;
    if(pact->pant)
    {
        pact->pant->psig=NULL;
    }
    else
        *pl=NULL;
    free(pact);
    return 1;


}

int main()
{
    t_lista lista;
    t_dato d;
    printf("\nCrearemos la lista.");
    Crear_Lista_Doble(&lista);
    printf("\n\nCargaremos la lista.\nLa condicion de fin de carga es '0'.");
    printf("\n\nIngrese un numero a colocar en la lista: ");
    scanf("%d",&d.dato);
    while(d.dato!=0)
    {
        Insertar_Al_Final_Lista(&lista,&d);
        printf("\n\nIngrese un numero a colocar en la lista: ");
        scanf("%d",&d.dato);
    }
    printf("\n\nTerminamos de cargar la lista.");
    printf("\n\nMostraremos la lista inicial: ");
    Mostrar_Lista_Doble(&lista);
    printf("\n\nAhora sacaremos el ultimo dato de la lista.");
    Sacar_Ultimo_Lista_Doble(&lista,&d);
    printf("\n\nEl dato que se encontraba al final de la lista es: %d.", d.dato);
    printf("\n\nMostraremos la lista final: ");
    Mostrar_Lista_Doble(&lista);

    return 0;
}
