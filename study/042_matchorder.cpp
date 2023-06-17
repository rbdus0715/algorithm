// 자료구조의 필요성을 느낌
#include <iostream>
#include <set>
using namespace std;

int n,rus[101], kor[101], win;
bool taken[101];

int main() {
    /*
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> rus[i] >> kor[i];
    }
    sort(kor, kor+n);

  
    int maxrate=n-1;
    int minrate=0;
    for(int i=0; i<n; i++) {
        if(taken[maxrate]) maxrate--;
        if(taken[minrate]) minrate++;
        
        if(rus[i]>kor[maxrate])
            minrate++;
        else {
            // 자료구조 필요..
            // kor 중에서 rus 보단 크지만 제일 작은 것을 찾아야함
            win++;
        }
    }
    */

  
  
    cout << win;
}


// multiset을 이용한 풀이
#include <iostream>
#include <set>
using namespace std;

int n,rus[101], kor[101], win;
bool taken[101];

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> rus[i];
    for(int i=0; i<n; i++)
        cin >> kor[i];
    
    multiset<int> rate(kor, kor+n);
    for(int i=0; i<n; i++) {
        if(*rate.rbegin() < rus[i]) rate.erase(rate.begin());
        else {
            rate.erase(rate.lower_bound(rus[i]));
            win++;
        }
    }
    cout << win;
}


