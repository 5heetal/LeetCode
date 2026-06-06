class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        int left=0;
        for(int i=0; i<n; i++){
            leftSum[i] = left;
            left += nums[i];
        }

        vector<int> rightSum(n, 0);
        int right=0;
        for(int i=n-1; i>=0; i--){
            rightSum[i] = right;
            right += nums[i];
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }

        return ans;
    }
};