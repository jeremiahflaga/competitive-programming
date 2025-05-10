using Shouldly;

namespace LeetCode
{
    // 167. Two Sum II - Input Array Is Sorted
    // https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
    public class TwoSumIIInputArrayIsSortedTests
    {
        [SetUp]
        public void Setup()
        {
        }

        [TestCase(new int[] { 0, 1 }, 1, new int[] { 1, 2 })]
        [TestCase(new int[] { 1, 2 }, 3, new int[] { 1, 2 })]
        [TestCase(new int[] { 1, 2, 3 }, 3, new int[] { 1, 2 })]
        [TestCase(new int[] { 1, 2, 3 }, 4, new int[] { 1, 3 })]
        [TestCase(new int[] { 1, 2, 3 }, 5, new int[] { 2, 3 })]
        [TestCase(new int[] { 1, 3, 7, 9 }, 10, new int[] { 1, 4 })]
        [TestCase(new int[] { 1, 3, 7, 9 }, 8, new int[] { 1, 3 })]
        // Test Cases from problem description
        [TestCase(new int[] { 2, 7, 11, 15 }, 9, new int[] { 1, 2 })]
        [TestCase(new int[] { 2, 3, 4 }, 6, new int[] { 1, 3 })]
        [TestCase(new int[] { -1, 0 }, -1, new int[] { 1, 2 })]
        public void Test(int[] numbers, int target, int[] expectedOutput)
        {
            var soln = new Solution();

            soln.TwoSum(numbers, target).ShouldBe(expectedOutput);
        }

        // The problem description says "The tests are generated such that there is exactly one solution."
        // These are test cases for which there is no solution.
        [TestCase(new int[] { }, 0, new int[] { })] // expected empty array
        [TestCase(new int[] { 0, 1 }, 0, new int[] { })] // expected empty array
        [TestCase(new int[] { 0, 0 }, 1, new int[] { })] // expected empty array
        [TestCase(new int[] { 1, 2 }, 4, new int[] { })] // expected empty array
        public void TestInvalidCases(int[] numbers, int target, int[] expectedOutput)
        {
            var soln = new Solution();

            soln.TwoSum(numbers, target).ShouldBe(expectedOutput);
        }
    }
}

public class Solution
{
    public int[] TwoSum(int[] numbers, int target)
    {
        int leftPointer = 0;
        int rightPointer = numbers.Length - 1;

        while (leftPointer < rightPointer)
        {
            var sum = numbers[leftPointer] + numbers[rightPointer];
            if (sum == target)
                return new int[] { leftPointer + 1, rightPointer + 1 };
            else if (sum < target)
                leftPointer++;
            else if (sum > target)
                rightPointer--;
        }

        return [];
    }
}