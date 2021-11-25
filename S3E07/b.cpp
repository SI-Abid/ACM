#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[100], t[100];
    gets(s);
    gets(t);
    short sc = 1;
    int len = strlen(s);
    for(int i = 0; i<len; i++)
    {
        if(s[i] == t[i])
            continue;
        else
        {
            if(sc>0 && i<len-1 && s[i] == t[i+1] && s[i+1] == t[i])
            {
                sc--;
                i++;
            }
            else
            {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}