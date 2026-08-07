class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // push all opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // closing bracket
            else {
                // stack empty , no matching open bracket
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }

        return st.empty();
    }
};