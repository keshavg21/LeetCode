// Problem Link - https://leetcode.com/problems/missing-number/

//Method 1 - Sort the array, keep a count variable initialize to zero if, compare count with nums[i], if the count is equal to nums[i] increase the count otherwise break from the
//loop and return the count.
//Time Complexity - O(nlogn) Space Complexity - O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //int ans;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == count) count++;
            else{
                break;
            }
        }
        return count;
    }
};

// Method 2 - Create a array v of size nums.size()+1 to store the frequency of each element present in the array. The element which has frequency equal to zero is our missing number.
// Time Complexity - O(n), Space Complexity - O(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>v(nums.size()+1, 0);
        for(auto x : nums){
            v[x]++;
        }
        int ans = -1;
        for(int i = 0 ; i<v.size() ; i++){
            if(v[i] == 0) ans = i;
        }
        return ans;
    }
};

//Method 3 - Find the sum of element from 1 to n, find the sum of the elements in the array, the missing number is given by (Sum of n elements - Sum of the array)
//Time Complexity - O(n), Space Complexity - O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int count = 0;
        for(auto i : nums){
            count += i;
        }
        return sum - count;
    }
};



