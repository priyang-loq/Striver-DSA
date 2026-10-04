#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int value) {
        data = value;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == NULL) return NULL;

        // Find length
        int length = 0;
        ListNode* current = head;

        while (current != NULL) {
            length++;
            current = current->next;
        }

        // If deleting head
        if (n == length) {
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;
            return head;
        }

        // Find node just before the node to delete
        int index = length - n;
        int cnt = 1;

        ListNode* temp = head;

        while (temp != NULL) {

            if (cnt == index) {

                ListNode* deleteNode = temp->next;

                temp->next = deleteNode->next;

                delete deleteNode;

                break;
            }

            cnt++;
            temp = temp->next;
        }

        return head;
    }
};
// Function to create linked list from array.
ListNode* createList(vector<int>& arr) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int value : arr) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

// Function to print linked list values.
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " ";
        current = current->next;
    }
}

// Driver code.
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* head = createList(arr);
    Solution sol;
    head = sol.removeNthFromEnd(head, n);
    printList(head);
    return 0;
}