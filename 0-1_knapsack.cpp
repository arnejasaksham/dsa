#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t,n,w,val[1001], wt[1001],dp[1001][1001];
	cin>>t;
	while(t--)
	{
	    cin>>n>>w;
	    
	    for(int i=1;i<=n;i++)
	    {
	        cin>>val[i];
	    }
	    for(int i=1;i<=n;i++)
	    {
	        cin>>wt[i];
	    }
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=w;j++)
	        {
	            if(i==0 || j==0)
	                dp[i][j]=0;
	            else if(wt[i]>j)
	                    dp[i][j]=dp[i-1][j];
	            else
	                    dp[i][j] = max(dp[i-1][j], val[i]+dp[i-1][j-wt[i]]);
	        }
    	}
	    cout<<dp[n][w]<<'\n';
	}
	return 0;
}
