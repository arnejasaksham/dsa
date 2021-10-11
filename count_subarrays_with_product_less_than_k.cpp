#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t,n,a[100000],ans;
	long long int k,p;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d", &a[i]);
	    }
	    p=1;
	    ans=0;
	    for(int i=0,j=0;i<n&&j<n;)
	    {
	        if(p*a[j]<k)
	        {
	            p*=a[j];
	            j++;
	            ans+=j-i;
	        }
	        else
	        {
	            p/=a[i];
	            i++;
	        }
	        if(i>j)
	        {
	            j=i;
	            p=1;
	        }
	    }
	    cout<<ans<<endl;

	}
	return 0;
}
