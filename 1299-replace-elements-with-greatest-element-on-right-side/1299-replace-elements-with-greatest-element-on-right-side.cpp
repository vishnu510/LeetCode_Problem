class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
    
    int max_ele =-1;
    int temp = 0;
   
   for(int i = arr.size()-1;i>=0;i--){
       
       temp = arr[i];
       arr[i] = max_ele;
       max_ele = max(temp,max_ele);

   }
        return arr;
        
    }
};