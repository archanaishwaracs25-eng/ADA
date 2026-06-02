#include<stdio.h>

int mobile(int a[], int dir[], int n)
{
    int mobile_prev = 0, mobile = 0;

    for(int i = 0; i < n; i++)
    {
        if(dir[a[i]-1] == 0 && i != 0)
        {
            if(a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

        if(dir[a[i]-1] == 1 && i != n-1)
        {
            if(a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    return mobile;
}

int search(int a[], int n, int mobile)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == mobile)
            return i;
    }
    return 0;
}

void printPermutation(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void johnsonTrotter(int n)
{
    int a[n], dir[n];

    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = 0;
    }

    printPermutation(a, n);

    for(int i = 1; i < n; i++)
    {
        int fact = 1;
        for(int j = 1; j <= n; j++)
            fact *= j;

        for(int k = 1; k < fact; k++)
        {
            int mobileNum = mobile(a, dir, n);
            int pos = search(a, n, mobileNum);

            if(dir[mobileNum-1] == 0)
            {
                int temp = a[pos];
                a[pos] = a[pos-1];
                a[pos-1] = temp;
                pos = pos - 1;
            }
            else
            {
                int temp = a[pos];
                a[pos] = a[pos+1];
                a[pos+1] = temp;
                pos = pos + 1;
            }

            for(int j = 0; j < n; j++)
            {
                if(a[j] > mobileNum)
                    dir[a[j]-1] = !dir[a[j]-1];
            }

            printPermutation(a, n);
        }
        break;
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}