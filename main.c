#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct Stack {
    struct node *top;
    struct node *bottom;
    int size;
};

void push(struct Stack *stack, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (stack->size == 0) {
        newNode->next = NULL;
        newNode->prev = NULL;
        stack->top = newNode;
        stack->bottom = stack->top;
    } else {
        newNode->next = NULL;
        struct node *temp = stack->top;
        newNode->prev = temp;
        temp->next = newNode;
        stack->top = newNode;
    }
    stack->size++;
}

void pop(struct Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
    } else {
        struct node *temp = stack->top;
        struct node *prev = stack->top->prev;
        prev->next = NULL;
        stack->top = prev;
        free(temp);
        stack->size--;
    }
}

void display(struct Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
    } else {
        struct node *temp = stack->bottom;
        while (temp != NULL) {
            printf("[%d] -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek(struct Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
    } else {
        printf("Peek is %d\n", stack->top->data);
    }
}

int main(void)
{
    struct Stack stack;
    stack.size = 0;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);
    push(&stack, 70);
    display(&stack);
    pop(&stack);
    peek(&stack);
    pop(&stack);
    pop(&stack);
    display(&stack);
    return 0;
}
