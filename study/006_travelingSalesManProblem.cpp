#include <iostream>
#include <vector>
using namespace std;

int N;
double map[8][8];

double solve(int start, int toGo, bool visited[8]){
    if(toGo==0) return map[start][0];
    double result = 2e9;
    
    for(int i=0; i<N; i++){
        if(!visited[i]){ 
            visited[i] = true;
            result = min(result, solve(i, toGo-1, visited)+map[start][i]);
            visited[i] = false;
        }
    }
    
    return result;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j]; 
        }
    }
    bool visited[8] = {0,};
    visited[0] = true;
    cout << solve(0, N-1, visited);
}
