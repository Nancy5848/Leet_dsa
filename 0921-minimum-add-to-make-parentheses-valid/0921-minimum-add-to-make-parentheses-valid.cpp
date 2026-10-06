class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;  // Tracks unmatched ')' that need a '(' inserted before them
        int close_needed = 0; // Tracks unmatched '(' that need a ')' inserted after them

        for (char c : s) {
            if (c == '(') {
                close_needed++;
            } else {
                if (close_needed > 0) {
                    close_needed--; // Match with an existing open parenthesis
                } else {
                    open_needed++;  // Unmatched ')', so an '(' must be added
                }
            }
        }

        return open_needed + close_needed;
    }
};