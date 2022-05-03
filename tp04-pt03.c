#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct tarea
{
    int tareaID;
    char * pDescripcion;
    int duracion;

} typedef tarea;

struct nodo
{
    tarea nTarea; //nodoTarea
    nodo * next;
} typedef nodo;

nodo * crearNodo();
nodo * cargarNodo(int);
void agregarNodos(nodo **, int);
void controlarTareas(nodo **, nodo **, int);
void mostrarTarea(nodo *, int);
void insertarNodo(nodo **, int, char *, int);
nodo * crearEsteNodo(int, char, int);

int main(int argc, char const *argv[])
{
    int cantTareas;
    
    //system("cls || clear");

    printf("--\n");
    printf("Ingrese la cantidad de tareas: ");
    scanf("%d", &cantTareas);
    fflush(stdin);

    nodo * listaTareas;
    nodo * tareasRealizadas;

    listaTareas = crearNodo();
    tareasRealizadas = crearNodo();

    agregarNodos(&listaTareas, cantTareas);

    return 0;
}

nodo * crearNodo()
{
    return (NULL);
}

nodo * cargarNodo(int i)
{
    nodo * nNodo = (nodo *) malloc(sizeof(nodo)); //nuevo Nodo
    nNodo->next = NULL;

    int duracion;
    char * buff = (char *) malloc(sizeof(char) * MAX);

    nNodo->nTarea.tareaID = i;

    printf("--\n");
    printf("Cargar Tarea ID %d:\n", i);
    gets(buff);
    fflush(stdin);
    nNodo->nTarea.pDescripcion = (char *) malloc(sizeof(char) * (strlen(buff) + 1));
    strcpy(nNodo->nTarea.pDescripcion, buff);
    
    printf("--\n");
    printf("Cargar duracion de la tarea:\n");
    scanf("%d", &duracion);
    fflush(stdin);
    nNodo->nTarea.duracion = duracion;

    return (nNodo);
}

void agregarNodos(nodo ** ppListaTareas, int cantTareas)
{
    for (int i = 0; i < cantTareas; i++)
    {
        nodo * nNodo;
        nNodo = cargarNodo(i);
        nNodo->next = * ppListaTareas;
        * ppListaTareas = nNodo;

    }
}

void insertarNodo(nodo ** startLista, int ID, char * descripcion, int duracion)
{
    nodo * nNodo = crearEsteNodo(ID, descripcion, duracion);
    nNodo->next = * startLista;
    * startLista = nNodo;
}

nodo * crearEsteNodo(int ID, char descripcion, int duracion)
{
    nodo * tarea = (nodo *) malloc(sizeof(nodo));

    tarea->nTarea.tareaID = ID;
    tarea->nTarea.pDescripcion = (char *) malloc((strlen(descripcion) + 1) * sizeof(char));
    strcpy(tarea->nTarea.pDescripcion, descripcion);
    tarea->nTarea.duracion = duracion;

    tarea->next = NULL;

    return (tarea);

}

void controlarTareas(nodo ** ppListaTareas, nodo ** ppTareasRealizadas, int cantTareas)
{
    nodo * nAux = crearNodo();
    int flag;

    flag = 0;

    for (int i = 0; i < cantTareas; i++)
    {
        mostrarTarea(* ppListaTareas, i);

        printf("--\n");
        printf("La tarea ID %d fue realizada 0: NO - 1: SI : ", i);
        scanf("%d", &flag);
        fflush(stdin);

        if (flag == 1)
        {
            insertarNodo(ppTareasRealizadas, (* ppListaTareas)->nTarea.tareaID, (* ppListaTareas)->nTarea.pDescripcion, (* ppListaTareas)->nTarea.duracion);
            
        }
        else
        {
            insertarNodo(nAux, (* ppListaTareas)->nTarea.tareaID, (* ppListaTareas)->nTarea.pDescripcion, (* ppListaTareas)->nTarea.duracion);

        }

    }

}

void mostrarTarea(nodo * pLista, int ID)
{
    nodo * tarea = pLista;

    while (tarea != NULL)
    {
        if (tarea->nTarea.tareaID == ID)
        {
            printf("Tarea ID \t%d\n", ID);
            printf("Descripcion de la tarea:\n");
            puts(pLista->nTarea.pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", pLista->nTarea.duracion);
            printf("--\n");
        }
        tarea = tarea->next;
    }
}

/*
void mostrarTareasRealizadas(tarea ** , int );
void mostrarTareasPendientes(tarea ** , int );
void buscarTareaPorID(tarea **, int);
void buscarTareaPorPalabra(tarea **, int);
*/

/*
void mostrarTareasRealizadas(tarea ** ppTareasRealizadas, int cantTareas)
{
    printf("--\n");
    printf("Tareas Realizadas\n");
    printf("--\n");

    for (int i = 0; i < cantTareas; i++)
    {
        if (ppTareasRealizadas[i] != NULL)
        {
            printf("Tarea ID \t%d\n", ppTareasRealizadas[i]->tareaID);
            printf("Descripcion de la tarea:\n");
            puts(ppTareasRealizadas[i]->pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", ppTareasRealizadas[i]->duracion);
            printf("--\n");

        }
    }
}

void mostrarTareasPendientes(tarea ** ppTareas, int cantTareas)
{
    printf("--\n");
    printf("Tareas Pendientes\n");
    printf("--\n");

    for (int i = 0; i < cantTareas; i++)
    {
        if (ppTareas[i] != NULL)
        {
            printf("Tarea ID \t%d\n", ppTareas[i]->tareaID);
            printf("Descripcion de la tarea:\n");
            puts(ppTareas[i]->pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", ppTareas[i]->duracion);
            printf("--\n");
            
        }
    }
}


void buscarTareaPorID(tarea ** ppTareas, int cantTareas)
{
    int buscar;

    printf("--\n");
    printf("Ingrese el ID a buscar: ");
    scanf("%d", &buscar);
    fflush(stdin);

    for (int i = 0; i < cantTareas; i++)
    {
        if (ppTareas[i]->tareaID == buscar)
        {
            printf("Tarea ID \t%d\n", ppTareas[i]->tareaID);
            printf("Descripcion de la tarea:\n");
            puts(ppTareas[i]->pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", ppTareas[i]->duracion);
            printf("--\n");
        }
    }
}

void buscarTareaPorPalabra(tarea ** ppTareas, int cantTareas)
{
    char buscar[MAX];

    printf("--\n");
    printf("Ingrese la palabra a buscar: ");
    gets(buscar);
    fflush(stdin);

    for (int i = 0; i < cantTareas; i++)
    {
        if (strstr(ppTareas[i]->pDescripcion, buscar))
        {
            printf("Tarea ID \t%d\n", ppTareas[i]->tareaID);
            printf("Descripcion de la tarea:\n");
            puts(ppTareas[i]->pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", ppTareas[i]->duracion);
            printf("--\n");
        }
    }
}



*/