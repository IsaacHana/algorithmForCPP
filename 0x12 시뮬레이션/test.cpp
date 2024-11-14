#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(vector<int>& nums, vector<int>& permutation, vector<bool>& used, vector<vector<int>>& result) {
    if (permutation.size() == nums.size()) {
        result.push_back(permutation);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;  // Skip duplicates
            used[i] = true;
            permutation.push_back(nums[i]);
            generatePermutations(nums, permutation, used, result);
            permutation.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> permutation;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());  // Sorting to handle duplicates
    generatePermutations(nums, permutation, used, result);
    return result;
}

int main() {
    vector<int> nums = {0, 0, 1, 2, 3};
    vector<vector<int>> permutations = permuteUnique(nums);

    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}