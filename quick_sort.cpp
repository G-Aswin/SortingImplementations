#include<iostream>
using namespace std;

int partition(int arr[], int p, int r){
    //Chosing first element as pivot
    int x = arr[p];
    int i = p, temp;
    for (int j = p + 1; j <= r; j++){
        if (arr[j] < x){
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    arr[p] = arr[i];
    arr[i] = x;

    return i;
}

void quick_sort(int arr[], int p, int r){
    if (p < r){
        int m = partition(arr, p, r);
        quick_sort(arr, p, m - 1);
        quick_sort(arr, m + 1, r);
    }
}




void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Testing the quick sort algo
int main(void){

    int a[7] = {12, 56, 72, 23, 12, 6, 9};

    cout <<"\nUnsorted Array: ";
    print_array(a, 7);

    quick_sort(a, 0, 6);

    cout<<"\nAfter Sorting: ";
    print_array(a, 7);
}