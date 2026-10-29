class Solution {
public:
    #define maxN 1005
    int longestCommonSubsequence(string text1, string text2) {
        int dp[maxN] = {};
        int prev = 0;
        for(int i = 1; i <= text1.size(); ++i){
            prev = 0;
            for(int j = 1; j <= text2.size(); ++j){
                int temp = dp[j];
                if(text1[i-1] == text2[j-1]) dp[j] = prev + 1;
                else dp[j] = max(dp[j], dp[j-1]);
                prev = temp;
            }
        }
        return dp[text2.size()];
        /*vector<int> prev(text2.size()+1, 0), curr(text2.size()+1, 0); O(2*m) space
        for(int i = 1; i <= text1.size(); ++i){
            for(int j = 1; j <= text2.size(); ++j){
                if(text1[i-1] == text2[j-1]) curr[j] = prev[j-1] + 1;
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return curr[text2.size()];*/
        /*int dp[maxN][maxN] = {}; o(nm) space
        for(int i = 1; i <= text1.size(); ++i){
            for(int j = 1; j <= text2.size(); ++j){
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[text1.size()][text2.size()];*/
    }
};