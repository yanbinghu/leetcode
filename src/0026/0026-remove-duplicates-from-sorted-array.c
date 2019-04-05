int removeDuplicates(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
    {
        printf("input para is NULL or zero");
        return 0;
    }
    int loop = 0;
    int maxIndex=0;
    for(loop=0;loop < numsSize;loop++)
    {
        
        if(nums[loop] != nums[maxIndex])
        {
            maxIndex++;
            nums[maxIndex] = nums[loop];
        }
    }
    return maxIndex+1;
}