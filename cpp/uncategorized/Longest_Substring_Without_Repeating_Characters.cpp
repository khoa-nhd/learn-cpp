class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        int m[300] = {};
        for(int r = 0; r < s.size(); ++r){
            m[(int)s[r]] += 1;
            while(m[(int)s[r]] > 1 && l < r){
                m[(int)s[l]] -= 1;
                l += 1;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};