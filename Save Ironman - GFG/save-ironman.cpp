// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool saveIronman(string ch);


int main()
{
    int t,b,c,d,e,f,g,h;
    cin>>t;
    char cc;
    cc = getchar();
    
    while(t--)
    {
        string ch;
        getline(cin,ch);
        
        if(saveIronman(ch)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }
}
// } Driver Code Ends



bool saveIronman(string str)
{
    // Complete the function
    int l = 0, r = str.size()-1;
    while(l < r){
        while(l<r && !isalpha(str[l]) && !isdigit(str[l]))
            l += 1;
        while(l<r && !isalpha(str[r]) && !isdigit(str[r]))
            r -= 1;
        if(l < r && (tolower(str[l]) != tolower(str[r])))
            return false;
        l += 1;
        r -= 1;
    }
    return true;
    
}
