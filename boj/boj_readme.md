# issues
- 메모리 초과
- 런타임 에러

## 분할 정복
## 다이나믹 프로그래밍
- [2096_memory](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/2096_memory.cpp) 배열 길이가 너무 길어질 때<br/>
    > 각각 순간의 입력을 받을 수 있는 크기의 배열, for문으로 돌아가며 입력<br/>
    > 원래는 인덱스가 0 1 2 3 4 ... 였는데 이제는 0 1 0 1 0 ... 이렇게 번갈아서 입력받음<br/>
    > [2096](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/2096.cpp)
- [11066](https://github.com/rbdus0715/algorithm/tree/main/boj/dynamic_programming) 신선한 문제<br/>
    > 보통 dp[i][j]로 for문으로 i, j를 움직이면서 dp를 계산하는데 (나도 처음에는 아무 생각 없이 그렇게 풀이했음) 바깥과 안쪽 for문 변수를 각각 계산할 배열의 길이, 출발 지점 으로 함<br/>
    > 그렇게 해야 배열의 길이를 1부터 계산하여 나머지 문제에 쓰일 수 있는 토대를 만들 수 있다<br/>
    > 배운점 : 바텀업 풀이에서는 무작정 dp[i][j]의 i, j를 for문으로 계산하려 하지 말고, 지금 내가 계산하는 dp의 하위 문제가 이미 계산 되었는지부터 생각하여, 어떻게 for문을 구성하면 밑의 문제부터 해결할 수 있을지를 생각한다 (비슷? 11049)<br>
    > 탐욕법으로 풀기 가능 [탐욕법 풀이](https://github.com/rbdus0715/algorithm/blob/main/study/044_stringMerge.cpp)
- [1006](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/1006*.cpp)
    > 원형 형태로 이어지는 배열이라 더 어려운 문제
    > 이어지는 경우의 케이스를 나눠서 풀이
    > 꼭 재귀로만 생각하지 말고 반복적dp로도 생각해보기
    > i번째 dp를 계산할 때 꼭 전 단계의 dp를 이용해서 i를 완성시키려고 하는 것이 아니라 i+1을 완성시키는 생각도 해보기
- [5557](https://github.com/rbdus0715/algorithm/blob/main/boj/dynamic_programming/5557.cpp)
    > 완전 탐색으로 하면 2의 지수 함수의 시간 복잡도가 나오는 문제이지만<br>
    > 문제에 범위가 주어져 그것을 dp의 한 차원으로 사용하였다. -> 반복적 동적 계획법
## 재귀
