#include<stdio.h>
#include<stdlib.h>

struct DLL{
    int data;
    struct DLL *previous, *next;
};
typedef struct DLL nodeType;
nodeType *first = NULL, *last = NULL;   

//creating and setting 
nodeType * createNode(int element){
    nodeType *NewNode; 
    NewNode = (nodeType *)malloc(sizeof(nodeType));
    if(NewNode == NULL)
        return NULL;
    else{
        NewNode->data = element;
        NewNode->previous = NULL;
        NewNode->next = NULL;
        return NewNode;
    }
}

//inserting at the beginning
void insertAtBeginning(int element){
    nodeType *NewNode = createNode(element);
    if(NewNode == NULL)
    {
        printf("memory allocation failed\n");
    }
    else{
        if(first == NULL){
            first = last = NewNode;
        }
        else{
            first->previous = NewNode;
            NewNode->next = first;
            first = NewNode;
        }
        printf("%d was inserted at the beginning\n", first->data);
    }
    
}

//inserting at the END
void insertAtEnd(int element){
    nodeType *NewNode = createNode(element);
    if(NewNode == NULL)
    {
        printf("memory allocation failed\n");
    }
    else{
        if(first == NULL){
            first = last = NewNode;
        }
        else{
            last->next = NewNode;
            NewNode->previous = last;
            last  = NewNode;
        }
        printf("%d was inserted at the end\n", last->data);
    }
    
}

//inserting at the specific position
void insertAtPosition(int POS, int element){
    nodeType *NewNode = createNode(element);
    nodeType *temp, *tempp; 
    if(NewNode == NULL)
    {
        printf("memory allocation failed\n");
    }
    else{
        if(first == NULL){
            first = last = NewNode;
        }
        else {
            if(POS == 1){
                insertAtBeginning(element);
            }
            else{
                temp = first;
                for(int i=1; i<POS-1; i++){
                    temp = temp->next;
                }
                tempp = temp->next;
                temp->next = NewNode;
                NewNode->previous = temp;
                NewNode->next = tempp;
                tempp->previous = NewNode;
                printf("%d was inserted at the position %d\n", NewNode->data, POS );
            }
            
        }
    }
    
}

//deleting from the beginning
int deleteFromBeginning(){
    int element = -1; 
    nodeType *temp;
    if(first == NULL){
        printf("the list is empty\n");
    }
    else if(first->next == NULL){
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else{
        temp = first;
        first = first->next;
        first->previous = NULL;
        element = temp->data;   
        free(temp);
        
    }
    return element;
}

//deleting from the end
int deleteFromEnd(){
    int element = -1; 
    nodeType *temp;
    nodeType *tempp;
    if(first == NULL){
        printf("the list is empty\n");
    }
    else if(first->next == NULL){
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else{
        temp = last;
        last = last->previous;
        last->next = NULL;
        element = temp->data;
        free(temp);
    }
    return element;
}

//deleting from the specific position
int deleteFromPosition(int POS){
    int element = -1; 
    nodeType *temp;
    nodeType *tempp;
    if(POS<1){
        printf("Invalid Position\n");
    }
    else if(POS==1){
        element = deleteFromBeginning();
    }
    else{
        temp = first;
        for(int i = 1; i<POS-1; i++){
            temp = temp->next;
        }
        if(temp->next == last){
            element = deleteFromEnd();
        }
        else{
            tempp = temp->next;
            temp->next = tempp->next;
            tempp->next->previous = temp;
            element = tempp->data;
            free(tempp);
        }
        
    }
    return element;
}

void display(){
    nodeType *temp;
    if(first == NULL){
        printf("list is empty\n");
    }
    else{
        temp = first;
        do{
            printf("%d->", temp->data);
            temp = temp->next;

        } while (temp != NULL);
        printf("NULL\n");
    }
}

int main(){
    int data;
    insertAtBeginning(100);
    display();
    insertAtEnd(200);
    display();
    insertAtEnd(300);
    display();
    insertAtBeginning(25);
    display();
    insertAtPosition(3, 75);
    display();
    insertAtPosition(1, 10);
    display();
    data = deleteFromBeginning();
    if(data != -1)
        printf("%d was deleted from the beginning\n", data);
        display();
    data = deleteFromEnd();
    if(data != -1)
        printf("%d was deleted from the end\n", data);
        display();
    data = deleteFromPosition(3);
    if(data != -1)
        printf("%d was deleted from the position %d\n", data, 3);
        display();
    printf("\n");
    display();
    return 0;

}


