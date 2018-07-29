/* *题目：
 *  729
 *  My Calendar I
 * *思路：
 *  
 */

class MyCalendar {
    vector<int> lefts;
    map<int, pair<int, int>> mp;
public:
    MyCalendar() {
        
    }
    
    void insert(int pos, int start, int end){
        mp[start] = make_pair(start, end); // map
        lefts.insert(lefts.begin() + pos, start); //only start
    }
    
    bool book(int start, int end) {
		if (lefts.size() == 0) {
			insert(0, start, end);
			return true;
		}

		int possibleRow;
		if (binarySearch(lefts, start, possibleRow)) {
			return false;
		}

		// left
		if (possibleRow == 0) {
			if (end <= mp[lefts[possibleRow]].first) {
				insert(possibleRow, start, end);
				return true;
			}
			return false;
		}

		// right
		if (possibleRow == lefts.size()) {
			if (start >= mp[lefts[possibleRow - 1]].second) {
				insert(possibleRow, start, end);
				return true;
			}
			return false;
		}

		// mid
		if (start >= mp[lefts[possibleRow - 1]].second && end <= mp[lefts[possibleRow]].first) {
			insert(possibleRow, start, end);
			return true;
		}
		return false;
	}
    
    bool binarySearch(vector<int>& arr, int target, int& possibleRow){
        int low = 0, high = arr.size()-1;
        int mid;
        while(low <= high){
            mid = low + (high-low) / 2;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            } 
        }
        possibleRow = low; // find possible interval
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */