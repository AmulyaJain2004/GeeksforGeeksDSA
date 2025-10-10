/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        // First we will detect the loop'
        // then we will count the length of loop
        Node* slow = head;
        Node* fast = head;
        while (fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
            if (slow == fast){
                int count = 1;
                fast = fast->next;
                while(slow!=fast){
                    count ++;
                    fast = fast->next;
                }
                return count;
            }
        }
        return 0;
    }
};