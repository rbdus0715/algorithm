#include <iostream>
#include <vector>
using namespace std;

int N, visited[8];
double map[8][8];

double solve(int start, int toGo){
    if(toGo==0) return map[start][0];
    cout << start << " ";
    double sum = 2e9;
    
    for(int i=0; i<N; i++){
        if(!visited[i]){ 
            visited[i] = true;
            sum = min(sum, solve(i, toGo-1)+map[start][i]);
        }
    }
    
    return sum;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j]; 
        }
    }
    visited[0] = true;
    cout << solve(0, N);
}
