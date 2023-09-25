def bubbleSort(arr):
    n = len(arr)
    
    for i in range(n):
        swapped = False
        
        # 배열의 마지막 요소들을 하나씩 완성시켜나감
        for j in range(0,n-i-1):
            
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        
        if not swapped:
            break

arr = [64, 34, 25, 12, 22, 11, 90]
bubbleSort(arr)

for i in range(len(arr)):
    print(arr[i], end=' ')
