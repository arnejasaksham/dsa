#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t,n,a[50],sum,ans;
	bool dp[51][2501];
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    sum=0;
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d", &a[i]);
            sum+=a[i];
	    }
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(j==0)
	                dp[i][j]=true;
	            else if(i==0)
	            {
	                dp[i][j]=false;
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j];
	                if(a[i-1]<=j)
	                {
	                    dp[i][j]|=dp[i-1][j-a[i-1]];
	                }
	            }
	        }
	    }
	    for(int j=(sum>>1);j>=0;j--)
	    {
	        if(dp[n][j])
	        {
	            ans=sum-(j<<1);
	            break;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
