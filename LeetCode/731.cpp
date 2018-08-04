/* *题目：
 *  731
 *  My Calendar II
 * *思路：
 *  
 */

class MyCalendarTwo {
    vector<pair<int, int>> lines;
    vector<pair<int, int>> doubles; // existing intersection
    
public:
    MyCalendarTwo() {
        
    }
    
    bool exist(pair<int, int>& lineA, pair<int, int>& lineB, pair<int, int>& out){
        if(lineA.second <= lineB.first || lineB.second <= lineA.first){
            return false;
        }
        
        out = make_pair(max(lineA.first, lineB.first), min(lineA.second, lineB.second));
        return true;
    }
    
    bool book(int start, int end) {
        pair<int, int> newline = make_pair(start, end);
        
        for(int i = 0; i < doubles.size(); i++){
            pair<int, int> out;
            if(exist(doubles[i], newline, out)){ // if triple
                return false;
            }
        }
        
        for(int i = 0; i < lines.size(); i++){
            pair<int, int> out;
            if(exist(lines[i], newline, out)){
                doubles.push_back(out);
            }
        }
        
        lines.push_back(newline);
        
        return true;
    } 
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */