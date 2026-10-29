class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, int> freq;
        for(int j = 0; j < equations.size(); ++j){
            string a = equations[j][0], b = equations[j][1];
            freq[a] += 1;
            freq[b] += 1;
        }
        for(int i = 0; i < queries.size(); ++i){
            string sobichia = queries[i][0];
            string sochia = queries[i][1];
            if(sobichia == sochia){
                if(freq[sobichia] && freq[sochia]){
                    res.push_back(1);
                } else res.push_back(-1);
                continue;
            }
            int moi = 1;
            unordered_map<string, double> um;
            um[sochia] = 1;
            while(moi){
                moi = 0;
                for(int j = 0; j < equations.size(); ++j){
                    string a = equations[j][0], b = equations[j][1];
                    double v = values[j];
                    if(um[a] != 0 && um[b] == 0){
                        um[b] = um[a] / v;
                        moi += 1;
                    }
                    if(um[a] == 0 && um[b] != 0){
                        um[a] = um[b] * v;
                        moi += 1;
                    }
                }
            }
            double temp;
            if(um[sobichia] == 0) temp = -1;
            else temp = um[sobichia];
            res.push_back(temp);
        }
        return res;
    }
};