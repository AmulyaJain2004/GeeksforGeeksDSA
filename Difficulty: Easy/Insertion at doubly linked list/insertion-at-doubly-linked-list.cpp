/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* temp = head;
        int count = 1;
        while (temp->next != nullptr) {
            if (count-1 == p) {
                break;
            }
            count ++;
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            Node* newNode = new Node(x);
            newNode->prev = temp;
            temp->next = newNode;
            return head;
        }
        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
        return head;
    }
};