#include "include.h"
#include "tree.h"

int main(){
    int n=0;
    cout<<"enter num of elems: "<<endl;
    cin>>n;
    cout<<"enter data set: "<<endl;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    Tree tree(arr,n);
    cout<<endl;
    tree.breadthFirst(tree.getRoot());
    cout<<endl;
    tree.inOrder(*tree.getRoot());
    cout<<endl;
    tree.preOrder(*tree.getRoot());
    cout<<endl;
    tree.postOrder(*tree.getRoot());

    return 0;
}
