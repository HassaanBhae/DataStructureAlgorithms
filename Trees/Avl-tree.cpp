#include <iostream>
using namespace std;

struct bstNode{
    int data;
    int heightLeft;
    int heightRight;
    bstNode *right,*left;
};
int maxHeight(int a, int b){
  return a > b ? a : b;
}
bstNode *shiftLeft(bstNode *unbalanceNode)
{
  bstNode *retNode = unbalanceNode->right;
  bstNode *tmp = retNode->left;
  retNode->left = unbalanceNode;
  unbalanceNode->right = tmp;
  if (tmp == NULL)
  {
    unbalanceNode->heightRight = 0;
  }
  else
  {
    unbalanceNode->heightRight = maxHeight(tmp->heightLeft, tmp->heightRight) + 1;
  }
  retNode->heightLeft = maxHeight(unbalanceNode->heightLeft, unbalanceNode->heightRight) + 1;
  return retNode;
}
bstNode *shiftRight(bstNode *unbalanceNode){
  bstNode *retNode = unbalanceNode->left;
  bstNode *tmp = retNode->right;
  retNode->right = unbalanceNode;
  unbalanceNode->left = tmp;
  if (tmp == NULL)
  {
    unbalanceNode->heightLeft = 0;
  }
  else
  {
    unbalanceNode->heightLeft = maxHeight(tmp->heightLeft, tmp->heightRight) + 1;
  }
  retNode->heightRight = maxHeight(unbalanceNode->heightLeft, unbalanceNode->heightRight) + 1;
  return retNode;
}
bstNode *insertBstNode(bstNode **root, int data){
  if ((*root) == NULL){
    bstNode *node = (bstNode *)malloc(sizeof(bstNode));
    node->data = data;
    node->heightLeft = node->heightRight = 0;
    node->left = node->right = NULL;
    return node;
  }
  if (data < (*root)->data){
    (*root)->left = insertBstNode(&(*root)->left, data);
    (*root)->heightLeft = maxHeight((*root)->left->heightLeft, (*root)->left->heightRight) + 1;
  }
  else if (data > (*root)->data){
    (*root)->right = insertBstNode(&(*root)->right, data);
    (*root)->heightRight = maxHeight((*root)->right->heightLeft, (*root)->right->heightRight) + 1;
  }
  int balanceFactor = (*root)->heightLeft - (*root)->heightRight;
  if (balanceFactor < -1){
    if (data > (*root)->right->data){
      (*root) = shiftLeft((*root));
    }
    else{
      // double shift
      (*root)->right = shiftRight((*root)->right);
      (*root) = shiftLeft((*root));
    }
  }
  else if (balanceFactor > 1){
    if (data < (*root)->left->data){
      (*root) = shiftRight((*root));
    }
    else{
      // double shift
      (*root)->left = shiftLeft((*root)->left);
      (*root) = shiftRight((*root));
    }
  }
  return (*root);
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
void printPreOrder(bstNode *root){
  if (root == NULL){
    return;
  }
  cout << root->data << " ";
  printPreOrder(root->left);
  printPreOrder(root->right);
}   
void printPostOrder(bstNode *root){
  if (root == NULL){
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
  if (root == NULL){
    return nullptr;
  }
  if (root->left == NULL){
    cout<<"Minimum Node:"<< root->data;
    return root;
  }
  minBstNode(root->left);
  return NULL;
}
bstNode* maxBstNode(bstNode *root){
  if (root == NULL){
    return NULL;
  }
  if (root->right == NULL){
    cout<<"Maximum Node:"<< root->data;
    return root;
  }
  maxBstNode(root->right);
  return NULL;
}
bstNode* deleteBstNode(bstNode **root,int toDelete){
  if ((*root) == NULL){
    cout << "Value not Found !" << endl;
    return NULL;
  }
  if (toDelete < (*root)->data){
    (*root)->left = deleteBstNode(&(*root)->left, toDelete);
  }
  else if (toDelete > (*root)->data){
    (*root)->right = deleteBstNode(&(*root)->right, toDelete);
  }
  else{
    if ((*root)->left == NULL){
      bstNode *tmp = (*root)->right;
      free((*root));
      cout << "Deleted Successfully " << endl;
      return NULL;
    }
    if ((*root)->right == NULL){
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
        root=insertBstNode(&root,data);
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

