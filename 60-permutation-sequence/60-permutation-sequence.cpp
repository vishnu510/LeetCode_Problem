class Solution {
public:
    
void findKthPermutation(vector<char>& nums,int k,vector<int>&fact ,string & str){
	if(nums.empty()) return;

	int n =(int)(nums.size());
	int select = (k-1)/fact[n-1];
	str+=nums[select];
	nums.erase(nums.begin()+select);
    k = k-(fact[n-1]*select);
	findKthPermutation(nums,k,fact,str);
}
    
    int factorial(int n){
        if(n==0 || n==1) return 1;
        return n*factorial(n-1);
    }
    
    string getPermutation(int n, int k) {
        vector<char> nums;
        char ch = '1';
        for(int i=0;i<n;i++){
            nums.push_back(ch);
            ch++;
        }
        vector<int> fact;
        for(int i=0;i<n;i++){
            if(i==0 || i==1){
                fact.push_back(1);
            }
            else{
                fact.push_back(factorial(i));
            }
        }
        string ans ="";
        findKthPermutation(nums,k,fact,ans);
        return ans;
    }
};