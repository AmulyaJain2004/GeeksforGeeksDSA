//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// A node of the doubly linked list
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end
// of the Doubly Linked List
Node *push(Node *tail, int new_data) {
    // Allocate node
    Node *newNode = new Node(new_data);

    // Since we are adding at the end, next is NULL
    newNode->next = NULL;

    // Make newNode's previous pointer point to the current tail
    newNode->prev = tail;

    // If the tail is not null, link it to the new node
    if (tail != NULL)
        tail->next = newNode;

    // Return the new node as the new tail
    return newNode;
}

bool verifyDLL(Node *head) {
    int c1 = 0;
    Node *tmp = head;
    while (tmp->next) {
        c1++;
        tmp = tmp->next;
    }
    int c2 = 0;
    while (tmp->prev) {
        c2++;
        tmp = tmp->prev;
    }
    return c1 == c2;
}

// Function to print nodes in a given doubly linked list
void printList(Node *head) {
    // If list is empty
    if (head == NULL)
        return;
    if (!verifyDLL(head))
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if (head == NULL){
            return nullptr;
        }
        Node* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            if(cnt == x){
                break;
            }
            temp=temp->next;
        }
        Node* front = temp->next;
        Node* prev = temp->prev;
        if (prev == NULL && front == NULL){
            delete temp;
            return nullptr;
        }
        else if (prev == NULL){
            head = front;
            head->prev = NULL;
            front = NULL;
            delete temp;
            return head;
        }
        else if (front == NULL){
            prev->next = NULL;
            temp->prev = NULL;
            delete temp;
            return head;
        }
        // both are not null
        prev->next = front;
        front->prev = prev;
        front = NULL;
        prev = NULL;
        delete temp;
        return head;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            tail = push(tail, arr[i]);
        }

        int x;
        cin >> x;
        cin.ignore();

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        cout << "\n";
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends