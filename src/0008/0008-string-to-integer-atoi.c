int myAtoi(char* str) {
        int negative = 0;
	int overflow = 0;
  	int cutoff;
    int cutlim;
    char c = 0;
    /*计算结果存储*/
    int ret = 0;
    //int errCode = 0;
    if(NULL == str)
    {
        //errCode = NULL_PTR_ERR;
        return 0;
    }
    /*跳过开始的空格*/
    while(' ' == (*str))
        str++;
    /*跳过空格之后，到达了字符串结尾，则退出*/
    if(0 == *str)
        return 0;
    /*负数*/
    if(*str == '-' )
    {
        negative = 1;
        str++;
    }
    /*正数*/
    else if(*str == '+')
    {
        negative = 0;
        str++;
    }
    /*正数*/
    else if(isdigit(*str))
    {
        negative = 0;
    }
    /*如果不是以上内容，则直接退出*/
    else
    {
        //errCode = INPUT_ERR;
        return 0;
    }
	cutoff = INT_MAX /10;
    cutlim = INT_MAX % 10;
    while(isdigit(*str))
    {
        /*如果当前结果已经大于int最大值除以10或者等于最大值除以10，并且当前数值大于其余数，则溢出*/
		if (ret > cutoff || (ret == cutoff && (int)(*str-'0') > cutlim))
		{
			//errCode = ERANGE;
            printf("overflow %d,%d,%d\n",*str,cutlim,cutoff); 
			overflow = 1;
		}       
		else
		{ 
			/*计算结果*/
        	ret = ret*10 + (*str -'0');
		}
        str++;
    }
    /*如果溢出，则返回最值*/
	if(overflow)
		return negative?INT_MIN:INT_MAX;
    /*根据正负号返回正确的结果*/
    return negative?-ret:ret;

    
}