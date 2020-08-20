/*剑指 Offer 53 - II. 0～n-1中缺失的数字
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
示例 1:
输入: [0,1,3]
输出: 2
示例 2:
输入: [0,1,2,3,4,5,6,7,9]
输出: 8
 限制：
1 <= 数组长度 <= 10000
*/
#include<bits/stdc++.h>
using namespace std;

/* 遍历 */
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        vector<bool> dp(n+1,false);
        for(int&it:nums)
                dp[it]=true;

        for(int i=0;i<=n;++i)
            if(dp[i]==false)
                return i;
        return 0;
    }
};

/* 如果数组是有序的，可以用二分法 */
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int left=0,right=nums.size();
        int mid;
        while(left<right)
        {
            mid=(left+right)/2;
            if(nums[mid]<=mid)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};

