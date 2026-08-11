class Solution {

public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        return kSum(nums, target, 0, 4);

    }

private:

    vector<vector<int>> kSum(vector<int>& nums, long target, int start, int k) {

        vector<vector<int>> res;

        int n = nums.size();

        

        if (start == n) return res;

        long avgValue = target / k;

        if (nums[start] > avgValue || nums[n - 1] < avgValue) return res;

        

        if (k == 2) return twoSum(nums, target, start);

        

        for (int i = start; i < n; i++) {

            if (i == start || nums[i] != nums[i - 1]) {

                for (vector<int>& subset : kSum(nums, target - nums[i], i + 1, k - 1)) {

                    res.push_back({nums[i]});

                    res.back().insert(res.back().end(), subset.begin(), subset.end());

                }

            }

        }

        

        return res;

    }

    

    vector<vector<int>> twoSum(vector<int>& nums, long target, int start) {

        vector<vector<int>> res;

        int lo = start, hi = nums.size() - 1;

        

        while (lo < hi) {

            long currSum = (long)nums[lo] + nums[hi];

            if (currSum < target || (lo > start && nums[lo] == nums[lo - 1])) {

                lo++;

            } else if (currSum > target || (hi < (int)nums.size() - 1 && nums[hi] == nums[hi + 1])) {

                hi--;

            } else {

                res.push_back({nums[lo], nums[hi]});

                lo++;

                hi--;

            }

        }

        

        return res;

    }

};