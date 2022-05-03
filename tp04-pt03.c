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
nodo * cargarTareaEnNodo(int);
void agregarNodos(nodo **, int);
void controlarTareas(nodo **, nodo **, int);
void mostrarTarea(nodo *, int);
void insertarNodo(nodo **, int, char *, int);
nodo * crearEsteNodo(int, char, int);

int main(int argc, char const *argv[])
{
    int cantNodos;
    
    //system("cls || clear");

    printf("--\n");
    printf("Ingrese la cantidad de tareas: ");
    scanf("%d", &cantNodos);
    fflush(stdin);

    nodo * listaDeTareas;
    nodo * listaDeTareasRealizadas;

    listaDeTareas = crearNodo();
    listaDeTareasRealizadas = crearNodo();

    agregarNodos(&listaDeTareas, cantNodos);

    controlarTareas(&listaDeTareas, &listaDeTareasRealizadas, cantNodos);



    return 0;
}

nodo * crearNodo()
{
    return (NULL);
}

nodo * cargarTareaEnNodo(int i)
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

void agregarNodos(nodo ** listaDeTareas, int cantNodos)
{
    for (int i = 0; i < cantNodos; i++)
    {
        nodo * nuevoNodo;
        nuevoNodo = cargarTareaEnNodo(i);
        nuevoNodo->next = * listaDeTareas;
        * listaDeTareas = nuevoNodo;

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
    nodo * nuevoNodo = (nodo *) malloc(sizeof(nodo));

    nuevoNodo->tareaEnNodo.tareaID = ID;
    nuevoNodo->tareaEnNodo.pDescripcion = (char *) malloc((strlen(descripcion) + 1) * sizeof(char));
    strcpy(nuevoNodo->tareaEnNodo.pDescripcion, descripcion);
    nuevoNodo->tareaEnNodo.duracion = duracion;

    nuevoNodo->next = NULL;

    return (nuevoNodo);

}

void controlarTareas(nodo ** listaDeTareas, nodo ** listaDeTareasRealizadas, int cantNodos)
{
    nodo * nodoAuxiliar = crearNodo();
    int flag;

    flag = 0;

    for (int i = 0; i < cantNodos; i++)
    {
        mostrarTarea(* listaDeTareas, i);

        printf("--\n");
        printf("La tarea ID %d fue realizada 0: NO - 1: SI : ", i);
        scanf("%d", &flag);
        fflush(stdin);

        if (flag == 1)
        {
            insertarNodo(listaDeTareasRealizadas, (* listaDeTareas)->tareaEnNodo.tareaID, (* listaDeTareas)->tareaEnNodo.pDescripcion, (* listaDeTareas)->tareaEnNodo.duracion);
            
        }
        else
        {
            insertarNodo(nodoAuxiliar, (* listaDeTareas)->tareaEnNodo.tareaID, (* listaDeTareas)->tareaEnNodo.pDescripcion, (* listaDeTareas)->tareaEnNodo.duracion);

        }
        * listaDeTareas = (* listaDeTareas)->next;

    }
    * listaDeTareas = nodoAuxiliar;

}

void mostrarTarea(nodo * listaDeTareas, int ID)
{
    nodo * nuevoNodo = listaDeTareas;

    while (nuevoNodo != NULL)
    {
        if (nuevoNodo->tareaEnNodo.tareaID == ID)
        {
            printf("Tarea ID \t%d\n", ID);
            printf("Descripcion de la tarea:\n");
            puts(listaDeTareas->tareaEnNodo.pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", listaDeTareas->tareaEnNodo.duracion);
            printf("--\n");
        }
        nuevoNodo = nuevoNodo->next;
    }
}

/*
void mostrarlistaDeTareasRealizadas(tarea ** , int );
void mostrarTareasPendientes(tarea ** , int );
void buscarTareaPorID(tarea **, int);
void buscarTareaPorPalabra(tarea **, int);
*/

/*
void mostrarlistaDeTareasRealizadas(tarea ** listaDeTareasRealizadas, int cantNodos)
{
    printf("--\n");
    printf("Tareas Realizadas\n");
    printf("--\n");

    for (int i = 0; i < cantNodos; i++)
    {
        if (listaDeTareasRealizadas[i] != NULL)
        {
            printf("Tarea ID \t%d\n", listaDeTareasRealizadas[i]->tareaID);
            printf("Descripcion de la tarea:\n");
            puts(listaDeTareasRealizadas[i]->pDescripcion);
            printf("Duracion de la tarea \t%d minutos\n", listaDeTareasRealizadas[i]->duracion);
            printf("--\n");

        }
    }
}

void mostrarTareasPendientes(tarea ** ppTareas, int cantNodos)
{
    printf("--\n");
    printf("Tareas Pendientes\n");
    printf("--\n");

    for (int i = 0; i < cantNodos; i++)
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


void buscarTareaPorID(tarea ** ppTareas, int cantNodos)
{
    int buscar;

    printf("--\n");
    printf("Ingrese el ID a buscar: ");
    scanf("%d", &buscar);
    fflush(stdin);

    for (int i = 0; i < cantNodos; i++)
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

void buscarTareaPorPalabra(tarea ** ppTareas, int cantNodos)
{
    char buscar[MAX];

    printf("--\n");
    printf("Ingrese la palabra a buscar: ");
    gets(buscar);
    fflush(stdin);

    for (int i = 0; i < cantNodos; i++)
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