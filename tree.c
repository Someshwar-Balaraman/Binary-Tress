#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct node *llink;
	struct node * rlink;
}node;

node *getnode(){
	return((node *)malloc(sizeof(node)));
}

void insert(node **root,int data){
	if(*root == NULL){
		node *temp = getnode();
		temp->data = data;
		temp->llink = temp->rlink = NULL;
		*root = temp;
		return;
	}
	printf("insert left or right of %d", (*root)->data);
	char a[5];
	scanf(" %s",a);
	if(!strcmp(a,"left")){
		//node *left = (*root)->llink;
		insert(&(*root)->llink,data);
	}
	else{
		insert(&(*root)->rlink,data);
	}
}

void inorder(node *root){
	if(root == NULL)
		return;
	
	inorder(root->llink);
	printf("%d",root->data);
	inorder(root->rlink);
	
	
}

int main(){
	int menu;
	node *root = NULL;
	int data;

	for(;;){
		printf("Choose \n1.Insert \n2.Display \n0.Exit");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				printf("enter data :");
				scanf("%d",&data);
				insert(&root,data);
				break;
			case 2:
				inorder(root);
				break;
			default:
				return 0;


		}
	}
	

	return 0;
}