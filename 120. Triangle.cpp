/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minPath(triangle.back()); //声明一个int型向量minPath,vector.back()返回末尾元素的引用，作为vector大小
        int n = triangle.size();
        for(int i=n-2;i>=0;i--){ //从0开始，一共n-1层，只有对n-2层才需要往上递推
            for (int j=0;j<=i;j++){
                minPath[j]=triangle[i][j]+ min(minPath[j],minPath[j+1]);
            }
        }
        return minPath[0];
    }
};