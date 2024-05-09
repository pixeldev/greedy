//
// Created by Angel Miranda on 08/05/24.
//

#include "valued_activities.h"

int compareByValue(const void *a, const void *b) {
    return ((ValuedActivity *) b)->value - ((ValuedActivity *) a)->value;
}

SelectedValuedActivities *selectValuedActivities(ValuedActivity arr[], int n) {
    // Ordenar las actividades por valor en orden descendente
    qsort(arr, n, sizeof(ValuedActivity), compareByValue);

    SelectedValuedActivities *selected = malloc(sizeof(SelectedValuedActivities));
    selected->activities = malloc(n * sizeof(ValuedActivity));
    selected->size = 0;

    // Seleccionar la actividad con el mayor valor
    selected->activities[selected->size++] = arr[0];

    int i = 0;

    // Para cada actividad restante, si no se superpone con la última actividad seleccionada, seleccionarla
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= selected->activities[i].finish) {
            selected->activities[selected->size++] = arr[j];
            i = j;
        }
    }

    return selected;
}

void freeSelectedValuedActivities(SelectedValuedActivities *selectedActivities) {
    free(selectedActivities->activities);
    free(selectedActivities);
}

void printSelectedValuedActivities(SelectedValuedActivities *selectedActivities) {
    printf("Número de actividades seleccionadas: %d\n", selectedActivities->size);
    printf("Actividades seleccionadas:\n");
    for (int i = 0; i < selectedActivities->size; i++) {
        printf("(%d %d)\n", selectedActivities->activities[i].start, selectedActivities->activities[i].finish);
    }
}