class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size()+num2.size(),0);
        
       for(int i=num1.size()-1;i>=0;--i){
           for(int j=num2.size()-1;j>=0;--j){
               int mul = (num1[i]-'0')*(num2[j]-'0');
               int sum  = mul + ans[i+j+1];
               ans[i+j+1] = sum%10;
               ans[i+j]+=sum/10;
           }
       }
        string res ="";
        for(auto i:ans){
            if(res.size()||i){
                res.append(to_string(i));
            }
        }
        if(res.size()==0){
            res = "0";
        }
        return res;
    }
};