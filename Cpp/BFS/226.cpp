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
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root == nullptr) {
//             return root;
//         }
//         TreeNode *Left = invertTree(root->left);
//         TreeNode *Right = invertTree(root->right);
//         root->left = Right;
//         root->right = Left;
//         return root;
//     }
// };