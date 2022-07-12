// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
int pal(int l,string a,int r)
   {
      
       if(l>=r)
           return 1;
       if(a[l]!=a[r])
       {
           return 0;}
           
        return pal(l+1,a,r-1);
       
   }

    int PalinArray(int a[], int n)
    {
    	// code here
    	string s ;
    int temp =0;
    for(int i=0;i<n;i++)
    {
    	 s = to_string(a[i]);
        if(pal(0,s,s.size()-1))
            temp=1;
        else 
        {
            temp=0;
            break;
        }
        
       
    }
    return temp;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends