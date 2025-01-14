#include <iostream>
using namespace std;

void mergeSort(int[],int,int);
void merge(int[],int,int,int);

int main() {
    int n;
    cout<<"Enter size n: ";
    cin>>n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<"Sorted array: \n";
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}

void mergeSort(int arr[], int left, int right){
    if (left>=right) return;
    int mid = (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

void merge(int arr[], int left, int mid, int right){
    int n1 = mid-left+1;
    int n2 = right-mid;

    int arr1[n1];
    int arr2[n2];

    for(int i=0; i<n1; i++){
        arr1[i]=arr[left+i];
    }
    for(int i=0; i<n2; i++){
        arr2[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if (arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }

    while (i<n1){
        arr[k]=arr1[i];
        k++; i++;
    }

    while (j<n2){
        arr[k]=arr2[j];
        k++; j++;
    }
}