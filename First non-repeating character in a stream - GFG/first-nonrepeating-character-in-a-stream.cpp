// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    map<char,int> mp;
		    char c =A[0];
		    string res ="";
		    int k =1;
		    mp[A[0]]++;
		    res+=A[0];
		    for(int i=1;i<A.size();i++){
		        mp[A[i]]++;
		        if(c==A[i] || c=='#'){
		            while(k<=i){
		                if(mp[A[k]]==1){
		                    c =A[k];
		                    break;
		                }
		                else if(k==i){
		                    c = '#';
		                    break;
		                }
		                k++;
		            }
		        }
		        res+=c;
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends