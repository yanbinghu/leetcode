/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char *fizz="Fizz";
    char *buzz="Buzz";
    char *fb = "FizzBuzz";
    *returnSize = 0;
    char **re =(char**) malloc(n * sizeof(char*));
    if(NULL == re)
        return NULL;
    memset(re,0,n * sizeof(char*));
    int i =1;
    for(;i<= n;i++)
    {
        re[i-1] = malloc(9);
        if(0 == i%15)
        {
            //snprintf(re[i-1],9,"%s",fb);
            strcpy(re[i-1],fb);
        }
        else if(0 == i%3)
        {
           // snprintf(re[i-1],9,"%s",fizz);
            strcpy(re[i-1],fizz);
        }
        else if(0 == i%5)
        {
            strcpy(re[i-1],buzz);
        }
        else
        {
            snprintf(re[i-1],9,"%d",i);
        }
    }
    *returnSize = n;
   // printf("%s,%s",re[0],re[1]);
    return re;
}