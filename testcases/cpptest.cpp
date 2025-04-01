#include <bits/stdc++.h>

#include "../main/main.cpp"

using namespace std;

void runTestCase(int arr[], int n, int expected, int *passedCount, int *total)
{
    (*total)++;
    Solution solution;
    int actual = solution.longestMountain(arr, n);

    if (actual == expected)
    {
        (*passedCount)++;
        cout << "\n✅ " << *(passedCount);
    }
    else
    {
        cout << "\n ❌ Test failed for input: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    if (actual != expected)
    {
        cout << "\nActual: " << actual << ", Expected: " << expected << endl;
    }
}

// ✅ Main function to run all test cases
int main()
{
    int passedCount = 0;
    int total = 0;

    // ✅ Basic Cases
    int arr1111[] = {2, 1, 4, 7, 3, 2, 5};
    runTestCase(arr1111, 7, 5, &passedCount, &total);

    int arr20[] = {1, 3, 5, 3, 4, 2, 0, 8, 10, 7, 6, 5, 4, 3, 1};
    runTestCase(arr20, 15, 9, &passedCount, &total);

    int arr1[] = {2, 1, 3, 2, 1, 5, 6, 5, 2, 1};
    runTestCase(arr1, 10, 6, &passedCount, &total);

    int arr2[] = {2, 2, 2};
    runTestCase(arr2, 3, 0, &passedCount, &total);

    // ✅ Edge Cases
    int arr3[] = {1};
    runTestCase(arr3, 1, 0, &passedCount, &total);

    int arr4[] = {1, 2};
    runTestCase(arr4, 2, 0, &passedCount, &total);

    int arr5[] = {1, 2, 3};
    runTestCase(arr5, 3, 0, &passedCount, &total);

    // ✅ Boundary Cases
    int arr6[] = {0, 1, 0};
    runTestCase(arr6, 3, 3, &passedCount, &total);

    int arr7[] = {5, 4, 3, 2, 1};
    runTestCase(arr7, 5, 0, &passedCount, &total);

    // ✅ Various Mountain Patterns
    int arr8[] = {1, 3, 2, 4, 3, 2, 1};
    runTestCase(arr8, 7, 5, &passedCount, &total);

    int arr9[] = {1, 2, 1, 2, 1};
    runTestCase(arr9, 5, 3, &passedCount, &total);

    int arr10[] = {2, 1, 2};
    runTestCase(arr10, 3, 0, &passedCount, &total);

    // ✅ Special Cases
    int arr11[] = {0, 0, 1, 0, 0};
    runTestCase(arr11, 5, 3, &passedCount, &total);

    int arr12[] = {1, 2, 3, 2, 1, 2, 3, 2, 1};
    runTestCase(arr12, 9, 5, &passedCount, &total);

    // ✅ Flat Sections (Edge Cases)
    int arr13[] = {1, 2, 2, 2, 1};
    runTestCase(arr13, 5, 0, &passedCount, &total);

    int arr14[] = {1, 2, 3, 3, 2, 1};
    runTestCase(arr14, 6, 0, &passedCount, &total);

    int arr15[] = {1, 3, 5, 3, 1, 2, 4, 6, 7};
    runTestCase(arr15, 9, 5, &passedCount, &total);

    int arr16[] = {1, 2, 3, 2, 1, 2, 3, 4, 3, 1, 5, 6, 5, 2, 1};
    runTestCase(arr16, 15, 6, &passedCount, &total);
    // ✅ Large Mountain with 1000 Values
    int plateauMountain[10000];
    for (int i = 0; i < 4999; i++)
    {
        plateauMountain[i] = 5; // Plateau at 5
    }
    plateauMountain[4999] = 10; // Peak at 10
    plateauMountain[5000] = 5;  // Back down to 5
    for (int i = 5001; i < 10000; i++)
    {
        plateauMountain[i] = 5;
    }
    runTestCase(plateauMountain, 10000, 3, &passedCount, &total);

    int largeMountain[999];
    for (int i = 1; i <= 500; i++)
    {
        largeMountain[i - 1] = i; // Increasing part
    }
    for (int i = 499, j = 500; i >= 1; i--, j++)
    {
        largeMountain[j] = i; // Decreasing part
    }
    runTestCase(largeMountain, 999, 999, &passedCount, &total);

    // ✅ Summary
    cout << "\nPassed " << passedCount << " / " << total << " test cases!" << endl;
    if (passedCount != total)
    {
        assert(false);
    }

    return 0;
}