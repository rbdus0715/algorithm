#include <iostream>
using namespace std;

// 내 풀이
int H, W;
const int coverTipe[4][3][2] = {
    {{0,0},{0,1},{1,0}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};

bool check(char board[20][20]){
    bool result = true;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(board[i][j]!='#') result = false; 
        }
    }
    return result;
}

bool set(int y, int x, int t, char board[20][20]){
    bool result = true;
    int ny{0}, nx{0};
    
    for(int i=0; i<3; i++){
        int dy = coverTipe[t][i][0];
        int dx = coverTipe[t][i][1];
        
        ny = y + dy; nx = x + dx;
        
        if(board[ny][nx]=='#'||ny>4||nx<0||nx>4) result = false;
    }
    if(result){
        for(int i=0; i<3; i++) board[ny][nx]='#';
    }

    return result;
}

int solve(int y, int x, char map[20][20]){
    if(check(map)) return 1;
    
    int sum{0};
    
    for(int i=0; i<4; i++){
        if(set(y,x,i,map)){
            int py = y, px = x; // 현재 위치
            if(map[py][px]=='#' && x<=3) px++;
            else if(map[py][px]=='#' && x==4){
                py++; px=0;
            }
            
            sum += solve(py, px, map);
        }
    }
    
    return sum;
}

int main(){
    char board[20][20];
    cin >> H >> W;
    for(int i=0; i<H; i++){
        cin >> board[i];
    }
    cout << solve(0,0, board);
}

/*
3 7
#.....#
#.....#
##...##

3 7
#.....#
#.....#
##..###

8 10
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########
*/
