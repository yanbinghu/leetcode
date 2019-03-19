int maxProfit(int* prices, int pricesSize) {
    if(NULL == prices || 0 == pricesSize)
        return 0;
    int profit = 0;
    int i = 1;
    while(i < pricesSize)
    {
        if(prices[i] > prices[i-1])
            profit+=prices[i]-prices[i-1];
        i++;
    }
    return profit;
    
}
