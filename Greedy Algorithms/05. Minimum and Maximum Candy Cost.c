
#include <stdio.h>

void solve() {
    int prices[] = {3, 2, 1, 4, 5};
    int k = 4;
    int n = sizeof(prices) / sizeof(prices[0]);


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (prices[j] > prices[j + 1]) {
                int temp = prices[j];
                prices[j] = prices[j + 1];
                prices[j + 1] = temp;
            }
        }
    }


    int min_cost = 0;
    int candies_to_buy = n;
    for (int i = 0; i < candies_to_buy; i++) {
        min_cost += prices[i];

        candies_to_buy = candies_to_buy - k;
    }


    int max_cost = 0;
    int free_candies_count = 0;
    for (int i = n - 1; i >= free_candies_count; i--) {
        max_cost += prices[i];
        free_candies_count = free_candies_count + k;
    }

    printf("Minimum Cost: %d\n", min_cost);
    printf("Maximum Cost: %d\n", max_cost);
}

int main() {
    solve();
    return 0;
}
