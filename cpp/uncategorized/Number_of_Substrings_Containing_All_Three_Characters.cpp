class Solution {
public:
    int numberOfSubstrings(string s) {
        int r = 0;
        int cnt[3] = {};
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            while(r < n && (!cnt[0] || !cnt[1] || !cnt[2])){
                cnt[s[r] - 'a'] += 1;
                r += 1;
            }
            if((!cnt[0] || !cnt[1] || !cnt[2])) break;
            res += n - r + 1;
            cnt[s[i] - 'a'] -= 1;
        }
        return res;
    }
};