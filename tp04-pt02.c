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
    ppTareasRealizadas = (tarea **) malloc(sizeof(tarea) * cantTareas);

    controlarTareas(ppTareas, ppTareasRealizadas, cantTareas);

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
        scanf("%d", ppTareas[i]->duracion);
        fflush(stdin);

    }
    free(buff);

}

void controlarTareas(tarea ** ppTareas, tarea ** ppTareasRealizadas, int cantTareas)
{
    int flag;
    for (int i = 0; i < cantTareas; i++)
    {
        ppTareas[i] = (tarea *) malloc(sizeof(tarea));

        printf("--\n");
        printf("La tarea %d fue realizada 0: NO - 1: SI : ", i + 1);
        scanf("%d", &flag);
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

}

void mostrarTareasPendientes(tarea ** ppTareas, int cantTareas)
{

}