class Solution {
public:
    void colorFill(vector<vector<int>>&img,int sr,int sc,int oldC,int newC){
        int r = img.size();
        int c = img[0].size();
        if(img[sr][sc]==oldC){
            img[sr][sc]=newC;
        }
        if(sr+1<r && img[sr+1][sc]==oldC){
            colorFill(img,sr+1,sc,oldC,newC);
        }
        if(sr-1>=0 && img[sr-1][sc]==oldC){
            colorFill(img,sr-1,sc,oldC,newC);
        }
        if(sc+1<c && img[sr][sc+1]==oldC){
            colorFill(img,sr,sc+1,oldC,newC);
        }
        if(sc-1>=0 && img[sr][sc-1]==oldC){
            colorFill(img,sr,sc-1,oldC,newC);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        colorFill(image, sr, sc, image[sr][sc], color);
        return image;
    }
};