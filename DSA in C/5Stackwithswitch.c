#include<stdio.h>
#include<stdlib.h>

# define MAX 5

int stack[MAX];
int top=-1;
int isEmpty(){
    return top==-1;
}

int isFull(){
    return top==MAX-1;
}

void push (int value){
    if (isFull())
    {
        printf("Stack Over flow Cannot PUSH element");
    }else{
        top++;
        stack[top]=value;
        printf(" %d value is pushed \n", value);

    }  
}

void pop(){
    if (isEmpty())
    {
        printf("Stack Underflow element cannot be delete");
    }
    else{
        int value=stack[top];
        top--;
        printf("Deleted Item is %d", value);
    }
    
}
int peek(){
    if (isEmpty())
    {
        printf("Stack is Empty");
        return(-1);
    }else{
        return stack[top];
    }
    
}
void display(){
    if (isEmpty())
    {
        printf("Stack is Empty");
        
    }
    else{
        printf("\n Stack element ");
        for (int i = top; i >=0; i--)
        {
            printf("\n %d", stack[i]);
        }
        
    }

}

int main(){
    int ch;
    while (1)
    {
        printf("Enter The choices  \n 1 for Push \n 2 for Pop \n 3 for display \n 4 for peek \n");
        scanf("%d", &ch);
        int a;
        switch (ch)
        {
        case 1:
        printf("Enter The value \n");
        
        scanf("%d", &a);
            push(a);
            break;
        case 2:
            pop();
            break;
        case 3: 
        display();
            break;    
        case 4: 
        peek();
            break;    
        
        default:
            printf("You have choose wrong Option ");
            break;
        }
    }
    
    return 0;
}
