class Solution {
public:
    int numberOfSpecialChars(string word) {
        pair<bool, bool> a[30];
        int n = word.size();
        string s = word;
        bool kodc[30];
        for(int i = 0; i < n; ++i){
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(a[s[i] - 'a'].second) a[s[i] - 'a'].first = false;
                else a[s[i] - 'a'].first = true;
            }
            else if(a[s[i] - 'A'].first) a[s[i] - 'A'].second = true;
            else kodc[s[i] - 'A'] = true;
        }
        int res = 0;
        for(int i = 0; i < 30; ++i){
            if(a[i].first && a[i].second && !kodc[i]) res += 1;
        }
        return res;
    }
};