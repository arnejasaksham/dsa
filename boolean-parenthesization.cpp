#include<bits/sdtc++.h>
using namespace std;

int main()
{
	int t,n,dpt[51][51], dpf[51][51];
	char val[51],op[51];
	string s;
	cin>>t;
	while(t--)
	{
	   // scanf("%d\n",&n);
	   cin>>n;
	   cin>>s;
	    for(int i=0;i<n;i++)
	    {
	        if(i&1)
	            op[i>>1]=s[i];
	        else
	            val[i>>1]=s[i];
	    }
	    for(int i=0;i<((n+1)>>1);i++)
	    {
	        fill(dpt[i],dpt[i]+((n+1)>>1),0);
	        fill(dpf[i],dpf[i]+((n+1)>>1),0);
	    }
	        
	    for(int l=(n>>1);l>-1;l--)
	    {
	        for(int i=0,j=(n>>1)-l;i<=l;i++,j++)
	        {
	           // j=i+(n>>1)-l;
	            if(i==j)
	            {
	                dpt[i][j]=(val[i]=='T');
	                //cout<<dpt[i][j]<<' ';
	                dpf[i][j]=(val[i]=='F');
	            }
	            else
	            {
	                for(int k=i;k<j;k++)
	                {
	                    if(op[k]=='&')
	                    {
	                        dpt[i][j]=(dpt[i][j] + (dpt[i][k]*dpt[k+1][j]))%1003;
	                        dpf[i][j]=(dpf[i][j] + (dpf[i][k]*(dpt[k+1][j]+dpf[k+1][j])) + (dpt[i][k]*dpf[k+1][j]))%1003;
	                    }
	                    else if(op[k]=='|')
	                    {
	                        dpt[i][j]=( dpt[i][j] + (dpt[i][k]*(dpt[k+1][j]+dpf[k+1][j])) + (dpf[i][k]*dpt[k+1][j]) )%1003;
	                        dpf[i][j]=( dpf[i][j] + (dpf[i][k]*dpf[k+1][j]) )%1003;
	                    }
	                    else
	                    {
	                        dpt[i][j]=( dpt[i][j] + (dpt[i][k]*dpf[k+1][j]) + (dpf[i][k]*dpt[k+1][j]) )%1003;
	                        dpf[i][j]=( dpf[i][j] + (dpt[i][k]*dpt[k+1][j]) + (dpf[i][k]*dpf[k+1][j]) )%1003;
	                    }
	                }
	            }
	        }
	    }
	    cout<<dpt[0][n>>1]<<endl;   
	    
	   // for(int i=0;i<n;i++)
	   // {
	   //     if(i&1)
	   //         cout<<op[i>>1];//=s[i];
	   //     else
	   //         cout<<val[i>>1];//=s[i];
	   // }
	   // cout<<endl;
	   
	   //for(int i=0;i<((n+1)>>1);i++)
	   // {
	   //     for(int k=0;k<i;k++)
	   //         cout<<"    ";
	   //     for(int j=i;j<((n+1)>>1);j++)
	   //     {
    //             cout<<dpt[i][j]<<' ';
	   //     }
	   //     cout<<endl;
	   // }
	}
	return 0;
}
