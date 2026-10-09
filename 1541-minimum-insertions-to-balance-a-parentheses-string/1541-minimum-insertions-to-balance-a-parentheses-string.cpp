class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int needed_right = 0;

        for (char c : s) {
            if (c == '(') {
                // If needed_right is odd, it means we have a single ')' waiting.
                // We need to add one ')' to complete the pair.
                if (needed_right % 2 != 0) {
                    insertions++;
                    needed_right--;
                }
                needed_right += 2;
            } else { // c == ')'
                needed_right--;
                // Encountered ')' without a matching '('
                if (needed_right < 0) {
                    insertions++; // Insert '('
                    needed_right += 2;
                }
            }
        }

        return insertions + needed_right;
    }
};