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

int isNodePresent(struct node *next, int A, int B, int wtrA, int wtrB){
    struct node *temp;
    if((next->x == wtrA) && (next->y == wtrB)){
        return 0;
    }
    if((next->x == A) && (next->y == B)){
        return 1;
    }
    if((next->x == 0) && (next->y == 0)){
        return 1;
    }
    temp = left;
    while(1){
        if((temp->x == next->x) && (temp->y == next->y)){
            return 1;
        }
        else if(temp->next == NULL){
            break;
        } 
		else {
            temp = temp->next;
        }
    }
    temp = right;
    
    while(1){
        if((temp->x == next->x) && (temp->y == next->y)){
            return(1);
        } 
		else if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }
    return(0);
}

struct node* createNode(struct node *current, int A, int B, int wtrA, int wtrB){
    int d;
    struct node *next;
    next = (struct node*)malloc(sizeof(struct node));
    
    next->x = A;
    next->y = current->y;
    if(!isNodePresent(next, A, B, wtrA, wtrB)){
        return next;
    }
    
    next->x = current->x;
    next->y = B;
    if(!isNodePresent(next, A, B, wtrA, wtrB)){
        return next;
    }
    
    next->x = 0;
    next->y = current->y;
    if(!isNodePresent(next, A, B, wtrA, wtrB)){
        return next;
    }
    
    next->y = 0;
    next->x = current->x;
    if(!isNodePresent(next, A, B, wtrA, wtrB)){
        return next;
    }
    
    if((current->y < B) && (current->x != 0)){
        d = B - current->y;
        if(d >= current->x){
            next->x = 0;
            next->y = current->y + current->x;
        }
        else {
            next->x = current->x-d;
            next->y = current->y+d;
        }
        if(!isNodePresent(next, A, B, wtrA, wtrB)){
            return next;
        }
    }
    
    if((current->x < A) && (current->y != 0)){
        d = A-current->x;
        if(d >= current->y) {
            next->y = 0;
            next->x = current->x + current->y;
        }
        else {
            next->y = current->y - d;
            next->x = current->x + d;
        }
        
        if(!isNodePresent(next, A, B, wtrA, wtrB)){
            return next;
        }
    }
    return NULL;
}

void createGraph(int A, int B, int wtrA, int wtrB){
    int flag1, flag2;
    struct node *tempLeft, *tempRight;
    root  = (struct node*)malloc(sizeof(struct node));
    root->x = 0;
	root->y = 0;
	root->next = NULL;

    left = (struct node*)malloc(sizeof(struct node));
    left->x = 0;
	left->y = B;
	left->next = NULL;

    right = (struct node*)malloc(sizeof(struct node));
    right->x = A;
	right->y = 0;
	right->next = NULL;

    tempLeft = left;
    tempRight = right;

    while(1){
        flag1 = 0;
		flag2 = 0;

        if((tempLeft->x != wtrA) || (tempLeft->y != wtrB)){
            tempLeft->next = createNode(tempLeft, A, B, wtrA, wtrB);
            tempLeft = tempLeft->next;
            tempLeft->next = NULL;
            flag1 = 1;
        }

        if((tempRight->x != wtrA) || (tempRight->y != wtrB)){
            tempRight->next = createNode(tempRight, A, B, wtrA, wtrB);
            tempRight = tempRight->next;
            tempRight->next = NULL;
            flag2 = 1;
        }

        if((flag1 == 0) && (flag2 == 0))
            break;
    }
}

void main(){
    int jugA, jugB, goalA, goalB;
    printf("Welcome to the Water Jug Problem Solver\n");
    printf("\nInput the capacity of the water jug A and B: ");
    scanf("%d %d",&jugA,&jugB);
    printf("\nInput the goal water volume in jug A and B: ");
    scanf("%d %d",&goalA,&goalB);
    createGraph(jugA, jugB, goalA, goalB);
    DFS();
}
