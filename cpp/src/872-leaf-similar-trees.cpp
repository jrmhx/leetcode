/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }

    void dfs(TreeNode *node, vector<int> &leaves){
        if (node == nullptr) return;
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        if (left == nullptr && right == nullptr) leaves.push_back(node->val);
        
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};
// @lc code=end
