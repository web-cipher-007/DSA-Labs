//Stack as an Abstract Data Type(ADT)
#include<stdio.h>
#include<string.h>


#define MAX 5
#define TRUE 1
#define FALSE 0
struct student{
    char name[20];
    int rn;
    int age;
};


struct stack{
    int TOS;
    struct student s[MAX];
};


void push(struct stack *ss, struct student st){
       if(ss->TOS==MAX-1){
           printf("Stack Overflow\n");
       }
       else{
           ss->TOS += 1;
           ss->s[ss->TOS] = st;
       }

}


struct student pop(struct stack *ss){
    struct student st;
  
    if (ss->TOS == -1)
    {
        printf("Stack Underflow\n");
      }
      else{
          st = ss->s[ss->TOS];
          ss->TOS -= 1;
       

          return st;
      }
     
}


struct student peek(struct stack *ss){
    struct student st;
    if (ss->TOS == -1)
    {
        printf("Stack Underflow\n");
      }
      else{
          st = ss->s[ss->TOS];
          return st;
      }

}

int isFull(struct stack *ss){
    if(ss->TOS == MAX-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


int isEmpty(struct stack *ss){
    if(ss->TOS == -1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}



int main(){
    char c;
    int choice,bool;
    struct student s;
    struct stack stk={-1};

    do{
        printf("1.push\n2.pop\n3.peek\n4.isFULL\n5.isEmpty\n6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
        if(!isFull(&stk)){
            printf("Enter your name\n");
            scanf("%s", s.name);
            printf("Enter your roll number\n");
            scanf("%d", &s.rn);

            printf("Enter your age\n");
            scanf("%d", &s.age);
            
        }
            push(&stk, s);
        
            break;
        case 2:
            

            
            if(isEmpty(&stk)){
                s = pop(&stk);
            printf("The removed members are\n");
            printf("NAME:%s\n", s.name);
            printf("Age:%d\n", s.age);
            printf("Roll number:%d\n", s.rn);
            }
            else
            {
                printf("Stack Underflow\n");
            }
            
            
            break;
        case 3:
             if(isEmpty(&stk)){
                 s = peek(&stk);
            printf("Value at the top is\n");
            printf("NAME:%s\n", s.name);
            printf("Age:%d\n", s.age);
            printf("Roll number:%d\n", s.rn);
            }
            else
            {
                printf("Stack Underflow\n");
            }
            
            break;
        case 4:
            if(isFull(&stk)){
                printf("Stack is Full\n");
            }
            else{
                printf("Stack is not full\n");
            }
            break;

        case 5:
            if(isEmpty(&stk)){
                printf("Stack is empty\n");
            }
            else{
                printf("Stack is not empty\n");
            }
            break;
        case 6:
        printf("Exit");
        break;
        default:
            printf("Choose numbers between 1 to 6\n");
                };
    } while (choice != 6);

    return 0;
}
