class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int n = cost.size();
        int sum = 0;
        for(int i = 0; i < n; i += 3){
            sum += cost[i];
            if(i + 1 < n) sum += cost[i+1];
        }
        return sum;
    }
};