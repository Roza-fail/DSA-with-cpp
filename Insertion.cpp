#include <iostream>
using namespace std;
void Insertions(int arr[],int n) {
    for(int i=1;i<n;i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
       
        }

    }
    int main() {
        int arr[] = {3,1,2,6,4,9,0,5};
        int size = sizeof(arr)/sizeof(arr[0]);
        for(int i=0;i<size;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        Insertions(arr,size);
        for(int i=0;i<size;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
    }


