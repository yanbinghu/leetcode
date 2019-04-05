int addDigits(int num) {
    int temp = num;
    if(0 == num/10)
    {
        return num;
    }
    else
    {
        num =0;
        while(0 != temp/10)
        {
            num +=temp%10;
            temp = temp/10;
        }
        num = num+temp;
       return  addDigits(num);
    }
    
}