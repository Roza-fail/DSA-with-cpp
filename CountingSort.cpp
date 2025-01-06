#include <iostream>
using namespace std;
void countSort(int arr[],int n) {
    int max = arr[0];
    int min = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
        if(arr[i]<min) {
            min = arr[i];
        }
    }
    int range = max-min+1;
    int count[range] = {0};
    for(int i=0;i<n;i++) {
        count[arr[i]-min]++;
    }
    int index = 0;
    for(int i=0;i<range;i++) {
        if(count[i]>0) {
            arr[index++] = i+min;
            count[i]--;
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
    countSort(arr,size);
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}