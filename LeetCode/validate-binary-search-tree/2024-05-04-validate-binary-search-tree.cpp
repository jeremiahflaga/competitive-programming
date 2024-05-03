
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <limits.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;

        // cout << "START: Root=" << root->val << " minVal=" << LLONG_MIN << " maxVal=" << LLONG_MAX << endl;

        if (root->left != nullptr && root->left->val >= root->val)
            return false;
        if (root->right != nullptr && root->right->val <= root->val)
            return false;
 
        
        // special case for inputs involving INT_MIN and INT_MAX, like [-2147483648,null,2147483647] or [-2147483648,null,2147483647,-2147483648]
        // From the Discussion section: Exclusive Tip : Use LLONG_MIN instead of INT_MIN
        bool leftResult = isValidBSTHelper(root->left, LLONG_MIN, root->val);
        bool rightResult = isValidBSTHelper(root->right, root->val, LLONG_MAX);
        
        // cout << "END: leftResult=" << leftResult << " rightResult=" << rightResult << endl;

        return leftResult && rightResult;
    }

    bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {        
        if (root == nullptr)
            return true;

        // cout << "Root=" << root->val << " minVal=" << minVal << " maxVal=" << maxVal << endl;

        if (root->val <= minVal || root->val >= maxVal)
            return false;
        
        if (root->left != nullptr && root->left->val >= root->val)
            return false;
        if (root->right != nullptr && root->right->val <= root->val)
            return false;
 
        // cout <<"Going Left" << endl;
        bool leftResult = isValidBSTHelper(root->left, minVal, root->val);
        // cout <<"Going Right" << endl;
        bool rightResult = isValidBSTHelper(root->right, root->val, maxVal);
        
        // cout << "leftResult=" << leftResult << " rightResult=" << rightResult << endl;
  
        return leftResult && rightResult;    
    }
};

/////////////////////////////////////////////////////////////////////

TEST_CASE("single node: [3]") {
    TreeNode* root = new TreeNode(3);
    Solution sol;
    CHECK(sol.isValidBST(root) == true);
}

TEST_CASE("[3,1]") {
    TreeNode* root = new TreeNode(3,
        new TreeNode(1), nullptr);
    Solution sol;
    CHECK(sol.isValidBST(root) == true);
}

TEST_CASE("[3,4]") {
    TreeNode* root = new TreeNode(3,
        new TreeNode(4), nullptr);
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[3,null,4]") {
    TreeNode* root = new TreeNode(3,
        nullptr, new TreeNode(4));
    Solution sol;
    CHECK(sol.isValidBST(root) == true);
}

TEST_CASE("[3,null,1]") {
    TreeNode* root = new TreeNode(3,
        nullptr, new TreeNode(1));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[2,1,3]") {
    TreeNode* root = new TreeNode(2,
        new TreeNode(1), new TreeNode(3));
    Solution sol;
    CHECK(sol.isValidBST(root) == true);
}

TEST_CASE("[5,1,4,null,null,3,6]") {
    TreeNode* root = new TreeNode(5,
        new TreeNode(1,
            nullptr, nullptr
        ), new TreeNode(4,
            new TreeNode(3), new TreeNode(6)
        ));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[10, 5, 20, null, 11]") {
    TreeNode* root = new TreeNode(10,
        new TreeNode(5,
            nullptr, new TreeNode(11)
        ), new TreeNode(20)
        );
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[10, 5, 20, null, null, 8, 21]") {
    TreeNode* root = new TreeNode(10,
        new TreeNode(5,
            nullptr, nullptr
        ), new TreeNode(20,
            new TreeNode(8), new TreeNode(21)
        ));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[2,2,1]") {
    TreeNode* root = new TreeNode(2,
        new TreeNode(2), new TreeNode(1));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[2,1,2]") {
    TreeNode* root = new TreeNode(2,
        new TreeNode(1), new TreeNode(2));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[1,1]") {
    TreeNode* root = new TreeNode(1,
        new TreeNode(1), nullptr);
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[2,2]") {
    TreeNode* root = new TreeNode(2,
        new TreeNode(2), nullptr);
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[2,2,2]") {
    TreeNode* root = new TreeNode(2,
        new TreeNode(2), new TreeNode(2));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[2,2,3]") {
    TreeNode* root = new TreeNode(2,
        new TreeNode(2), new TreeNode(3));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[3,null,30,10,null,null,15,null,45]") {
    TreeNode* root = new TreeNode(3,
        nullptr, new TreeNode(30,
            new TreeNode(10,
                nullptr, new TreeNode(15,
                    nullptr, new TreeNode(45))
                ), nullptr
            )
        );
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

// [-2147483648,null,2147483647]
TEST_CASE("[INT_MIN,null,INT_MAX]") {
    TreeNode* root = new TreeNode(INT_MIN,
        nullptr, new TreeNode(INT_MAX));
    Solution sol;
    CHECK(sol.isValidBST(root) == true);
}

TEST_CASE("[INT_MAX,INT_MIN,null]") {
    TreeNode* root = new TreeNode(INT_MAX,
        new TreeNode(INT_MIN), nullptr);
    Solution sol;
    CHECK(sol.isValidBST(root) == true);
}

TEST_CASE("[INT_MIN,INT_MAX,null]") {
    TreeNode* root = new TreeNode(INT_MIN,
        new TreeNode(INT_MAX), nullptr);
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[INT_MAX,null,INT_MIN]") {
    TreeNode* root = new TreeNode(INT_MAX,
        nullptr, new TreeNode(INT_MIN));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[INT_MIN,INT_MIN,null]") {
    TreeNode* root = new TreeNode(INT_MIN,
        new TreeNode(INT_MIN), nullptr);
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

TEST_CASE("[INT_MAX,null,INT_MAX]") {
    TreeNode* root = new TreeNode(INT_MAX,
        nullptr, new TreeNode(INT_MAX));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}

// [-2147483648,null,2147483647,-2147483648]
TEST_CASE("[INT_MIN,null,INT_MAX,INT_MIN]") {
    TreeNode* root = new TreeNode(INT_MIN,
        nullptr, new TreeNode(INT_MAX,
            new TreeNode(INT_MIN), nullptr));
    Solution sol;
    CHECK(sol.isValidBST(root) == false);
}
