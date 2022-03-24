class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q != nullptr) {
            return false;
        }
        if(p != nullptr && q == nullptr) {
            return false;
        }
        if(p == nullptr && q == nullptr) {
            return true;
        }
        queue<TreeNode*> listp;
        queue<TreeNode*> listq;
        listp.push(p);
        listq.push(q);
        bool falg = true;
        while(!listq.empty() && !listp.empty()) {
            TreeNode *tempP = listp.front();
            TreeNode *tempQ = listq.front();
            if((tempP->left == nullptr && tempQ->left != nullptr) || (tempP->left != nullptr && tempQ->left == nullptr)) {
                falg = false;
                return falg;
            }
            if(tempP->left != nullptr && tempQ->left != nullptr) {
                listp.push(tempP->left);
                listq.push(tempQ->left);
            }
            if((tempP->right == nullptr && tempQ->right != nullptr) || (tempP->right != nullptr && tempQ->right == nullptr)) {
                falg = false;
                return false;
            }
            if(tempP->right != nullptr && tempQ->right != nullptr) {
                listp.push(tempP->right);
                listq.push(tempQ->right);
            }
            if(tempP->val != tempQ->val) {
                return false;
            }
            listq.pop();
            listp.pop();
        }
        return falg;
    }
};