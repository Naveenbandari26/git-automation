#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../main/main.c"

void runTestCase(int* arr, int arrSize, int expected, int* passedCount, int* total) {
    (*total)++;
    int actual = longestMountain(arr, arrSize);

    printf("\nTest Case %d: ", *total);
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }

    if (actual == expected) {
        (*passedCount)++;
        printf("\n✅ Test Passed!\n");
    } else {
        printf("\n❌ Test Failed\n");
    }
    printf("   Expected: %d\n   Actual  : %d\n", expected, actual);
}

int main() {
    int passedCount = 0;
    int total = 0;

    // Test Case 1
    int arr1[] = {2, 1, 4, 7, 3, 2, 5};
    runTestCase(arr1, sizeof(arr1)/sizeof(arr1[0]), 5, &passedCount, &total);

    // Test Case 2
    int arr2[] = {1, 3, 5, 3, 4, 2, 0, 8, 10, 7, 6, 5, 4, 3, 1};
    runTestCase(arr2, sizeof(arr2)/sizeof(arr2[0]), 9, &passedCount, &total);

    // Test Case 3
    int arr3[] = {2, 1, 3, 2, 1, 5, 6, 5, 2, 1};
    runTestCase(arr3, sizeof(arr3)/sizeof(arr3[0]), 6, &passedCount, &total);

    // Test Case 4
    int arr4[] = {2, 2, 2};
    runTestCase(arr4, sizeof(arr4)/sizeof(arr4[0]), 0, &passedCount, &total);

    // Test Case 5
    int arr5[] = {1};
    runTestCase(arr5, sizeof(arr5)/sizeof(arr5[0]), 0, &passedCount, &total);

    // Test Case 6
    int arr6[] = {1, 2};
    runTestCase(arr6, sizeof(arr6)/sizeof(arr6[0]), 0, &passedCount, &total);

    // Test Case 7
    int arr7[] = {1, 2, 3};
    runTestCase(arr7, sizeof(arr7)/sizeof(arr7[0]), 0, &passedCount, &total);

    // Test Case 8
    int arr8[] = {0, 1, 0};
    runTestCase(arr8, sizeof(arr8)/sizeof(arr8[0]), 3, &passedCount, &total);

    // Test Case 9
    int arr9[] = {5, 4, 3, 2, 1};
    runTestCase(arr9, sizeof(arr9)/sizeof(arr9[0]), 0, &passedCount, &total);

    // Test Case 10
    int arr10[] = {1, 3, 2, 4, 3, 2, 1};
    runTestCase(arr10, sizeof(arr10)/sizeof(arr10[0]), 5, &passedCount, &total);

    // Test Case 11
    int arr11[] = {1, 2, 1, 2, 1};
    runTestCase(arr11, sizeof(arr11)/sizeof(arr11[0]), 3, &passedCount, &total);

    // Test Case 12
    int arr12[] = {2, 1, 2};
    runTestCase(arr12, sizeof(arr12)/sizeof(arr12[0]), 0, &passedCount, &total);

    // Test Case 13
    int arr13[] = {0, 0, 1, 0, 0};
    runTestCase(arr13, sizeof(arr13)/sizeof(arr13[0]), 3, &passedCount, &total);

    // Test Case 14
    int arr14[] = {1, 2, 3, 2, 1, 2, 3, 2, 1};
    runTestCase(arr14, sizeof(arr14)/sizeof(arr14[0]), 5, &passedCount, &total);

    // Test Case 15
    int arr15[] = {1, 2, 2, 2, 1};
    runTestCase(arr15, sizeof(arr15)/sizeof(arr15[0]), 0, &passedCount, &total);

    // Test Case 16
    int arr16[] = {1, 2, 3, 3, 2, 1};
    runTestCase(arr16, sizeof(arr16)/sizeof(arr16[0]), 0, &passedCount, &total);

    // Test Case 17
    int arr17[] = {1, 3, 5, 3, 1, 2, 4, 6, 7};
    runTestCase(arr17, sizeof(arr17)/sizeof(arr17[0]), 5, &passedCount, &total);

    // Test Case 18
    int arr18[] = {1, 2, 3, 2, 1, 2, 3, 4, 3, 1, 5, 6, 5, 2, 1};
    runTestCase(arr18, sizeof(arr18)/sizeof(arr18[0]), 6, &passedCount, &total);

    // Test Case 19 (Plateau Mountain)
    int plateauMountain[10000];
    for (int i = 0; i < 4999; ++i) plateauMountain[i] = 5;
    plateauMountain[4999] = 10;
    plateauMountain[5000] = 5;
    for (int i = 5001; i < 10000; ++i) plateauMountain[i] = 5;
    runTestCase(plateauMountain, 10000, 3, &passedCount, &total);

    // Test Case 20 (Large Mountain)
    int largeMountain[999];
    for (int i = 1; i <= 500; ++i) largeMountain[i - 1] = i;
    for (int i = 499, j = 500; i >= 1; --i, ++j) largeMountain[j] = i;
    runTestCase(largeMountain, 999, 999, &passedCount, &total);

    printf("\n\n✅ Passed %d / %d test cases!\n", passedCount, total);
    if (passedCount != total) {
        assert(0);
    }

    return 0;
}