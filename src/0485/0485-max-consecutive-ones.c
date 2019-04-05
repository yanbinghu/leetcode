int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int times = 0;
    int loop = 0;
    int maxTime = 0;
    //printf("the num size is %d",numsSize);
    if(NULL == nums || 0 == numsSize)
    {
        //printf("the input para is NULL or num is zero");
        return 0;
    }
    for(loop = 0;loop < numsSize && loop < 10000;loop++)
    {

        if(nums[loop] == 1)
        {
            //printf("if %d\n",nums[loop]);
            times++;
        }
        else
        {
            //printf("else %d,max %d\n",nums[loop],maxTime);
            if(maxTime < times)
                maxTime = times;
            times = 0;
        }
        
    }
    if(times > maxTime)
        maxTime = times;
    return maxTime;

}