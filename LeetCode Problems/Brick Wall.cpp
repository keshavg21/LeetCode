//Problem Link - https://leetcode.com/problems/brick-wall/


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int max_freq = 0, n = wall.size();
        unordered_map<int, int>edge_count;
        for(int i = 0; i<n; i++){
            int edge_pos = 0;
            for(int j = 0; j<wall[i].size()-1; j++){
                edge_pos += wall[i][j];
                edge_count[edge_pos]++;
                max_freq = max(max_freq, edge_count[edge_pos]);
            }
        }
        return wall.size()-max_freq;
    }
};

// Time Complexity - O(N*M) where N number of rows(height of the wall) and M number of columns(width of each row), N*M is the total number of walls which we need to iterate.

// Space Complexity - O(M) where M is the number of bricks in each row.
