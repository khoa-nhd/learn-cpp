class Solution {
  public:
    #define maxN 10005
    bool isSubsetSum(vector<int>& arr, int sum) {
        bool dp[maxN] = {};
        dp[0] = true;
        int n = arr.size();
        for(int i = 0; i < n; ++i){
            for(int j = sum; j > 0; --j){
                if(j >= arr[i]) dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
        return dp[sum];
    }
};