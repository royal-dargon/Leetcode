/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return root;
        }
        queue<Node*> myList;
        int depth = 0;
        int temp = 1;
        myList.push(root);
        while(!myList.empty()) {
            if(temp == 0) {
                temp = pow(2,depth);
            }
            Node *now = myList.front();
            if(now->left) {
                myList.push(now->left);
            }
            if(now->right) {
                myList.push(now->right);
            }
            myList.pop();
            if(temp == 1) {
                now->next = NULL;
                temp --;
                depth ++;
            } else {
                now->next = myList.front();
                temp --;
            }
        }
        return root;
    }
};