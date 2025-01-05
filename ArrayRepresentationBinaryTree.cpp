#include <iostream>
using namespace std;
#define MAX 100

void insert(int tree[], int value, int &i) {
    if(i<MAX) {
        tree[i++] = value;

    }
    else {
        cout<<endl;
    }
}
void print(int tree[],int i) {
    for(int j=0;j<i;j++) {
        cout<<tree[j]<<" ";
    }
    cout<<endl;
}
void preorder(int tree[],int i) {
    if(i>=MAX || tree[i]==0) {
        return ;
    
    }
    else {
        cout<<tree[i]<<" ";
        preorder(tree,2*i+1);
        preorder(tree,2*i+2);
    }
}
void inorder(int tree[],int i) {
    if(i>=MAX || tree[i]==0) {
        return ;
    
    }
    else {
       
        inorder(tree,2*i+1);
         cout<<tree[i]<<" ";
        inorder(tree,2*i+2);
    }
}
void postorder(int tree[],int i) {
    if(i>=MAX || tree[i]==0) {
        return ;
    
    }
    else {
       
        postorder(tree,2*i+1);
         
        postorder(tree,2*i+2);
        cout<<tree[i]<<" ";
    }
}
int main() {
    int tree[MAX] = {0};
    int i=0;
    insert(tree,1,i);
    insert(tree,2,i);
    insert(tree,3,i);
    insert(tree,4,i);
    insert(tree,5,i);
    insert(tree,6,i);
    insert(tree,7,i);
    insert(tree,8,i);
    print(tree,i);
    cout<<endl;

    cout<<"Preorder traversal"<<endl;
    preorder(tree,0);
    cout<<endl;
    cout<<"Inorder traversal"<<endl;
    inorder(tree,0);
    cout<<endl;
    cout<<"Postorder traversal"<<endl;
    postorder(tree,0);
    cout<<endl;
    return 0;
}