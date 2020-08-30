#include<iostream>
using namespace std;


//Selection sort logic
void selection_sort(int arr[], int n){
    int min, temp;
    for (int i = 0; i < n - 1; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}


//Function to print contents of any array
void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Testing the selection sort algo
int main(void){

    int a[7] = {12, 56, 72, 23, 12, 6, 9};

    cout <<"\nUnsorted Array: ";
    print_array(a, 7);

    selection_sort(a, 7);

    cout<<"\nAfter Sorting: ";
    print_array(a, 7);
}