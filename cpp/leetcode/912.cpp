#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void merge(vector<ll>& left, vector<ll>& right, vector<ll>& res) {
    ll i = 0, j = 0;

    while (i < left.size() || j < right.size()) {
        if (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                res.push_back(left[i]);
                i++;
            } else {
                res.push_back(right[j]);
                j++;
            }
        }
        else if (i < left.size()) {
            res.push_back(left[i]);
            i++;
        }
        else {
            res.push_back(right[j]);
            j++;
        }
    }
}

vector<ll> mergeSort(vector<ll>& a, ll l, ll r) {
    vector<ll> res;

    if (l == r) {
        res.push_back(a[l]);
        return res;
    }

    ll mid = (l + r) / 2;

    vector<ll> left = mergeSort(a, l, mid);
    vector<ll> right = mergeSort(a, mid + 1, r);

    merge(left, right, res);

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<ll> sorted = mergeSort(nums, 0, n - 1);

    for(ll x : sorted) {
        cout << x << " ";
    }

    return 0;
}
