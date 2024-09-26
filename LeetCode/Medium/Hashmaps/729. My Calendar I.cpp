class MyCalendar {
public:
    map<int, int> m;
    // A map to store booked intervals, where key is 'end' time and value is 'start' time.

    MyCalendar() {
        // Constructor (empty since no initialization is needed for the map)
    }
    
    bool book(int start, int end) {
        // Find the first interval in 'm' with a start time greater than 'start'.
        auto p = m.upper_bound(start);

        // Check if there is no such interval (p == m.end()) or if the current interval does not overlap.
        // It means 'end' time should be less than or equal to 'p->second' (the start time of the next interval).
        if (p == m.end() || end <= p->second) {
            // If no overlap, insert the new interval [start, end) into the map with 'end' as the key and 'start' as the value.
            m[end] = start;
            return true; // Successfully booked the interval.
        } 
        return false; // Overlap detected, unable to book the interval.
    }
};
static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
