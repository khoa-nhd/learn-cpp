class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        n = target.size();
        for(int i = 0; i < target[0]-1; ++i){
            res.push_back("Push");
            res.push_back("Pop");
        }
        res.push_back("Push");
        for(int i = 0; i < n-1; ++i){
            for(int j = 0; j < target[i+1] - target[i] - 1; ++j){
                res.push_back("Push");
                res.push_back("Pop");
            }
            res.push_back("Push");
        }
        return res;
    }
};