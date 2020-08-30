#include<iostream>
using namespace std;

//Function to merge two arrays
void merge(int arr[], int p, int m, int q){
    int a1[m - p + 1];
    int a2[q - m];
    int k = p;

    for (int i = 0; i < (m - p + 1); i++){
        a1[i] = arr[k++];
    }

    for (int i = 0; i < (q - m); i++){
        a2[i] = arr[k++];
    }

    k = p;
    int i = 0, j = 0;

    while (i < (m - p + 1) && j < (q - m)){
        if (a1[i] < a2[j]){
            arr[k] = a1[i];
            i++;
        }
        else{
            arr[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < (m - p + 1)){
        arr[k] = a1[i];
        i++;
        k++;
    }

    while (j < (q - m)){
        arr[k] = a2[j];
        j++;
        k++;
    }
}


//Merge sort logic
void merge_sort(int arr[], int p, int q){
    if (p < q){
        int m = (p + q) / 2;
        merge_sort(arr, p, m);
        merge_sort(arr, m+1, q);
        merge(arr, p, m, q); 
    }
}





//Function to print any array
void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Testing the merge sort algo
int main(void){

    int a[11] = {12, 56, 72, 23, 12, 6, 9, 12139, -983, -87, 0};

    cout <<"\nUnsorted Array: ";
    print_array(a, 11);

    merge_sort(a, 0, 10);

    cout<<"\nAfter Sorting: ";
    print_array(a, 11);
}