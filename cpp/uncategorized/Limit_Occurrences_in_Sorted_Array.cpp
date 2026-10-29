class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int curr = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[i-1]) curr = 0;
            if(curr == k){
                while(i < nums.size() && nums[i] == nums[i-1]) nums.erase(nums.begin() + i, nums.begin() + i + 1);
                i -= 1;
            }
            curr += 1;
        }
        return nums;
    }
}