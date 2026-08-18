int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    
    // Stack to store indices
    int* stack = (int*)malloc((len + 1) * sizeof(int));
    int top = -1;
    
    // Push -1 as base index
    stack[++top] = -1;
    
    int maxLen = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            // Push index of '('
            stack[++top] = i;
        } else {
            // Pop for ')'
            top--;
            
            if (top == -1) {
                // Stack empty, push current index as new base
                stack[++top] = i;
            } else {
                // Valid substring found
                int currLen = i - stack[top];
                if (currLen > maxLen) {
                    maxLen = currLen;
                }
            }
        }
    }
    
    free(stack);
    return maxLen;
}