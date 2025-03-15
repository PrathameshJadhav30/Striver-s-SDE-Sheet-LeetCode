// https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            map<int, int> eleToFreq; // Stores the frequency of each element
            map<int, vector<int>> freqToEle; // Maps frequency to a list of elements with that frequency
            
            // Count the frequency of each element in nums
            for (int i = 0; i < nums.size(); i++) 
            {
                if (eleToFreq.find(nums[i]) == eleToFreq.end()) 
                {
                    eleToFreq[nums[i]] = 1; // First occurrence of the element
                    freqToEle[1].push_back(nums[i]); // Store element under frequency 1
                } 
                else 
                {
                    int old_freq = eleToFreq[nums[i]]; // Get the current frequency of the element
                    vector<int>& vec = freqToEle[old_freq]; // Get the vector of elements with that frequency
                    
                    // Remove the element from the old frequency list
                    for (int j = 0; j < vec.size(); j++) 
                    {
                        if (vec[j] == nums[i]) 
                        {
                            vec.erase(vec.begin() + j);
                            break;
                        }
                    }
    
                    eleToFreq[nums[i]]++; // Increase the frequency of the element
                    freqToEle[eleToFreq[nums[i]]].push_back(nums[i]); // Add element to the new frequency list
                }
            }
            
            vector<int> ans; // Store the k most frequent elements
            
            // Iterate through the frequency map in descending order (from highest frequency)
            for (auto it = freqToEle.rbegin(); it != freqToEle.rend(); it++) 
            {
                vector<int>& elements = it->second; // Get the list of elements with the current frequency
                
                // Add elements to the result list until we reach k elements
                for (int i = 0; i < elements.size(); i++) 
                {
                    ans.push_back(elements[i]);
                    if (ans.size() == k) 
                    {
                        return ans; // Return the result when k elements are added
                    }
                }
            }
    
            return ans; // In case we somehow don't reach k elements (though guaranteed by constraints)
        }
    };