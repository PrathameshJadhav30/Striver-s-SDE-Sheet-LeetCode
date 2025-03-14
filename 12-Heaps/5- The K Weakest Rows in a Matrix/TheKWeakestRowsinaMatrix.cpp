// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description
class Solution {
    public:
        vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
            vector<pair<int, int>> r; // Stores (number of soldiers, row index)
            
            // Count soldiers in each row and store in the vector
            for (int i = 0; i < mat.size(); i++)
            {
                int soldiers = count(mat[i].begin(), mat[i].end(), 1);
                r.push_back({soldiers, i});
            }
    
            // Sort based on the number of soldiers, and by index in case of a tie
            sort(r.begin(), r.end());
    
            vector<int> result;
            
            // Extract indices of the k weakest rows
            for (int i = 0; i < k; i++) 
            {
                result.push_back(r[i].second);
            }
            
            return result;
        }
    };
    