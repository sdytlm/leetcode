/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/


class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if(prices.empty())
      return 0;
      vector<int> left;
      vector<int> right;
      int i,len=prices.size();
      if(len<=1)
          return 0;
      for(i=0;i<len;i++) {
          left.push_back(0);
          right.push_back(0);
      }
      findMaxProfit(prices,left,right);
      int maxVal=0;
      for(i=0;i<prices.size();i++) {
          maxVal = max(maxVal, left[i]+right[i]);
      }
      return maxVal;
  }

  void findMaxProfit(vector<int> &prices, vector<int> &left, vector<int> &right) {
      int len = prices.size();
      int minVal = prices[0];
      int i;
      for(i=1;i<len;i++) {
          // 找到prices[i]左边prices[0...i-1]的最大值
          left[i] = max(prices[i]-minVal, left[i-1]);
          minVal = min(prices[i],minVal);
      }
      int maxVal = prices[len-1];
      // 找到prices[i]右边[i+1...end]的最大值
      for(i=len-2;i>=0;i--) {
          right[i] = max(maxVal-prices[i], right[i+1]);
          maxVal = max(prices[i],maxVal);
      }
      return ;

      }
    };
