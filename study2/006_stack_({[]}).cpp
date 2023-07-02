#include <iostream>
#include <stack>
#include <string>
using namespace std;

string a;

bool solve(string a) {
    const string opening("({["), closing(")}]");
    
    stack<char> stk;
    for(int i=0; i<a.size(); i++) {
        if(opening.find(a[i]) != -1) 
            stk.push(a[i]);
        else {
            if(stk.empty()) 
                return false;
            
            if(opening.find(stk.top()) != closing.find(a[i]))
                return false;
        
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    cin >> a;
    cout << solve(a);
}
