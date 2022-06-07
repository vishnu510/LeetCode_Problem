// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    int getIndex(int y[],int n,int ele){
        int low=0,high=n-1,ans=-1;
        while(low<=high){
            int midle = (low+high)/2;
            if(y[midle]>ele){
                ans = midle;
                high = midle-1;
            }
            else{
                low =midle+1;
            }
        }
        return ans;
    }
    long long countPairs(int x[], int y[], int m, int n)
    {
       //Your code here
       int zeros = 0,one=0,two=0,three=0,four=0;
       sort(x,x+m);
       sort(y,y+n);
       for(int i=0;i<n;i++){
           if(y[i]==0) zeros++;
           if(y[i]==1) one++;
           if(y[i]==2) two++;
           if(y[i]==3) three++;
           if(y[i]==4) four++;
       }
       long long totalPair = 0;
       for(int i=0;i<m;i++){
           if(x[i]==0){
               continue;
           }
           else if(x[i]==1){
               totalPair+=zeros;
           }
           else if(x[i]==2){
               int index = getIndex(y,n,2);
               if(index!=-1){
                   totalPair+=n-index;
               }
               totalPair-=three;
               totalPair-=four;
               totalPair+=one+zeros;
           }
           else{
               int index = getIndex(y,n,x[i]);
               if(index!=-1){
                   totalPair+=n-index;
               }
               totalPair+=one+zeros;
               if(x[i]==3){
                   totalPair+=two;
               }
           }
       }
       return totalPair;
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends