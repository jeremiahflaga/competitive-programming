using Shouldly;

namespace LeetCode.RangeSumQueryImmutable
{
    public class NumArray
    {
        private int[] prefixSum;

        public NumArray(int[] nums)
        {
            prefixSum = new int[nums.Length];
            prefixSum[0] = nums[0];
            for (int i = 1; i < nums.Length; i++)
            {
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            }
        }

        public int SumRange(int left, int right)
        {
            return prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
        }
    }

    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray obj = new NumArray(nums);
     * int param_1 = obj.SumRange(left,right);
     */
}