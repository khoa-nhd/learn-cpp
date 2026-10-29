class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt[5] = {};
        for(int x : students) cnt[x] += 1;
        for(int i = 0; i < sandwiches.size(); ++i){
            cnt[sandwiches[i]] -= 1;
            if(cnt[sandwiches[i]] < 0) return sandwiches.size() - i;
        }
        return 0;
    }
};