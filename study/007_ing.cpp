#include <iostream>
#include <vector>
using namespace std;

vector<int> button[10] = {
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

int clocks[16];

bool check(){
    bool isTrue = 1;
    for(int i=0; i<16; i++){
        if(clocks[i]!=12) isTrue = 0;
    }
    return isTrue;
}

int solve(){
    if(check()) return 0;
    
}

int main(){
    for(int i=0; i<16; i++){
        cin >> clocks[i];
    }
    cout << solve();
}
