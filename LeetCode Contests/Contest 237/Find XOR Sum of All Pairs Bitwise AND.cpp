//Problem Link - https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

// Solution 1 - In this method we take bitwise and of every element of arr1 with arr2 and store them in a array let's call it store_xor, 
//after doing this we will calculate the xor of the all the elements present in store_xor array and return the value. 
//This method can work for small value but will give TLE due to large constraints.
// Time Complexity - O(n*m) where n is size of the array arr1 and m is size of the array arr2.
// Space Complexity - O(n*m) where n is size of the array arr1 and m is size of the array arr2.

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        Brute force
        vector<int>store_xor;
        for(int i = 0 ; i<arr1.size() ; i++){
            for(int j = 0 ; j<arr2.size() ; j++){
                int d = arr1[i] & arr2[j];
                store_xor.push_back(d);
            }
        }
        int ans = 0;
        for(int x : store_xor){
            ans = ans ^ x;
        }
        return ans;
    }
};

// Solution 2 - In this method we will use the distributive property which is 
// (a&b)^(a&c) = a&(b^c).
// Then, (arr1[i]&arr2[0])^(arr1[i]&arr2[1]).. = arr1[i]&(arr2[0]^arr2[1]^arr[2]...).
// Let arr2XorSum = (arr2[0]^arr2[1]^arr2[2]...), arr1XorSum = (arr1[0]^arr1[1]^arr1[2]...) 
// So the final ans = (arr2XorSum&arr1[0]) ^ (arr2XorSum&arr1[1]) ^ (arr2XorSum&arr1[2]) ^ ... 
// If we take common arr2XorSum&
// then the expression would become
// final ans = arr2XorSum&(arr1[0]^arr1[1]^arr2[2]^...)
// final ans = arr2XorSum & arr1XorSum.

// Time Complexity - O(n+m) where n is size of the array arr1 and m is size of the array arr2.
// Space Complexity - O(1).

//Code
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor1 = 0, xor2 = 0;
        for(int i = 0; i<arr1.size(); i++){
            xor1 ^= arr1[i];
        }
        for(int i = 0 ; i<arr2.size() ; i++){
            xor2 ^= arr2[i];
        }
        return (xor1 & xor2);
    }
};
