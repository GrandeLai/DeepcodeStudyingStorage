class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        set<int> set;
        int len = nums1.size();
        for (int i = 0; i < len; i++)
        {
            if (set.count(nums1[i]) == 0)
            {
                set.insert(nums1[i]);
            }
        }
        for (auto i : nums2)
        {
            if (set.count(i) == 1)
            {
                set.erase(i);
                vec.push_back(i);
            }
        }
        return vec;
    }
};