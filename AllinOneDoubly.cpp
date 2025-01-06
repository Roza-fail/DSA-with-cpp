
#include<iostream>

using namespace std;

struct ll{

    struct Node{
        int data;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;
    Node* tail = NULL;

    void insert(int x){
        Node* a = new Node();
        a->data = x;
        a->next = NULL;
        a->prev = NULL;

        if(head == NULL){
            head = a;
            tail = a;
        }else{
            tail->next = a;
            a->prev = tail;
            tail = a;
        }
    }

    void print(){
        Node* a = head;
        while(a != NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
    }

    void insert_atHead(int x){
        Node* a = new Node();
        a->data = x;
        a->next = head;
        a->prev = NULL;
        head->prev = a;
        head = a;
    }

    void insert_atTail(int x){
        Node* a = new Node();
        a->data = x;
        a->next = NULL;
        a->prev = tail;
        tail->next = a;
        tail = a;
    }

    void insert_atPos(int x, int pos){
        Node* a = new Node();
        a->data = x;
        a->next = NULL;
        a->prev = NULL;

        Node* a1 = head;
        for(int i=0; i<pos-2; i++){
            a1 = a1->next;
        }

        a->next = a1->next;
        a1->next->prev = a;
        a1->next = a;
        a->prev = a1;
    }

    void delete_atHead(){
        Node* a = head;
        head = head->next;
        head->prev = NULL;
        delete a;
    }

    void delete_atTail(){


        Node* a = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete a;
    }

    void delete_atPos(int pos){
        Node* a = head;
        for(int i=0; i<pos-2; i++){
            a = a->next;
        }



        Node* a1 = a->next;
        a->next = a1->next;
        a1->next->prev = a;

        delete a1;

    } 
    void reverse(){
        Node* temp = head;
        while(temp != NULL){
            Node* temp1 = temp->next;
            temp->next = temp->prev;
            temp->prev = temp1;
            temp = temp1;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
};  



int main(){
    int n;
    cin>>n;

    ll l;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        l.insert(x);
    }

    l.print();

    l.insert_atHead(10);
    cout<<endl;
    l.print();

    l.insert_atTail(20);
    cout<<endl;
    l.print();

    l.insert_atPos(30, 3);

    cout<<endl;

    l.print();

    l.delete_atHead();
    cout<<endl;

    l.print();

    l.delete_atTail();

    cout<<endl;

    l.print();

    l.delete_atPos(3);

    cout<<endl;

    l.print();
    cout<<endl;
    l.reverse();

    l.print();
    

    return 0;

}