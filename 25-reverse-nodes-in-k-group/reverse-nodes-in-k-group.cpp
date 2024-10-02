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
    // Function to reverse a linked list between two nodes
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;  // new head after reversal
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes to reverse
        ListNode* node = head;
        for (int i = 0; i < k; i++) {
            if (!node) return head;  // Not enough nodes, return head as is
            node = node->next;
        }

        // Step 2: Reverse the first k nodes
        ListNode* newHead = reverse(head, node);  // Reverse from head to node (exclusive)

        // Step 3: Recursively reverse the remaining list and connect
        head->next = reverseKGroup(node, k);

        // Step 4: Return new head of the reversed group
        return newHead;
    }
};
