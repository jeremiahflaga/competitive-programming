using Shouldly;

namespace LeetCode.RunningSumOf1DArray
{
    // 1480. Running Sum of 1d Array
    // https://leetcode.com/problems/running-sum-of-1d-array/description/
    
    public class Solution
    {
        public int[] RunningSum(int[] nums)
        {
            var runningSum = new int[nums.Length];
            var currentSum = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                currentSum += nums[i];
                runningSum[i] = currentSum;
            }
            return runningSum;
        }
    }
}