#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
   for(int i=0;i<n;i++) {
    for(int j=1;j<n-i;j++) {
        if(arr[j]<arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
   }
}
int main() {
    int arr[] = {3,1,2,6,4,9,0,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubbleSort(arr,size);
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}