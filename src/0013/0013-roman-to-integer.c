int romanToInt(char* s) {
    if(NULL == s)
        return 0;
    int len = strlen(s);
    int i = 0;
    int num = 0;
    int last = 0;
    int temp = 0;
    for(;i <len;i++) 
    {
        /*判断当前字符代表的值*/
        switch(s[i])
        {
            case 'I':
            {
                temp = 1;
                break;
            }
            case 'V':
            {
                temp = 5;
                break;
            }
            case 'X':
            {
                temp = 10;
                break;
            }
            case 'L':
            {
                temp = 50;
                break;
            }
             case 'C':
            {
                temp = 100;
                break;
            }
            case 'D':
            {
                temp = 500;
                break;
            }
            case 'M':
            {
                temp = 1000;
                break;
            }
            default:break;
        }
        //printf("%d,%d\n",temp,last);
        /*如果当前值大于前一个，说明需要减去前面的值*/
        if(temp>last)
            num=temp+num-2*last;
        else
            num=temp+num;
        last = temp;
    }
    return num;
}