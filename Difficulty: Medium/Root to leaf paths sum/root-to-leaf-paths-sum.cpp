/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    void numPath(Node* root, int num, vector<int>& pathNum) {
        if (root == nullptr) return ;
        if (root != nullptr) {
            num = num*10 + root->data;
        }
        if (root->left == nullptr && root->right == nullptr) {
            pathNum.push_back(num);
        }
        numPath(root->left, num, pathNum);
        numPath(root->right, num, pathNum);
    }
    
    int treePathsSum(Node *root) {
        // code here.
        vector<int> pathNum;
        int sum = 0;
        numPath(root, 0, pathNum);
        for (int i: pathNum){
            sum += i;
        }
        return sum;
    }
};