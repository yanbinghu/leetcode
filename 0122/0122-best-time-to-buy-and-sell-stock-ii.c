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
#if 0 
## 题目
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
```
示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```
## 解法一
最容易想到，也是最暴力的解法便是计算所有的可能，从第一个价格开始，内循环每次计算利润，如果得到的利润比当前的利润大，则在该时刻卖出，直到遍历完所有的价格，得到最大利润。根据该解法所实现的代码如下：
```
int maxProfit(int* prices, int pricesSize) 
{
        int maxprofit = 0;
        int i = 0;
        int j = 0;
        int profit = 0;
        for (; i < pricesSize; i++) 
        {
            for (j = i + 1; j < pricesSize; j++) 
            {
                profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
}
```
## 解法一
暴力解法，我们从第一个买入开始计算，分别计算第二个卖出，加上后面可能的最大利润，第三个卖出，加上后面可能的最大利润，以此类推，得到这所有情况中，利润最大的一种；再计算第二个买入，分别计算第三个卖出，加上后面可能的最大利润，第四个卖出，加上后面可能的最大利润，得到买入第二个能得到的最大利润，最终得到所能得到的最大利润。该方式所实现的代码如下：
```
/******************************************************************************

#include<stdio.h>
int getMaxProfit(int *prices,int pricesSize,int start)
{
    /*如果开始计算的下标等于数组大小，则计算结束*/
    if(start >= pricesSize)
        return 0;
    int max = 0;
    int s = start;
    for(;s < pricesSize;s++)
    {
        int maxPro = 0;
        int j = s + 1;
        for(; j < pricesSize;j++)
        {
            /*有利可图*/
            if(prices[j] > prices[s])
            {
                /*当前最大利润为后面部分最大利润加上当前利润*/
                int nowPro = getMaxProfit(prices,pricesSize,j+1) + prices[j] - prices[s];
                /*本次买入利润为两者中较大的一个*/
                maxPro = nowPro > maxPro?nowPro:maxPro;
            }
        }
        max = maxPro > max?maxPro:max;
    }
    return max;
    
}

int maxProfit(int* prices, int pricesSize) 
{
    if(NULL == prices || 0 == pricesSize)
        return 0;
    return getMaxProfit(prices, pricesSize,0);
}
#include <stdio.h>

int main()
{
    int a[] = {7,1,5,3,6,4,1,6};
    int profit = maxProfit(a,8);
    printf("%d\n",profit);
    return 0;
}

```

该解法复杂度较高，其中时间复杂度O(n^n),而空间复杂度O(n)(递归深度)。

## 解法二
换个角度思考，我们其实就是在赚差价，既然如此，我们只要遇见一个阶段最大的差价赚它一笔就可以了，而且尽可能多的赚。也就是说其实一旦到了某个阶段的最低点（波谷），就可以买入，到了某个阶段的最高点（波峰），就可以卖出。以[7,1,5,3,6,4]为例，我们首先要找到一个波谷，从开始往后扫描，发现第一个波谷为1（左右两边比它大），而找到第一个波峰为5（左边两边都比它低），因此1为买入点，5为卖出点，利润为4。继续往后，发现第二个波谷为3(左右两边都比它大)，而找到波谷6,（左右两边都比它小），因此在3时买入，在6时卖出，利润为3。因此总利润为7。

按照这种思路我们的代码实现如下：
```
#include<stdio.h>
int maxProfit(int* prices,int pricesSize) 
{
    if(NULL == prices || 0 == pricesSize)
        return 0;
    int i = 0;
    int low = prices[0];
    int hig = prices[0];
    int maxprofit = 0;
    while (i < pricesSize - 1) 
    {
        /*如果一直有比当前小的，继续往前扫描*/
        while (i < pricesSize - 1 && prices[i] >= prices[i + 1])
            i++;
        /*得到波谷点*/
        low = prices[i];
        
        /*找到波峰*/
        while (i <pricesSize - 1 && prices[i] <= prices[i + 1])
            i++;
        hig = prices[i];
        /*当前最大利润*/
        maxprofit += hig - low;
    }
    return maxprofit;
}

int main()
{
    int a[] = {7,1,5,3,6,4,1,6};
    int profit = maxProfit(a,8);
    printf("%d\n",profit);
    return 0;
}
```
这种解法的时间复杂度为O(n),空间复杂度O(1)。
## 解法三
既然通过波峰与波谷的差价可以得到利润，那么实际上可以在发现在上升期就开始计算利润了，也就是说不需要达到波峰时，才用波峰减去波谷计算利润。,是以[7,1,5,3,4,6]为例，从头开始，1大于7，无利可图，5大于1，有利可图，得利润4；3小于5，无利可图；4大于3，有利可图，得利润1；6大于4，有利可图，得利润2；总利润为7。

按照这种思路，我们实现的代码如下：
```
#include<stdio.h>
int maxProfit(int* prices, int pricesSize) 
{
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
int main()
{
    int a[] = {7,1,5,3,4,6};
    int profit = maxProfit(a,8);
    printf("%d\n",profit);
    return 0;
}
```
这种解法的时间复杂度为O(n),空间复杂度O(1)。
#endif