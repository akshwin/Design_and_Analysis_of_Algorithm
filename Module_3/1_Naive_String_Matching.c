// Naive String Matching 

#include<stdio.h>
#include<string.h>
#include<conio.h>

int match(char st[100], char pat[100])
{
    int n , m , i , j , count = 0 , temp = 0;

    n = strlen(st);
    m = strlen(pat);

    for(i = 0 ; i < n-m ; i++)
    {
        temp ++;
        for( j = 0 ; j < m ; j++)
        {
            if(st[i+j] == pat[j])
                count++;
        }
        if(count == m )
            return temp;
            count = 0;
    }
    return -1;
}

int main()
{
    char st[100] , pat[100];
    int status;

    printf("Enter the String ");
    gets(st);

    printf("Enter the pattern to match");
    gets(pat);

    status = match(st , pat);
    if(status == -1)
    {
        printf("No match found");
    }
    else
    {
        printf("Match has been found on %d position",status);
    }
    return 0 ;
}

// Best Time CComplexity = O(n)
// Worst  Time Complexity = O(m*(n-m+1))