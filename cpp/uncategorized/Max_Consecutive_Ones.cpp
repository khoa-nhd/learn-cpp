class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = nums[0];
        int res = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[i] == 0) curr = 0;
            else curr += 1;
            res = max(res, curr);
        }
        return res;
    }
};