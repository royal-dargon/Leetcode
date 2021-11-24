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
//     bool isSymmetric(TreeNode* root) {
//         queue<TreeNode*> listLeft;
//         queue<TreeNode*> stackRight;
//         if(root == nullptr) {
//             return true;
//         }
//         if((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr)) {
//             return false;
//         }
//         if(root->left != nullptr && root->right != nullptr) {
//             listLeft.push(root->left);
//             stackRight.push(root->right);
//         } else {
//             return true;
//         }
//         while(!listLeft.empty() && !stackRight.empty()) {
//             //cout << "1 ";
//             TreeNode *tempRight = stackRight.front();
//             TreeNode *tempLeft = listLeft.front();
//             if(tempLeft->val != tempRight->val) {
//                 //cout << "1";
//                 return false;
//             }
//             if((tempLeft->left != nullptr && tempRight->right == nullptr) || (tempLeft->left == nullptr && tempRight->right != nullptr)) {
//                 //cout << "1";
//                 return false;
//             }
//             if((tempLeft->right != nullptr && tempRight->left == nullptr) || (tempLeft->right == nullptr && tempRight->left != nullptr)) {
//                 return false;
//             }
//             if(tempLeft->left != nullptr) {
//                 listLeft.push(tempLeft->left);
//                 //listLeft.push(tempRight->left);
//                 stackRight.push(tempRight->right);
//             }
//             if(tempLeft->right != nullptr) {
//                 stackRight.push(tempLeft->right);
//                 listLeft.push(tempRight->left);
//             }
//             // if(tempRight->right != nullptr) {
//             //     stackRight.push(tempRight->right);
//             // }
//             listLeft.pop();
//             stackRight.pop();
//         }
//         return true;
//     }
// };