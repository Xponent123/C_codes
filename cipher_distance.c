#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n, k;
    scanf("%d %d\n", &n, &k);
    char s[n];
    int sum = 0;
    scanf("%s", &s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= 'm')
        {
            sum = sum + abs(s[i] - 'z');
        }
        if (s[i] >= 'n')
        {
            sum = sum + abs(s[i] - 'a');
        }
    }
    if (sum < k)
    {
        printf("-1");
    }

    else if (sum == k)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] <= 'm')
            {
                printf("z");
            }
            if (s[i] >= 'n')
            {
                printf("a");
            }
        }
    }
    else
    {
        char s1[n];
        int sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            s1[i] = 'a';
            sum2 = sum2 + s[i] - 'a';
        }
        if (k > sum2)
        {
            int diff = abs(k - sum2);
            int i = n - 1;
            while (sum2 != k,i >= 0)
            {
                if(s[i]>='n'){
                    i--;
                    continue;
                }
                else if (s[i] <= 'm')
                {
                    sum2 = sum2 - (s[i] - s1[i]);
                    diff = diff + (s[i] - s1[i]);
                    int diffo = 'z' - s[i];
                    if (diffo < diff)
                    {
                        s1[i] = 'z';
                        
                        sum2 = sum2 + (s1[i] - s[i]);
                        diff = k-sum2;
                        
                    }
                    else if (diffo >= diff)
                    {
                        s1[i] = s[i] + diff;
                        sum2 = k;
                        break;
                    }
                }
                i--;
            }
        }
        if(sum2>=k){
            int diff=sum2-k;
            int i=n-1;
            while(sum2!=k,i>=0){
                if((s[i]-'a')<diff){
                    s1[i]=s[i];
                    sum2=sum2-(s[i]-'a');
                    diff=sum2-k;
                }
                else if((s[i]-'a')>=diff){
                    s1[i]=s1[i]+diff;
                    sum2=k;
                    break;
                }
                i--;
            }
        }
        
        for(int j=0;j<n;j++){
            printf("%c",s1[j]);
        }
    }

    return 0;
}
