class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }

            // Closing brackets
            else {

                // No opening bracket to match
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                if (c == ')' && top != '(') {
                    return false;
                }

                if (c == ']' && top != '[') {
                    return false;
                }

                if (c == '}' && top != '{') {
                    return false;
                }
            }
        }

        // If something is still open, it's invalid
        return st.empty();
    }
};