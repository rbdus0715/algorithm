def isPrime(n):
    if n <= 1: return False
    if n == 2: return False
    if n % 2 == 0: return False
    
    sqrtn = int(n ** (1/2))
    for i in range(3, sqrtn + 1):
        if n % i == 0:
            return False
    
    return True

isPrime(13)
