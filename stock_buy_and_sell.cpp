#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t,n,a[1000];
	vector<int> lmin,lmax;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    lmin.clear();
	    lmax.clear();
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d", &a[i]);
	    }
	    for(int i=0;i<n-1;)
	    {
	        while(i<n-1 && a[i]>=a[i+1])
	            i++;
	        if(i<n-1)
	        {
	            lmin.push_back(i);
	            i++;
	        }
	        else
	            break;
	        while(i<n && a[i]>=a[i-1])
	            i++;
	        lmax.push_back(i-1);
	    }
	    if(lmax.empty())
	    {
	        cout<<"No Profit\n";
	        continue;
	    }
	    for(int i=0;i<lmax.size();i++)
	    {
	        cout<<"("<<lmin[i]<<" "<<lmax[i]<<") ";
	    }
	    cout<<endl;

	}
	return 0;
}
