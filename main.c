#include <stdio.h>
#include "activities.h"
#include "valued_activities.h"
#include "flip_coins.h"

int main(void) {
    puts("Bienvenido al programa de ejercicios de divide y vencerás.");
    puts("Escoge una opción:");
    puts("1. Programación de Actividades");
    puts("2. Programación de Actividades con valor");
    puts("3. Voltear monedas");
    printf(">> ");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 1: {
            printf("Introduce el número de actividades:\n>> ");
            int n;
            scanf("%d", &n);
            Activity activities[n];
            printf("Introduce las actividades:\n");
            for (int i = 0; i < n; i++) {
                printf("(inicio-fin) >> ");
                scanf("%d-%d", &activities[i].start, &activities[i].finish);
                if (activities[i].start >= activities[i].finish || activities[i].start < 0 || activities[i].finish < 0) {
                    puts("La actividad no es válida.");
                    i--;
                }
            }
            SelectedActivities *selectedActivities = selectActivities(activities, n);
            printSelectedActivities(selectedActivities);
            freeSelectedActivities(selectedActivities);
            break;
        }
        case 2: {
            printf("Introduce el número de actividades:\n>> ");
            int n;
            scanf("%d", &n);
            ValuedActivity activities[n];
            printf("Introduce las actividades:\n");
            for (int i = 0; i < n; i++) {
                printf("(inicio-fin-valor) >> ");
                scanf("%d-%d-%d", &activities[i].start, &activities[i].finish, &activities[i].value);
                if (activities[i].start >= activities[i].finish || activities[i].start < 0 || activities[i].finish < 0 || activities[i].value < 0) {
                    puts("La actividad no es válida.");
                    i--;
                }
            }
            SelectedValuedActivities *selectedActivities = selectValuedActivities(activities, n);
            printSelectedValuedActivities(selectedActivities);
            freeSelectedValuedActivities(selectedActivities);
            break;
        }
        case 3: {
            printf("Introduce el número de monedas:\n>> ");
            int n;
            scanf("%d", &n);
            int coins[n];
            printf("Introduce las monedas:\n");
            for (int i = 0; i < n; i++) {
                printf(">> ");
                scanf("%d", &coins[i]);
            }
            printf("Introduce el tamaño del grupo:\n>> ");
            int groupSize;
            scanf("%d", &groupSize);
            int result = flipCoins(coins, n, groupSize);
            if (result == -1) {
                puts("No se puede voltear el grupo de monedas.");
            } else {
                printf("La menor cantidad de veces que necesitas realizar la operación es: %d.\n", result);
            }
            break;
        }
        default:
            puts("Opción no válida.");
            break;
    }
    return 0;
}
