#include<iostream>
using namespace std;

//Bubble sort logic
void bubble_sort(int arr[], int n){
    int flag, temp;
    for(int i = 0; i < n; i++){
        flag = 0;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; 
            }
        }
        if (!flag){
            return;
        }
    }
}

//Function to print contents of an array
void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Testing the bubble sort algo
int main(void){

    int a[7] = {12, 56, 72, 23, 12, 6, 9};

    cout <<"\nUnsorted Array: ";
    print_array(a, 7);

    bubble_sort(a, 7);

    cout<<"\nAfter Sorting: ";
    print_array(a, 7);
}