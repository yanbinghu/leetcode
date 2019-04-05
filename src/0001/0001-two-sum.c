/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int loop = 0;
    int inloop = 0;
    int* result = NULL;
    result =(int*) malloc(2*sizeof(int));
    memset(result,0,2*sizeof(int));
    if(NULL == nums || numsSize==0)
    {
        return result;
    }
    for(loop = 0;loop < numsSize;loop++)
    {
        for(inloop = loop+1;inloop <numsSize;inloop++)
        {
            if(*(nums+loop)+*(nums+inloop) == target)
            {
                if(NULL != result)
                {
                    
                    *result = loop;
                    *(result+1) = inloop;
                }
                return result;
            }
        }
    }
    return result;
}