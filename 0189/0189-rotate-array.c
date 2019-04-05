void rotate(int* nums, int numsSize, int k) {
    if(NULL == nums || 0 == numsSize)
    {
        printf("input para is NULL or zero");
        return;
    }
    //when k > numsSize
    k = k%numsSize;
    if(1 == numsSize || 0 ==k)
    {
        printf("do nothing");
        return;
    }

    int *tempNum = (int*)malloc(sizeof(int)*numsSize);
    if(NULL == tempNum)
    {
        return;
    }
    memset(tempNum,0,sizeof(int)*numsSize);
    memcpy(tempNum,nums,sizeof(int)*numsSize);
    int loop = 0;
    
    for(loop=0;loop < numsSize;loop++)
    {
        
        nums[loop] = tempNum[(numsSize-k+loop)%(numsSize)];
    }
    free(tempNum);
    
    return;
}