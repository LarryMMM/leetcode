/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

//@Larry_version1
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum &1) ==1){//奇数
            return false;
        }
        vector<int> dp(sum+1);//从0开始，因此需要sum+1大小
        int target = sum>>1; //和为sum/2
        dp[0]=1;
        
        for(auto num:nums){//从0开始，先初始化
            for(int j=target;j>=num;j--){//如果j<nums[i]则无必要更新，因为必然不取该元素
                dp[j]=dp[j] || dp[j-num];
            }
            if(dp[target]) return true;
        }
        return false;
    }
}; 

//notes:sum&1==1 取位运算，也可以考虑 sum%2==1,sum&1==True
//在c++中，sum>>1代表sum除以2的1次幂，求结果。但不一定是整除，例如3>>1=1;4>>1=2

/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sums = accumulate(nums.begin(),nums.end(),0);
        if((sums&1)==true){
            // 奇数
            return false;
        }
        vector<int>dp(sums+1);
        dp[0]=1;
        for(auto num:nums){
            for(int i=sums>>1;i>=0;i--){
                
                if(dp[i]) dp[i+num]=1;
            }
            if(dp[sums>>1]) return true;
        }
        return false;
    }
};
*/


