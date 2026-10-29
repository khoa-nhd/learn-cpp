class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {};
        for(int i = 0; i < text.size(); ++i){
            cnt[text[i]- 'a'] += 1;
        }
        int res = 2e9;
        for(int i = 0; i < 26; ++i){
            if((i + 'a') == 'b' || (i + 'a') == 'a' || (i + 'a') == 'n'){
                res = min(res, cnt[i]);
            } else if((i + 'a') == 'o' || (i + 'a') == 'l'){
                res = min(res, cnt[i]/2);
            }
        }
        return res;
    }
};