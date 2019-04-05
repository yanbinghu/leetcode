int maxProfit(int* prices, int pricesSize) {
    if(NULL == prices || 0 == pricesSize)
        return 0;
    int profit = 0;
    int i = 0;
    int min = INT_MAX;
    while(i < pricesSize)
    {
        if(prices[i] < min)
            min = prices[i];
        else if(prices[i] - min > profit)
            profit = prices[i] - min;
        i++;
    }
    return profit;
    
}