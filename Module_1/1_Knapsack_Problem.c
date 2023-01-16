#include<stdio.h>

void knapsack(int num , float weight[] , float profit[] , float capacity)
{
    float x[20] , tp = 0; //total profit
    int i , j , u;
    u = capacity;

    for( i = 0 ; i < num ; i ++)
        x[i] = 0.0;

    for(i = 0 ; i< num ; i++)
    {
        if(weight[i]>u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp+profit[i];
            u = u-weight[i];
        }
    }
    if(i <num)
    {
        x[i] = u/weight[i];
    }

    tp = tp +(x[i]*profit[i]);

    printf("The result vector is ");
    for( i  = 0 ; i < num ; i++)
    {
        printf("%f\t",x[i]);
    }

    printf("Maximum profit is %f",tp);
}

int main()
{
    float weight[20] , profit[20] , capacity;
    int num , i , j;
    float ratio[20],temp;

    printf("Enter the number of objects\n");
    scanf("%d",&num);

    printf("Enter weights of the objects");
    for( i = 0 ; i < num ; i++)
    {
        scanf("%f",&weight[i]);
    }
    
    printf("Enter the profits of the objects");
    for(i = 0 ; i < num ; i++)
    {
        scanf("%f",&profit[i]);
    }
    
    for( i = 0; i < num ; i++)
    {
        ratio[i] = profit[i]/weight[i];
    }

    printf("Enter the capacity of knapsack");
    scanf("%f",&capacity);

    //ARRANGING IN DESCENDING ORDER

    for( i = 0 ; i < num ; i++)
    {
        for( j = i+1 ; j < num ;j++)
        {
            if(ratio[i] <ratio[j])
            {
                temp = ratio[j];
                ratio[j]  =ratio[i];
                ratio[i] = temp;

                temp= weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    knapsack(num, weight , profit , capacity);
    return 0;
}