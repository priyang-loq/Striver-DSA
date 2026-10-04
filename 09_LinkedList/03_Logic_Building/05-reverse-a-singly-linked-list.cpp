#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to reverse linked list values using a stack.
    ListNode *reverseList(ListNode *head)
    {
        stack<int> values;
        ListNode *current = head;
        // Store all node values in LIFO order.
        while (current != nullptr)
        {
            values.push(current->val);
            current = current->next;
        }
        current = head;
        // Replace node values using stack top values.
        while (current != nullptr)
        {
            current->val = values.top();
            values.pop();
            current = current->next;
        }
        return head;
    }
};

// Function to create a linked list from an array.
ListNode *createList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int index = 1; index < (int)arr.size(); index++)
    {
        current->next = new ListNode(arr[index]);
        current = current->next;
    }
    return head;
}

// Function to print linked list values.
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val;
        if (current->next != nullptr)
            cout << " ";
        current = current->next;
    }
}

// Driver code.
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createList(arr);
    Solution sol;
    head = sol.reverseList(head);
    printList(head);
    return 0;
}