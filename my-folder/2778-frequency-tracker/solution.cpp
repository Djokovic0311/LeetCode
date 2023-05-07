class FrequencyTracker {
private:
    unordered_map<int, int> numberToFrequency;
    unordered_map<int, int> frequencyToCount;

public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        // Decrease the count of the current frequency
        int oldFrequency = numberToFrequency[number];
        frequencyToCount[oldFrequency]--;

        // Increase the frequency of the number
        numberToFrequency[number]++;

        // Increase the count of the new frequency
        int newFrequency = numberToFrequency[number];
        frequencyToCount[newFrequency]++;
    }
    
    void deleteOne(int number) {
        if (numberToFrequency.find(number) != numberToFrequency.end()) {
            // Decrease the count of the current frequency
            int oldFrequency = numberToFrequency[number];
            frequencyToCount[oldFrequency]--;

            // Decrease the frequency of the number
            numberToFrequency[number]--;

            // If the number's frequency is 0, remove it from the numberToFrequency map
            if (numberToFrequency[number] == 0) {
                numberToFrequency.erase(number);
            } else {
                // Increase the count of the new frequency
                int newFrequency = numberToFrequency[number];
                frequencyToCount[newFrequency]++;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return frequencyToCount[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
