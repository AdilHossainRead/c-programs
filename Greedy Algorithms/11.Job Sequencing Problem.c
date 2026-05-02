/*Given two arrays, deadline[] and profit[], where deadline[i] is the last time unit by which the i-th job must be completed, and profit[i] is the profit earned from completing it.
Each job takes 1 unit time, and only one job can be scheduled at a time. A job earns profit only if finished within its deadline. Find the number of jobs completed and maximum profit.

Examples:

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job 1 (profit 20, deadline 4) can be scheduled. Among the three jobs with deadline 1, only one fits, so we pick the highest profit (40). Hence, 2 jobs with total profit = 60.

Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Picking the job with profit 100 (deadline 2) and the job with profit 27 (deadline 2); they can occupy the two available slots before deadline 2. Thus 2 jobs are scheduled for a maximum total profit of 127.
*/

#include <stdio.h>

void solveJobSequencing(int deadline[], int profit[], int n) {
    // ধাপ ১: প্রফিট অনুযায়ী বড় থেকে ছোট সাজানো (Bubble Sort)
    // এখানে profit এবং deadline উভয়কেই একসাথে সোয়াপ করতে হবে
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap Profit
                int tempP = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempP;

                // Swap Deadline
                int tempD = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempD;
            }
        }
    }

    // সর্বোচ্চ ডেডলাইন খুঁজে বের করা (স্লট সংখ্যা নির্ধারণের জন্য)
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadline[i] > maxDeadline) {
            maxDeadline = deadline[i];
        }
    }

    // টাইম স্লট তৈরি করা (সব স্লট শুরুতে খালি/০)
    int slots[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) {
        slots[i] = 0;
    }

    int countJobs = 0;
    int maxProfit = 0;

    // ধাপ ২ ও ৩: প্রতিটি কাজ চেক করা এবং স্লটে বসানো
    for (int i = 0; i < n; i++) {
        // কাজের ডেডলাইন থেকে শুরু করে পিছনের দিকে খালি স্লট খোঁজা
        for (int j = deadline[i]; j > 0; j--) {
            if (slots[j] == 0) { // যদি স্লটটি খালি থাকে
                slots[j] = 1;    // স্লটটি বুক করা হলো
                countJobs++;
                maxProfit += profit[i];
                break;
            }
        }
    }

    printf("Number of jobs: %d, Maximum Profit: %d\n", countJobs, maxProfit);
}

int main() {
    int deadline1[] = {4, 1, 1, 1};
    int profit1[] = {20, 10, 40, 30};
    int n1 = sizeof(deadline1) / sizeof(deadline1[0]);
    solveJobSequencing(deadline1, profit1, n1);

    int deadline2[] = {2, 1, 2, 1, 1};
    int profit2[] = {100, 19, 27, 25, 15};
    int n2 = sizeof(deadline2) / sizeof(deadline2[0]);
    solveJobSequencing(deadline2, profit2, n2);

    return 0;
}
