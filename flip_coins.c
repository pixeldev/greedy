//
// Created by Angel Miranda on 08/05/24.
//

#include "flip_coins.h"

int flipCoins(int *coins, int size, int groupSize) {
    int operations = 0;
    for (int i = 0; i <= size - groupSize; i++) {
        if (coins[i] == 0) {
            operations++;
            for (int j = i; j < i + groupSize; j++) {
                coins[j] = 1 - coins[j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (coins[i] == 0) {
            return -1;
        }
    }

    return operations;
}