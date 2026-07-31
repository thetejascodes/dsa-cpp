class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;
        int n = s.size();
        
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            int len = r - l - 1;
            if (len > maxLen) {
                maxLen = len;
                start = l + 1;
            }
        };
        
        for (int i = 0; i < n; i++) {
            expand(i, i);     
            expand(i, i + 1);
        }
        
        return s.substr(start, maxLen);
    }
};