/*Given a 2D array intervals[][], where intervals[i] = [starti, endi]. Find the minimum number of intervals need to be removed to make the rest of the intervals non-overlapping.

Note: Two intervals are considered non-overlapping if the end time of one interval is less than or equal to the start time of the next interval.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: Removal of [1, 3] makes the ranges non-overlapping.

Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
Output: 2
Explanation: Removal of two occurrences of [1, 3] makes the remaining ranges non-overlapping.

Input: intervals[][]  = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
Explanation: All ranges are already non-overlapping
*/

#include <stdio.h>

int eraseOverlapIntervals(int intervals[][2], int n) {
    if (n == 0) return 0;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (intervals[j][1] > intervals[j + 1][1]) {
                // Swap End Time
                int tempEnd = intervals[j][1];
                intervals[j][1] = intervals[j + 1][1];
                intervals[j + 1][1] = tempEnd;

                // Swap Start Time
                int tempStart = intervals[j][0];
                intervals[j][0] = intervals[j + 1][0];
                intervals[j + 1][0] = tempStart;
            }
        }
    }

    int count = 1;
    int last_end = intervals[0][1];


    for (int i = 1; i < n; i++) {

        if (intervals[i][0] >= last_end) {
            count++;
            last_end = intervals[i][1];
        }
    }

    return n - count;
}

int main() {

    int intervals1[][2] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int n1 = 4;
    printf("Output 1: %d\n", eraseOverlapIntervals(intervals1, n1));


    int intervals2[][2] = {{1, 3}, {1, 3}, {1, 3}};
    int n2 = 3;
    printf("Output 2: %d\n", eraseOverlapIntervals(intervals2, n2));


    int intervals3[][2] = {{1, 2}, {5, 10}, {18, 35}, {40, 45}};
    int n3 = 4;
    printf("Output 3: %d\n", eraseOverlapIntervals(intervals3, n3));

    return 0;
}
