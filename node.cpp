#include<iostream>
#include<string>

using namespace std;

class Node
{
    public:
    int rollno;
    string name;
    Node* next;
        
};

class LinkedList
{
    private:
    Node* head;

    public:
    LinkedList(){
        head=nullptr;
    }
    Node* createnode(){
        int rollno;
        string name;
        cout<<"Enter roll no: ";
        cin>>rollno;
        cout<<"Enter name: ";
        cin>>name;
        Node* newnode=new Node();
        newnode->rollno=rollno;
        newnode->name=name;
        newnode->next=nullptr;
        return newnode;
    }

    void insert_atfirst(){
        Node* newnode=createnode();
        if (head == nullptr)
        {
            head=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }

    void incert_atlast(){
        Node *newnode=createnode();
        if (head == nullptr)
        {
            head=newnode;
        }
        else
        {
            Node* temp=head;
            while (temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }

    void display(){
        if (head == nullptr)
        {
            cout<<"Linked list is empty"<<endl;
            system("pause");
            return;
        }
        else{
            Node* temp=head;
            while (temp!=nullptr)
            {
                cout<<"Roll no is: "<<temp->rollno<<" "<<"\n Name is: "<<temp->name<<"\n ";
                temp=temp->next;
            }
            cout <<"Null ptr"<<endl;
        }
        system("pause");
    }

    void dell_first(){
        if (head == nullptr){
            cout <<"Linked list is empty"<<endl;
            system("pause");
            return;
        }
        else{
            Node* temp=head;
            head =head->next;
            delete temp;
        }
    }

    void dell_atlast(){
        if (head == nullptr){
            cout <<"Linked list is empty"<<endl;
            system("pause");
            return;
        }
        else{
            Node* current = head;
            while (current->next->next!=nullptr)
            {
                current=current->next;
            }
            delete current->next;
            current->next=nullptr;
        }
    }
};

int main()
{
    LinkedList mylist;
    while(1){
        system("cls");
        cout<<"===============Linked List================\n"
        <<"                                            \n"
        <<"1. Inseart at first\n"
        <<"2. Inseart at last\n"
        <<"3. Display\n"
        <<"4. Delete at first\n"
        <<"5. Delete at last\n"
        <<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            mylist.insert_atfirst();
            break;
        case 2:
            mylist.incert_atlast();
            break;
        case 3:
            mylist.display();
            break;
        case 4:
            mylist.dell_first();
            break;
        case 5:
            mylist.dell_atlast();
            break;
        default:
            break;
        }
    }

    return 0;
}