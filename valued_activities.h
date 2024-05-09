//
// Created by Angel Miranda on 08/05/24.
//

#ifndef GREEDY_VALUED_ACTIVITIES_H
#define GREEDY_VALUED_ACTIVITIES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, finish, value;
} ValuedActivity;

typedef struct {
    ValuedActivity *activities;
    int size;
} SelectedValuedActivities;

int compareByValue(const void* a, const void* b);

SelectedValuedActivities *selectValuedActivities(ValuedActivity arr[], int n);

void freeSelectedValuedActivities(SelectedValuedActivities *selectedActivities);

void printSelectedValuedActivities(SelectedValuedActivities *selectedActivities);

#endif //GREEDY_VALUED_ACTIVITIES_H
