#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> target;

    unordered_map<int, int> um;

    for (int i = 0; i < nums.size(); i++) {
        if (um.find(target - nums[i]) != um.end()) {
            cout << um[target - nums[i]] << " " << i << endl;
            return 0;
        }
        um[nums[i]] = i;
    }

    return 0;
}
