#include <iostream>
using namespace std ;

struct LL {
    struct node {
        int data ;
        node *next;
    };
    node *head = nullptr;
    node *tail = nullptr;
    //insert first element
    void insert_first (int x) {
        node *a = new node ;
        a->next = nullptr;
        a->data = x;
        if(head==nullptr) {
            head = a;
            tail = a;
        }
        else {
            a->next = head;
            head = a;
        }
    }
    //insert last element
    void insert_last (int x) {
        node *a = new node ;
        a->next = nullptr;
        a->data = x;
        if(head == nullptr) {
            head = a;
            tail = a;
        }
        else {
            tail->next = a;
            tail = a;
        }
    }
    //delete first element

    int delete_first () {
        if(head==nullptr) {
            return -1;
        }
        else if(head == tail) {
            int x = head->data;
            head = nullptr;
            tail = nullptr;
            return x;
        }
        else {
            int x = head->data;
            head = head->next;
            return x;
        }
    }
    //delete last element
    int delete_last() {
        node *temp = head;
        if(head == nullptr) {
            return -1;
        }
        else if(head == tail) {
            int x = head->data;
            head = nullptr;
            tail = nullptr;
            return x;
        }
        else {
            while(temp->next->next!=nullptr) {
                temp = temp->next;
            }
            node *p = temp->next;
            int x = temp->next->data;
            temp->next = nullptr;
            tail = temp;

            delete p;
            return x;
        }
    }
    //sorting
    void sort() {
        node *b = head;
        while(b) {
            node *c = b->next;
            while(c) {
                if(b->data>c->data) {
                    int temp = b->data;
                    b->data = c->data;
                    c->data = temp;
                }
                c = c->next;
            }
            b = b->next;
        }
        
    }
    
    //reversing linked list
    node *reverse(node *head) {
        node *prev = nullptr;
        node *current = head;
        node *forward;
      while(current!=nullptr) {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
      }
      return prev;
    }
    //middle of ll 
    int middle(node *head) {
        node *fast = head;
        node *slow = head;
        while(fast!=nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;

    }
    //another approach
    node *mid(node *head, node*slow, node *fast) {
        if(fast==nullptr || fast->next== nullptr) {
            return slow;
        }
        return mid(head,slow->next,fast->next->next);
    }
    node *printMid(node *head) {
        return mid(head,head,head);
    }
    //summation of linked list elements
    int sum() {
        int total = 0;
        node *current = head;
        while (current != nullptr) {
            total += current->data;
            current = current->next;
        }
        return total;
    }
    //multiplication of linked list elements
    int multiply() {
        int total = 1;
        node *p = head;
        while(p) {
            total *= p->data;
            p = p->next;
        }
        return total;
    }
    //displaying linked list

    void display() {
        node *p = head;
        while (p) {
            std::cout<<p->data<<" ";
            p = p->next;
        }
        std::cout<<endl;
    }
    //destructing nodes
    ~LL() {
        node *p = head;
        while(p) {
            node *temp = p;
            p = p->next;
            delete temp;
        }
    }
};
int main() {
    LL list;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int inputs;
        std::cin>>inputs;
        list.insert_first(inputs);
        list.insert_last(inputs);
        }

        list.display();
        cout<<endl;
    
    for(int i=0;i<n;i++) {
        int deletedVal = list.delete_first();
        std::cout<<deletedVal<<" ";
    }
    std::cout<<endl;
       list.display();

       list.sort();
       list.display();
       list.head = list.reverse(list.head);
       list.display();
       int mid = list.middle(list.head);
       cout<<mid<<endl;
       LL:: node *middle = list.printMid(list.head);
       cout<<middle->data<<endl;
       int totalSum = list.sum();
       cout << "Sum of Elements: " << totalSum << endl;
         int totalMultiply = list.multiply();
         cout << "Multiplication of Elements: " << totalMultiply << endl;


       return 0;
    
}