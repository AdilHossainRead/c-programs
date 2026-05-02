/*Given two arrays gas[] and cost[], each gas station i provides gas[i] fuel, and it takes cost[i] fuel to travel to the next station. Starting with an empty tank, find the index of the gas station from which you can complete a full circular tour. If it’s not possible, return -1.

Note: If a solution exists, it is guaranteed to be unique.

Examples:

Input: gas[] = [4, 5, 7, 4], cost[] = [6, 6, 3, 5]
Output: 2
Explanation: Start at gas station at index 2 and fill up with 7 units of gas. Your tank = 0 + 7 = 7
Travel to station 3. Available gas = (7 - 3 + 4) = 8.
Travel to station 0. Available gas = (8 - 5 + 4) = 7.
Travel to station 1. Available gas = (7 - 6 + 5) = 6.
Return to station 2. Available gas = (6 - 6) = 0.
Therefore, 2 is the starting index.

Input: gas[] = [3, 9], cost[] = [7, 6]
Output: -1
Explanation: There is no gas station to start with such that you can complete the tour.
*/
#include <stdio.h>

int canCompleteCircuit(int gas[], int cost[], int n) {
    int total_gas = 0;
    int total_cost = 0;

    for (int i = 0; i < n; i++) {
        total_gas += gas[i];
        total_cost += cost[i];
    }

    if (total_gas < total_cost) {
        return -1;
    }

    int start_index = 0;
    int current_tank = 0;

    for (int i = 0; i < n; i++) {
        current_tank += (gas[i] - cost[i]);

        if (current_tank < 0) {
            start_index = i + 1;
            current_tank = 0;
        }
    }

    return start_index;
}

int main() {

    int gas1[] = {4, 5, 7, 4};
    int cost1[] = {6, 6, 3, 5};
    int n1 = sizeof(gas1) / sizeof(gas1[0]);
    printf("Starting Index (Example 1): %d\n", canCompleteCircuit(gas1, cost1, n1));


    int gas2[] = {3, 9};
    int cost2[] = {7, 6};
    int n2 = sizeof(gas2) / sizeof(gas2[0]);
    printf("Starting Index (Example 2): %d\n", canCompleteCircuit(gas2, cost2, n2));

    return 0;
}
