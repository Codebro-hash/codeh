#include <iostream> 
using namespace std; 
 

template <typename T> 
void selectionSort(T arr[], int size) { 
    for (int i = 0; i < size - 1; ++i) { 
        int minIndex = i; 
        for (int j = i + 1; j < size; ++j) { 
            if (arr[j] < arr[minIndex]) { 
                minIndex = j; 
            } 
        } 
        
        T temp = arr[minIndex]; 
        arr[minIndex] = arr[i]; 
        arr[i] = temp; 
    } 
} 
 

template <typename T> 
void displayArray(T arr[], int size) { 
    for (int i = 0; i < size; ++i) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
} 
 
int main() { 
    
    int intArr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int intSize = sizeof(intArr) / sizeof(intArr[0]); 
 
    cout << "Original integer array: "; 
    displayArray(intArr, intSize); 
 
    selectionSort(intArr, intSize); 
 
    cout << "Sorted integer array: "; 
    displayArray(intArr, intSize); 
 
    
    float floatArr[] = {64.5, 34.2, 25.1, 12.4, 22.9, 11.0, 90.3}; 
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]); 
 
    cout << "\nOriginal float array: "; 
    displayArray(floatArr, floatSize); 
 
    selectionSort(floatArr, floatSize); 
 
    cout << "Sorted float array: "; 
    displayArray(floatArr, floatSize); 
 
    return 0;
}