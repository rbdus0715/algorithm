// 활동 선택 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y, earl, selected;
vector<pair<int, int> > meeting;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        meeting.push_back(make_pair(y, x));
    }
    sort(meeting.begin(), meeting.end());
    
    for(int i=0; i<n; i++) {
        int meetBegin = meeting[i].second;
        int meetEnd = meeting[i].first;
        
        if(earl <= meetBegin) {
            selected++;
            earl = meetEnd;
        }
    }
    cout << selected;
}
