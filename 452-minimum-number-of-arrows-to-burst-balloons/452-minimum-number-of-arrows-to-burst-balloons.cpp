bool cmp(vector<int>& a1,vector<int>& b1) {return(a1[1]<b1[1]);}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         if(points.size()==0) return 0;
        sort(points.begin(),points.end(),cmp);
        int curr_inx = 0;
        int arrow = 0;
        for(int i=0;i<points.size();i++){
            if(arrow==0 || points[i][0]>curr_inx){
                arrow++;
                curr_inx = points[i][1];
            }
        }
        return arrow;
    }
};