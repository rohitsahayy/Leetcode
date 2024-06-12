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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /* Brute force : 
        ListNode* dummy = new ListNode;
        ListNode* head = dummy;
        while(list1!=nullptr && list2!= nullptr){
            if(list1->val <= list2->val){
                ListNode* newNode = new ListNode(list1->val);
                dummy->next = newNode;
                dummy = newNode;
                list1 = list1->next;
            }
            else{
                ListNode* newNode = new ListNode(list2->val);
                dummy->next = newNode;
                dummy = newNode;
                list2 = list2->next;
            }
        }
        if(list1!=nullptr) dummy->next = list1;
        else dummy->next = list2;

        return head->next;
        */
        if(list1 == nullptr) return list2;
        if(list2==nullptr) return list1;
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};