#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> matching[10];

int solve(int n, int toMatch, bool visited[10]){
    if(toMatch==2) return 1;
    
    int sum = 0;
    for(int i:matching[n]){
        if(!visited[i]){
            visited[i] = true;
            sum += solve(i, toMatch-2, visited);
        }
    }
    
    return sum;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int x, y; cin >> x >> y;
        matching[x].push_back(y); matching[y].push_back(x);
    }
    bool visited[10];
    cout << solve(0, N, visited);
}

/*
2 1
1

4 6
0 1 1 2 2 3 3 0 0 2 1 3
3

6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
4
*/
