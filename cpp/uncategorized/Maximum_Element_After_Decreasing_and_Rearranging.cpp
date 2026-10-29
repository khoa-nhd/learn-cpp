class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int res = n;
        vector<int> cnt(n+1, 0);
        int sum = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] < n) cnt[arr[i]] += 1;
            else sum += 1;
        }
        for(int i = n; i > 0; --i){
            sum += cnt[i];
            if(res - i + 1 > sum) res -= 1;
            if(res - i + 1 > sum) res = i - 1;
        }
        return res;
        /*sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i = 1; i < arr.size(); ++i){
            arr[i] = min(arr[i], arr[i-1] + 1);
        }
        return arr.back();*/
    }
};