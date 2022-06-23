// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        set<char> s;
        for(int i=0;i<a.size();i++){
            s.insert(a[i]);
        }
        for(int i=0;i<a.size();i++){
            s.erase(a[i]);
            if(s.empty()) break;
            char ch1 = *s.begin();
            if(ch1<a[i]){
                char ch2 = a[i];
                for(int j=0;j<a.size();j++){
                    if(a[j]==ch1){
                        a[j] = ch2;
                    }
                    else if(a[j]==ch2){
                        a[j] = ch1;
                    }
                }
                break;
            }
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends