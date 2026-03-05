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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        return head;

        int count=0;

        ListNode*cur=head;
        ListNode*pre=NULL;
        ListNode*next=NULL;

        ListNode*temp=head;
        for(int i=0;i<k;i++){
            if(temp==NULL)
            return head;
            temp=temp->next;
        }

        
        while(cur!=NULL &&count<k){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
            count++;
        }
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        return pre;
        

    }
};