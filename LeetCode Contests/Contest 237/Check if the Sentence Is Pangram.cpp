// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

// Example 1:

// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.
// Example 2:

// Input: sentence = "leetcode"
// Output: false

//Solution 1
class Solution {
public:
    bool checkIfPangram(string sentence) {
        //created a vector v to store the count of ocuurences of character.
        vector<int>v(26, 0);
        for(int i = 0 ; i<sentence.length() ; i++){
            v[sentence[i] - 'a']++;
        }
        for(int i = 0 ; i<v.size() ; i++){
            //if frequency of a character in the sentence equals zero it means it is not panagram by definition.
            if(v[i] == 0){
                return false;
            }
        }
        return true;
    }
};
//Time Complexity - O(n), space complexity - O(26)

//Solution 2
class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<int>s;
        for(auto c : sentence){
            s.insert(c);
        }
        return s.size() == 26;
    }
};
//Set stores only unique characters hence if after inserting all the charatcers of sentence in set the size of the set equals 26 then the given sentence is a panagram.
//Time Complexity - O(n), space complexity - O(26)

 
