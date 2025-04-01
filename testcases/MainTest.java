package testcases;
import java.util.Arrays;

import main.Main; // Adjust the import statement based on your project structure

public class MainTest {
    public static void runTestCase(int[] arr, int expected, int[] passedCount, int[] total) {
        total[0]++;
        int actual = Main.longestMountain(arr);

        System.out.print("\nTest Case " + total[0] + ": ");
        
        if (actual == expected) {
            passedCount[0]++;
            System.out.println("\n✅ Test Passed!");
        } else {
            for (int num : arr) {
                System.out.print(num + " ");
            }
            System.out.println("\n❌ Test Failed");
        
        System.out.println("   Expected: " + expected);
        
        System.out.println("   Actual  : " + actual);
        }
    }

    public static void main(String[] args) {
        int[] passedCount = new int[1];
        int[] total = new int[1];

        runTestCase(new int[]{2, 1, 4, 7, 3, 2, 5}, 5, passedCount, total);
        runTestCase(new int[]{1, 3, 5, 3, 4, 2, 0, 8, 10, 7, 6, 5, 4, 3, 1}, 9, passedCount, total);
        runTestCase(new int[]{2, 1, 3, 2, 1, 5, 6, 5, 2, 1}, 6, passedCount, total);
        runTestCase(new int[]{2, 2, 2}, 0, passedCount, total);
        runTestCase(new int[]{1}, 0, passedCount, total);
        runTestCase(new int[]{1, 2}, 0, passedCount, total);
        runTestCase(new int[]{1, 2, 3}, 0, passedCount, total);
        runTestCase(new int[]{0, 1, 0}, 3, passedCount, total);
        runTestCase(new int[]{5, 4, 3, 2, 1}, 0, passedCount, total);
        runTestCase(new int[]{1, 3, 2, 4, 3, 2, 1}, 5, passedCount, total);
        runTestCase(new int[]{1, 2, 1, 2, 1}, 3, passedCount, total);
        runTestCase(new int[]{2, 1, 2}, 0, passedCount, total);
        runTestCase(new int[]{0, 0, 1, 0, 0}, 3, passedCount, total);
        runTestCase(new int[]{1, 2, 3, 2, 1, 2, 3, 2, 1}, 5, passedCount, total);
        runTestCase(new int[]{1, 2, 2, 2, 1}, 0, passedCount, total);
        runTestCase(new int[]{1, 2, 3, 3, 2, 1}, 0, passedCount, total);
        runTestCase(new int[]{1, 3, 5, 3, 1, 2, 4, 6, 7}, 5, passedCount, total);
        runTestCase(new int[]{1, 2, 3, 2, 1, 2, 3, 4, 3, 1, 5, 6, 5, 2, 1}, 6, passedCount, total);

        // Test Case 19 (Plateau Mountain)
        int[] plateauMountain = new int[10000];
        Arrays.fill(plateauMountain, 0, 4999, 5);
        plateauMountain[4999] = 10;
        plateauMountain[5000] = 5;
        Arrays.fill(plateauMountain, 5001, 10000, 5);
        runTestCase(plateauMountain, 3, passedCount, total);

        // Test Case 20 (Large Mountain)
        int[] largeMountain = new int[999];
        for (int i = 1; i <= 500; i++) {
            largeMountain[i - 1] = i;
        }
        for (int i = 499, j = 500; i >= 1; i--, j++) {
            largeMountain[j] = i;
        }
        runTestCase(largeMountain, 999, passedCount, total);

        System.out.printf("\n\n✅ Passed %d / %d test cases!\n", passedCount[0], total[0]);
        if (passedCount[0] != total[0]) {
            throw new AssertionError("Some test cases failed.");
        }
    }
}
