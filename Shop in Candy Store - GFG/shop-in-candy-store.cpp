// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int minCost =0,maxCost =0,totalCandy =0,i=0;
        while(totalCandy<N){
            minCost+=candies[i];
            totalCandy++;
            if(K<=(N-totalCandy)){
                totalCandy+=K;
            }
            else{
                totalCandy+=N-totalCandy;
            }
            i++;
        }
        totalCandy =0;
        i = N-1;
        while(totalCandy<N){
            maxCost+=candies[i];
            totalCandy++;
            if(K<=(N-totalCandy)){
                totalCandy+=K;
            }
            else{
                totalCandy+=(N-totalCandy);
            }
            i--;
        }
        return {minCost,maxCost};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends