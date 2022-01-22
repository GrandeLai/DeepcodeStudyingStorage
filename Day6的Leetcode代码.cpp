
28. 实现 strStr()
class Solution {
public:
    int strStr(string haystack, string needle) {
        string s;
        int len1 = haystack.size();
        int len2 = needle.size();
        if (len2 == 0) {
            return 0;
        }
        for (int pos = 0; pos <= len1 - len2; pos++) {
            s = haystack.substr(pos, len2);
            if (s == needle)
            {
                return pos;
            }
        }
        return -1;
    }
};

1486. 数组异或操作
class Solution {
public:
    int xorOperation(int n, int start) {
        int k;
        for (int i = 0; i < n; i++)
        {
            if (i == 0) {
                k = start + 2 * i;
            }
            else {
                k ^= start + 2 * i;
            }
        }
        return k;
    }
};

1332. 删除回文子序列
class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty())
            return 0;

        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j])
                return 2;
        }

        return 1;
    }
};