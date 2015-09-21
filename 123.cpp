#include <iostream>

using namespace std;


class Solution 
{
public:
	int maxProfit(vector<int>& prices) 
    {
    	int profit [] = new int[prices.size()];

    	for (int i = 0; i < prices.size(); ++i)
    	{

    	}
    }
};


int main()
{
	return 0;
}



class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        if (prices.size() <= 1) return 0;
        else {
            int K = 2; // number of max transation allowed
            int maxProf = 0;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= K; kk++) {
                int tmpMax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
                    maxProf = max(f[kk][ii], maxProf);
                }
            }
            return maxProf;
        }
    }
};









public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2) return 0;//one of zero days, cannot sell
        // break the problem in to subproblems, what is the max profit if i decide to buy and sell one stock on or before day i
        // and the other stock after day i

        int[] left = new int[prices.length];//store the max profit so far for day [0,i] for i from 0 to n
        int[] right = new int[prices.length];//store the max profit so far for the days [i,n] for i from 0 to n
        int minl,maxprofit,maxr,profit;
        maxprofit = 0;//lower bound on profit
        minl = Integer.MAX_VALUE;//minimum price so far for populating left array
        for(int i = 0; i < left.length; i++){
            if (prices[i] < minl) minl = prices[i];//check if this price is the minimum price so far
            profit = prices[i] - minl;//get the profit of selling at current price having bought at min price so far
            if (profit > maxprofit) maxprofit = profit;//if the profit is greater than the profit so far, update the max profit
            left[i] = maxprofit;
        }
        maxprofit = 0;//reset maxprofit to its lower bound
        maxr = Integer.MIN_VALUE;//maximum price so far for populating the right array
        //same line of reasoning as the above
        for(int i = left.length - 1; i >= 0; i--){
            if (prices[i] > maxr) maxr = prices[i];
            profit = maxr - prices[i];
            if (profit > maxprofit) maxprofit = profit;
            right[i] = maxprofit;
        }
        //get the best by combining the subproblems as described above
        int best = 0;
        for(int i = 0; i < prices.length - 1; i++){
            if (left[i] + right[i+1] > best) best = left[i] + right[i+1];
        }
        best = best > maxprofit ? best : maxprofit;
        // in total 3 passes required and 2 extra arrays of size n
        return best;

    }
}