// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int pageFaults(int N, int C, int pages[]){
        // code here
        int ans = 0;
        unordered_set<int> s;
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++){
            if(s.size()<C){
                if(s.find(pages[i])==s.end()){
                    ans++;
                    s.insert(pages[i]);
                }
                mp[pages[i]] =i;
            }
            else{
                if(s.find(pages[i])==s.end()){
                    ans++;
                    int LRU = INT_MAX;
                    int value;
                    for(auto it:mp){
                        if(LRU>it.second){
                            LRU = it.second;
                            value = it.first;
                        }
                    }
                    s.erase(value);
                    mp.erase(value);
                    s.insert(pages[i]);
                }
                mp[pages[i]] = i;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends