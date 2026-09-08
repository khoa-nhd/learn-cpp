#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int people[1000];

int election(int n){
    int vote,  maxx = -1, winner = 0;
    for(int i = 0; i<n; ++i){
        cin>>vote;
        if(vote>maxx){
            maxx = vote;
            winner = i;
        }
    }
    return winner;
}

int checkWinner(int n){
    int winner, now = 0, maxx = -1;
    for(int i = 0; i<n; ++i){
        now = people[i];
        if(now>maxx){
            maxx = now;
            winner = i+1;
        }
    }
    return winner;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ELECTION.INP", "r", stdin);
    freopen("ELECTION.OUT", "w", stdout);
    int m, n, winnerCity, halfCity, winner = -1;
    cin>>n>>m;
    halfCity = (m + 1)/2;
    for(int i = 0; i<m; ++i){
        winnerCity = election(n);
        people[winnerCity]+= 1;
        if(people[winnerCity]>halfCity){
            winner = winnerCity+1;
            break;
        }
    }
    if(winner == -1){
        winner = checkWinner(n);
    }
    cout<<winner;

    return 0;
}

