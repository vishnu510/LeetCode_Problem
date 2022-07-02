#include<iostream>
using namespace std;

string help(string s){
    string res="";
    int arr[256]={0};
    for(int i=0;i<s.size();i++){
        arr[tolower(s[i])]++;
        if(arr[tolower(s[i])]%2!=0){
            res+=s[i];
        }
    }
    return res;
}
int main()
 {
	//code
    int t;
	cin>>t;
	cin.ignore();
	while(t--){
	    string s;
	    getline(cin,s);
	    cout<<help(s)<<endl;
	}
	return 0;
}