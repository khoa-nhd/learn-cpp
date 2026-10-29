class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = k+1;
        for(int i = 0; i <= k; ++i){
            tickets[i] -= 1;
        }
        for(int i = 0; i < tickets.size(); ++i){
            res += min(tickets[k], tickets[i]);
        }
        return res;
    }
};