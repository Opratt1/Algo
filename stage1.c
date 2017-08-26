
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
  /*current char in word is smaller than char in pData*/
  if (key < pNode->key){
    insert(root->left,key, weight);
  }
  /*current char in word is equal to char in pData*/
  else if(*(key)==)

}
f


/* current char in word i s smaller than char in pData */
