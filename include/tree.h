#include "include.h"

struct Node{
    int elem;
    Node* left;
    Node* right;
};

class Tree{
    private:
        Node* root;
    public:
        Tree(int* arr,int n);
        Node* populateLevelOrder(int* arr,int treeIndex,int n,Node* currNode);
        void add(int elem);
        void preOrder(Node& node);  // root, left, right
        void postOrder(Node& node); // left, right, root
        void inOrder(Node& node);   // left, root, right
        void breadthFirst(Node* node);  // breadth/level order
        Node* getRoot();
};

struct qNode{
    Node* node;
    qNode* next;
    qNode* prev;
};

class queue{
    private:
        qNode* head;
        qNode* tail;
        int n;
    public:
        queue(){
            head=new qNode();
            tail=new qNode();

            head->node=NULL;
            head->next=tail;
            head->prev=NULL;

            tail->node=NULL;
            tail->next=NULL;
            tail->prev=head;

            n=0;
        }

        void enqueue(Node* node){
            qNode* elem=new qNode();
            elem->node=node;

            elem->next=tail;
            elem->prev=tail->prev;

            tail->prev->next=elem;
            tail->prev=elem;

            n++;
        }
        Node* dequeue(){
            Node* temp=head->next->node;

            head->next->next->prev=head;
            head->next=head->next->next;

            n--;

            return temp;
        }
        bool isEmpty(){
            if(n==0)
                return true;
            return false;
        }
};


