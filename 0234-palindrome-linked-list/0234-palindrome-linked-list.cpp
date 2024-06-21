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
    ListNode* reverseLL(ListNode* head){
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
    ListNode* middleLL(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middle = middleLL(head);
        ListNode* nodeToReverse = middle->next;
        middle->next = nullptr;
        ListNode* reverseHead = reverseLL(nodeToReverse);
        middle->next = reverseHead;
        ListNode* dummy1 = head;
        ListNode* dummy2 = reverseHead;
        bool result = true;
        while(dummy2!=nullptr){
            if(dummy1->val != dummy2->val) {
                result = false;
                break;
                }
            dummy1 = dummy1->next;
            dummy2 = dummy2->next;
        }        
        middle->next = reverseLL(reverseHead);
        return result;
    }
};