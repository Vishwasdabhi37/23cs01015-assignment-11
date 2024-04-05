#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char arr[100];
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void printStack(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is empty!\n");
    }
    else

        for (int i = 0; i <= ptr->top; i++)
        {
            printf("Element %c\n", ptr->arr[i]);
        }
}
void push(struct stack *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("The stack is full.Cannot perform given operation\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is empty.Cannot perform given operation.\n");
    }
    else
    {
        return ptr->arr[ptr->top--];
    }
}
int main()
{
    struct stack s1;
    s1.size = 100;
    s1.top = -1;
    char input[100];
    printf("Enter the input string: ");
    gets(input);
    char output[100];
    int i = 0;
    while (input[i] != '\0')
    {
        push(&s1, input[i]);
        i++;
    }
    i = 0;
    while (!isEmpty(&s1))
    {
        output[i] = pop(&s1);
        i++;
    }
    output[i] = '\0';
    puts(output);
    return 0;
}
