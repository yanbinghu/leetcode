void moveZeroes(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
    {
        return;
    }
    int loop = 0;
    int num = 0;
    for(loop = 0;loop < numsSize;loop++)
    {
       if(nums[loop] != 0)
       {
           nums[num] = nums[loop];
           num++;
       }

    }
    for(loop = 0;loop < numsSize - num;loop++)
    {
        nums[numsSize-loop-1] = 0;
    }
    
}