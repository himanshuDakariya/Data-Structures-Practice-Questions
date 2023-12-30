// 6. Write a program to implement Binary Search Tree as an ADT which supports the following 
// operations:
// i. Insert an element x
// ii. Delete an element x
// iii. Search for an element x in the BST 
// iv. Display the elements of the BST in preorder, inorder, and postorder traversal


#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};
class BSTtree{

public:
    Node* minVal(Node* node){
        Node* temp = node;

        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    Node* maxVal(Node* node){
        Node* temp = node;

        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }

    void takeinput(Node* &node){
        int data;
        cin>>data;

        while(data!= -1){
            insertintoBST(node,data);
            cin>>data;
        }
    }

    void preorder(Node* node){

        if(node==NULL){
            return;
        }
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node){

        if(node==NULL){
            return;
        }
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    void postorder(Node* node){

        if(node==NULL){
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }

    

    // void inorderscc(Node* node,int val){
        
    //     Node* temp= node;

    //     int pred=-1;
    //     int succ=-1;

    //     while(temp->data!=val){
    //         if(temp->data > val){
    //             succ=temp->data;
    //             temp=temp->left;
    //         }
    //         else{
    //             pred=temp->data;
    //             temp=temp->right;

    //         }
    //     }

    //     Node* leftTreePtr = temp->left;
    //     while(leftTreePtr !=NULL){
    //         pred= leftTreePtr->data;
    //         leftTreePtr=leftTreePtr->right;
    //     }
    //     Node* ritghTreePtr = temp->right;
    //     while(ritghTreePtr !=NULL){
    //         succ= ritghTreePtr->data;
    //         ritghTreePtr=ritghTreePtr->left;
    //     }

    //     cout<<pred<<" "<<succ<<endl;


    // }



    Node* insertintoBST(Node* &node,int d){

        if(node==NULL){
            node=new Node(d);
            return node;
        }

        if(d>node->data){
            node->right = insertintoBST(node->right,d); 
        }
        else{
            node->left = insertintoBST(node->left, d);
        }

        return node;
    };


    void searchBST(Node* node,int x){
        if(node == NULL){
            cout<<"Not found! "<<endl;
            return;

        }
        if(node->data ==x){
            cout<<"Founded "<<x<<endl;
            return;
        }
        if(node->data > x){
            searchBST(node->left,x);
        }
        else{
            searchBST(node->right,x);
        }

    }

    Node* deletenode(Node* &node,int val){

        if(node == NULL){
            return node;
        }

        if(node->data == val){
            // 0 child
            if(node->left==NULL && node->right == NULL){
                delete node;
                return NULL;
            }

            // 1 child

            if(node->left != NULL && node->right == NULL){
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
            if(node->left == NULL && node->right != NULL){
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }

            // 2 child

            if(node->left != NULL && node->right != NULL){
                    
                    int min= minVal(node->right)->data;
                    node->data = min;
                    node->right = deletenode(node->right, min);
                    return node;

                }

        }
        else if(node->data > val){
            node->left = deletenode(node->left, val);
            return node;
        }
        else{
            node->right = deletenode(node->right, val);
            return node;
        }};






};

int main (){
    Node* root = NULL;

    BSTtree t;

    cout<<"Enter the data: "<<endl;
    t.takeinput(root);


    cout<<"Printing. . Preorder Traversal"<<endl;
    t.preorder(root);
    cout<<endl;
    cout<<"Printing. . Inorder Traversal"<<endl;
    t.inorder(root);
    cout<<endl;
    cout<<"Printing. . Postorder Traversal"<<endl;
    t.postorder(root);
    cout<<endl;

    t.searchBST(root,78);

    root=t.deletenode(root,50);

    cout<<"After Deletion"<<endl;
    t.preorder(root);

return 0;

}