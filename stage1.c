
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

/*Struct node including the input and nodes*/
struct node{
  char key;
  int weight;
  struct node *left;
  struct node *right;
  struct node *equal;
  typedef int end_of_key;
}node_t;
/*new node function for pNode = NULL*/
node_t
*new_node(char key){

    node_t *new;

    new=malloc(sizeof(struct node));

    new->key=key;
    new->left=NULL;
    new->right=NULL;
    new->equal=NULL;

  return new;
}


/*Insert function*/
node_t *insert(node_t *pNode , char* key , int weight ){
  /*insert new node if tree is empty*/
  if (pNode==NULL){
    pNode=new_node(key);
  }
  /*current char in key is smaller than char in pData*/
  if (key < pNode->key){
    insert(pNode->left,key, weight);
  }
  /*current char in key is equal to char in pData*/
  else if(key== pNode->key){
    /*next char in key is '\0'*/
    if((*key+1)=='\0')/*end of flag*/){
      pNode->end_of_key=TRUE;
      pNode->weight=weight;
    }
    /*If the key contains more characters,
    insert them under the equal branch*/
    else (pNode->equal= insert(pNode->equal,key+1,weight))
  }
  /*If current char in key is greater than char in pData
  Insert character on the right branch*/
  else (pNode->right = insert(pNode->right,key,weight));
}

return pNode;


/*find_and_traverse function*/
void find_and_traverse( node* pNode , char * prefix ){
  /*Find the node in the tree that represents the prefix*/
  while(*prefix !='\0' && pNode !=NULL){
    /*left branch*/
    if(prefix<pNode->key){
      find_and_traverse(pNode->left,prefix);
    } continue;
    /*right branch*/
    if(prefix>pNode->key){
      find_and_traverse(pNode->right,prefix);
    } continue;
    /*equal branch*/
    if(prefix==pNode->key){
      find_and_traverse(pNode->equal,prefix);
    } continue;
  }
  if(pNode!=NULL){
    if pNode->end_of_key==TRUE{
      buffer[strlen(prefix)+1]='\0';
      printf("%s\n",buffer);
    }
    traverse(pNode, buffer, strlen(prefix));
  }
}


/*Tree traversal from a given node*/
