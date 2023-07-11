#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct RangeResult {
    int size;
    int mostfreq;
    int leftN, leftF;
    int rightN, rightF;
};

RangeResult merge(const RangeResult a, const RangeResult b) {
    RangeResult ret;
    
    ret.size = a.size + b.size;
    
    ret.leftN = a.leftN;
    ret.leftF = a.leftF;
    ret.rightN = b.rightN;
    ret.rightF = b.rightF;
    
    if(a.size==a.leftF && a.leftN==b.leftN)
        ret.leftF = a.size + b.leftF;
    if(b.size==b.rightF && a.rightN==b.rightN)
        ret.leftF = b.size + a.rightF;
    
    ret.mostfreq = max(ret.leftF, ret.rightF);
    if(ret.leftN==ret.rightN)
        ret.mostfreq = max(ret.mostfreq, a.rightF + b.leftF);
}

struct 

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        
}


