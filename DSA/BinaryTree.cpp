#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode*left,*right;
    TreeNode(){
        left=right=NULL;
    }
    TreeNode(int data){
        this->data = data;
        left=right=NULL;
    }
};
TreeNode* buildBST(TreeNode*root, int data){
    if(root==NULL){
        root = new TreeNode(data);
        return root;
    }
    if(data < root->data){
        root->left = buildBST(root->left,data);
    }else if(data > root->data){
        root->right = buildBST(root->right,data);
    }
    return root;
}
TreeNode* buildTree(int preOrder[], int inOrder[], int inL, int inR, int n){
    //create Node
    if(inL>inR){
        return NULL;
    }
    static int preIndex=0;
    TreeNode*root = new TreeNode(preOrder[preIndex]);
    int inIndex;
    for(int i = 0; i < n; i++){
        if(inOrder[i] == preOrder[preIndex]){
            inIndex=i;
            break;
        }
    }
    preIndex++;
    root->left = buildTree(preOrder,inOrder,inL,inIndex-1,n);
    root->right = buildTree(preOrder,inOrder,inIndex+1,inR,n);
    return root;
}
void print(TreeNode*root){
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<endl;
    print(root->right);
}
TreeNode* inorderPredecessor(TreeNode*root){
    //find rightmost child of its left child
    if(root->left == NULL) return NULL;
    root = root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
TreeNode* inorderSuccessor(TreeNode*root){
    if(root->right == NULL) return NULL;
    root=root->right;
    while(root->left != NULL){
        root=root->left;
    }
    return root;
}
TreeNode* deleteNode(TreeNode*root, int data){
    if(root==NULL){
        return NULL;
    }
    if(data < root->data){
        root->left = deleteNode(root->left,data);
    }else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }else{
        //we have found the target node
        TreeNode*inorderPre = inorderPredecessor(root);
        if(inorderPre == NULL){
            //findout root's inorder Successor
            TreeNode*inorderSucc = inorderSuccessor(root);
            if(inorderSucc == NULL){
                //it is a leaf node delete it directly
                delete root;
                return NULL;
            }else{
                root->data = inorderSucc->data;
                root->right = deleteNode(root->right,inorderSucc->data);
            }
        }else{
            root->data = inorderPre->data;
            root->left = deleteNode(root->left, inorderPre->data);
        }
    }
    return root;
}

int main(){
    int pre[11]={1,2,4,8,9,10,11,5,3,6,7};
    int in[11]={8,4,10,9,11,2,5,1,6,3,7};
    TreeNode* root = NULL;
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        int key; cin>>key;
        root = buildBST(root,key);
    }
    root=deleteNode(root,3);
    print(root);

    return 0;
}