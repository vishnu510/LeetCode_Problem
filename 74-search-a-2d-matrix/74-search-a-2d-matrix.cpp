class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int B) {
        
        if(A.size()==1){
        if(A[0][0]==B)
        return true;
    }
   
   int start=0,end=A.size()-1,m=A[0].size()-1;
   if(A[end][m]==B)return true;
while(start<end){
int mid=(start+end)/2;
if(A[mid][m]==B)return true;
else if(A[mid][m]<B){
start=mid+1;
}
else {
end=mid;
}
}
int j=0;

int i=0;
while(i<m){
    int midd=(i+m)/2;
    if(A[start][midd]==B)return true;
    else if(A[start][midd]<B){
        i=midd+1;
    }
    else{
        m=midd;
    }
}
return false;
    }
};