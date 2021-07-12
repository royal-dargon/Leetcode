/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    typedef struct ListNode Node;
    Node *head,*tail,*pnew;
    int flag = 0;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node *p1,*p2;
    p1 = l1;
    p2 = l2;
    tail = head;
    while(p1 != NULL &&p2 != NULL)
    {
        pnew = (Node*)malloc(sizeof(Node));
        pnew->val = p1->val + p2->val;
        if(flag == 1)
        {
            pnew->val = pnew->val + 1;
            flag = 0;
        }
        if(pnew->val>=10)
        {
            flag = 1;
            pnew->val = pnew->val % 10;
        }
        tail->next = pnew;
        pnew->next = NULL;
        tail = pnew;
        p1 = p1->next;
        p2 = p2->next;
    }
    while(p1 != NULL)
    {
        pnew = (Node*)malloc(sizeof(Node));
        pnew->next = NULL;
        pnew->val = p1->val;
        if(flag == 1)
        {
            pnew->val = pnew->val + 1;
            flag = 0;
        }
        if(pnew->val >= 10)
        {
            flag = 1;
            pnew->val = pnew->val % 10;
        }
        tail->next = pnew;
        tail = pnew;
        p1 = p1->next;
    }
     while(p2 != NULL)
    {
        pnew = (Node*)malloc(sizeof(Node));
        pnew->next = NULL;
        pnew->val = p2->val;
        if(flag == 1)
        {
            pnew->val = pnew->val + 1;
            flag = 0;
        }
        if(pnew->val >= 10)
        {
            flag = 1;
            pnew->val = pnew->val - 10;
        }
        tail->next = pnew;
        tail = pnew;
        p2 = p2->next;
    }
    if(flag == 1)
    {
        pnew = (Node*)malloc(sizeof(Node));
        pnew->next = NULL;
        pnew->val = 1;
        tail->next = pnew;
        tail = pnew; 
    }
    return head->next;
}