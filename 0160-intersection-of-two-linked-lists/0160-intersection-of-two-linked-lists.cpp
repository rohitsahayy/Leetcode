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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       /* Brute Force
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1!=nullptr){
            while(t2!=nullptr){
                if(t1==t2){
                    return t1;
                }
                else{
                    t2=t2->next;
                }
            }
            t1=t1->next;
            t2 = headB;
        }
        return nullptr;
        */
        int l1 = getLength(headA);
        int l2 = getLength(headB);
        int diff = abs(l1-l2);

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        if(l1>l2){
            for(int i=0;i<diff;i++){
                t1 = t1->next;
            }
        }
        else{
            for(int i=0;i<diff;i++){
                t2 = t2->next;
            }
        }

        while(t1!=nullptr && t2!=nullptr){
            if(t1 == t2){
                return t1;
            }
            else{
                t1=t1->next;
                t2=t2->next;
            }
        }
        return nullptr;
    }
};