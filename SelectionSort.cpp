#include <iostream>
using namespace std;
int Max_index(int arr[],int n) {
    int max = 0;
    for(int i=1;i<n;i++) {
        if(arr[i]>arr[max]) {
            max = i;
        }
    }
    return max;
}
void swap(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        int minIndex = i;
        for(int j=i+1;j<n;j++) {
        if(arr[j]<arr[minIndex]) {
            minIndex = j;
        }
        }
        if(minIndex!=i) {
            swap(arr,i,minIndex);
        }

        
    }
}
int main() {
    int arr[] = {3,1,2,6,4,9,0,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int Max = Max_index(arr,n);
    cout<<Max<<endl;
    swap(arr,0,Max);
    selection(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}


