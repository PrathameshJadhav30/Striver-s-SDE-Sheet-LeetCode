// https://leetcode.com/problems/online-stock-span/description/
class StockSpanner {
    public:
        stack<pair<int, int>> s; // Stack to store (price, span) pairs
    
        // Constructor to initialize the StockSpanner object
        StockSpanner() { }
        
        int next(int price) {
            int span = 1; // Each price has at least a span of 1 (itself)
    
            // While the stack is not empty and the top price is <= current price,
            // pop elements and add their spans to the current span.
            while (!s.empty() && s.top().first <= price) {
                span += s.top().second; // Add the span of the popped element
                s.pop(); // Remove the smaller price from the stack
            }
            
            // Push the current price along with its calculated span to the stack
            s.push({price, span});
            
            // Return the calculated span for the current price
            return span;
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */
    