int findMin(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
    {
        return 0;
    }
    if(1 == numsSize)
        return nums[0];
    if(2 == numsSize && nums[0] > nums[1])
        return nums[1];

    if(nums[numsSize-1] < nums[numsSize-2])
        return nums[numsSize-1];
    int loop = 0;
    for(loop = 0;loop < numsSize-1;loop++)
    {
        if(nums[loop] > nums[loop+1])
            return nums[loop+1];
    }    
    return nums[0];
}