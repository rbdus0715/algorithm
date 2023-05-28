#include <iostream>
using namespace std;

string s;
int i;

// 중간과정을 정의하는 것이 아직은 많이 어렵다..
// 문제는 분할정복이므로 마지막에 작은 문제들을 병합하는 것도 생각해야 한다.
// 나중에 다시 풀어보기!

string reverse() {
    char head = s[i];
    i++;
    if(head=='b' || head=='w') return string(1, head);
    
    string UL = reverse();
    string UR = reverse();
    string DL = reverse();
    string DR = reverse();
    
    return string("x") + DL + DR + UL + UR;
}

int main() {
    cin >> s;
    cout << reverse();
}
