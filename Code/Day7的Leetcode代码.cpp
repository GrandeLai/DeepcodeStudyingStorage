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


13.罗马数字转整数
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    ans += 4;
                    i++;
                    continue;
                }
                else if (s[i + 1] == 'X') {
                    ans += 9;
                    i++;
                    continue;
                }
                else ans += 1;
            }
            if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    ans += 40;
                    i++;
                    continue;
                }
                else if (s[i + 1] == 'C') {
                    ans += 90;
                    i++;
                    continue;
                }
                else ans += 10;
            }
            if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    ans += 400;
                    i++;
                    continue;
                }
                else if (s[i + 1] == 'M') {
                    ans += 900;
                    i++;
                    continue;
                }
                else ans += 100;
            }
            if (s[i] == 'V') ans += 5;
            if (s[i] == 'L') ans += 50;
            if (s[i] == 'D') ans += 500;
            if (s[i] == 'M') ans += 1000;
        }
        return ans;
    }
};

3. 无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128] = { 0 };
        for (int i = 0; i < 128; ++i) {
            last[i] = -1;
        }
        int n = s.size();
        int start = 0;
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            int index = s[i];
            start = max(start, last[index] + 1);
            maxLength = max(maxLength, i - start + 1);
            last[index] = i;
        }
        return maxLength;
    }
};