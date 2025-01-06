#include<iostream>
using namespace std;   //for unsorted arrays

int BinarySearch (int arr[], int target) {
    int length;
    std::cin>>length;
    int start = 0;
    int end = length-1;

    while(start<=end) {
        int mid = start + (end-start)/2;  // not exceeding integer numbers 

        if(target==arr[mid]) {
            return mid;
        }
        else if(target>arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}
int main() {
    int arr[] = {-3,-1,0,6,8,9,11,15};
    int target = -6;
    int ans = BinarySearch(arr,target);
    std::cout<<ans<<endl;
    return 0;
}