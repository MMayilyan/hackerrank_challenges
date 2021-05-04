#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

int getHeight(Node* root) {
    //Write your code here
    if (root->right == nullptr && root->left == nullptr) {
        return 0;
    }
    
    int height_right = 0;
    int height_left = 0;
    if (root->right) {
        height_right = getHeight(root->right);
    }
    if (root->left) {
        height_left = getHeight(root->left);
    }
    
    return 1 + max(height_right, height_left);
}

}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}
