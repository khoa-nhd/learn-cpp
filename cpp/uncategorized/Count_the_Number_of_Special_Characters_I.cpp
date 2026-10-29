class Solution {
public:
    int numberOfSpecialChars(string word) {
        pair<bool, bool> tt[30];
        int n = word.size();
        for(int i = 0; i < n; ++i){
            if(word[i] >= 'a' && word[i] <= 'z') tt[word[i] - 'a'].first = true;
            else tt[word[i] - 'A'].second = true;
        }
        int res = 0;
        for(int i = 0; i < 30; ++i){
            res += tt[i].first && tt[i].second;
        }
        return res;
    }
};