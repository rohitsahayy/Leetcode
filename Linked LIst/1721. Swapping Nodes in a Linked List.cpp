#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    int getLength(ListNode* head){
        int count = 0;
        while (head != nullptr){
            head = head->next;
            count++;
        }
        return count;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = getLength(head);
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        for (int i = 1; i < k; i++){
            temp1 = temp1->next;
        }

        for (int i = 1; i < n - k + 1; i++){
            temp2 = temp2->next;
        }

        swap(temp1->val, temp2->val);

        return head;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createLinkedList({1, 2, 3, 4, 5});
    int k = 2;

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    head = solution.swapNodes(head, k);

    cout << "Linked List after Swapping " << k << "-th and " << k << "th from end: ";
    printLinkedList(head);

    return 0;
}
