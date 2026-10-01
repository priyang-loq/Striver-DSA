#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
        back = NULL;
    }

};

Node* conArray2DLL(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i],NULL,prev);
        prev -> next = temp;
        prev = temp;
    }
    
    return head;
}

Node* traverse(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

int main(){
    vector<int> arr = {2,3,4,5,6};

    Node* head = conArray2DLL(arr);
    traverse(head);


    return 0;
}