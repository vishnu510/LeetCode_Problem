// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   vector<int> ans;
   while(!s.empty()){
       ans.push_back(s.top());
       s.pop();
   }
   for(int i=ans.size()-1;i>=0;i--){
       for(int j=i-1;j>=0;j--){
           if(ans[i]<ans[j]){
               swap(ans[i],ans[j]);
           }
       }
   }
   for(int i=0;i<ans.size();i++){
       s.push(ans[i]);
   }
}