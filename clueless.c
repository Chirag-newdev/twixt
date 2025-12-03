#include <stdio.h>
int main()
{
    long long n;
    scanf("%lld",&n);
    char a[n+2][n+2];
    for(long long i=0;i<n;i++)scanf("%s",a[i]);
    char ans[2*n+1];
    ans[0]=a[0][0];
    long long i=0,j=0,c=0;
    while(i<n-1 && j<n-1)
    {
        if(a[i+1][j]>a[i][j+1])
            ans[++c]=a[i][++j];
        else if(a[i][j+1]>a[i+1][j])
            ans[++c]=a[++i][j];
        else
        {
            if(a[i+2][j]>a[i][j+2])ans[++c]=a[i][++j];
            else ans[++c]=a[++i][j];
        }
    }
    while(i<n-1)ans[++c]=a[++i][n-1];
    while(j<n-1)ans[++c]=a[n-1][++j];
    ans[++c]='\0';
    printf("%s\n",ans);
}