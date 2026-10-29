class Solution {
public:
    int passwordStrength(string password) {
        char c[] = {'!', '@', '#', '$'};
        bool freqc[100] = {};
        bool freqt[100] = {};
        bool freqh[100] = {};
        bool freqs[100] = {};
        for(int i = 0; i < password.size(); ++i){
            for(int j = 0; j < 4; ++j){
                if(password[i] == c[j]) freqc[j] = true;
            }
            if(password[i] <= 'z' && password[i] >= 'a') freqt[password[i] - 'a'] = true;
            else if(password[i] >= 'A' && password[i] <= 'Z') freqh[password[i] - 'A'] = true;
            else if(password[i] >= '0' && password[i] <= '9') freqs[password[i] - '0'] = true;
        }
        int res = 0;
        for(int i = 0; i < 4; ++i) res += freqc[i] * 5;
        for(int i = 0; i < 100; ++i){
            res += freqt[i];
            res += freqh[i] * 2;
            res += freqs[i] * 3;
        }
        return res;
    }
}