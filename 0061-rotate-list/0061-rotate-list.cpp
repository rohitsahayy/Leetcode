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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==nullptr || head->next== nullptr) return head;
        int n = getLength(head);
        k = k%n;
        if(k==0) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<k;i++){
            if(fast==nullptr){
                return nullptr;
            }
            else{
                fast=fast->next;
            }
        }
        while(fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newHead;
    }
};