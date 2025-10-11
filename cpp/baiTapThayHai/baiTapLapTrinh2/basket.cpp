#include <iostream>
#include <cstdio>
using namespace std;

void basket(int n){
    int teamScore[n+1] = {}, timeScore[n+1] = {};
    int minute, second;
    int firstTime = 0, secondTime = 0;
    int firstScore = 0, secondScore = 0;
    char colon;
    for(int i = 0; i<n; ++i){
        cin >> teamScore[i] >> minute >> colon >> second;
        timeScore[i] = minute*60 + second;
    }
    timeScore[n] = 48*60;
    teamScore[n] = 0;
    for(int i = 0; i<=n; ++i){
        if(firstScore>secondScore){
            firstTime = firstTime + timeScore[i] - timeScore[i-1];
        } else if(secondScore>firstScore){
            secondTime = secondTime + timeScore[i] - timeScore[i-1];
        }
        if(teamScore[i] == 1){
            firstScore += 1;
        } else if(teamScore[i] == 2){
            secondScore += 1;
        }
    }
    cout << (firstTime / 60 < 10 ? "0" : "") << firstTime / 60
     << ":"
     << (firstTime % 60 < 10 ? "0" : "") << firstTime % 60
     << "\n";

    cout << (secondTime / 60 < 10 ? "0" : "") << secondTime / 60
     << ":"
     << (secondTime % 60 < 10 ? "0" : "") << secondTime % 60
     << "\n";

}

int main(){
    freopen("BASKET.INP", "r", stdin);
    freopen("BASKET.OUT", "w", stdout);
    int n;
    cin >> n;
    basket(n);
    return 0;
}
