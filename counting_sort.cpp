#include<iostream>
using namespace std;


//Counting sort logic
void counting_sort(int arr[], int n){
    //Find the max element
    int k = arr[0];
    for(int i = 1; i < n; i++){
        if (arr[i] > k)
            k = arr[i];
    }

    //Create an array of size k + 1
    int aux[k + 1] = {0};

    //Create a result array to store sorted array
    int res[n] = {0};

    //Count the occurance of each element in arr
    for (int i = 0; i < n; i++){
        aux[arr[i]]++;
    }

    //Convert aux into cumulative sum
    for (int i = 1; i < k + 1; i++){
        aux[i] += aux[i - 1];
    }

    //Store the res one by one 
    for (int i = n - 1; i >= 0; i--){
        res[aux[arr[i]] - 1] = arr[i];
        aux[arr[i]]--;
    }

    //Copy elements of res in arr
    for (int i = 0; i < n; i++){
        arr[i] = res[i];
    }
}


//Function to print contents of any array
void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Testing the counting sort algo
int main(void){

    int a[7] = {12, 56, 72, 23, 12, 6, 9};

    cout <<"\nUnsorted Array: ";
    print_array(a, 7);

    counting_sort(a, 7);

    cout<<"\nAfter Sorting: ";
    print_array(a, 7);
}