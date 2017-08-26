
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/*Struct node including the input and nodes*/
typedef struct node{
  char key;
  int weight;
  struct node *left;
  struct node *right;
  struct node *equal;
  int end_of_key;
}node_t;

/*prototyping*/
node_t *insert(node_t *pNode, char* word, int weight);
void find_and_traverse(struct node* pNode , char * prefix);
void traverse(struct node* pNode, char* buffer, int depth);


/*main function*/
int main(int argc, char *argv[]){
node_t *pNode=NULL;
char *word;
int weight;

word=malloc((250+1)*(sizeof(char)));

  while(scanf("%d;%250[^\n]", &weight, word)!=EOF) {
    insert(pNode,word,weight);
  }

find_and_traverse(pNode, "Melb");

  return 0;
}



/*new node function for pNode = NULL*/
node_t
*new_node(char word){

    node_t *new;

    new=malloc(sizeof(struct node));

    new->key=word;
    new->left=NULL;
    new->right=NULL;
    new->equal=NULL;

  return new;
}


/*Insert function*/
node_t *insert(node_t *pNode , char* word , int weight ){
  /*insert new node if tree is empty*/
  if (pNode==NULL){
    pNode=new_node(*word);
  }
  /*current char in key is smaller than char in pData*/
  if (*word < pNode->key){
    insert(pNode->left,word, weight);
  }
  /*current char in key is equal to char in pData*/
  else if(*word== pNode->key){
    /*next char in key is '\0'*/
    if((*word+1)=='\0')/*end of flag*/{
      pNode->end_of_key=TRUE;
      pNode->weight=weight;
    }
    /*If the key contains more characters,
    insert them under the equal branch*/
    else (pNode->equal= insert(pNode->equal,word+1,weight));
  }
  /*If current char in key is greater than char in pData
  Insert character on the right branch*/
  else (pNode->right = insert(pNode->right,word,weight));

  return pNode;
}




/*find_and_traverse function*/
void find_and_traverse(struct node* pNode , char * prefix ){

  char* buffer=NULL;
  /*Find the node in the tree that represents the prefix*/
  while(*prefix !='\0' && pNode !=NULL){
    /*left branch*/
    if(*prefix<pNode->key){
      find_and_traverse(pNode->left,prefix);
    } continue;
    /*right branch*/
    if(*prefix>pNode->key){
      find_and_traverse(pNode->right,prefix);
    } continue;
    /*equal branch*/
    if(*prefix==pNode->key){
      find_and_traverse(pNode->equal,prefix);
    } continue;
  }
  if(pNode!=NULL){
    if(pNode->end_of_key==TRUE){
      buffer[strlen(prefix)+1]='\0';
      printf("%s\n",buffer);
    }
    traverse(pNode, buffer, strlen(prefix));
  }
}

/*Tree traversal from a given node*/

void traverse(struct node* pNode, char* buffer, int depth){

  if (pNode==NULL){
    return;
  }
  /*Go to the left most branch*/
  traverse(pNode->left,buffer, depth);
  /*If there is no more branches, then save the character*/
  buffer[depth]=pNode->key;

  if (pNode->end_of_key==TRUE){
    buffer[depth+1]='\0';
    printf("%s\n",buffer);
  }
  /*Going to the equal branch to advance to the next character
  in the key*/

  traverse(pNode->equal,buffer,depth+1);

/*Going to branches that contains characters greater than the current
one in the buffer*/
  traverse(pNode->right,buffer,depth);
}
