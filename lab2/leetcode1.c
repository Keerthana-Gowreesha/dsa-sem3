#include <stdio.h>
#include <string.h>
#define MAX 50

char stk[MAX];
int top = -1;

void push(char item)
{
    stk[++top] = item;
}

char pop()
{
    return stk[top--];
}

void reverse(char str[], char res[], char ch)
{
    int i, j = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ch)
        {
            push(str[i]);
        }
        else
        {
            res[j++] = str[i];
            while (top != -1)
            {
                res[j++] = pop();
            }
            break;
        }
    }

    i = i + 1;

    while (str[i] != '\0')
    {
        res[j++] = str[i];
        i = i + 1;
    }

    res[j] = '\0';
}

int main()
{
    char str[50], res[50], ch;

    printf("enter the string = ");
    scanf("%s", str);
    getchar();

    printf("enter the character = ");
    scanf("%c", &ch);
    getchar();

    reverse(str, res, ch);

    printf("the reversed string is = %s ", res);

    return 0;
}
