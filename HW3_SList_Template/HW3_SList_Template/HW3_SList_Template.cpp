//
//  main.cpp
//  HW3_SList_Template
//
//  Created by Natalie Hill on 10/17/22.
//

//
// This is the template for HW3.
// We will implement a singly linked list (SLL) class and sort it.
//
// The node class is defined for you.
// The singly linked list (SLL) class is partly defined.
// Do not change the existing definitions.
//
// You have two major tasks:
// 1. Complete five member functions of the SLL class.
// 2. Complete merge sort based on the SLL data structure.
// Detailed instructions are given below.
//
// Tip: to facilitate debugging, you may first implement a simple
// add function (e.g., only add to head). This allows you to quickly
// construct a list and test/debug other functions.
//
//
#include <vector>
#include <iostream>
using namespace std;
// -----------------------
// -----------------------
// Node Class Definition
// -----------------------
// -----------------------
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
// -------------------------------------
// -------------------------------------
// Singly Linked List Class Definition
// -------------------------------------
// -------------------------------------
// The following is a partly defined singly linked class.
// Its only private member is a head pointer -- you cannot add others.
// It has multiple public member functions.
// Four member functions are given to you.
// Your job is to complete the following five member functions:
//
// *************
// 1. GetSize()
// *************
// This function returns the number of nodes in the list.
// Below is an example.
//
// Example:
// If list = 5, 7, 1, 3,
// then GetSize() returns 4.
//
//
// *************************
// 2. LinearSearch(int key)
// *************************
// This function performs linear search on the list with the given key.
// If key is not found or the list is empty, return -1.
// If key is found, return location of the node holding that key.
// Location will start from 0 and ends at n-1.
// Below is an example.
//
// Example:
// If list = 5, 7, 1, 3, then
// LinearSearch(5) returns 0.
// LinearSearch(1) returns 2.
// LinearSearch(10) returns -1.
//
//
// *************************
// 3. Add(int val, int idx)
// *************************
// This function adds a node with data "val" at location "idx".
// Here, "idx" starts from 0 (head node) and ends at n-1 (tail node).
// If the input "idx" is bigger than n-1, then add node to the tail.
// Below are three examples.
//
// Example 1:
// If list = 5, 7, 1, 2.
// If we run Add(3,2),
// then new list = 5, 7, 3, 1, 2.
//
// Example 2:
// If list = 5, 7, 1, 2.
// If we run Add(3,0),
// then new list = 3, 5, 7, 1, 2.
//
// Example 3:
// If list = 5, 7, 1, 2.
// If we run Add(3,7)
// then new list = 5, 7, 1, 2, 3.
// (Here, "7" is bigger than n-1, so add "3" to the tail.)
//
//
// *******************
// 4. Remove(int idx)
// *******************
// This function removes the node at location "idx".
// Here, "idx" starts from 0 (head node) and ends at n-1 (tail node).
// If the input "idx" is bigger than n-1, then remove the tail.
// Below are three examples.
//
// Example 1:
// If list = 5, 7, 1, 2.
// If we run Remove(0),
// then new list = 7, 1, 2.
//
// Example 2:
// If list = 5, 7, 1, 2.
// If we run Remove(2),
// then new list = 5, 7, 2.
//
// Example 3:
// If list = 5, 7, 1, 2.
// If we run Remove(7),
// then new list = 5, 7, 1.
// (Here, "7" is bigger than n-1, so remove the tail. )
//
//
// *************
// 5. Reverse()
// *************
// This function reverses the current list.
// If the list is empty or contains only one node, do nothing.
// Below are three examples.
//
// Example 1:
// If list is empty.
// If we run Reverse(),
// then new list is empty.
//
// Example 2:
// If list = 5.
// If we run Reverse(),
// then new list = 5.
//
// Example 3:
// If list = 5, 7, 1, 2.
// If we run Reverse(),
// then new list = 2, 1, 7, 5.
//
//
class SList {
private:
    Node* head;
public:
    // The following four functions are given to you.
    // The SetHead and GetHead functions are only useful for merge sort.
    SList();
    void Print();
    void SetHead(Node* ptr);
    Node* GetHead();
    // You need to complete the following five functions.
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
//
// -----------
// Merge Sort
// -----------
// The following is an incomplete merge sort function.
// Its input is the head pointer of a singly linked list.
// Its output is the head pointer of the sorted list.
// We will test this function in the following way:
// First, use your SList class to generate a singly linked list.
// Then, retrive its head pointer and pass it to the merge sort function.
// Finally, get a new head pointer of the sorted list, pass it back to the list
// class and print it.
// You can see the testing code in the main function (mode = 7)
// .........
// Your task is to design and implement this merge sort function
// based on the singly linked list data structure.
// No array or vector can be used.
// Tip: it should be recursive.
//


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
    //
    // The main function is given to you.
    // It first constructs a singly linked list.
    // It then tests your implemented member functions
    // and the merge sort function.
    //
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
