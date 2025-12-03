#include <stdio.h>
#include <string.h>
#define ll long long
#define l "%lld"
int main()
{
    long x;
    scanf("%ld",&x);
    while(x--)
    {
        ll n,c=0,d=0,b=0;
        scanf(l,&n);
        int a[2*n+1];
        memset(a,0,sizeof(a));
        for (ll i = 0; i < 2*n; i++)
        {
            ll x;
            scanf(l,&x);
            a[x]++;
        }
        for (int i = 0; i <= 2*n; i++)
        {
            if(a[i]==0)continue;
            if(a[i]%4==0)
            {
                b+=1;
            }
            else
            {
                c++;
                if(a[i]%2)d++;
                else c++;
            }
        }
        printf(l,c);        
    }
    return 0;
}
