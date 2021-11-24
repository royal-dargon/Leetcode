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
//     void MidOrder(TreeNode* root,vector<int> &res) {
//         if(root == nullptr) {
//             return;
//         }
//         if(root->left != nullptr) {
//             MidOrder(root->left,res);
//         }
//         res.push_back(root->val);
//         if(root->right != nullptr) {
//             MidOrder(root->right,res);
//         }
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         MidOrder(root,res);
//         return res;
//     }
// };