int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    static int result[500]; 
    int count[101] = {0};   

    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }


    for (int i = 1; i < 101; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            result[i] = 0; // There are no numbers smaller than 0
        } else {
            result[i] = count[nums[i] - 1]; // Numbers smaller than nums[i]
        }
    }

    *returnSize = numsSize; // Return the size of the result array
    return result;          // Return the statically allocated result array
}
