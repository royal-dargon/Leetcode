/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i;
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        int count = 0;
        while(slow != NULL) {
            count ++;
            slow = slow->next;
        }
        if(count == 1) {
            return NULL;
        }
        int temp = count - n;
        for(count = 1; count < temp; count ++) {
            fast = fast -> next;
        }
        if(temp == 0) {
            return fast->next;
        }
        ListNode *tmp = fast->next;
        fast->next = tmp->next;
        return head;
    }
};
*/