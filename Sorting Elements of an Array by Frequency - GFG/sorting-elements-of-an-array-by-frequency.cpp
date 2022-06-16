#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[61] = {0};
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            arr[temp]++;
        }
        multimap<int,int> m;
        multimap<int,int>::iterator it;
        for(int j=60;j>0;j--){
            if(arr[j]!=0){
                m.insert(pair<int,int>(arr[j],j));
            }
        }
        for(auto it = m.rbegin();it!=m.rend();it++){
            for(int k=0;k<it->first;k++){
                cout<<it->second<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}