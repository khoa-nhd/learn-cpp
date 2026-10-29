class Solution {
public:
    bool palind[2005][2005];
    int minCut(string s){
        int dp[2005] = {};
        int n = s.size();
        for(int len = 1; len <= n; ++len){
            for(int i = 0; i+len-1 < n; ++i){
                int j = i + len - 1;
                if(i == j) palind[i][j] = true;
                else if(j - i == 1) palind[i][j] = (s[i] == s[j]);
                else palind[i][j] = (s[i] == s[j]) && palind[i+1][j-1];
            }
        }
        for(int i = 0; i < n; ++i){
            dp[i] = i;
            for(int j = 0; j <= i; ++j){
                if(palind[j][i]){
                    if(j == 0) dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        return dp[n-1];
    }
};