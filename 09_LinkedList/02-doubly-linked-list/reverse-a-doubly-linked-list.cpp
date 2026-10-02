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

Node *convertArrayToDLL(vector<int> &arr)
{
    if (arr.empty())
        return NULL;

    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);

        temp->back = prev;
        prev->next = temp;

        prev = temp;
    }

    return head;
}

Node *reverseDLL(Node *head)
{
    Node *current = head;
    Node *temp = NULL;

    while (current != NULL)
    {
        // Swap next and back
        temp = current->back;
        current->back = current->next;
        current->next = temp;

        // Move to the next node in original DLL
        current = current->back;
    }

    // temp is the old back of the first node
    if (temp != NULL)
        head = temp->back;

    return head;
}

void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = convertArrayToDLL(arr);

    cout << "Original DLL: ";
    printDLL(head);

    head = reverseDLL(head);

    cout << "\nReversed DLL: ";
    printDLL(head);

    return 0;
}