class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); 
        int maxLen = 0;
        int start = 0; 

        for (int end = 0; end < (int)s.size(); end++) {
            char c = s[end];
            if (lastSeen[c] >= start) {
                start = lastSeen[c] + 1;
            }
            lastSeen[c] = end;
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }

};