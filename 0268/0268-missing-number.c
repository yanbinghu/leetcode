int missingNumber(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
        return 0;
    
    /*将总和减去数组的和*/
    int sum = 0;
    int oSum = 0;
    int i = 0;
    for(;i < numsSize;i++)
    {
        sum+=i;
        oSum+=nums[i];
    }
    return sum-oSum+i;
    
}