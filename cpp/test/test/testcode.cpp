#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double findn(vector<int>& nums1, vector<int>& nums2, int x){
    int d = 0, c = nums1.size()-1;
    int res = 10000000;
    while(d <= c){
        int half = (d + c) / 2;
        int v = half;
        v += upper_bound(nums2.begin(), nums2.end(), nums1[half]) - nums2.begin();
        if(v >= x){
            c = half - 1;
            res = nums1[half];
        } else{
            d = half + 1;
        }
    }
    return res;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int x = nums1.size() + nums2.size();
    double res = 0;
    if(x % 2 == 1){
        res = min(findn(nums1, nums2, x / 2), findn(nums2, nums1, x / 2));
    } else{
        res = min(findn(nums1, nums2, x / 2 - 1), findn(nums2, nums1, x / 2 - 1));
        double res2;
        res2 = min(findn(nums1, nums2, x / 2), findn(nums2, nums1, x / 2));
        res += res2;
        res /= 2;
    }
    return res;
}
int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double res;
    res = findMedianSortedArrays(nums1, nums2);
    cout << res;
    return 0;
}
