#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int, int> map1;
        for (auto i : nums) {
            map1[i] = 1;
        }

        ListNode* temp = head;
        int ans = 0;
        while (temp) {
            if (map1[temp->val] != 0) {
                while (temp->next && map1[temp->next->val] != 0) {
                    temp = temp->next;
                }
                ans++;
            }
            temp = temp->next;
        }
        return ans;
    }
};

int main() {
    // Create a sample linked list: 0 -> 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, nullptr)))));

    // Values to look for in the linked list
    vector<int> nums = {1, 3};

    // Create a Solution object
    Solution solution;

    // Call the numComponents function and print the result
    int result = solution.numComponents(head, nums);
    cout << "Number of connected components: " << result << endl;

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

