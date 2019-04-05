bool search(int* nums, int numsSize, int target) {
    if(NULL == nums || 0 == numsSize)
    {
        return false;
    }
    int loop = 0;
    for(loop = 0;loop < numsSize;loop++)
    {
        if(nums[loop] == target)
            return true;
    }
    return false;
}