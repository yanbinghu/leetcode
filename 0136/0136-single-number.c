/*
int compFun(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}*/
int singleNumber(int* nums, int numsSize) {
    /* method one
    int loop = 0;
    int loop2 = 0;
    int returnVal = 0;
    for(loop=0;loop < numsSize;loop++)
    {
        for(loop2=0;loop2<numsSize;loop2++)
        {
            if(loop != loop2 && nums[loop] == nums[loop2])
                break;
        }
        if(loop2 == numsSize)
        {
             return nums[loop];
        }
    }
    return nums[returnVal];
    */
    /*method 2
     qsort(nums,numsSize,sizeof(int),compFun);
    int loop = 0;
    if(1 == numsSize)
    {
        return nums[0];
    }
    for(loop = 0;loop < numsSize;loop++)
    {
        //printf("value %d\n",nums[loop]);
        if((0==loop && nums[loop] < nums[loop+1]) || (numsSize-1 ==loop && nums[loop] < nums[numsSize-1]) )
        {
            //printf("find 111\n");
            return nums[loop];
        }
        if(nums[loop] > nums[loop-1] && nums[loop] < nums[loop+1])
        {
            //printf("find\n");
            return nums[loop];
        }

    }*/
    if(1 == numsSize)
        return nums[0];
    int loop=0;
    int num=0;
    for(loop=0;loop < numsSize;loop++)
    {
        num ^= nums[loop];
    }
    return num;
}