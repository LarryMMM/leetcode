/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   */
class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1,0);
        num[0]=1;
        num[1]=1;
        
        if(n>1){
            for(int i =2;i<=n;i++){//计算i个value对应的BST方案数量
                for(int j=1;j<=i;j++){//根节点为j对应的BST方案数量
                    num[i]+=num[j-1]*num[i-j];
                } 
            }
        }
        
        return num[n];
    }
};