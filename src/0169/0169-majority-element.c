int majorityElement(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
        return 0;
    int i = 0;
    int number = nums[0];
    int times = 1;
    for(i = 1;i < numsSize;i++)
    {
        if(0 == times)
        {
                number = nums[i];
                times++;
        }
        else if(nums[i] == number)
            times++;
        else
        {
            times--;
        }
    }
    return number;
}