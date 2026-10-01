#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }

};

Node* conArrayLL(vector<int> &arr)
{
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    
    return head;
}

void traverse(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* deletekpostion(Node *head,int pos)
{
    if(head == NULL) return head;
    if(pos == 1)
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL)
    {
        cnt++;

        if(cnt == pos)
        {
            prev -> next = temp -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,3,4,5,6,7};

    Node* head = conArrayLL(arr);
    traverse(head);
    deletekpostion(head,3);
    traverse(head);


    return 0;
}