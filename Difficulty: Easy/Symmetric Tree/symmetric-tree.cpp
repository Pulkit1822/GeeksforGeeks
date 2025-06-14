/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
        bool helper(Node* leftnode,Node* rightnode){
        if(!leftnode && rightnode) return false;
        if(leftnode && !rightnode) return false;
        if(!leftnode && !rightnode) return true;
        if(leftnode->data!=rightnode->data) return false;
        
        Node* a=leftnode->left,*b=leftnode->right;
        Node* c=rightnode->left,*d=rightnode->right;
        
        bool res1=helper(a,d),res2=helper(b,c);
        if(!res1) return false;
        if(!res2) return false;
        
        return true;
    }
  
    bool isSymmetric(Node* root) {
        // Code here
        if(!root) return true;
        Node* leftnode=root->left,*rightnode=root->right;
        return helper(leftnode,rightnode);
    }
};