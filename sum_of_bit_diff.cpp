#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,n,*a,x,ans;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    a=new int[n];
	    x=0;
	    ans=0;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            x=a[i]^a[j];
	            while(x)
	            {
	                ans+=(x&1);
	                x=x>>1;
	            }
	        }
	    }
	    cout<<ans<<"\n";
	    delete[] a;
	}
	return 0;
}
