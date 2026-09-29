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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0); // Dummy node serving as the head of the sorted list
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            
            // Find the insertion location in the sorted list starting from dummy
            ListNode* prev = &dummy;
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            // Move to the next node in the original list
            curr = nextNode;
        }

        return dummy.next;
    }
};