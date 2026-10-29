class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid[0].size();
        int m = boxGrid.size();
        vector<vector<char>> ans(n, vector<char>(m));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ans[j][i] = boxGrid[i][j];
            }
        }
        for(int i = 0; i < n; ++i) reverse(ans[i].begin(), ans[i].end());
        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j < m; ++j){
                if(ans[i][j] == '#'){
                    int k = i;
                    while(k < n-1 && ans[k+1][j] == '.'){
                        swap(ans[k][j], ans[k+1][j]);
                        k += 1;
                    }
                }
            }
        }
        return ans;
    }
};