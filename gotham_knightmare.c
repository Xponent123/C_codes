#include <stdio.h>
unsigned long long int n,m;
unsigned long long int f = 1000000007;
unsigned long long int arr[1002][1002];
unsigned long long int boundary(unsigned long long int i,unsigned long long int j){
    if(arr[i][j]!=-1 && i<n && j<m && i>=0 && j>=0){

        return 1;
    }
    else{
        return 0;
    }
}
unsigned long long int knight(unsigned  long long int i, unsigned long long int j)
{
    if(boundary(i,j)==1){
        if (i == (0))
        {
            return (1);
        }
        else if(arr[i][j] != 0)
        {
            return (arr[i][j]);
        }

        
        else{
        arr[i][j]= (knight(i-2, j - 1)%f + knight(i-2, j + 1)%f + knight(i-1, j + 2)%f + knight(i-1, j - 2)%f);
        return arr[i][j];
    }}
    else
    {
        return 0;
    }
}

int main()
{
    unsigned long long int k;
    scanf("%lld %lld %lld", &n, &m, &k);
    unsigned long long int arr2[k][2];
    for (unsigned long long int i = 0; i < k; i++)
    {
        for (unsigned long long int j=0; j <2; j++)
        {
            scanf("%lld", &arr2[i][j]);
        }
    }

    for (unsigned long long int i = 0; i < n; i++)
    {
        for (unsigned long long int j = 0; j < m; j++)
        {
            
                arr[i][j] = 0;
            
        }
    }
     
    for (unsigned long long int i = 0; i < k; i++)
    {
        
                arr[arr2[i][0]-1][arr2[i][1]-1] = -1;
            
        }
    
    for (unsigned long long int q =0; q < m; q++)
    {
        printf("%llu ",(knight(n-1, q))%f);
       
    }
    return 0;
}
