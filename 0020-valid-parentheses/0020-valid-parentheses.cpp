class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char ch : s) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            // Check closing brackets
            else {
                if (st.empty()) return false;
                
                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        // Valid only if all opened brackets have been matched and popped
        return st.empty();
    }
};