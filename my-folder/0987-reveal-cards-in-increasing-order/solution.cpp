class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Sort by increasing order.
        sort(deck.begin(), deck.end());
        
        // Return the ans if there are max 2 elements since it's already sorted.
        if (deck.size() <= 2)
        {
            return deck;
        }
        
        // For more than 2 elements.
        deque<int> ans;
        ans.push_front(deck.back());
        deck.pop_back();
        
        while (!deck.empty())
        {
            int temp = ans.back();
            ans.pop_back();
            ans.push_front(temp);
            ans.push_front(deck.back());
            deck.pop_back();
        }

        return vector<int>(ans.begin(), ans.end());        
    }
};
