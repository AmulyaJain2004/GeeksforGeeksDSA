/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if (root == nullptr) return {};
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level.push_back(node->data);
            }
            ans.push_back(level[0]);
        }
        return ans;
    }
};