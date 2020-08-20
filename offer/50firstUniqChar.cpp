/*剑指 Offer 50. 第一个只出现一次的字符
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
示例:
s = "abaccdeff"
返回 "b"
s = "" 
返回 " "
 限制：
0 <= s 的长度 <= 50000
通过次数40,521提交次数67,282
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        int cnt[26]={0};
        for(auto&ch:s)
            cnt[ch - 'a']++;
        for (auto &ch : s)
            if (cnt[ch - 'a'] == 1)
                return ch;
        return ' ';
    }
};