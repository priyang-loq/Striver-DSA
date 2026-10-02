#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
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

Node *conArray2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node *removeKthElement(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    int cnt = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;

        if (cnt == k)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }

    else if (prev == NULL)
    {
        return deleteHead(head);
    }

    else if (front == NULL)
    {
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;

    temp->next = NULL;
    temp->back = NULL;

    return head;
}

void deleteNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = NULL;
        temp->back = NULL;
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->back = temp->next = NULL;
    free(temp);
}

Node *insertBeforeHead(Node *head, int val)
{
    Node *newNode = new Node(val, head, NULL);
    head->back = newNode;

    return newNode;
}

Node *insertBeforeTail(Node *head, int val)
{
    if (head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node *prev = tail->back;

    Node *newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};

    Node *head = conArray2DLL(arr);
    // head = deleteHead(head);
    // head = removeKthElement(head,2);
    // deleteNode(head->next);

    head = insertBeforeTail(head, 1);
    traverse(head);

    return 0;
}