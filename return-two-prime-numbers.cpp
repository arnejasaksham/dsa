#include<bits/stdc++.h>
using namespace std;

int main()
 {
     bool prime[10001];
     memset(prime,true,sizeof(prime));
     prime[0]=prime[1]=false;
     for(int p=2;p*p<10001;p++)
     {
         if(prime[p])
             for(int i=p*p;i<10001;i+=p)
             {
                 prime[i]=false;
             }
     }
     set<int> s;
        for(int i=2;i<10001;i++)
         {
             if(prime[i])
                s.insert(i);
         }
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(auto it:s)
	    {
            if(s.find(n-it)!=s.end())
            {
                cout<<min(it,n-it)<<" "<<max(it,n-it)<<endl;
                break;
            }
	    
	    }
	    
	}
	return 0;
}
