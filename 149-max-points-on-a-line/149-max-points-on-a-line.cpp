class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size();
        if(n<=2) return n;
        int res =0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            int dup =0;
            double slope = 0.0;
            for(int j=0;j<n;j++){
                int x1 = p[i][0];
                int x2 = p[j][0];
                int y1 = p[i][1];
                int y2 = p[j][1];
                int dx = x2-x1;
                int dy = y2-y1;
                if(dx ==0 && dy == 0){
                    dup++;
                    continue;
                };
                if(dx!=0){
                    slope = dy*1.0/dx;
                }
                else{
                    slope = INT_MAX;
                }
                mp[slope]++;
            }
            if(mp.size()==0){
                res = dup;
            }
            else{
                for( auto slope:mp){
                    res = max(res,slope.second+dup);
                }
            }
        }
        return res;
    }
};