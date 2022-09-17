#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data, height;
    TreeNode*left, *right;
    TreeNode(){
        left=right=NULL;
    }
    TreeNode(int d){
        data = d;
        left=right=NULL;
        height = 1;
    }
};
int getHeight(TreeNode*root){
    if(root==NULL) return 0;
    return root->height;
}
int getBalanceFactor(TreeNode*node){
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* rotateRight(TreeNode*z){
    TreeNode*y = z->left;
    TreeNode*T3 = y->right;
    
    y->right = z;
    z->left = T3;

    z->height = 1+max(getHeight(z->left), getHeight(z->right));
    y->height = 1+max(getHeight(y->left), getHeight(y->right));

    return y;
}
TreeNode* rotateLeft(TreeNode*y){
    TreeNode*z = y->right;
    TreeNode*T3 = z->left;
    
    z->left = y;
    y->right = T3;

    z->height = 1+max(getHeight(z->left), getHeight(z->right));
    y->height = 1+max(getHeight(y->left), getHeight(y->right));

    return z;
}

TreeNode* insert(TreeNode*root, int data){
    if(root==NULL){
        root = new TreeNode(data);
        return root;
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);
    if(bf > 1 && data < root->left->data){
        //LL ROTATION-> rotate right
        root = rotateRight(root);
    }else if(bf < -1 && data > root->right->data){
        //RR ROTATION-> rotate left
        root = rotateLeft(root);
    }else if(bf > 1 && data > root->left->data){
        //LR ROTATION-> left then right
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }else if(bf < -1 && data < root->right->data){
        //RL ROTATION
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}
void print(TreeNode*root){
    if(root==NULL) return;
    cout<<root->data<<endl;
    print(root->left);
    print(root->right);
}
TreeNode* inorderPredecessor(TreeNode*root){
    if(root->left == NULL) return NULL;
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}
TreeNode* inorderSuccessor(TreeNode*root){
    if(root->right == NULL) return NULL;
    root = root->right;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
TreeNode* deleteNode(TreeNode*root, int data){
    //find this data first
    if(root == NULL){
        return NULL;
    }
    if(data < root->data){
        root->left = deleteNode(root->left,data);
    }else if(data > root->data){
        root->right = deleteNode(root->right,data);
    }else{
        //we have found the target node
        TreeNode*inPre = inorderPredecessor(root);
        if(inPre == NULL){
            TreeNode*inSucc = inorderSuccessor(root);
            if(inSucc == NULL){
                //it is a leaf node
                delete root;
                return NULL;
            }else{
                root->data = inSucc->data;
                root->right = deleteNode(root->right, inSucc->data);
            }
        }else{
            root->data = inPre->data;
            root->left = deleteNode(root->left, inPre->data);
        }
    }
    root->height = 1+max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);
    if(bf > 1 && getBalanceFactor(root->left) >= 0){
        //LL ROTATION-> rotate right
        root = rotateRight(root);
    }else if(bf < -1 && getBalanceFactor(root->right) < 0){
        //RR ROTATION-> rotate left
        root = rotateLeft(root);
    }else if(bf > 1 && getBalanceFactor(root->left)<0){
        //LR ROTATION-> left then right
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }else if(bf < -1 && getBalanceFactor(root->right) >= 0){
        //RL ROTATION
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}
void printKthLargestElement(TreeNode*root, int k){
    static int cnt=0;
    if(root==NULL){
        return;
    }
    printKthLargestElement(root->right,k);
    cnt++;
    if(cnt == k){
        cout<<root->data;
    }else if(cnt > k){
        return;
    }else{
        printKthLargestElement(root->left,k);
    }
    return;
}
void printkthSmallestElement(TreeNode*root, int k){
    static int cnt = 0;
    if(root==NULL){
        return;
    }
    printkthSmallestElement(root->left,k);
    cnt++;
    if(cnt == k){
        cout<<root->data;
        return;
    }else if(cnt>k){
        return;
    }else{
        return printkthSmallestElement(root->right,k);
    }
}
int main(){
    TreeNode*root = NULL;
    root = insert(root,12);
    root = insert(root,11);
    root = insert(root,10);
    root = insert(root,9);
    root = insert(root,8);
    root = insert(root,7);
    root = insert(root,6);
    printkthSmallestElement(root,1);
    return 0;
}