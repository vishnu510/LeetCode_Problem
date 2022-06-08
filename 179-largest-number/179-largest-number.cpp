class Solution {
public:
    static bool cmp(string a,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        string res ="";
        vector<string> str;
        for(auto i:nums){
            str.push_back(to_string(i));
        }
        sort(str.begin(),str.end(),cmp);
        if(str[0] == "0"){
            return "0";
        }
        for(auto s:str){
            res+=s;
        }
        return res;
    }
};