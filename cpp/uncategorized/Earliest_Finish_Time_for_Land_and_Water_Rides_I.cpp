class Solution {
public:
    bool lap = true;
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int t = 1e9;
        int tt = 1e9;
        for(int i = 0; i < landStartTime.size(); ++i){
            t = min(t, landStartTime[i] + landDuration[i]);
        }
        for(int i = 0; i < waterStartTime.size(); ++i){
            tt = min(tt, max(t, waterStartTime[i]) + waterDuration[i]);
        }
        if(lap){
            lap = false;
            return min(tt, earliestFinishTime(waterStartTime, waterDuration, landStartTime, landDuration));
        }
        return tt;
    }
};