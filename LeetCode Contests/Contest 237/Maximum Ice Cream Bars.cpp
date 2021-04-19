//Problem Link - https://leetcode.com/problems/maximum-ice-cream-bars/

// The problem can be solved greedily as we have to buy the maximum number of ice creams from the given coins. 
// We will pick the ice cream which takes minimum number of coins to purchase and increase our count.
// In this manner we can buy maximum number of ice creams from the given coins.
// Implementation - We will sort the array, then keep subtracting the costs[i] from coins till coins > 0,
// if the coins < 0 we will return the index which is count of max ice creams which can be purchased from the given coins.

//Time Complexity - O(nlogn) where n is the size of the array costs.
//Space Complexity - O(1)
//Code
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        for(int i = 0; i<costs.size(); i++){
            if((coins = coins - costs[i]) < 0)
                return i;
        }
        return costs.size();
    }
};
