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
public:
    int count=1;
    unordered_map<int,int> Kth;
    void DFS(TreeNode *root){
        if(!root) return;
        DFS(root->left);
        Kth[count++] = root->val;
        DFS(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        DFS(root);
        return Kth[k];
    }
};