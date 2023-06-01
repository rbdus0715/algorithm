[문제 링크](https://www.algospot.com/wiki/read/JMBook_%EB%AC%B8%EC%A0%9C%EB%93%A4_%EB%A7%81%ED%81%AC)

계획: 1권에서는 동적 계획법이 어려운 난이도여서 1권 뒤쪽의 알고리즘을 메인으로 다루면서 공부하기

# Q001-007 : brute force, 재귀함수

# Q008-011 : divide conquer

# Q012-? : dynamic programing
- 동적 계획법 팁
  - 모든 답을 만들어 보고 그중 최적해 점수를 반환하는 완탐 알고리즘 설계
  - 입력이 배열이거나 문자열이면 가능하다면 적절한 변환으로 메모이제이션
  - 부분 문제의 개수가 너무 많을 때, 최적 부분 조건이 성립하지 않을 때 :
    - 답이 항상 어떤 구조를 가질 것이라고 예측하고 그것을 강제하는 것
    - 정렬 등의 방법을 이용하거나 해서 주어진 데이터/문제의 특성, 성질을 잘 파악하여 일반화하기

# 탐욕법

# 조합 탐색

# 최적화 문제 결정 문제로 바꿔 풀기

# 수치 해석

# 정수론

# 계산 기하

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 2.0*acos(0.0); 

// 2차원 벡터
struct vector2 {
    double x, y;
    
    // 생성자 함수
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    // 벡터끼리의 비교 연산자
    bool operator == (const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator < (const vector2& rhs) const { 
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    } // 끝점의 x 좌표가 작은 벡터일수록, x좌표가 같다면 y좌표가 작은 벡터일수록
    
    // 벡터끼리의 덧셈 뺄셈
    vector2 operator + (const vector2& rhs) const {
        return vector2(x+rhs.x, y+rhs.y);
    }
    vector2 operator - (const vector2& rhs) const {
        return vector2(x-rhs.x, y-rhs.y);
    }
    
    // 실수배
    vector2 operator * (double rhs) const {
        return vector2(x*rhs, y*rhs);
    }
    
    // 벡터의 길이 반환
    double norm() const {
        return hypot(x, y); // hypot은 ㅂ;ㅅ
    }
    
    
}

int main() {
    cout << 1;
}
