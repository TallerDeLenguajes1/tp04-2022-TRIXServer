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
    tarea tareaEnNodo; 
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

    nodo * listaDeTareas;
    nodo * listaDeTareasRealizadas;

    listaDeTareas = crearNodo();
    listaDeTareasRealizadas = crearNodo();

    agregarNodos(&listaDeTareas, cantTareas);

    return 0;
}

nodo * crearNodo()
{
    return (NULL);
}

nodo * cargarNodo(int i)
{
    nodo * nuevoNodo = (nodo *) malloc(sizeof(nodo));
    nuevoNodo->next = NULL;

    int duracion;
    char * buff = (char *) malloc(sizeof(char) * MAX);

    nuevoNodo->tareaEnNodo.tareaID = i;

    printf("--\n");
    printf("Cargar Tarea ID %d:\n", i);
    gets(buff);
    fflush(stdin);
    nuevoNodo->tareaEnNodo.pDescripcion = (char *) malloc(sizeof(char) * (strlen(buff) + 1));
    strcpy(nuevoNodo->tareaEnNodo.pDescripcion, buff);
    
    printf("--\n");
    printf("Cargar duracion de la tarea:\n");
    scanf("%d", &duracion);
    fflush(stdin);
    nuevoNodo->tareaEnNodo.duracion = duracion;

    return (nuevoNodo);
}

void agregarNodos(nodo ** pplistaDeTareas, int cantTareas)
{
    for (int i = 0; i < cantTareas; i++)
    {
        nodo * nuevoNodo;
        nuevoNodo = cargarNodo(i);
        nuevoNodo->next = * pplistaDeTareas;
        * pplistaDeTareas = nuevoNodo;

    }
}

void insertarNodo(nodo ** inicioLista, int ID, char * descripcion, int duracion)
{
    nodo * nuevoNodo = crearEsteNodo(ID, descripcion, duracion);
    nuevoNodo->next = * inicioLista;
    * inicioLista = nuevoNodo;
}

nodo * crearEsteNodo(int ID, char descripcion, int duracion)
{
    nodo * tarea = (nodo *) malloc(sizeof(nodo));

    tarea->tareaEnNodo.tareaID = ID;
    tarea->tareaEnNodo.pDescripcion = (char *) malloc((strlen(descripcion) + 1) * sizeof(char));
    strcpy(tarea->tareaEnNodo.pDescripcion, descripcion);
    tarea->tareaEnNodo.duracion = duracion;

    tarea->next = NULL;

    return (tarea);

}

void controlarTareas(nodo ** pplistaDeTareas, nodo ** pplistaDeTareasRealizadas, int cantTareas)
{
    nodo * nAux = crearNodo();
    int flag;

    flag = 0;

    for (int i = 0; i < cantTareas; i++)
    {
        mostrarTarea(* pplistaDeTareas, i);

        printf("--\n");
        printf("La tarea ID %d fue realizada 0: NO - 1: SI : ", i);
        scanf("%d", &flag);
        fflush(stdin);

        if (flag == 1)
        {
            insertarNodo(pplistaDeTareasRealizadas, (* pplistaDeTareas)->tareaEnNodo.tareaID, (* pplistaDeTareas)->tareaEnNodo.pDescripcion, (* pplistaDeTareas)->tareaEnNodo.duracion);
            
        }
        else
        {
            insertarNodo(nAux, (* pplistaDeTareas)->tareaEnNodo.tareaID, (* pplistaDeTareas)->tareaEnNodo.pDescripcion, (* pplistaDeTareas)->tareaEnNodo.duracion);

        }

    }

}

void mostrarTarea(nodo * pLista, int ID)
{
    nodo * tarea = pLista;

    while (tarea != NULL)
    {
        if (tarea->tareaEnNodo.tareaID == ID)
        {
            printf("Tarea ID \t%d\n", ID);
            printf("Descripcion de la tarea:\n");
            puts(pLista->tareaEnNodo.pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", pLista->tareaEnNodo.duracion);
            printf("--\n");
        }
        tarea = tarea->next;
    }
}

/*
void mostrarlistaDeTareasRealizadas(tarea ** , int );
void mostrarTareasPendientes(tarea ** , int );
void buscarTareaPorID(tarea **, int);
void buscarTareaPorPalabra(tarea **, int);
*/

/*
void mostrarlistaDeTareasRealizadas(tarea ** pplistaDeTareasRealizadas, int cantTareas)
{
    printf("--\n");
    printf("Tareas Realizadas\n");
    printf("--\n");

    for (int i = 0; i < cantTareas; i++)
    {
        if (pplistaDeTareasRealizadas[i] != NULL)
        {
            printf("Tarea ID \t%d\n", pplistaDeTareasRealizadas[i]->tareaID);
            printf("Descripcion de la tarea:\n");
            puts(pplistaDeTareasRealizadas[i]->pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", pplistaDeTareasRealizadas[i]->duracion);
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