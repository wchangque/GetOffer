/*剑指 Offer 20. 表示数值的字符串
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
*/
#include<bits/stdc++.h>
using namespace std;

/* 
这道题的几个条件：
1：除前后外，中间不得有空格
2：'.'只能出现一次，且不能再'e'后面
3：'e'只能出现一次，且前面必须已有数字
4：'+','-'要么出现在第一位，要么出现在'e'后面
5：最后一位不能是'e','+','-'

 */
class Solution
{
public:
    bool isNumber(string s)
    {
        int start=0,end=s.size()-1;
        while (s[start] == ' ')
            ++start;
        while (s[end] == ' ')
            --end;
        for (int i = start; i <= end; ++i)
        {
            if(s[i]==' ')return false;      
            else if(s[i]=='e')
            {
                if()
            }
        }
    }
}; 

int main()
{
    
    return 0;
}