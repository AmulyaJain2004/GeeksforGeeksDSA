//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};


// } Driver Code Ends
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        // if (head == NULL){
        //     Node* newNode = new Node(data);
        //     return newNode;
        // }
        // Node* temp = head;
        // if (temp->next == NULL){
        //     Node* newNode = new Node(data);
        //     newNode->prev = temp;
        //     temp->next = newNode;
        //     return head;
        // }
        // int cnt = 0;
        // while (temp!=NULL && temp->next!=NULL){
        //     if (cnt == pos){
        //         Node* newNode = new Node(data);
        //         newNode->next = temp->next;
        //         temp->next->prev = newNode;
        //         newNode->prev = temp;
        //         temp->next = newNode;
        //     }
        //     cnt++;
        //     temp = temp->next;
        // }
        // if (temp->next == NULL && cnt==pos){
        //     Node* newNode = new Node(data);
        //     newNode->prev = temp;
        //     temp->next = newNode;
        //     return head;
        // }
        // return head;
        
        // Optimised Code:
        if (head == NULL) return new Node(data);  // Handle empty list case

        Node* temp = head;
        int cnt = 0;

        // Traverse to the position just before 'pos'
        while (cnt < pos && temp->next != NULL) {
            temp = temp->next;
            cnt++;
        }

        // Create a new node
        Node* newNode = new Node(data);

        // Insert in the middle
        if (temp->next != NULL) {
            newNode->next = temp->next;
            temp->next->prev = newNode;
        }
        
        // Common insertion logic (works for both middle and end)
        newNode->prev = temp;
        temp->next = newNode;

        return head;
    }
};

//{ Driver Code Starts.

Node *insert(Node *head, int x) {
    if (head == NULL) {
        return new Node(x);
    }
    Node *n = new Node(x);

    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

void printList(Node *head) {
    // The purpose of below two loops is
    // to test the created DLL
    Node *temp = head;
    if (temp != NULL) {
        int ct1 = 0, ct2 = 0;
        while (temp->next != NULL)
            temp = temp->next, ct1++;
        while (temp->prev != NULL)
            temp = temp->prev, ct2++;
        if (ct1 != ct2) {
            cout << -1 << "\n";
            return;
        }
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after reading T to use getline properly

    while (t--) {
        Node *head = NULL;
        Node *root = NULL;
        vector<int> arr;
        string input;
        getline(cin, input);    // Read the entire line as input
        stringstream ss(input); // Use stringstream to split the input into integers
        int number;
        while (ss >> number) {
            arr.push_back(number); // Add each number to the vector
        }
        if (arr.empty()) {
            return NULL; // Return NULL if the vector is empty
        }
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            head = insert(head, x);
            if (root == NULL)
                root = head;
        }
        head = root;
        int pos, data;
        cin >> pos >> data;
        cin.ignore();
        Solution ob;
        head = ob.addNode(head, pos, data);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends