#include<stdio.h>
#include<string.h>

char s[100],a[100],b[100];
int top = -1;



void push(char a)
{
		top = top+1;
		s[top] = a;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return s[top--];
}


int operand(char x)
{
	if(x == '*' || x== '/' || x== '+' || x=='-' || x =='(' || x==')')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


int precedence(char x)
{
	if(x== '*' || x== '/')
	{
		return 2;
	}
	else if(x=='+' || x== '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void infixtopostfix()
{
    int i=0,k=0;

    char x ;
    for(i=0;i<strlen(a);i++)

    {
        if(operand(a[i])==0 && operand(a[i+1])==1)
            {
                b[k]=a[i];
                k++;
                b[k]=' ';
                k++;
            }
        else if(operand(a[i])==0 && operand(a[i+1])==0)
            {
                b[k]=a[i];
                k++;
            }
        else if(a[i] == '(')
            {
                push(a[i]);
                }
        else if(a[i] == ')')
        {
            while((x = pop()) != '(')
                {
                b[k]=x;
                k++;
                b[k]=' ';
                k++;
                }
        }
        else
        {
            while(precedence(s[top]) >= precedence(a[i]))
            {
                x=pop();
                b[k]=x;
                k++;
                b[k]=' ';
                k++;
            }
            push(a[i]);
        }
        a[i]++;
    }

    while(top != -1)
    {
        b[k]=pop();
        k++;
        b[k]=' ';
        k++;
    }
    b[k]='\0';
    printf("Postfix Expression: ");
    printf(b);
}

int main()
{
	int total;
	printf("Enter infix expression: ");
	gets(a);
    infixtopostfix();

return 0;
}
