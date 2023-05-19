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

bool possible = true;

bool check(int clocks[16]){
    bool isTrue = true;
    for(int i=0; i<16; i++){
        if(clocks[i]!=12) isTrue = false;
    }
    return isTrue;
}

void push(int n, int clocks[16]){
    for(int i=0; i<button[n].size(); i++){
        int c = button[n][i];
        if(clocks[c]!=12) clocks[c] += 3;
        else clocks[c] = 3;
    }
}

void back(int n, int clocks[16]){
    for(int i=0; i<button[n].size(); i++){
        int c = button[n][i];
        if(clocks[c]!=3) clocks[c] -= 3;
        else clocks[c] = 12;
    }
}

int solve(int n_switch, int clocks[16]){
    cout << n_switch;
    if(check(clocks)) return 0;
    if(n_switch==10){ // 불가능 한 경우
        possible = false;
        return 0;
    }
    
    int result = 2e9;
    for(int i=0; i<4; i++){
        push(n_switch, clocks);
        result = min(result, solve(n_switch+1, clocks)+1);
    }
    
    return result;
}

int main(){
    int clocks[16];
    for(int i=0; i<16; i++){
        cin >> clocks[i];
    }
    int result = solve(0, clocks);
    if(possible) cout << result;
    else cout << -1;
}

/*
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
*/
