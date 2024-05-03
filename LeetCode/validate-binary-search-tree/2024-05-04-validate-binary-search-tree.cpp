
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

        // cout << "Root=" << root->val << " minVal=" << INT_MIN << " maxVal=" << INT_MAX << endl;

        bool leftResult = isValidBSTForLeft(root->left, INT_MIN, root->val);
        bool rightResult = isValidBSTForRigth(root->right, root->val, INT_MAX);
        return leftResult && rightResult;
    }
    
    bool isValidBSTForLeft(TreeNode* root, int minVal, int maxVal) {
        if (root == nullptr)
            return true;
        
        // cout << "Root=" << root->val << " minVal=" << minVal << " maxVal=" << maxVal << endl;

        if (root->val > maxVal)
            return false;

        if (root->left != nullptr && root->left->val > root->val)
            return false;
        if (root->right != nullptr && root->right->val < root->val)
            return false;

        bool leftResult = isValidBSTForLeft(root->left, INT_MIN, root->val);
        bool rightResult = isValidBSTForLeft(root->right, root->val, maxVal);

        // cout << "leftResult=" << leftResult << " rightResult=" << rightResult << endl;

        return leftResult && rightResult;
    }
    
    bool isValidBSTForRigth(TreeNode* root, int minVal, int maxVal) {
        if (root == nullptr)
            return true;
        
        // cout << "Root=" << root->val << " minVal=" << minVal << " maxVal=" << maxVal << endl;

        if (root->val <= minVal)
            return false;

        if (root->left != nullptr && root->left->val > root->val)
            return false;
        if (root->right != nullptr && root->right->val < root->val)
            return false;

        bool leftResult = isValidBSTForRigth(root->left, minVal, root->val);
        bool rightResult = isValidBSTForRigth(root->right, root->val, INT_MAX);

        // cout << "leftResult=" << leftResult << " rightResult=" << rightResult << endl;

        return leftResult && rightResult;
    }
};

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
