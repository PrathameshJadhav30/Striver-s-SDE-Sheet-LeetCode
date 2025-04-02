// https://leetcode.com/problems/number-of-recent-calls/description
class RecentCounter {
    public:
          queue<int> requests; // Queue to store timestamps of requests
    
        RecentCounter() {
            // Constructor: Initializes an empty queue
        }
        
        int ping(int t) {
            // Add the current request timestamp to the queue
            requests.push(t); 
            
            // Remove outdated requests that are older than (t - 3000)
            while (!requests.empty() && requests.front() < t - 3000)
             {
                requests.pop(); 
            }
            
            // Return the number of valid requests in the last 3000 milliseconds
            return requests.size(); 
        }
    };
    
    /**
     * Your RecentCounter object will be instantiated and called as such:
     * RecentCounter* obj = new RecentCounter();
     * int param_1 = obj->ping(t);
     */