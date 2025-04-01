package main;
public class Main {
    public static int longestMountain(int[] arr) {
        if (arr.length < 3) return 0;

        int longest = 0;

        for (int i = 1; i < arr.length - 1; i++) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                while (left > 0 && arr[left - 1] < arr[left]) left--;
                while (right < arr.length - 1 && arr[right] > arr[right + 1]) right++;

                int length = right - left + 1;
                longest = Math.max(longest, length);
            }
        }

        return longest;

        ///ans
    }

    public static void main(String[] args) {
        System.out.println("Main class compiled successfully. Run MainTest.java for tests.");
    }
}
