using Shouldly;

namespace LeetCode.RootEqualsSumOfChildren
{
    // 2236. Root Equals Sum of Children
    // https://leetcode.com/problems/root-equals-sum-of-children/description/

    /**
     * Definition for a binary tree node.
     */
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public class Solution
    {
        public bool CheckTree(TreeNode root)
        {
            return root?.left?.val + root?.right?.val == root?.val;
        }
    }
}