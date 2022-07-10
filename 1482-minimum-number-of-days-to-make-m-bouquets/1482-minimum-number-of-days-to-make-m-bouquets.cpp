class Solution {
public:
    
    int makeBouque(vector<int>&bloomDay,int m,int k,int mid){
        
        int adjCount =0;
        for(auto i:bloomDay){
            if(i<=mid){
                if(++adjCount==k){
                    adjCount =0;
                    if(--m==0){
                        return true;
                    }
                }
            }
            else{
                adjCount =0;
            }
        }
        return m==0;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
     if(m*k > bloomDay.size()){
         return -1;
     }   
        int left =0;
        int right = 1e9;
        while(left<right){
            
            int mid = (left+right)/2;
            if(makeBouque(bloomDay,m,k,mid)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
};