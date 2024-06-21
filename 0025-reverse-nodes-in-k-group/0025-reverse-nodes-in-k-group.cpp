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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* forward = nullptr;
        while(curr!=nullptr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* findKnode(ListNode* node,int k){
        ListNode* temp = node;
        for(int i=0;i<k-1;i++){
            if(temp == nullptr) return nullptr;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k==1) return head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* prevEnd = dummy;
        ListNode* temp = head;
        while(temp!=nullptr){
            ListNode* kthNode = findKnode(temp,k);
            if(kthNode==nullptr){
                prevEnd->next = temp;
                break;
            }
            ListNode* nextStart = kthNode->next;
            kthNode->next = nullptr;
            ListNode* reverseHead = reverse(temp);

            prevEnd->next = reverseHead;
            temp->next = nextStart;
            prevEnd = temp;
            temp = nextStart;
        }
        ListNode* newHead = dummy->next;
        // dummy->next = nullptr;
        delete(dummy);
        return newHead;
    }
};