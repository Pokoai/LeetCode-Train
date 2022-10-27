/*
 * 题目：724.寻找数组的中心下标 [E]
 * 时间：2022-10-27
 * 链接：https://leetcode.cn/problems/find-pivot-index/
 * 题号：1
 */


// 1
int pivotIndex(int* nums, int numsSize){
    for ( int i = 0; i < numsSize; i++ ) {
        int sumLeft = 0, sumRight = 0;
        if ( 0 == i ) {
            sumLeft = 0;
        }
        if ( numsSize - 1 == i ) {
            sumRight = 0;
        }

        for ( int j = 0; j < i; j++ ) {
            sumLeft += nums[j];
        }
        for ( int k = i+1; k < numsSize; k++ ) {
            sumRight += nums[k];
        }

        if ( sumRight == sumLeft ) {
            return i;
        }
    }
    return -1;
}

// 2
int pivotIndex(int* nums, int numsSize){
    int sum = 0;

    // 先求总和
    for ( int i = 0; i < numsSize; i++ ) {
        sum += nums[i];
    }

    for ( int j = 0; j < numsSize; j++ ) {
        int sumLeft = 0, sumRight = 0;
        // 求左边之和
        for ( int k = 0; k < j; k++ ) {
            sumLeft += nums[k];
        }
        // 右边之和
        sumRight = sum - sumLeft - nums[j];

        if ( sumRight == sumLeft ) {
            return j;
        }
    }
    return -1;
}

// 3 最终提交
// ![](https://img.arctee.cn/one/202210270253668.png)
// 不用分别求左边之和以及右边之和，只要有了一边，另一边可以通过sum总和计算出来
// 这样就不用嵌套循环了，只需两个独立的循环
// 时间复杂度：O(n)  空间复杂度：O(1)
int pivotIndex(int* nums, int numsSize){
    int sum = 0;

    // 先求总和
    for ( int i = 0; i < numsSize; i++ ) {
        sum += nums[i];
    }

    int sumLeft = 0, sumRight = 0;
    for ( int j = 0; j < numsSize; j++ ) {
        // 左边之和
        sumLeft += nums[j];
        // 右边之和
        sumRight = sum - sumLeft;

        if ( sumRight == sumLeft-nums[j] ) {
            return j;
        }
    }
    return -1;
}

// 4
int pivotIndex(int* nums, int numsSize){
    int sum = 0;

    // 先求总和
    for ( int i = 0; i < numsSize; i++ ) {
        sum += nums[i];
    }

    // 左边之和
    int sumLeft = 0;
    for ( int j = 0; j < numsSize; j++ ) {
        sumLeft += nums[j];
        if ( sumLeft * 2 - nums[j] == sum ) {
            return j;
        }
    }
    return -1;
}

// 5
int pivotIndex(int* nums, int numsSize){
    int sum = 0;

    // 先求总和
    for ( int i = 0; i < numsSize; i++ ) {
        sum += nums[i];
    }

    // 左边之和
    int sumLeft = 0;
    for ( int j = 0; j < numsSize; j++ ) {
        sumLeft += nums[j];  // 这一句放在比较的前面，导致多加了nums[j]，后面又要减掉，浪费了时间
        if ( sumLeft * 2 - nums[j] == sum ) {
            return j;
        }
    }
    return -1;
}

// 6 官方同解
int pivotIndex(int* nums, int numsSize){
    int sum = 0;

    // 先求总和
    for ( int i = 0; i < numsSize; i++ ) {
        sum += nums[i];
    }

    // 左边之和
    int sumLeft = 0;
    for ( int j = 0; j < numsSize; j++ ) {
        if ( sumLeft * 2 + nums[j] == sum ) {  
            return j;
        }
        sumLeft += nums[j];  // 放在比较语句后面 
    }  // 放在后面就不会包含当前循环的值，而是上次循环的值
    return -1;
}

// 7，反而比不上6
int pivotIndex(int* nums, int numsSize){
    int sum = 0;

    // 先求总和
    for ( int i = 0; i < numsSize; i++ ) {
        sum += nums[i];
    }

    // 左边之和
    int sumLeft = 0;
    for ( int j = 0; j < numsSize; j++ ) {
        sum -= nums[j];
        if ( sum == sumLeft ) {  // 去掉乘法
            return j;
        }
        sumLeft += nums[j];  // 放在比较语句后面 
    }
    return -1;
}

// c++
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
