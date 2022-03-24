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
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        queue<TreeNode*> myList;
        myList.push(root);
        bool found = false;
        int count = 1;
        int k = 1;
        int b = 0;
        while(!myList.empty() && !found) {
            TreeNode *temp = myList.front();
            k = k - 1;
            if(temp->left == NULL && temp->right == NULL) {
                found = true;
                return count;
            }
            if(temp->left != NULL) {
                myList.push(temp->left);
                b = b + 1;
            }
            if(temp->right != NULL) {
                myList.push(temp->right);
                b = b + 1;
            }
            myList.pop();
            if(k == 0) {
                count ++;
                k = b;
                b = 0;
            }
        }
        return count;
    }
};