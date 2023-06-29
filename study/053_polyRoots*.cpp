/*
문제 : 다음 함수를 완성시키기

// 다항식의 계수가 주어질 때 미분한 결과의 계수 반환
vector<double> differentiate(const vector<double>& poly);

// 방정식 풀기
vector<double> solveNaive(const vector<double>& poly);

// 다항식 f(x)의 계수가 주어질 때 f(x0) 반환
double evaluate(const vector<double>& poly, double x0);

// 방정식의 해의 절대 값은 L 이하여야 함 ([-L, L] 범위 내에 해가 존재)
const double L = 25;

// 방정식의 근을 반환하는 최종 함수
vector<double> solve(const vector<double>& poly);
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// 다항식의 계수가 주어질 때 미분한 결과의 계수 반환
vector<double> differentiate(const vector<double>& poly) {
    
    int n = poly.size() - 1;
    vector<double> ret;
    
    for(int i=0; i<n; i++)
        ret.push_back((n-i)*poly[i]);

    return ret;
}

// 방정식 풀기 (1차 혹은 2차)
vector<double> solveNaive(const vector<double>& poly) {
    
    int n = poly.size() - 1;
    vector<double> ret;
    
    if(n==1) {
        ret.push_back(-poly[1]/poly[0]);
    }
    else if(n==2) {
        double a = poly[0], b = poly[1], c = poly[2];
        ret.push_back((-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
        ret.push_back((-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
    }
    
    sort(ret.begin(), ret.end());
    return ret;
}

// 다항식 f(x)의 계수가 주어질 때 f(x0) 반환
double evaluate(const vector<double>& poly, double x0) {
    
    int n = poly.size() - 1;
    double ret = 0;
    
    for(int i=0; i<=n; i++)
        ret += pow(x0, n-i)*poly[i];
    
    return ret;
}
 
// 방정식의 해의 절대 값은 L 이하여야 함 ([-L, L] 범위 내에 해가 존재)
const double L = 10;

// 방정식의 근을 반환하는 최종 함수
vector<double> solve(const vector<double>& poly) {
    int n = poly.size() - 1;
    
    if(n<=2) return solveNaive(poly);
    
    vector<double> de = differentiate(poly);
    vector<double> solve_de = solve(de);
    
    solve_de.insert(solve_de.begin(), -L-1);
    solve_de.insert(solve_de.end(), L+1);
    
    vector<double> ret;
    for(int i=0; i<solve_de.size()-1; i++) {
        double x1 = solve_de[i], x2 = solve_de[i+1];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);    

        if(y1*y2>0) continue;
        
        if(y1>y2) {
            swap(y1, y2);
            swap(x1, x2);
        }
        
        // 정해진 횟수만큼 반복하기 방법 사용
        for(int i=0; i<100; i++) {
            double mid = (x1+x2)/2;
            double fmid = evaluate(poly, mid);
            
            if(y1*fmid > 0) {
                x1 = mid;
                y1 = fmid;
            }
            else {
                x2 = mid;
                y2 = fmid;
            }
        }
        
        ret.push_back((x1+x2)/2);
    }
    
    sort(ret.begin(), ret.end());
    return ret;
}

// 방정식 근 구하기
int n;

int main() {
    vector<double> poly;
    cin >> n;
    for(int i=0; i<=n; i++) {
        double x; cin >> x;
        poly.push_back(x);
    }
    
    vector<double> result = solve(poly);
    cout << fixed << setprecision(12);
    
    for(double i:result) cout << i << " ";
}
