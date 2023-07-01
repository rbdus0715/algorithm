#include <iostream>
#include <cmath>
using namespace std;
#define EPSILON 1e-6f

const double PI = 2.0*acos(0.0);

// 2차원 벡터
struct vector2 {
    double x, y;
   
    // 생성자 함수
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    /*
    기본 연산 함수
        - 비교 연산자
        - 벡터끼리 덧뺄셈
        - 실수배
        - 벡터의 길이
    */

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
    
    
    /*
    응용 계산 함수
        - 단위벡터 계산
        - 벡터의 각도
        - 내/외적
        - 사영
    */
    
    // 방향이 같은 단위벡터를 반환
    vector2 normalize() const {
        return vector2(x/norm(), y/norm());
    }
   
    // x축 양의 방향 기준 반시계 방향 각도
    double polar() const {
        return fmod(atan2(y, x) + 2*PI, 2*PI);
    }
   
    // 내적 / 외적 (외적은 3차원 연산이므로 2차원에서는 double 형태로만 계산)
    double dot(const vector2& rhs) const {
        return x*rhs.x + y*rhs.y;
    }
    double cross(const vector2& rhs) const {
        return x*rhs.y - rhs.x*y;
    }
   
    // 이 벡터를 rhs에 사영
    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r*r.dot(*this);
    }
};


/*
두 벡터를 이용한 응용 연산
    - 벡터 사잇각
    - 사잇각이 90도인지
    - 넓이
    - 두 벡터의 방향성 확인
*/

double between_angle(vector2 a, vector2 b) {
   
    double theta = acos(a.dot(b)/(a.norm()*b.norm()));
   
    return theta;
}

bool isRightAngle(vector2 a, vector2 b) {
   
    bool yes = (a.dot(b)==0 ? 1 : 0);
   
    return yes;
}

// double area(vector2 a, vector2 b) {
    
//     double area = 
    
//     return area;
// }

// 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수, 평행이면 0
double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}

// 두 직선의 교점 : 두 직선 ab, cd
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
    double det = (b-a).cross(d-c);
    
    if(fabs(det)<EPSILON) return false;
    x = a + (b-a) * ((c-a).cross(d-c)/det);
    return true;
}

// 점과 선 사이의 거리
vector2 foot(vector2 p, vector2 a, vector2 b) {
    return a + (p-a).project(b-a);
}
double pointToLine(vector2 p, vector2 a, vector2 b) {
    return (p-foot(p,a,b)).norm();
}

int main() {
    vector2 a = vector2(0,1);
    vector2 b = vector2(1,0);
    cout << between_angle(a, b); // PI/2
    cout << isRightAngle(a, b); // true
}
