/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        if (root == nullptr) return {};
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right); 
                temp.push_back(node->data);
            }
            ans.push_back(temp);
        }
        reverse (ans.begin(), ans.end());
        vector<int> finalAns;
        for (int i = 0; i < ans.size(); i++){
            for (int j = 0; j < ans[i].size(); j ++){
                finalAns.push_back(ans[i][j]);
            }
        }
        return finalAns;
    }
};