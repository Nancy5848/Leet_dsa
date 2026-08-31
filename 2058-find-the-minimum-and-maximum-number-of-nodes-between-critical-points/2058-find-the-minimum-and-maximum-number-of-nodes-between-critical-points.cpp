class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans = {-1, -1};

        // Need at least 3 nodes for a critical point
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int position = 1;

        // First critical point position
        int firstCritical = -1;

        // Previous critical point position
        int prevCritical = -1;

        int minDistance = INT_MAX;

        while (curr->next != nullptr) {

            int prevVal = prev->val;
            int currVal = curr->val;
            int nextVal = curr->next->val;

            // Check local maximum or local minimum
            bool isCritical =
                (currVal > prevVal && currVal > nextVal) ||
                (currVal < prevVal && currVal < nextVal);

            if (isCritical) {

                // First critical point
                if (firstCritical == -1) {
                    firstCritical = position;
                }
                else {
                    // Distance from previous critical point
                    minDistance = min(minDistance,
                                      position - prevCritical);
                }

                prevCritical = position;
            }

            prev = curr;
            curr = curr->next;
            position++;
        }

        // Fewer than two critical points
        if (firstCritical == -1 || firstCritical == prevCritical)
            return ans;

        // Maximum distance = last - first critical point
        int maxDistance = prevCritical - firstCritical;

        ans[0] = minDistance;
        ans[1] = maxDistance;

        return ans;
    }
};