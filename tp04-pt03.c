#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct tarea {
    int tareaID;
    char * pDescripcion;
    int duracion;

} typedef tarea;

void cargarTareas(tarea **, int);
void controlarTareas(tarea **, tarea **, int);
void mostrarTareasRealizadas(tarea ** , int );
void mostrarTareasPendientes(tarea ** , int );

void buscarTareaPorID(tarea **, int);
void buscarTareaPorPalabra(tarea **, int);



int main(int argc, char const *argv[])
{
    int cantTareas;
    
    //system("cls || clear");

    printf("--\n");
    printf("Ingrese la cantidad de tareas: ");
    scanf("%d", &cantTareas);
    fflush(stdin);

    tarea ** ppTareas;
    ppTareas = (tarea **) malloc(cantTareas * sizeof(tarea *));

    cargarTareas(ppTareas, cantTareas);

    tarea ** ppTareasRealizadas;
    ppTareasRealizadas = (tarea **) malloc(sizeof(tarea *) * cantTareas);

    controlarTareas(ppTareas, ppTareasRealizadas, cantTareas);

    mostrarTareasRealizadas(ppTareasRealizadas, cantTareas);

    mostrarTareasPendientes(ppTareas, cantTareas);

    buscarTareaPorID(ppTareas, cantTareas);

    buscarTareaPorPalabra(ppTareas, cantTareas);

    return 0;
}

void cargarTareas(tarea ** ppTareas, int cantTareas)
{
    char * buff;
    buff = (char *) malloc(MAX * sizeof(char));

    for (int i = 0; i < cantTareas; i++)
    {
        ppTareas[i] = (tarea *) malloc(sizeof(tarea));
        
        ppTareas[i]->tareaID = i;

        printf("--\n");
        printf("Cargar Tarea %d:\n", i + 1);
        gets(buff);
        fflush(stdin);
        ppTareas[i]->pDescripcion = (char *) malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(ppTareas[i]->pDescripcion, buff);
        
        printf("--\n");
        printf("Cargar duracion de la tarea:\n");
        scanf("%d", &ppTareas[i]->duracion);
        fflush(stdin);

    }
    free(buff);

}

void controlarTareas(tarea ** ppTareas, tarea ** ppTareasRealizadas, int cantTareas)
{
    for (int i = 0; i < cantTareas; i++)
    {
        ppTareasRealizadas[i] = (tarea *) malloc(sizeof(tarea));
        int flag;  

        printf("--\n");
        printf("La tarea ID %d fue realizada 0: NO - 1: SI : ", ppTareas[i]->tareaID);
        scanf("%i", &flag);
        fflush(stdin);

        if (flag == 1)
        {
            ppTareasRealizadas[i]->tareaID = ppTareas[i]->tareaID;
            ppTareasRealizadas[i]->pDescripcion = (char *) malloc(sizeof(char) * (strlen(ppTareas[i]->pDescripcion) + 1));
            strcpy(ppTareasRealizadas[i]->pDescripcion, ppTareas[i]->pDescripcion);
            ppTareasRealizadas[i]->duracion = ppTareas[i]->duracion;
            ppTareas[i] = NULL;

        }
        else
        {
            ppTareasRealizadas[i] = NULL;

        }

    }

}

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
