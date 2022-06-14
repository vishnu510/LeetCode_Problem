class MedianFinder {
    priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	int size;

public:
    MedianFinder() {
        max_pq = priority_queue<int>();
		min_pq = priority_queue<int, vector<int>, greater<int>>();
		size = 0;
    }
    
    void addNum(int num) {
        size++;
		max_pq.push(num);
		if(int(min_pq.size()))
		while(max_pq.top() > min_pq.top()){
			min_pq.push(max_pq.top());
			max_pq.pop();
		}
		while(max_pq.size() > min_pq.size()+1){
			min_pq.push(max_pq.top());
			max_pq.pop();
		}
		while(1+max_pq.size() < min_pq.size()){
			max_pq.push(min_pq.top());
			min_pq.pop();
		}
    }
    
    double findMedian() {
        if(size&1) {
			if(max_pq.size() > min_pq.size()) return max_pq.top();
			return min_pq.top();
		}
		else return (max_pq.top() + min_pq.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */