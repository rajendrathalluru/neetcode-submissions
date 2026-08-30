class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Opening brackets -> push into stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // No opening bracket available
                if (st.empty()) {
                    return false;
                }

                // Check whether current closing bracket
                // matches the most recent opening bracket
                if (c == ')' && st.top() != '(')
                    return false;

                if (c == '}' && st.top() != '{')
                    return false;

                if (c == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
        }

        // If anything is left, some opening bracket
        // was never closed
        return st.empty();
    }
};