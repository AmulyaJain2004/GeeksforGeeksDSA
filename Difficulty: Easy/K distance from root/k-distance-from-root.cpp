/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(Node *root, int k) {
        // Your code here
        vector<int> result;
        if (!root) return result;
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (level == k) {
                while (size--) {
                    Node* node = q.front(); 
                    q.pop();
                    result.push_back(node->data);
                }
                break;
            }
            while (size--) {
                Node* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            level++;
        }
        return result;
    }
};