def SelectionSort(arr, n):
    for i in range(0, n-1):
        Min = i
        for j in range(i+1, n):
            if arr[j] < arr[Min]:
                Min = j
        if Min != i:
            arr[i], arr[Min] = arr[Min], arr[i]
    print(arr)


def BubbleSort(arr, n):
    for i in range(0,n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    print(arr)
    
    print("Top Five Scores are...")
    for i in range (n-1,n-6,-1):
            print(arr[i])


# Driver Code
print("\nEnter the no of students in the first year")
n = int(input())
arr = []
for i in range(n):
    per = float(input("Enter percentage : "))
    arr.append(per)

print("\nThe sorted scores form selection sort are")
SelectionSort(arr, n)

print("\nThe sorted scores from bubble sort are")
BubbleSort(arr, n)


