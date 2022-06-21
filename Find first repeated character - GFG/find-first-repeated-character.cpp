// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    vector<int> fre(26);
    string ans ="";
    for(auto &it:s){
        fre[it-'a']++;
        if(fre[it-'a']==2){
            return ans+it;
            break;
        }
    }
    return "-1";
}