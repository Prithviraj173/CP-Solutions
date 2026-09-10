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
class Solution {
private:
    pair<int, int> dfs(TreeNode* root, int &ans) {
        if(!root) return {0, 0};
        pair<int, int> v1 = dfs(root -> left, ans);
        pair<int, int> v2 = dfs(root -> right, ans);
        int sum = v1.first + v2.first + root -> val;
        int count = v2.second + v1.second + 1;
        if(sum / count == root -> val) ans++;
        return {sum, count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};