## stdin.readline() 할 경우
입력이 'abc'일 때 실제 받는 경우는 'abc\n' 이므로 '\n'를 제거하기 위해 다음 코드를 사용한다.
```python
from sys import stdin
s = stdin.readline().rstrip()
```
