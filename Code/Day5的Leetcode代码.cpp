class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        return n == 1;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string s;

        if (len == 0)
        {
            return s;
        }
        if (len == 1)
        {
            return strs[0];
        }
        int min = INT_MAX;
        for (int k = 0; k < len; k++)
        {
            int strSize = strs[k].size();
            if (min > strSize)
            {
                min = strSize;
            }
        }
        for (int i = 0; i < min; ++i)
        {
            int count = 0;
            char temp = strs[0][i];
            for (int j = 0; j < len; j++)
            {
                if (strs[j][i] == temp)
                    count++;
            }
            if (count == strs.size())
            {
                s += strs[0][i];
            }
            else
                break;
        }
        return s;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n > m)
            return false;
        int len = 0;
        for (int i = 0; i < m; i++)
        {
            if (s[len] == t[i])
                len++;
        }
        if (len == n)
            return true;
        return false;
    }
};