#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestMountain(int arr[], int n)
    {
        if (n < 3) return 0;

        int longest = 0;

        for (int i = 1; i < n - 1; i++) {
            // Check if arr[i] is a peak
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                // Expand to the left (avoid flat sections)
                while (left > 0 && arr[left - 1] < arr[left]) {
                    left--;
                }

                // Expand to the right (avoid flat sections)
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                // Only count valid mountain if length >= 3
                int length = right - left + 1;
                if (length >= 3) {
                    longest = max(longest, length);
                }
            }
        }

        return longest;

    }
};
