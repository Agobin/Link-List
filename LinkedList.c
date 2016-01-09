#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct node{
        int value;
        struct node *next;
    };
bool isempty( struct node * first){
        return first==NULL;
    }
bool ispresent( struct node *, int );
void sort( struct node *first);
 struct node *add_node( struct node *first,int n);
 struct node *search( int n);
 bool Delete( struct node *first,int n);
 void print( struct node *first);
 void instruction(void){
    printf("\nEnter a to add elements in the list.\n");
    printf("Enter d to delete elements from the list.\n");
    printf("Enter i to see instructions.\n");
    printf("Enter p to print sorted list.\n");
    printf("Enter c to clear the screen.");
    printf("Enter q to quit.\n");
 }
int main(){

    int i,n;
    struct node *first=NULL;
    struct node *new_node = malloc( sizeof(struct node));
    char c;
    int del;
    char *status;
    instruction();
    //system("cls");
 for( ; ; ){
    printf("\nEnter mode:");
    c=getch();
    //scanf("%c",&c); fflush(stdin);
    switch (c){
    case 'i':
        instruction();
        break;
    case 'q':
        exit(0);
    case 'a':
        printf("\nEnter value to add: ");
        scanf("%d",&n);
        first=add_node( first,n);
        sort(first);
        break;
    case 'c':
        system("cls");
        break;
    case 'd':
        if( isempty(first))
            printf("\n\nList is empty!\n");
        else{
            if ( !ispresent( first,n ) )
                printf("\nElement %d not found!\n",n);
            else{
                printf("\nEnter the element of list to delete: ");
                scanf("%d",&del);
                if( Delete(first,del) )
                    printf("Deleted successfully!");
            }
      }
        break;
    case 'p':
        print(first);
        break;
    }
}

    getchar();
    return 0;

}
bool Delete( struct node *first,int n){
    struct node *cur,*prev;
    bool note;
            if (  (first->value) == n){
                first=first->next;
                note = true;
            }
            else{
                for( cur = first,prev=NULL;cur !=NULL,cur->value !=n; prev=cur,cur=cur->next);
                   if(  (cur->value) == n && cur != NULL ){
                    prev->next=cur->next;
                    note = true;
                    }
                    else if ( cur == NULL)
                        note = false;
            }
    return note;
}
struct node *add_node( struct node *first,int n){
    struct node * new_node,*cur,*prev=NULL;
    new_node=malloc( sizeof( struct node));
    if(new_node==NULL){
        printf("Memory full!");
        return;
    }
    new_node->value=n;
    new_node->next=first;
    first=new_node;

    return first;
}
void print( struct node *first){
    printf("\n\n");
    for(;first !=NULL;first=first->next ){
        printf("%d -> ",first->value);
    }
    printf("NULL\n\n");

}
void sort( struct node *first){
    struct node *cur,*prev=NULL,*new_node;
    new_node=malloc( sizeof( struct node));
        for( cur=first->next,prev=first ; cur !=NULL;prev=cur,cur=cur->next){
            if(prev->value > cur->value){
                    new_node->value=prev->value;
                    prev->value=cur->value;
                    cur->value=new_node->value;
            }
        }
        //printf("\nList has being sorted!");
}
bool ispresent( struct node *first, int n){
    struct node *cur;
    for( cur = first ; cur != NULL ; cur=cur->next){
        if( cur -> value == n)
            return true;
    }
    return false;
}
