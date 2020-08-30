#include<iostream>
using namespace std;

int find_max_ele(int arr[], int n){
    int max = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] > arr[max]){
            max = i;
        }
    }
    return arr[max];
}

//Counting sort logic
void counting_sort(int arr[], int n, int place){
    //Find the max element
    int k = find_max_ele(arr, n), d;

    //Create an array of size k + 1
    int aux[10] = {0};

    //Create a result array to store sorted array
    int res[n] = {0};

    //Count the occurance of each element in arr
    for (int i = 0; i < n; i++){
        d = arr[i] / place;
        aux[d % 10]++;
    }

    //Convert aux into cumulative sum
    for (int i = 1; i < 10; i++){
        aux[i] += aux[i - 1];
    }

    //Store the res one by one 
    for (int i = n - 1; i >= 0; i--){
        d = arr[i] / place;
        res[aux[d % 10] - 1] = arr[i];
        aux[d % 10]--;
    }

    //Copy elements of res in arr
    for (int i = 0; i < n; i++){
        arr[i] = res[i];
    }
}


void radix_sort(int arr[], int n){
    //For each digit in the maximum number, run the counting sort algorithm

    int max_ele = find_max_ele(arr, n);
    int place = 1; //keeps track of the current place

    while (max_ele / place > 0){
        counting_sort(arr, n, place);
        place *= 10;
    }
}


void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Testing the radix sort algo
int main(void){

    int a[7] = {12, 56, 72, 23, 12, 6, 9};

    cout <<"\nUnsorted Array: ";
    print_array(a, 7);

    radix_sort(a, 7);

    cout<<"\nAfter Sorting: ";
    print_array(a, 7);
}