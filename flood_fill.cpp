#include<bits/stdc++.h>
using namespace std;

void fill(int a[][1000], int i, int j, int n, int m, int k, int old)
{
    a[i][j]=k;
    if(i<n-1 && a[i+1][j]==old)
        fill(a,i+1,j,n,m,k,old);
    if(i>0 && a[i-1][j]==old)
        fill(a,i-1,j,n,m,k,old);
    if(j<m-1 && a[i][j+1]==old)
        fill(a,i,j+1,n,m,k,old);
    if(j>0 && a[i][j-1]==old)
        fill(a,i,j-1,n,m,k,old);
    
}

int main()
 {
	int t,n,m,a[1000][1000],x,y,k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            scanf("%d", &a[i][j]);
	        }
	    }
	    cin>>x>>y>>k;
	    fill(a,x,y,n,m,k,a[x][y]);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            printf("%d ", a[i][j]);
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
