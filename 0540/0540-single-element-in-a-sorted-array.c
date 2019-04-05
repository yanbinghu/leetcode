int singleNonDuplicate(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
        return 0;
    if(1 == numsSize)
        return nums[0];
    int loop = 0;
    int num = 0;
    for(loop = 0; loop < numsSize;loop++)
        num^=nums[loop];
    return num;
}