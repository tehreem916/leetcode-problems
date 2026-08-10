class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;                    // stores indices of unmatched '('
        unordered_set<int> toRemove;      // indices to remove

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);               // store index
            }
            else if (s[i] == ')') {
                if (!st.empty())
                    st.pop();             // matched — remove from stack
                else
                    toRemove.insert(i);   // unmatched ')' — mark for removal
            }
        }

        // remaining in stack = unmatched '('
        while (!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }

        // build result skipping removed indices
        string result = "";
        for (int i = 0; i < (int)s.size(); i++) {
            if (!toRemove.count(i))
                result += s[i];
        }

        return result;
    }
};