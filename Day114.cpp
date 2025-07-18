
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }

        int m = t.size(), c = 0, r = 0;
        vector<int> p(m, 0);
        int maxLen = 0, center = 0;

        for (int i = 0; i < m; i++) {
            int mirror = 2 * c - i;
            if (i < r) p[i] = min(r - i, p[mirror]);

            while (i + p[i] + 1 < m && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }

            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }

            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }

        int start = (center - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};


