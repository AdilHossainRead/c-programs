
#include <stdio.h>

float fractionalKnapsack(int value[], int weight[], int capacity, int n) {
    float profit = 0;
    float currentCapacity = capacity;

    float items[n][2];
    for (int i = 0; i < n; i++) {
        items[i][0] = (float)value[i];
        items[i][1] = (float)weight[i];
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float r1 = items[j][0] / items[j][1];
            float r2 = items[j + 1][0] / items[j + 1][1];

            if (r1 < r2) {
                // Swap Value
                float t0 = items[j][0];
                items[j][0] = items[j + 1][0];
                items[j + 1][0] = t0;

                // Swap Weight
                float t1 = items[j][1];
                items[j][1] = items[j + 1][1];
                items[j + 1][1] = t1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (items[i][1] <= currentCapacity) {
            profit += items[i][0];
            currentCapacity -= items[i][1];
        } else {
            profit += (items[i][0] / items[i][1]) * currentCapacity;
            break;
        }
    }
    return profit;
}

int main() {
    int capacity = 50;
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int n = sizeof(value) / sizeof(value[0]);

    printf("Max Profit : %.2f\n", fractionalKnapsack(value, weight, capacity, n));
    return 0;
}
