# issues
- 메모리 초과
- 런타임 에러

## 분할 정복
## 다이나믹 프로그래밍
- [2096_memory](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/2096_memory.cpp) 배열 길이가 너무 길어질 때
    - 각각 순간의 입력을 받을 수 있는 크기의 배열, for문으로 돌아가며 입력
    - 원래는 인덱스가 0 1 2 3 4 ... 였는데 이제는 0 1 0 1 0 ... 이렇게 번갈아서 입력받음
    - [2096](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/2096.cpp)
- [11066](https://github.com/rbdus0715/algorithm/tree/main/boj/dynamic_programming) 신선한 문제
    - 보통 dp[i][j]로 for문으로 i, j를 움직이면서 dp를 계산하는데 (나도 처음에는 아무 생각 없이 그렇게 풀이했음) 바깥과 안쪽 for문 변수를 각각 계산할 배열의 길이, 출발 지점 으로 함
    - 그렇게 해야 배열의 길이를 1부터 계산하여 나머지 문제에 쓰일 수 있는 토대를 만들 수 있다
    - 배운점 : 바텀업 풀이에서는 무작정 dp[i][j]의 i, j를 for문으로 계산하려 하지 말고, 지금 내가 계산하는 dp의 하위 문제가 이미 계산 되었는지부터 생각하여, 어떻게 for문을 구성하면 밑의 문제부터 해결할 수 있을지를 생각한다 (비슷? 11049)
    - 탐욕법으로 풀기 가능 [탐욕법 풀이](https://github.com/rbdus0715/algorithm/blob/main/study/044_stringMerge.cpp)
- [1006](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/1006*.cpp)
    - 원형 형태로 이어지는 배열이라 더 어려운 문제
    - 이어지는 경우의 케이스를 나눠서 풀이
    - 꼭 재귀로만 생각하지 말고 반복적dp로도 생각해보기
    - i번째 dp를 계산할 때 꼭 전 단계의 dp를 이용해서 i를 완성시키려고 하는 것이 아니라 i+1을 완성시키는 생각도 해보기
- [5557](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/5557.cpp)
    - 완전 탐색으로 하면 2의 지수 함수의 시간 복잡도가 나오는 문제이지만
    - 문제에 범위가 주어져 그것을 dp의 한 차원으로 사용하였다. -> 반복적 동적 계획법
- [17404](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/17404.cpp)
    - 최소를 구하는 문제에서 기저사례는 1e9 즉 무한대를 반환한다 이는 반복적 동적 계획법에서도 마찬가지
- [2618](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/2618*.cpp)
    - 신기한 메모이제이션 + reconstruction
    - 내가 생각하던 메모이제이셙 고정관념은 dp[i]로 해서 i번째 사건일 때의 값을 불러오는 것이었는데, 이 문제에서는 어떤 상황이 주어졌을 때 이것이 몇 번째 상황인지 알 수 있어서 그걸 메모이제이션 했다. 예를 들어 dp[경찰차 1의 위치][경찰차 2의 위치] 이렇게 dp에 상황을 저장하는 것이다.
## 재귀
