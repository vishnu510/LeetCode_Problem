// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int> left(n),right(n);
    left[0]=arr[0];
    for(int i=1;i<n;i++){
        if(left[i-1]<arr[i]){
            left[i] = arr[i];
        }
        else{
            left[i] = left[i-1];
        }
    }
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]<right[i+1]){
            right[i] = arr[i];
        }
        else{
            right[i] = right[i+1];
        }
    }
    for(int i=1;i<n-1;i++){
        if(arr[i]==left[i] && arr[i]==right[i]){
            return arr[i];
        }
    }
    return -1;
}