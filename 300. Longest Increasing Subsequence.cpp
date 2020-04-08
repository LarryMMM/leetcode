
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

/*
//@Larry 普通动态规划，复杂度n^2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        else{
            vector<int> dp(nums.size()+1,1);//创建并赋初值
            int maxLength = 1;
            for(int i=1;i<nums.size();i++){ //求解前i个数中，最长上升子序列的长度
                for(int j=0;j<i;j++){
                    if (nums[j]<nums[i]) dp[i]=max(dp[i],dp[j]+1);
                }
                maxLength=maxLength<dp[i]?dp[i]:maxLength;
            }
            return maxLength;    
        }
    }
};
*/

//@Larry 动态规划+二分查找法，复杂度nlogn
//思路是创建一个数组，使得该数组的长度始终与最长上升子序列一致，而其最后一个元素，始终是该序列最大的一个值
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        else{
            vector<int>tail = {nums[0]}; //初始化记录，有序数组
            for(auto num:nums){
                int left =0, right=tail.size(); //初始化二分查找法左右边界
                if(num > tail[right-1]){tail.push_back(num);continue;}//大于最大值
                // 二分查找第一个大于等于num[i]的数的索引
                while(left<right){//必定mid=target或者比target小的最少的位置
                    int mid = left + ((right - left)>>1) ;//防止位溢出
                    if(tail[mid]<num){
                        left = mid + 1;
                    }
                    else{
                       right = mid;
                    }
                }
                if(left == tail.size()){}//只剩一种可能，即等于该序列最大值，因此不做任何操作
                // if(left == tail.size()){tail.push_back(num);}
                else{tail[left]=num;}//赋值，替换成现有值
                }
            return tail.size();  
        }             
    }
};