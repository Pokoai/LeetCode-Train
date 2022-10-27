#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            // 求总和
            int sum = accumulate(nums.begin(), nums.end(), 0);
            int sumLeft = 0;
            for ( int i = 0; i != nums.size(); ++i ) {
                if ( sumLeft * 2 + nums[i] == sum ) {
                    return i;
                }
                sumLeft += nums[i];
            }
            return -1;
        }
};