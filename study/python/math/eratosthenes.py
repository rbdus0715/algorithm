isPrime_arr = [1] * (n + 1)
def eratosthenes(): 
    isPrime_arr[0] = isPrime_arr[1] = False
    
    sqrtn = int(n ** (1/2))
    for i in range(2, sqrtn + 1):
        if isPrime_arr[i]:
            for j in range(i*i, n + 1, i):
                isPrime_arr[j] = False

eratosthenes()
