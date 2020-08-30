#include <iostream>
using namespace std;


//CPP code for insertion sort algorithm
void insertion_sort(int arr[], int n){
    int key, j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Testing the insertion sort algo
int main(void){

    int a[7] = {12, 56, 72, 23, 12, 6, 9};

    cout <<"\nUnsorted Array: ";
    print_array(a, 7);

    insertion_sort(a, 7);

    cout<<"\nAfter Sorting: ";
    print_array(a, 7);
}