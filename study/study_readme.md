[문제 링크](https://www.algospot.com/wiki/read/JMBook_%EB%AC%B8%EC%A0%9C%EB%93%A4_%EB%A7%81%ED%81%AC)

계획: 1권에서는 동적 계획법이 어려운 난이도여서 1권 뒤쪽의 알고리즘을 메인으로 다루면서 공부하기

- 도움을 많이 받은 문제 : *
- 어려워서 미룬 문제 : #

# Q001-007 : brute force, 재귀함수 (5/19~)

# Q008-011 : divide conquer (5/22~)
- 재귀함수와 가장 큰 차이 : 재귀함수는 큰 문제에서 작은 것을 하나 떼어 풀고, 떼어 풀고를 반복하는 반면 분할정복은 큰 문제를 여러 개의 동일한 소문제로 나누는 개념이다
- 분할정복 코드를 짤 때 재귀함수와 마찬가지로 (1) 기저문제, (2) 재귀적 정의 이 두 가지를 가장 먼저 생각하기
# Q012-025 : dynamic programing (5/26~)
- 동적 계획법 팁
  - 모든 답을 만들어 보고 그중 최적해 점수를 반환하는 완탐 알고리즘 설계
  - 입력이 배열이거나 문자열이면 가능하다면 적절한 변환으로 메모이제이션
  - 부분 문제의 개수가 너무 많을 때, 최적 부분 조건이 성립하지 않을 때 :
    - 답이 항상 어떤 구조를 가질 것이라고 예측하고 그것을 강제하는 것
    - 정렬 등의 방법을 이용하거나 해서 주어진 데이터/문제의 특성, 성질을 잘 파악하여 일반화하기
  - dp를 두 번 이상 쓸 경우도 있으니 대비하기! (최대합 경로에서 만들었던 dp 배열을 경로 개수 문제 dp에서 재활용)

# Q026- : dynamic programing technique (6/5~)
- 동적 계획법을 뿌시자!
  - 최적해를 직접 계산하는 문제를 만난다면 >> 원래 바탕이 되는 문제를 풀어 dp를 마련하는데, 여기서 본 문제에 도움이 되는 정보를 배열에 저장해놓는다
    - ex) [LIS 실제로 출력하기](https://github.com/rbdus0715/algorithm/blob/main/study/026_LISfind.cpp) | [실제 배낭문제 답 구하기](https://github.com/rbdus0715/algorithm/blob/main/study/027_knapsackFind.cpp)
  - k 번째 최적해를 찾는 문제 >> 완탐에서 시작해서 메모이제이션적용, skip개를 건너뛰고 첫 번째 답을 반환하는 재귀호출함수로 풀이 >> 건너뛰기 위해서는 개수를 미리 세어놔야함
    - ex) [k번째 모스부호 효율적으로 찾기](https://github.com/rbdus0715/algorithm/blob/main/study/029_morseKth.cpp) | [k-th LIS 구하기](https://github.com/rbdus0715/algorithm/blob/main/study/030_kthLIS.cpp) | [드래곤 커브 #](https://github.com/rbdus0715/algorithm/blob/main/study/031_dragonCurve%23.cpp)
  - 정수 이외의 입력에 대한 메모이제이션
    - 연관 배열 사용? map<벡터, 인트> cache : 단점은 접근 시간이나 컨테이너끼리 비교도 오래걸림
    - 일대일 대응 함수 적용하기 : 입력을 적절하게 정수로 변환
    - 입력이 순열인 경우 : 앞 자리가 4이면 그 순열 앞에 3*9!개의 입력이 옴
    - 입력 범위가 좁을 경우 : 배열 [4, 0, 1, 7, 1] 은 자연수 40171로
  - 다음 탐색으로 넘겨줘야 하는 데이터가 너무 많을 때 
    - ex) [짐바브웨문제](https://github.com/rbdus0715/algorithm/blob/main/study/032.zimbabwe%23.cpp)
    - 굳이 모든 정보들을 다 가지고 기저사례까지 가야할까? >> 그럴 필요 없이 최소한의 정보만 가지고 가면 된다
      - 최종 결과가 m으로 나누어 떨어지는지 확인 >> 나머지 연산의 분배법칙을 이용해 각 탐색마다 나머지 연산 결과만을 넘겨준다
      - 최종 결과의 크기를 비교해야 할 때 >> 높은 자리수끼리만 비교하면 됨
# 탐욕법

# 조합 탐색

# 최적화 문제 결정 문제로 바꿔 풀기

# 수치 해석

# 정수론

# 계산 기하
- [기하 계산도구](https://github.com/rbdus0715/algorithm/blob/main/study/reusable_cal_geometric.cpp)
