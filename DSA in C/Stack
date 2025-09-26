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
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    push(40);
    push(50);
    push(60);
    push(70);
    display();
    return 0;
}
