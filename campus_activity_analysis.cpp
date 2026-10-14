/*
 * Course: COEN 2220 - Programming 2
 * Name: [Julian A. Pagan Hernandez]
 * Lab: Lab 8 - Big-O / Time Complexity
 * Description: Resolved code for time-complexity a`nalysis
 * Due date: [10/12/2026]
 */

#include <iostream>
using namespace std;

/* Returns the ID stored at a valid position already known by the caller. */
int getActivityIdAt(const int activityIds[], int activityIndex)
{
    return activityIds[activityIndex]; // Read one known array position.
}

/* Returns how many activities have an active status. */
int countActiveActivities(const bool isActive[], int activityCount)
{
    int activeCount = 0;

    for (int index = 0; index < activityCount; index++)
    {
        if (isActive[index])
        {
            activeCount++;
        }
    }

    return activeCount;
}

/*
 * Returns how many middle IDs binary search compares before finding targetId.
 * Precondition: activityIds is sorted in ascending order and contains targetId.
 */
int countBinaryComparisons(const int activityIds[], int activityCount, int targetId)
{
    int first = 0;
    int last = activityCount - 1;
    int comparisons = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        comparisons++;

        if (activityIds[middle] == targetId)
        {
            break;
        }
        else if (activityIds[middle] < targetId)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return comparisons;
}

/* Returns how many times a positive count can be reduced by half before reaching 1. */
int countHalvingSteps(int itemCount)
{
    int steps = 0;

    while (itemCount > 1)
    {
        itemCount = itemCount / 2; // Remove approximately half of the remaining items.
        steps++;
    }

    return steps;
}

/* Returns the number of distinct activity pairs visited by two nested loops. */
int countPossiblePairs(int activityCount)
{
    int pairCount = 0;

    for (int first = 0; first < activityCount; first++)
    {
        for (int second = first + 1; second < activityCount; second++)
        {
            pairCount++; // One distinct pair would be compared here.
        }
    }

    return pairCount;
}

int main()
{
    // These activity IDs are sorted so binary search is valid.
    int activityIds[] = {101, 104, 108, 115, 130, 136, 140, 155};
    bool isActive[] = {true, false, true, true, false, false, true, false};
    int activityCount = 8;

    cout << "Activity at index 2: "
         << getActivityIdAt(activityIds, 2) << endl;
    cout << "Active activities: "
         << countActiveActivities(isActive, activityCount) << endl;
    cout << "Binary comparisons for 140: "
         << countBinaryComparisons(activityIds, activityCount, 140) << endl;
    cout << "Halving steps for 8: " << countHalvingSteps(8) << endl;
    cout << "Halving steps for 16: " << countHalvingSteps(16) << endl;
    cout << "Halving steps for 32: " << countHalvingSteps(32) << endl;
    cout << "Possible pairs for 4 activities: " << countPossiblePairs(4) << endl;
    cout << "Possible pairs for 8 activities: " << countPossiblePairs(8) << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * C1 — Direct access
 * Answer: O(1)
 *
 * C2 — Count active activities
 * Answer: O(n)
 *
 * C3 — Binary search
 * Answer: O(log n)
 *
 * C4 — Halving steps
 * Answer: O(log n)
 *
 * C5 — Distinct pairs
 * Answer: O(n^2)
 *
 * C6 — Compare the observed patterns
 * Answer: ¿Qué evidencia del código y del output apoya cada comportamiento?
 * The direct access (getActivityIDAt) is 0(1): only does one riding (returns 108) without giving importance of the array. The count active is 0(n): the cicle goes thru the 8 positions one time each time. The reduction of the middle is 0(log n): 8, 16, 32 elements giving 3,4, and 5 steps. The pairs are 0(n^2): 4 activities gives 6 pairs and 8 pairs gives 28, because the total is n(n-1)/2 for the two cicles. 
 * The order of growth is: 0(1) < 0(log n) < 0(n) < 0(n^2)
 * 
 *   
 *
 * C7 — Sorting decision
 * Answer: If the IDs are not sorted, it will use the linear search without organazation when less searchs happen(or just one). When 'n' is tiny, or when the data change frequently, because linear search cost 0(n) per search and sort the first only will costs more than savings. 
 * The sorting efficient only costs 0(n log n), but after each search with binary search will cost 0(log n). With 'k' searches the linear search costs k*0(n) and sort + binary search costs 0(n log n) + k*0(log n), therefore sorting aproximantely when k is greater than log n. 
 * In addition, binary search requires that que array is sorted for it can be correct.
 */