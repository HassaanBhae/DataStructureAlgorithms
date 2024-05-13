#include <iostream>
using namespace std;

struct bstNode{
    int data;
    bstNode *right,*left;
};
void insertbstNode(bstNode **root,int data){
    if((*root)==NULL){
        bstNode *ptr = (bstNode*)malloc(sizeof(bstNode));
        ptr->data=data;
        ptr->right=ptr->left=NULL;
        (*root)=ptr;
    }else{
        if(data < ((*root)->data)){
            insertbstNode(&((*root)->left),data);
        }
        if(data > ((*root)->data)){
            insertbstNode(&(*root)->right,data);
        }
    }
}
void printInOrder(bstNode * root){
    //printInOrder Algorithm (Memorise it) Uses Stack
    if(root==nullptr){
        return;
    }
    printInOrder(root->left);
    cout << root->data<<" ";
    printInOrder(root->right);
}
void printPreOrder(bstNode *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  printPreOrder(root->left);
  printPreOrder(root->right);
}   
void printPostOrder(bstNode *root)
{
  if (root == NULL)
  {
    return;
  }
  printPostOrder(root->left);
  printPostOrder(root->right);
  cout << root->data << " ";
}
int searchBstNode(bstNode* root,int toSearch,int &a){
    if (root==NULL){
        return 0;
    }
    if (toSearch == root->data){
        a=1;
        return a;
    }
    if (toSearch < root->data){
    searchBstNode(root->left, toSearch,a);
    }
    else if (toSearch > root->data){
    searchBstNode(root->right, toSearch,a);
    } 
    return a;   
}
bstNode* minBstNode(bstNode *root){
  if (root == NULL)
  {
    return nullptr;
  }
  if (root->left == NULL)
  {
    cout<<"Minimum Node:"<< root->data;
    return root;
  }
  minBstNode(root->left);
  return NULL;
}
bstNode* maxBstNode(bstNode *root){
  if (root == NULL)
  {
    return NULL;
  }
  if (root->right == NULL)
  {
    cout<<"Maximum Node:"<< root->data;
    return root;
  }
  maxBstNode(root->right);
  return NULL;
}
bstNode* deleteBstNode(bstNode **root,int toDelete){
  if ((*root) == NULL)
  {
    cout << "Value not Found !" << endl;
    return NULL;
  }
  if (toDelete < (*root)->data)
  {
    (*root)->left = deleteBstNode(&(*root)->left, toDelete);
  }
  else if (toDelete > (*root)->data)
  {
    (*root)->right = deleteBstNode(&(*root)->right, toDelete);
  }
  else
  {
    if ((*root)->left == NULL)
    {
      bstNode *tmp = (*root)->right;
      free((*root));
      cout << "Deleted Successfully " << endl;
      return NULL;
    }
    if ((*root)->right == NULL)
    {
      bstNode *tmp = (*root)->left;
      free((*root));
      cout << "Deleted Successfully " << endl;
      return NULL;
    }
    bstNode *minNode = minBstNode((*root)->right);
    (*root)->data = minNode->data;
    (*root)->right = deleteBstNode(&(*root)->right, minNode->data);
  }
  return NULL;
}
main() {
  	bstNode* root=NULL;
    int value;
  	while(true){
    cout <<"Press\n[1] Insert A Value\n[2] Print InOrder \n[3] Print PreOrder \n[4] Print PostOrder \n[5] Search A Value \n[6] Print Minimum Node \n[7] Print Maximum Node \n[8] Delete A Node \n[9] End the Program\n> ";
    cin >> value;
    if(value==1){ 
         int data;
        cout<<"Enter Value To Insert:";
        cin>>data;
        insertbstNode(&root,data);
	}
    if(value==2){
        printInOrder(root);
        cout<<endl;
	}
    if(value==3){
        printPreOrder(root);
        cout <<endl;
	}
	if(value==4){
        printPostOrder(root);
        cout <<endl;
	}
	if(value==5){
         int toSearch;
         int flag=0;
        cout<<"Enter Value To Search:";
        cin>>toSearch;
        if(1==searchBstNode(root,toSearch,flag)){
            cout<<"Value Found!\n";
        }else{
            cout<<"Value Not Found!\n";
        }
	}
	if(value==6){
        minBstNode(root);
        cout <<endl;
	}
	if(value==7){
        maxBstNode(root);
        cout <<endl;
	}
	if(value==8){
        int data;
        cout<<"Enter Value To Delete:";
        cin>>data;
        deleteBstNode(&root,data);
	}
    if(value==9){
      cout <<"Program Ended!";
      break;
    }
  }
}

