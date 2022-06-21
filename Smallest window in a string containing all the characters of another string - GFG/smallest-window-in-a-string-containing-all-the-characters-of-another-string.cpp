// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if(p.size()>s.size()) return "-1";
        unordered_map<char,int> mp;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        int count = mp.size(),i=0,k=0,end =s.size(),start;
        while(k<s.size()){
            if(mp.find(s[k])!=mp.end()){
                mp[s[k]]--;
                if(mp[s[k]]==0){
                    count--;
                }
            }
            while(count==0){
                if(end>k-i+1){
                    end = k-i+1;
                    start =i;
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1) count++;
                }
                i++;
            }
            k++;
        }
        return end == s.size()?"-1":s.substr(start,end);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends