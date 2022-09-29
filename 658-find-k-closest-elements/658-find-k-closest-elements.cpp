class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
	for(int i = k; i < arr.size(); i++) {
		if(arr[i] == arr[start])
			start++;
		else if(abs(x - arr[i]) < abs(x - arr[start]))
			start++;
		else
			break;
	}
	return vector<int>(arr.begin() + start, arr.begin() + start + k);
    }
};