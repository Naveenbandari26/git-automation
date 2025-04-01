# /GitHub-TestCases-Automat.../testcases/pythontest.py
from main.main import Solution  # Absolute import

def run_test_case(arr, expected, passed_count, total):
    total[0] += 1
    solution = Solution()
    actual = solution.longestMountain(arr)

    if actual == expected:
        passed_count[0] += 1
        print(f"\n✅ Test passed {passed_count[0]}")
    else:
        print(f"\n❌ Test failed for input: {arr}")
        print(f"Actual: {actual}, Expected: {expected}")

def main():
    passed_count = [0]
    total = [0]

    # Basic Cases
    run_test_case([2, 1, 4, 7, 3, 2, 5], 5, passed_count, total)
    run_test_case([1, 3, 5, 3, 4, 2, 0, 8, 10, 7, 6, 5, 4, 3, 1], 9, passed_count, total)
    run_test_case([2, 1, 3, 2, 1, 5, 6, 5, 2, 1], 6, passed_count, total)
    run_test_case([2, 2, 2], 0, passed_count, total)

    # Edge Cases
    run_test_case([1], 0, passed_count, total)
    run_test_case([1, 2], 0, passed_count, total)
    run_test_case([1, 2, 3], 0, passed_count, total)

    # Boundary Cases
    run_test_case([0, 1, 0], 3, passed_count, total)
    run_test_case([5, 4, 3, 2, 1], 0, passed_count, total)

    # Various Mountain Patterns
    run_test_case([1, 3, 2, 4, 3, 2, 1], 5, passed_count, total)
    run_test_case([1, 2, 1, 2, 1], 3, passed_count, total)
    run_test_case([2, 1, 2], 0, passed_count, total)

    # Special Cases
    run_test_case([0, 0, 1, 0, 0], 3, passed_count, total)
    run_test_case([1, 2, 3, 2, 1, 2, 3, 2, 1], 5, passed_count, total)

    # Flat Sections (Edge Cases)
    run_test_case([1, 2, 2, 2, 1], 0, passed_count, total)
    run_test_case([1, 2, 3, 3, 2, 1], 0, passed_count, total)
    run_test_case([1, 3, 5, 3, 1, 2, 4, 6, 7], 5, passed_count, total)
    run_test_case([1, 2, 3, 2, 1, 2, 3, 4, 3, 1, 5, 6, 5, 2, 1], 6, passed_count, total)

    # Large Mountain with 10000 Values
    plateau_mountain = [5] * 4999 + [10] + [5] * 5000
    run_test_case(plateau_mountain, 3, passed_count, total)

    # Large Mountain with 999 Values
    large_mountain = list(range(1, 501)) + list(range(499, 0, -1))
    run_test_case(large_mountain, 999, passed_count, total)

    # Summary
    print(f"\nPassed {passed_count[0]} / {total[0]} test cases!")
    if passed_count[0] != total[0]:
        raise AssertionError("Some test cases failed!")

if __name__ == "__main__":
    main()