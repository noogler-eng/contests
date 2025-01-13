// All subsets
// subsets contains all substring and subarray


#include<iostream>
#include<vector>
using namespace std;

void findSubsets(vector<int> &nums, vector<int> &current, int index, vector<vector<int>> &result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }

    // not selecting
    findSubsets(nums, current, index + 1, result);

    // selecting
    current.push_back(nums[index]);
    findSubsets(nums, current, index + 1, result);
    current.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    findSubsets(nums, current, 0, result);
    return result;
}

