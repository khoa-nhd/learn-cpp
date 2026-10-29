class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int timefree = 0;
        double res = 0;
        int n = customers.size();
        for(int i = 0; i < n; ++i){
            if(customers[i][0] > timefree) timefree = customers[i][0] + customers[i][1];
            else{
                res += timefree - customers[i][0];
                timefree += customers[i][1];
            }
            res += customers[i][1];
        }
        res /= n;
        return res;
    }
};