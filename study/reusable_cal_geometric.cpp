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
        return hypot(x, y); // hypot : 직각삼각형 빗변 길이
    }
    
    // 방향이 같은 단위벡터를 반환
    vector2 normalize() const {
        return vector2(x/norm(), y/norm());
    }
    
    // x축 양의 방향 기준 반시계 방향 각도
    double polar() const {
        return fmod(atan2(y, x) + 2*PI, 2*PI);
    }
    
    // 내적 / 외적
    double dot(const vector2& rhs) const {
        return x*rhs.x + y*rhs.y;
    }
    vector2 cross(const vector2& rhs) const {
        return vector2(x*rhs.y, -rhs.x*y);
    }
    
    // 이 벡터를 rhs에 사영
    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r*r.dot(*this);
    }
    
};
