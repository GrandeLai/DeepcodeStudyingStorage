class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;

    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        \
            if (nums.size() == 0) return 0;
        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            if (nums[j] == nums[i])
            {
                j++;
            }
            else
            {
                nums[++i] = nums[j++];
            }
        }
        return i + 1;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        while (n % 2 == 0) {
            n /= 2;
        }

        return n == 1;
    }
};