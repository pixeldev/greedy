//
// Created by Angel Miranda on 08/05/24.
//

#include "activities.h"

int compareByFinish(const void *a, const void *b) {
    return ((Activity *) a)->finish - ((Activity *) b)->finish;
}

SelectedActivities *selectActivities(Activity arr[], int n) {
    qsort(arr, n, sizeof(Activity), compareByFinish);

    SelectedActivities *selected = malloc(sizeof(SelectedActivities));
    selected->activities = malloc(n * sizeof(Activity));
    selected->size = 1;
    selected->activities[0] = arr[0];

    int i = 0;

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            selected->activities[selected->size++] = arr[j];
            i = j;
        }
    }

    return selected;
}

void freeSelectedActivities(SelectedActivities *selectedActivities) {
    free(selectedActivities->activities);
    free(selectedActivities);
}

void printSelectedActivities(SelectedActivities *selectedActivities) {
    printf("Número de actividades seleccionadas: %d\n", selectedActivities->size);
    printf("Actividades seleccionadas:\n");
    for (int i = 0; i < selectedActivities->size; i++) {
        printf("(%d %d)\n", selectedActivities->activities[i].start, selectedActivities->activities[i].finish);
    }
}