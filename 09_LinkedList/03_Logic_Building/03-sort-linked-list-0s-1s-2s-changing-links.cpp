#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor to create a linked list node.
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to sort the linked list by relinking nodes.
    Node *sortList(Node *head)
    {
        // Return the same head for empty or single-node lists.
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Create dummy heads for the three value-based chains.
        Node zeroDummy(0);
        Node oneDummy(0);
        Node twoDummy(0);

        // Tail pointers keep O(1) append operations for each chain.
        Node *zeroTail = &zeroDummy;
        Node *oneTail = &oneDummy;
        Node *twoTail = &twoDummy;
        Node *current = head;

        // Detach each node and append into the matching list.
        while (current != nullptr)
        {
            // Save the next pointer before detaching the node.
            Node *nextNode = current->next;
            current->next = nullptr;

            if (current->data == 0)
            {
                zeroTail->next = current;
                zeroTail = zeroTail->next;
            }
            else if (current->data == 1)
            {
                oneTail->next = current;
                oneTail = oneTail->next;
            }
            else
            {
                twoTail->next = current;
                twoTail = twoTail->next;
            }

            current = nextNode;
        }

        // Connect non-empty lists in sorted order.
        zeroTail->next = (oneDummy.next != nullptr) ? oneDummy.next : twoDummy.next;
        oneTail->next = twoDummy.next;
        twoTail->next = nullptr;

        // Return the first non-empty chain as the final head.
        if (zeroDummy.next != nullptr)
        {
            return zeroDummy.next;
        }
        if (oneDummy.next != nullptr)
        {
            return oneDummy.next;
        }
        return twoDummy.next;
    }
};

// Function to build a linked list from an array.
Node *buildList(vector<int> &arr)
{
    // Return null for an empty input array.
    if (arr.empty())
    {
        return nullptr;
    }

    // Create the head node from the first value.
    Node *head = new Node(arr[0]);
    Node *tail = head;

    // Append the remaining values one by one.
    for (int index = 1; index < (int)arr.size(); index++)
    {
        tail->next = new Node(arr[index]);
        tail = tail->next;
    }

    return head;
}

// Function to print linked list values.
void printList(Node *head)
{
    Node *current = head;

    // Print every node value in sequence.
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            cout << " ";
        }
        current = current->next;
    }
    cout << "\n";
}

// Driver code.
int main()
{
    vector<int> arr = {1, 2, 0, 1, 2, 0, 1};
    Node *head = buildList(arr);

    Solution sol;
    head = sol.sortList(head);

    printList(head);
    return 0;
}