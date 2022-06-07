class Solution {
public:
    int countTriples(int n) {
        int count =0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int square = i*i + j*j;
                int n1 = pow(square,0.5);
                float n2 = pow(square,0.5);
                if(n1==n2){
                    if(n1>=1 and n1<=n) count++;
                }
            }
        }
        return count;
    }
};