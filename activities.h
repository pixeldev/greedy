//
// Created by Angel Miranda on 08/05/24.
//

#ifndef GREEDY_ACTIVITIES_H
#define GREEDY_ACTIVITIES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, finish;
} Activity;

typedef struct {
    Activity *activities;
    int size;
} SelectedActivities;

int compareByFinish(const void* a, const void* b);

SelectedActivities *selectActivities(Activity arr[], int n);

void freeSelectedActivities(SelectedActivities *selectedActivities);

void printSelectedActivities(SelectedActivities *selectedActivities);

#endif //GREEDY_ACTIVITIES_H
