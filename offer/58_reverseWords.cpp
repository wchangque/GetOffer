/*剑指 Offer 58 - I. 翻转单词顺序
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/
#include<bits/stdc++.h>
using namespace std;

/* 双指针  */
class Solution
{
public:
    string reverseWords(string s)
    {
        int i=s.size()-1;
        int j;
        string ans;
        while (i>=0)
        {
            if(s[i]==' ')
                --i;
            else
            {
                j=i;
                while(j>=0&&s[j]!=' ')
                    --j;
                ans+=s.substr(j+1,i-j)+' ';
                i=j;
            } 
        }
        if(!ans.empty())
            ans.pop_back();
        return ans;
    }
};

/* 分割字符串  面试不建议使用 */
class Solution1
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string temp;
        s.clear();
        while (ss>>temp)
        {
            reverse(temp.begin(),temp.end());
            s+=temp+' ';
        }
        if(s.size())
            s.pop_back();
        reverse(s.begin(),s.end());
        return s;
    }
};

int main()
{
    Solution test;
    string eg1{"  hello world!  "};
    cout<<test.reverseWords(eg1)<<endl;
    return 0;
}