void sortColors(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
        return;
    int redNum = 0;
    int whNum = 0;
    int blNum = 0;
    int loop = 0;
    for(loop = 0;loop < numsSize;loop++)
    {
        if(0 == nums[loop] )
            redNum++;
        else if(1== nums[loop])
            whNum++;
        else if(2 == nums[loop])
            blNum++;
        else
        {
           // printf("1231\n");
            break;
        }
    }
    
    for(loop = 0;loop < redNum;loop++)
    {
        nums[loop] = 0;
        //printf("%d 0\n",nums[loop]);
    }
    for(loop = 0;loop < whNum;loop++)
    {
        nums[loop+redNum] = 1;
        //printf("%d 1\n",nums[loop]);
    }
    for(loop = 0;loop < blNum;loop++)
    {
        nums[loop+redNum+whNum] = 2;
       // printf("%d 2\n",nums[loop]);
    }
}