/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>temp;
        ListNode *c=head;
        while(c)
        {
            temp.push_back(c->val);
            c=c->next;
        }
        int n=temp.size(),i=0;
        swap(temp[k-1],temp[n-k]);
        c=head;
        while(c)
        {
            c->val=temp[i++];
            c=c->next;
        }
        return head;
    }
};
/* Time complexity : O(n)
   Space complexity: O(n)
  */