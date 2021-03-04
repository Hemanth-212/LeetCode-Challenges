/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *c1=headA,*c2=headB;
        int n=0,m=0;
        
        /* To find the length of first linkedList */
        while(c1)
        {
            ++n;
            c1=c1->next;
        }
        
        /* To find the length of second Linked List */
        while(c2)
        {
            ++m;
            c2=c2->next;
        }
        
        c1=headA;
        c2=headB;
        
        /* If the first linked list length is larger then
            traverse until the no of remaining nodes are m .
        */
        if(n>m)
        {
            while(n>m)
            {
                c1=c1->next;
                --n;
            }
        }
        
        /* If second LinkedlIts length is larger then 
           traverse until the no of remaining nodes are n.
           */
        else
        {
            while(n<m)
            {
                c2=c2->next;
                --m;
            }
        }
        
        /* At this point the no of nodes in both are equal,
          Now traverse parallely two linkedlist until first 
          common listnode is encountered .
          */
        while(c1 && c2)
        {
            if(c1==c2)
            {
                return c1;
            }
            c1=c1->next;
            c2=c2->next;
        }
        return NULL;
    }
};