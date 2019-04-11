class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            int tar = target - nums[i];
            if (mp.count(tar))
            {
                ans.push_back(mp[tar]); 
                ans.push_back(i);
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};
