// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
for(int i=0;i<n;++i){
    pq.push({p[i].first,p[i].second});
}
int start = pq.top().first;
int end = pq.top().second;
pq.pop();
int count = 1;
while(!pq.empty()){
    if(pq.top().first>end){
        count++;
        start = pq.top().first;
        end = pq.top().second;
    }
    if(pq.top().second<end){
        end = pq.top().second;
    }
    pq.pop();
}
return count;
}