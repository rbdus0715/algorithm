/*
<idea>

A : 10 20 30 1 2
B : 10 20 30

A의 증가 부분 수열들
i=0부터 시작 : 10, 10 20, 10 20 30, 10 30
i=1부터 시작 : 20, 20 30
i=2부터 시작 : 30
i=3부터 시작 : 1, 1 2
i=4부터 시작 : 2

B의 증가 부분 수열들
i=0부터 시작 : 10, 10 20, 10 20 30, 10 30
i=1부터 시작 : 20, 20 30
i=2부터 시작 : 30

나의 첫 풀이 방법
A의 증가 부분 수열들 중에서 하나씩 B에 넣었다 빼보면서 jlis를 확인한다.

10 10 20 30 → 10 20 30
10 10 20 20 30 → 10 20 30
10 10 20 20 30 30 → 10 20 30
10 10 20 30 30 → 10 20 30
10 20 20 30 → 10 20 30
10 20 20 30 30 → 10 20 30
10 20 30 30 → 10 20 30
1 10 20 30 → 1 10 20 30
1 2 10 20 30 → 1 2 10 20 30
2 10 20 30 → 2 10 20 30
에서의 최장 부분 수열을 찾으면 된다. 중복되는 계산은 dp로 처리한다.

→ 이상한 것 같다.

<책에서 푼 방법>

작은 문제를 정의해서 풀어본다
i >> 수열 A에서 i번째 원소로 시작하는 부분수열
j >> 수열 B에서 j번째 원소로 시작하는 부분수열

jlis(i,j) = max {
	
	max	jlis(next_i, j) + 1
	max	jlis(i, next+j) + 1
	(단, 여기서 next는 i나j 뒤의 원소 모든 것을 말함)

}
*/
