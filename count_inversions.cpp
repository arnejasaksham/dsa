#include<bits/stdc++.h>
using namespace std;

unsigned long long int c(int *a, int low, int high, int *temp)
{
    if(low<high)
    {
        int mid=low+((high-low)>>1),i,j,k;
        unsigned long long int ans=c(a,low,mid,temp)+c(a,mid+1,high,temp);
        for(i=low,j=mid+1,k=0; i<=mid && j<=high;)
        {
            if(a[i]<=a[j])
                temp[k++]=a[i++];
            else
            {
                ans+=mid+1-i;
                temp[k++]=a[j++];
            }
        }
        while(i<=mid)
        { 
            temp[k++]=a[i++];
        }
        while(j<=high)
        {
            temp[k++]=a[j++];
        }
        for(i=low;i<=high;i++)
        {
            a[i]=temp[i-low];
        }
        return ans;
    }
    else
        return 0;
}

int main()
 {
	int t,n,*a=new int[10000000],*temp=new int[10000000];
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d", &a[i]);
	    }
	    cout<<(c(a,0,n-1,temp))<<endl;
	}
	return 0;
}
