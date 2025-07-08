/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
    int height(Node* node, bool* bl){
        if (node == nullptr) return 0;
        int lh = height(node->left, bl);
        int rh = height(node->right, bl);
        int absDiff = lh > rh ? lh - rh : rh - lh;
        if (absDiff > 1){
            *bl = false;
        }
        return 1 + max(lh, rh);
    }
    bool isBalanced(Node* root) {
        if (root == nullptr) return false;
        bool bl = true;
        height(root, &bl);
        return bl;
    }
};