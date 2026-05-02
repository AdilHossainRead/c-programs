/*Given two arrays start[] and finish[], representing the start and finish times of activities. A person can perform only one activity at a time, and an activity can be performed only if its start time is greater than the finish time of the last chosen activity.
Find the maximum number of activities that can be performed without overlapping.

Examples:

Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: A person can perform at most four activities. The maximum set of activities that can be performed is {0, 1, 3, 4} (these are the indexes in the start[] and finish[] arrays).

Input: start[] = [10, 12, 20], finish[] = [20, 25, 30]
Output: 1
Explanation: A person can perform at most one activity.*/
#include <stdio.h>

void selectActivities(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {

                int tempF = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = tempF;


                int tempS = start[j];
                start[j] = start[j + 1];
                start[j + 1] = tempS;
            }
        }
    }

    printf("Selected activities (start, finish):\n");

    int count = 1;
    int lastFinishTime = finish[0];
    printf("(%d, %d) ", start[0], finish[0]);

    for (int i = 1; i < n; i++) {
        if (start[i] > lastFinishTime) {
            printf("(%d, %d) ", start[i], finish[i]);
            lastFinishTime = finish[i];
            count++;
        }
    }

    printf("\nMaximum number of activities: %d\n", count);
}

int main() {
    int start1[] = {1, 3, 0, 5, 8, 5};
    int finish1[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start1) / sizeof(start1[0]);
    selectActivities(start1, finish1, n1);

    printf("\n");


    int start2[] = {10, 12, 20};
    int finish2[] = {20, 25, 30};
    int n2 = sizeof(start2) / sizeof(start2[0]);
    selectActivities(start2, finish2, n2);

    return 0;
}
