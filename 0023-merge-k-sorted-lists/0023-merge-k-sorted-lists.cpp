class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Add the first node of every list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        // Dummy node
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            // Get smallest node
            ListNode* current = pq.top();
            pq.pop();

            // Add it to result
            tail->next = current;
            tail = current;

            // Add next node from the same list
            if (current->next != nullptr) {
                pq.push(current->next);
            }
        }

        return dummy.next;
    }
};