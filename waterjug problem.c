#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int x, y;
    struct node *next;
}*root, *left, *right;

void DFS(){
    struct node *temp;
    temp = left;
    int i=1;
    printf("\nStart State : (%d,%d)\n", root->x, root->y);
    printf("Solution : \n");
    
    while(1){
    	if(temp->next == NULL){
    		printf("Goal state: -> (%d,%d)\n", temp->x, temp->y);
            break;
        }
        printf("Step %d -> (%d,%d)\n", i, temp->x, temp->y);
        i++;
        
        temp = temp->next;
    }
    temp = right;
}

int isNodePresent(struct node *next, int A, int B, int f1, int f2){
}

struct node* createNode(struct node *current, int A, int B, int f1, int f2){
}

void createGraph(int A, int B, int f1, int f2){
}

void main(){
}
