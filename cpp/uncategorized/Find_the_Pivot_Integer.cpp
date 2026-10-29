class Solution {
public:
    int pivotInteger(int n) {
        int res = sqrt((n*n + n)/2);
        if(res * res != (n*n + n)/2) return -1;
        return res;
    }
};