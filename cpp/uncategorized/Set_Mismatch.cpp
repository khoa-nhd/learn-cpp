class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> freq(n+1);
        for(int i = 0; i < n; ++i){
            freq[nums[i]] += 1;
        }
        for(int i = 1; i <= n; ++i){
            if(freq[i] == 2) res.push_back(i);
        }
        for(int i = 1; i <= n; ++i){
            if(freq[i] == 0) res.push_back(i);
        }
        return res;
    }
};