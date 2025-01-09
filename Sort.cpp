#include <iostream>
using namespace std;

//Sort the array with BubbleSort
void BubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//Sort the array with SelectionSort
void SelectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int smallestIdx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[smallestIdx]){
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}
//Sort the array with InsertionSort
void InsertionSort(int arr[], int n){
    for(int i = 1; i < n; i++ ){
        int curr = arr[i];
        int prev = i - 1;
        while(prev >=0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

//Print the elements of array
void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i] <<" ";
    }
}

int main() {
    int arr1[] = {4, 2, 5, 1, 7};
    int arr2[] = {2, 3, 1, 5, 8};
    int arr3[] = {1, 5, 3, 2, 7};
    int n = 5;
    BubbleSort(arr1, n);
    printArr(arr1, n);
    cout<<endl;
    SelectionSort(arr2, n);
    printArr(arr2, n);
    cout<<endl;
    InsertionSort(arr3, n);
    printArr(arr3, n);
    return 0;
}