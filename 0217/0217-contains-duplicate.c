int compFun(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
bool containsDuplicate(int* nums, int numsSize) {
    
    if(NULL == nums || numsSize == 0 )
    {
        return false;
    }
    if(1 == numsSize)
    {
        return false;
    }
    qsort(nums,numsSize,sizeof(int),compFun);
    int loop = 0;
    for(loop=1;loop < numsSize;loop++)
    {
        if(nums[loop] == nums[loop-1])
            return true;
    }
    return false;
  /*
    int loop = 0;
    int tmpL = 0;
    int size = 0;
    for(loop=0;loop < numsSize;loop++)
    {
        for(tmpL=loop;tmpL < numsSize;tmpL++)
        {
            if(tmpL == loop)
            {
                continue;
            }
            if(nums[tmpL] == nums[loop] && tmpL != loop)
            {
                return true;
            }
        }
        if(numsSize == tmpL)
        {
            size++;
        }
    }
    if(size == numsSize)
        return false;
    return true;
    */
    
    
}