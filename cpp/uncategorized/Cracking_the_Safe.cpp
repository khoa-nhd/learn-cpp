class Solution {
public:
    unordered_set<string> us;
    string res;

    void dfs(string dinh, int k){
        for(int i = 0; i < k; ++i){
            string canh;
            canh = dinh;
            canh.push_back(i + '0');
            if(us.find(canh) == us.end()){
                us.insert(canh);
                dfs(canh.substr(1), k);
                res.push_back(i + '0');
            }
        }
    }

    string crackSafe(int n, int k) {
        string dinh(n-1, '0');
        dfs(dinh, k);
        res += dinh;
        return res;
    }
};