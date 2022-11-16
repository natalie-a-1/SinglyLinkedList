#include <vector>
#include <iostream>
using namespace std;
class Node {
private:
    int data;
    Node* link_next;
public:
    void SetData(int x);
    int GetData();
    void SetLink_Next(Node* ptr);
    Node* GetLink_Next();
    Node();
};
Node::Node() {
    data = 0;
    link_next = NULL;
}
void Node::SetData(int x) {
    data = x;
}
int Node::GetData() {
    return data;
}
void Node::SetLink_Next(Node* ptr) {
    link_next = ptr;
}
Node* Node::GetLink_Next() {
    return link_next;
}
class SList {
private:
    Node* head;
public:
    SList();
    void Print();
    void SetHead(Node* ptr);
    Node* GetHead();
    int GetSize();
    int LinearSearch(int key);
    void Add(int val, int idx);
    void Remove(int idx);
    void Reverse();
};

int SList::LinearSearch(int key) {
    int size = GetSize() -1;
    Node* current = GetHead();
    for (int i = 0; i < size; i++) {
        if (current->GetData() == key) {
            return i;
        }
        current = current->GetLink_Next();
    }
    return -1;
}


void SList::Add(int val, int idx) {
    Node* newNode = new Node();
    newNode->SetData(val);
    int count = 0;
    
    if (idx == 0) {
        newNode->SetLink_Next(GetHead());
        SetHead(newNode);
    }
    else if (GetSize() < idx) {
        Node* current = GetHead();
        while (current->GetLink_Next() != NULL) {
            current = current->GetLink_Next();
        }
        current->SetLink_Next(newNode);
    }
    else {
        Node* current = GetHead();
        Node* previous = new Node();
        while (current->GetLink_Next() != NULL && count != idx) {
            previous = current;
            current = current->GetLink_Next();
            count++;
        }
        previous->SetLink_Next(newNode);
        newNode->SetLink_Next(current);
    }
}
void SList::Remove(int idx) {
    if (idx == 0) {
        Node* temp = GetHead();
        head = head->GetLink_Next();
        delete temp;
    }
    else if (GetSize() < idx) {
        Node* current = GetHead();
        while (current->GetLink_Next()->GetLink_Next() != NULL) {
            current = current->GetLink_Next();
        }
        current->SetLink_Next(NULL);
    }
    else {
        Node* previous = new Node();
        Node* current = GetHead();
        for (int i = 0; i < idx; i++) {
            previous = current;
            current = current->GetLink_Next();
        }
        previous->SetLink_Next(current->GetLink_Next());
        delete current;
    }
}

void SList::Reverse() {
    if (GetHead() == NULL) {
        return;
    }
    Node* current = GetHead();
    Node* previous = NULL;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->GetLink_Next();
        current->SetLink_Next(previous);
        previous = current;
        current = next;
    }
    SetHead(previous);
}
int SList::GetSize() {
    int count = 0;
    Node* iterator = GetHead();
    while (iterator != NULL) {
        count++;
        iterator = iterator->GetLink_Next();
    }
    return count;
}

SList::SList() {
    head = NULL;
}
void SList::Print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->GetData() << endl;
        temp = temp->GetLink_Next();
    }
}
Node* SList::GetHead() {
    return head;
}
void SList::SetHead(Node* ptr) {
    head = ptr;
}
Node* MergeList(Node* a, Node* b) {
    Node* newHead = NULL;
    Node *tail=NULL;
    if (a->GetData() <= b->GetData()) {
        newHead = a;
        a = a->GetLink_Next();
    }
    else {
        newHead = b;
        b = b->GetLink_Next();
    }
    tail=newHead;
       
    while(a!=NULL && b!=NULL)
    {
        if (a->GetData() <= b->GetData()) {
            tail->SetLink_Next(a);
            a = a->GetLink_Next();
        }
        else {
            tail->SetLink_Next(b);
            b=b->GetLink_Next();
        }
        tail=tail->GetLink_Next();
        }

        if(a!=NULL)
        {
            tail->SetLink_Next(a);
        }
        if(b!=NULL)
        {
            tail->SetLink_Next(b);
        }

        return newHead;
}
Node* middle(Node *head) {
    Node *mid = head;
    Node *tail = head->GetLink_Next();
   
    while(mid->GetLink_Next()!= NULL && (tail!=NULL && tail->GetLink_Next()!=NULL)) {
        mid = mid->GetLink_Next();
        tail = tail->GetLink_Next()->GetLink_Next();
    }
    return mid;
}

Node* MergeSort(Node* ptr) {
    if (ptr == NULL || ptr->GetLink_Next() == NULL) {
        return ptr;
    }
    Node* mid = new Node();
    mid = middle(ptr);
    
    Node* ptr2 = mid->GetLink_Next();
    mid->SetLink_Next(NULL);
    
    Node *newHead = MergeList(MergeSort(ptr),MergeSort(ptr2));
    return newHead;
}

int main()
{
    SList x;
        int mode, value, temp, idx, key;
        cin >> mode >> value >> idx >> key;
        for (int i = 0; i < 4; i++) {
            cin >> temp;
            x.Add(temp,0);
        }
        switch (mode) {
        case 1: // check your add function with idx = 0
            x.Print();
            break;
        case 2: // check your GetSize function
            cout << x.GetSize();
            break;
        case 3: // check your LinearSearch function
            cout << x.LinearSearch(key);
            break;
        case 4: // check your add function with arbirary idx
            x.Add(value, idx);
            x.Print();
            break;
        case 5: // check your remove function
            x.Remove(idx);
            x.Print();
            break;
        case 6: // check your reverse function
            x.Reverse();
            x.Print();
            break;
        case 7: // check your merge sort function
            x.SetHead(MergeSort(x.GetHead()));
            x.Print();
            break;
        }
        return 0;
    }
