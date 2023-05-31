#include <iostream>
#include <string>
#define MAX 10002
using namespace std;

string nums;
int dp[MAX];


int point(int a, int b) {
    string part = nums.substr(a, b-a+1);
    
    // case 1
    // bool allSame=true;
    // int temp = part[0];
    // for(int i=0; i<part.size(); i++) {
    //     if(temp!=part[i]){ 
    //         allSame = false;
    //         break;
    //     }
    // }
    // if(allSame) return 1;
    // 위 과정을 쉽게 하는 법 : if(part==string(part.size(), part[0])) return 1;    
    if(part==string(part.size(), part[0])) return 1;
    
    // case 2
    // <원래 나의 답>
    // bool arith=true;
    // bool inc = (part[1] == (part[0]+1));
    // for(int i=2; i<part.size(); i++) {
    //     if( (part[i] == (part[i-1]-1)) != inc ) {
    //         arith = false;
    //         break;
    //     }
    // }
    // if(arith) return 2;
    /*
    위 과정을 쉽게 하는 법
    bool progressive = true;
    for(int i=0; i<part.size()-1; i++)
        if(part[i+1]-part[i] != part[1]-part[0]);
    */
    
    // case 2 & case 4 한꺼번에 하기
    bool progressive = true;
    for(int i=0; i<part.size()-1; i++) 
        if(part[i+1]-part[i] != part[1]-part[0]) 
            progressive = false;
    
    if(progressive && abs(part[1]-part[0])) return 2;
    
    
    // case 3
    bool turn=true;
    for(int i=0; i<part.size(); i++)
        if(part[i]!=part[i%2]) turn=false;
    if(turn) return 4;
    
    
    // case 4
    if(progressive) return 5;
    
    
    // case 5
    return 10;
}


int d(int i) {
    /**************************
    끝났으면 끝났다고 표시를 해야지!
    **************************/
    if(i==nums.size()) return 0;
    
    int& ret = dp[i];
    if(ret) return ret;
    
    ret = 2e9;
    for(int L=3; L<=5; L++) {
        if(i+L<=nums.size()) ret = min(ret, d(i+L) + point(i, i+L-1));
    }
    return ret;
}


int main() {
    cin >> nums;
    cout << d(0);
}
