
#include <iostream>      // For input/output operations
#include <vector>        // For using the std::vector container
#include <unordered_map> // For using the std::unordered_map (hash map)

// This function accepts a vector of integers 'nums' and an integer 'target'.
// It returns a vector containing the two indices of elements in 'nums' whose
// values add up to 'target'.
std::vector<int> twoSum(const std::vector<int>& nums, int target) {

    // Create an unordered_map called 'seen' to store elements and their indices.
    std::unordered_map<int, int> seen;

    // Loop over each element in 'nums'.
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {

        // Calculate the complement: the number we need to reach the 'target'.
        int complement = target - nums[i];
        
        // Check if 'complement' is already in the map.
        if (seen.find(complement) != seen.end()) {
            // If found, return the indices (the index of the complement and the current index).
            return { seen[complement], i };
        }

        // If the complement is not found, record the current element and its index in the map.
        seen[nums[i]] = i;
    }
    
    // By the problem statement, there is guaranteed to be exactly one solution.
    // This return is just a fallback.
    return {};
}

int main() {
    // Example 1:
    // nums = [2, 7, 11, 15], target = 9
    // The two numbers 2 and 7 add up to 9, so the expected indices are [0, 1].
    std::vector<int> nums1 = { 2, 7, 11, 15 };
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);

    // Print result for Example 1
    std::cout << "Example 1:\n";
    std::cout << "nums = [2, 7, 11, 15], target = 9\n";
    std::cout << "Output indices: [" << result1[0] << ", " << result1[1] << "]\n\n";

    // Example 2:
    // nums = [3, 2, 4], target = 6
    // The two numbers 2 and 4 add up to 6, so the expected indices are [1, 2].
    std::vector<int> nums2 = { 3, 2, 4 };
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);

    // Print result for Example 2
    std::cout << "Example 2:\n";
    std::cout << "nums = [3, 2, 4], target = 6\n";
    std::cout << "Output indices: [" << result2[0] << ", " << result2[1] << "]\n\n";

    // Example 3:
    // nums = [3, 3], target = 6
    // The two numbers 3 and 3 add up to 6, so the expected indices are [0, 1].
    std::vector<int> nums3 = { 3, 3 };
    int target3 = 6;
    std::vector<int> result3 = twoSum(nums3, target3);

    // Print result for Example 3
    std::cout << "Example 3:\n";
    std::cout << "nums = [3, 3], target = 6\n";
    std::cout << "Output indices: [" << result3[0] << ", " << result3[1] << "]\n\n";

    return 0;
}
