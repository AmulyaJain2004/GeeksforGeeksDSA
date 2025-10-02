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
    Node* delPos(Node* head, int x) {
        // code here
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