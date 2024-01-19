/* lists all the permutations as well as number of permutations in sorted order of all user input strings with lenght <=8 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *arr[40320];
int m=0;
char a1[40320][9];
int compare(const void* num1, const void* num2)  
{  
    return strcmp(*(char**)num1, *(char**)num2);  
      
}  
void swap(char* x,char* y){
    char t=*x;
    *x=*y;
    *y=t;
    }
void permute(int l,int r,char* s){
    if(l==r){
        int q=strlen(s);
        arr[m]=(char*)malloc(q*sizeof(char));
        for(int i=0;i<q;i++){
            a1[m][i]=s[i];
        }
        arr[m]=a1[m];
        m++;
        }
    else{
        for(int i=l;i<=r;i++){
        swap(s+l,s+i);
        permute(l+1,r,s);
        swap(s+l,s+i);
    }}}
int main(){
    char s[9];
    scanf("%s",s);
    int n=strlen(s);
    permute(0,n-1,s);
    char a[m+1][9];
    int p=0;
    
    qsort(arr, m, sizeof(char*), compare);

    
    for(int o=0;o<m-1;o++){
        if(strcmp(arr[o],arr[o+1])!=0){
            strcpy(a[p],arr[o]);
            p++;
        }}
 
    printf("%d\n",p+1);
    for(int e=0;e<p;e++){
    printf("%s\n",a[e]);}
    printf("%s",arr[m-1]);
   return 0;
    
}
