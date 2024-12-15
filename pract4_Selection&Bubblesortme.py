"""
Experiment 12: Write a Python program to store first year percentage of students in an array. 
Write a function for sorting an array of floating point numbers in ascending order using 
a) Selection Sort
b) Bubble Sort and display the top five scores
Selection Sort Algorithm:
Step 1 − Set MIN to location 0
Step 2 − Search the minimum element in the list
Step 3 − Swap with value at location MIN
Step 4 − Increment MIN to point to next element
Step 5 − Repeat until list is sorted
Bubble Sort Algorithm: (Ascending order):
1. Starting with the first element (index=0) compare the current element with the next element of the list. 
2. If the current element is greater than the next element of the list, swap them. 
3. If the current element is less than the next element, move to the next element. Repeat step 1.
"""

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
    for i in range(n):
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
    per = float(input(f"\nEnter percentage of student {i+1}: "))
    arr.append(per)

print("\nThe sorted scores form selection sort are")
SelectionSort(arr, n)

print("\nThe sorted scores from bubble sort are")
BubbleSort(arr, n)
print("Thanks for using this program!")

