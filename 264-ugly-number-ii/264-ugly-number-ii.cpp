class Solution {
public:
    int nthUglyNumber(int n) {
      int dpMat[n+1];
    dpMat[1] =1;
    int p2=1,p3=1,p5=1;
    
    for(int i=2;i<=n;i++){
        int f1 = 2*dpMat[p2];
        int f2 = 3*dpMat[p3];
        int f3 = 5*dpMat[p5];
        int f = min(f1,min(f2,f3));
        dpMat[i] = f;
        if(f == f1) p2++;
        if(f == f2) p3++;
        if(f == f3) p5++;
    }
        return dpMat[n];  
    }
};