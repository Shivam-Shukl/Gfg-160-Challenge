
class Solution {
public:
    int maxLength(string& s) {
        stack<int> st;
        st.push(-1); // Base case for valid substring calculations
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // Update base index
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }
        return maxLength;
    }
};

