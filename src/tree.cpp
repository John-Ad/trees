#include "tree.h"

Tree::Tree(int* arr,int n){
    root=populateLevelOrder(arr,0,n,root);
}

Node* Tree::populateLevelOrder(int* arr,int treeIndex,int n,Node* currNode){
    if(treeIndex<n){
        Node* temp=new Node();
        temp->elem=arr[treeIndex];

        currNode=temp;
        currNode->left=populateLevelOrder(arr,(2*treeIndex)+1,n,currNode->left);
        currNode->right=populateLevelOrder(arr,(2*treeIndex)+2,n,currNode->right);
    }
    return currNode;
}

void Tree::add(int elem){
    Node* node=new Node();
    node->elem=elem;
    node->left=NULL;
    node->right=NULL;

    if(root==NULL){
        root=node;
        return;
    }

    Node* currNode=root;
    while(true){
        if(elem < currNode->elem){
            if(currNode->left==NULL){
                currNode->left=node;
                return;
            }

            currNode=currNode->left;
        }else if(elem > currNode->elem){
            if(currNode->right==NULL){
                currNode->right=node;
                return;
            }

            currNode=currNode->right;
        }else{
            delete node;
            return;
        }
    }
}

void Tree::preOrder(Node& node){
    cout<<node.elem<<endl;
    if(node.left != NULL)
        preOrder(*node.left);
    if(node.right != NULL)
        preOrder(*node.right);
}
void Tree::postOrder(Node& node){
    if(node.left != NULL)
        postOrder(*node.left);
    if(node.right != NULL)
        postOrder(*node.right);   
    cout<<node.elem<<endl;
}
void Tree::inOrder(Node& node){
    if(node.left != NULL)
        inOrder(*node.left);
    cout<<node.elem<<endl;
    if(node.right != NULL)
        inOrder(*node.right);   
}
void Tree::breadthFirst(Node* node){    // queue method
    queue q;
    q.enqueue(node);

    while(!q.isEmpty()){
        Node* n=q.dequeue();
        cout<<n->elem<<endl;

        if(n->left != NULL){
            q.enqueue(n->left);
        }

        if(n->right != NULL){
            q.enqueue(n->right);
        }
    }
}

Node* Tree::getRoot(){
    return root;
}
