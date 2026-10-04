#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Solution {
public:
    // Segregate even and odd node values by collecting and rewriting.
    Node* segregate(Node* head) {
        // Return early for an empty list.
        if (head == nullptr) {
            return head;
        }

        // Store even values in encounter order.
        vector<int> evenValues;

        // Store odd values in encounter order.
        vector<int> oddValues;

        // Traverse the list once and collect values.
        Node* current = head;
        while (current != nullptr) {
            if (current->data % 2 == 0) {
                evenValues.push_back(current->data);
            } else {
                oddValues.push_back(current->data);
            }
            current = current->next;
        }

        // Reset traversal for value rewriting.
        current = head;

        // Write all even values first.
        for (int value : evenValues) {
            current->data = value;
            current = current->next;
        }

        // Write all odd values after even values finish.
        for (int value : oddValues) {
            current->data = value;
            current = current->next;
        }

        // Return the updated head.
        return head;
    }
};

// Build a linked list from an array.
Node* buildList(const vector<int>& values) {
    Node* dummy = new Node(0);
    Node* tail = dummy;

    for (int value : values) {
        tail->next = new Node(value);
        tail = tail->next;
    }

    return dummy->next;
}

// Print the linked list in one line.
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " ";
        }
        head = head->next;
    }
    cout << "\n";
}

// Run the array-based solution on a hard-coded sample.
int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6};
    Node* head = buildList(values);

    Solution solution;
    Node* answer = solution.segregate(head);

    printList(answer);
    return 0;
}
