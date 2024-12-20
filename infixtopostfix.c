//Infix to postfix
#include<stdio.h>
#define MAX 20
struct Stack
{
    int TOS;
    char data[MAX];
};
void push(struct Stack*,char);
char pop(struct Stack*);
int priority(char);

int main()
{
    struct Stack temp={-1};
    struct Stack output={-1};
    char infix[MAX];
    char garbge,opr;
    int i=0;
    printf("Enter infix expression: ");
    fgets(infix,MAX,stdin);
    while(infix[i]!='\n')
    {
        switch (infix[i])
        {
        case '(':
        push(&temp,'(');

            break;

        case ')':
        while(temp.data[temp.TOS]!='(')
       {
        garbge=pop(&temp);
        push(&output,garbge);
       }
       garbge=pop(&temp);
       break;

       case '+':
       case '-':
       case '*':
       case '/':
       case '^':

       opr=infix[i];
       while(priority(temp.data[temp.TOS])>=priority(opr))
       {
        garbge=pop(&temp);
        push(&output,garbge);
       }
       push(&temp,opr);
       break;

        default:
            push(&output,infix[i]);
            break;
        }
        i+=1;
    }
    while (temp.TOS!=-1)
    {
       garbge=pop(&temp);
       push(&output,garbge);
    }

    printf("The postfix Expression is %s",output.data);
    printf("\n");
    return 0;
}

void push(struct Stack*s,char element)
{
    s->data[++s->TOS]=element;
}
char pop(struct Stack*s)
{
    return s->data[s->TOS--];
}
int priority(char opr)
{
    if(opr=='^')
    return 3;
    if(opr=='*'||opr=='/')
    return 2;
    if(opr=='+'||opr=='-')
    return 1;
    if(opr=='(')
    return 0;
}
