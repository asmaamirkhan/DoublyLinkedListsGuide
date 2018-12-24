#include <iostream>

using namespace std;

class Node{
    int data;
    Node * prev = NULL;
    Node * next = NULL;
    friend class DLinkedList;
};

class DLinkedList{
    Node * head = new Node;
    Node * tail = new Node;
    int list_size = 0;
    public:
    void printList();
    void addToTop();
    void addToEnd();
    void deleteTop();
    void deleteEnd();
    void addAfterPosition();
    void addBeforePosition();
};

void printMenu();
void doOperation(int, DLinkedList*);
int main()
{
    DLinkedList * my_list = new DLinkedList();
    int option = 0;
    do{
        printMenu();
        cin>>option;
        doOperation(option, my_list);
    }while(option!=8);


}

void DLinkedList::printList(){
    if(!list_size){
        cout<<"\nThe list is empty!\n\n";
    }else{
        cout<<"\nYour list:\n\n";
        Node * control = new Node();
        control = head;
        int counter = 1;
        while(control){
            cout<<counter<<". element's data: "<<control->data<<endl;
            control = control->next;
            counter++;
        }
        cout<<"List size: "<<list_size<<endl<<endl;
    }
}

void DLinkedList::addToTop(){
    int data;
    cout<<"\nData: ";
    cin>>data;
    Node * new_node = new Node();
    new_node->data = data;
    if(!list_size){
        head = tail = new_node;
    }else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    list_size++;
}

void DLinkedList::addToEnd(){
    int data;
    cout<<"\nData: ";
    cin>>data;
    Node * new_node = new Node();
    new_node->data = data;
    if(!list_size){
        head = tail = new_node;
    }
    else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    list_size++;
}

void DLinkedList::deleteTop(){
    head = head->next;
    list_size--;
}

void DLinkedList::deleteEnd(){
    tail->prev->next = NULL;
    tail = tail->prev;
    list_size--;
}

void DLinkedList::addAfterPosition(){
    int pos, data;
    cout<<"Position: "; cin>>pos;
    cout<<"Data: "; cin>>data;
    Node * new_node = new Node();
    new_node->data = data;
    Node * control = new Node();
    control = head;
    while(control){
        if(control->data == pos){
            new_node->prev = control;
            new_node->next = control->next;
            control->next->prev = new_node;
            control->next = new_node;
            list_size++;
            break;
        }
        control = control->next;
    }
}

void DLinkedList::addBeforePosition(){
    int pos, data;
    cout<<"Position: "; cin>>pos;
    cout<<"Data: "; cin>>data;
    Node * new_node = new Node();
    new_node->data = data;
    Node * control = new Node();
    control = head;
    while(control){
        if(control->next->data == pos){
            new_node->prev = control;
            new_node->next = control->next;
            control->next->prev = new_node;
            control->next = new_node;
            list_size++;
            break;
        }
        control = control->next;
    }
}

void printMenu(){
    cout<<"Options List:\n1- Add to top\n2- Add to end\n3- Delete top\n"
    <<"4- Delete end\n5- Add after position\n6- Add before position\n7- Print list\n8- Exit\nYour option: ";
}

void doOperation(int option, DLinkedList * some_list){
    switch(option){
        case 1: some_list->addToTop();
        break;
        case 2: some_list->addToEnd();
        break;
        case 3: some_list->deleteTop();
        break;
        case 4: some_list->deleteEnd();
        break;
        case 5: some_list->addAfterPosition();
        break;
        case 6: some_list->addBeforePosition();
        break;
        case 7: some_list->printList();
        break;
        default:
            cout<<"Incorrect input!\n";
    }
}

