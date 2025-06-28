// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Sort the folder paths lexicographically
        // This ensures that parent folders come before their subfolders
        sort(folder.begin(), folder.end());

        // Vector to store the final result of non-subfolders
        vector<string> result;

        // Step 2: Iterate over each folder path
        for (const string& path : folder) 
        {
            // If result is empty OR current path is not a subfolder of the last added path
            // Check if the current path starts with last added path followed by "/"
            if (result.empty() || path.find(result.back() + "/") != 0) 
            {
                // If not a subfolder, add it to the result
                result.push_back(path);
            }
            // Else, skip adding as it's a subfolder of the previous one
        }

        // Step 3: Return the final result with only top-level folders
        return result;
    }
};