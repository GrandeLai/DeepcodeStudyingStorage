class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (const char a : s) {
            switch (a) {
            case ')': {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
                break;
            }
            case ']': {
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
                break;
            }
            case '}': {
                if (st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
                break;
            }
            default: {
                st.push(a);
                break;
            }
            }
        }
        return st.empty();
    }
};