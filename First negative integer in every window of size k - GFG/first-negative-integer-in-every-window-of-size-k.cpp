// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    
    vector<long long int> ans;
    queue<long long> temp;
    
    for(long long  i=0;i<K;i++){
        if(A[i]<0){
            temp.push(A[i]);
        }
    }
    for(long long i=0;i<=N-K;i++){
        if(temp.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(temp.front());
        }
        if(temp.front()==A[i]) temp.pop();
        if(A[i+K]<0){
            temp.push(A[i+K]);
        }
    }
    return ans;
 }