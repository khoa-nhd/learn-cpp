class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        int prevTime = 0;
        for(int i = 0; i < logs.size(); ++i){
            int num = 0;
            int idx = 0;
            while(logs[i][idx] != ':'){
                num *= 10;
                num += logs[i][idx] - '0';
                idx += 1;
            }
            idx += 1;
            bool start = false;
            if(logs[i][idx] == 's'){
                start = true;
                idx += 6;
            } else{
                idx += 4;
            }
            int time = 0;
            while(idx < logs[i].size()){
                time *= 10;
                time += logs[i][idx] - '0';
                idx += 1;
            }
            if(st.size() > 0){
                res[st.top().first] += time - prevTime + 1;
                if(start) res[st.top().first] -= 1;
            } 
            prevTime = time;
            if(start){
                st.push({num, time});
            } else{
                st.pop();
                prevTime += 1;
            }
        }
        return res;
    }
};