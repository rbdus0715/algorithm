n = int(input())

def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x%y)

def lcm(x, y):
  return int(x*y/gcd(x, y))
  
for _ in range(n):
    x, y = map(int, input().split())
    print(gcd(x, y), lcm(x, y))
