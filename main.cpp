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
    void deletePosition();
    void editData();
    void swapNodes();
    void sortList();
    void clearList();
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
    }while(option!=0);
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

void DLinkedList::deletePosition(){
    int pos;
    cout<<"Position: "; cin>>pos;
    if(head->data == pos){
        head = head->next;
    }else if(tail->data == pos){
        tail->prev->next = NULL;
        tail = tail->prev;
    }else{
        Node * control = new Node();
        control = head;
        while(control){
            if(control->data == pos){
                control->next->prev = control->prev;
                control->prev->next = control->next;
                break;
            }
            control = control->next;
        }
    }
    list_size--;
}

void DLinkedList::editData(){
    int pos, new_data;
    cout<<"Position: "; cin >> pos;
    cout<<"New data: "; cin >> new_data;
    Node * control = new Node();
    control = head;
    while(control){
        if(control->data == pos){
            control->data = new_data;
            break;
        }
        control = control->next;
    }
}

void DLinkedList::swapNodes(){ // can be optimized!!!!!!!
    int pos1, pos2;
    cout << "First position: "; cin >> pos1;
    cout << "Second position: "; cin >> pos2;
    Node * temp1 = new Node();
    Node * temp2 = new Node();
    Node * temp = new Node();
    Node * control = new Node();
    control = head;
    while(control){
        if(control->data == pos1){
            temp1 = control;
        }else if(control->data == pos2){
            temp2 = control;
        }
        control=control->next;
    }
    temp1->prev->next = temp2;
    temp1->next->prev = temp2;
    temp2->prev->next = temp1;
    temp2->next->prev = temp1;
    temp = temp1;
    temp1 = temp2;
    temp2 = temp;
    // Resolve error(s) does not work!!!
}

void DLinkedList::sortList(){
    Node * control = new Node();
    control = head; //TODO

}

void DLinkedList::clearList(){
    head = NULL;
    tail = NULL;
    list_size = 0;
}

void printMenu(){
    cout<<"Options List:\n1- Add to top\n2- Add to end\n3- Delete top\n"
    <<"4- Delete end\n5- Add after position\n6- Add before position\n7- Delete position\n"
    <<"8- Edit data\n9- Swap nodes\n10- Sort list\n11- Clear list\n12- Print list\n0- Exit\nYour option: ";
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
        case 7: some_list->deletePosition();
        break;
        case 8: some_list->editData();
        break;
        case 9: some_list->swapNodes();
        break;
        case 10: some_list->sortList();
        break;
        case 11: some_list->clearList();
        break;
        case 12: some_list->printList();
        break;
        case 0: cout<<"\nBye bye!\n"; break;
        default:
            cout<<"Incorrect input!\n";
    }
}

