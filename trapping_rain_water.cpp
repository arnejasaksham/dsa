#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t,n,*a=new int[10000000], *l=new int[10000000], *r=new int[10000000],ans;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d", &a[i]);
	    }
	    l[0]=a[0];
	    for(int i=1;i<n;i++)
	        l[i]=max(a[i],l[i-1]);
	    r[n-1]=a[n-1];
	    for(int i=n-2;i>-1;i--)
	        r[i]=max(a[i],r[i+1]);
	    ans=0;
	    for(int i=0;i<n;i++)
	    {
	        ans+=min(l[i],r[i])-a[i];
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}
