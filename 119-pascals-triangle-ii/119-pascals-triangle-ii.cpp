class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector< int >ans;
for(int i=0;i<rowIndex+1;i++)
{
long long int val=1;

        for(int j=0;j<=i;j++)
        {
            ans.push_back(val);
            val=val*(i-j)/(j+1);
        }
        if(i!=rowIndex)
        {
            ans.clear();
        }
    }
    return ans;
    }
};