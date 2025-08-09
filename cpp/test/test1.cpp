#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<long long> test_cases;
vector<long long> results;

long long reversee(long long n){
    long long result = 0;
    while(n>0){
        result = result*10+n%10;
        n = n/10;
    }
    return result;
}

void seq2(long long n){
    long long i, result = 1;
    results.push_back(1);
    for(i = 1; i<n; ++i){
        result =  reversee(result)+2;
        results.push_back(result);
    }
}

long long maxx(){
    int length = test_cases.size();
    long long now = 0, maxx = -1;
    for(int i = 0; i<length; ++i){
        now = test_cases[i];
        if(now>maxx){
            maxx = now;
        }
    }
    return maxx;
}

void printResult(long long n){
    cout<<results[n-1]<<"\n";
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    long long n;
    while (cin >> n) {
        test_cases.push_back(n);
    }
    long long maxVal = maxx();
    seq2(maxVal);
    int sizee = test_cases.size();
    for(int i = 0; i<sizee; ++i){
        printResult(test_cases[i]);
    }
    return 0;
}


