#include<bits/stdc++.h>
using namespace std;

int a[301];

int c(int m, int n)
{
    if(n==0)
        return 1;
    if(m<=0)
        return 0;
    int dp[m][n+1];
    for(int i=0;i<m;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=((i>0)?dp[i-1][j]:0)+((j-a[i]>=0)?dp[i][j-a[i]]:0);
        }
    }
    return dp[m-1][n];
}

/* wrong
int c(int n)
{
    int dp[n+1]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(auto s=a.begin();s!=a.end();s++)
        {
            if((*s)<=i)
            {
                dp[i]+=dp[i-(*s)];
            }
        }
    }
    return  dp[n];
}


int cc(int n)
{
    if(n<0)
         return 0;
    int sum=0;
    for(auto s:a)
    {
        if(n>=s)
        {
            if(dp[n-s]==-1)
                dp[n-s]=cc(n-s);
            sum+=dp[n-s];
        }
    }
    dp[n]=sum;
    return dp[n];
}*/

int main()
 {
	int t,m,n,q;
	cin>>t;
	while(t--)
	{
	    cin>>m;
	    for(int i=0;i<m;i++)
	    {
	        cin>>a[i];
	    }
	    cin>>n;
	    cout<<c(m,n)<<endl;
	}
	return 0;
}
