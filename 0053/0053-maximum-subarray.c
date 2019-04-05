int maxSubArray(int* nums, int numsSize) {
    if(NULL == nums)
        return 0;
    int curMax = 0;
    int maxSum = INT_MIN;
    int loop  = 0;
    for(loop;loop < numsSize;loop++)
    {
        if(curMax > 0)
            curMax = curMax+nums[loop];
        else
            curMax = nums[loop];
        if(curMax > maxSum)
            maxSum = curMax;
    }
    return maxSum;
    
}