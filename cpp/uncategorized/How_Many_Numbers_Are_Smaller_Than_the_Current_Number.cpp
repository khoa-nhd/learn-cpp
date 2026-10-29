class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(105, 0);
        int n = nums.size();
        for(int i = 0; i < n; ++i) freq[nums[i]] += 1;
        for(int i = 1; i < 103; ++i) freq[i] += freq[i-1];
        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0) res.push_back(0);
            else res.push_back(freq[nums[i]-1]);
        }
        return res;
    }
};