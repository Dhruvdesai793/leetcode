// Follow-up : Using 1 queue
class MyStack {
public:
    queue<int> que;

    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
        int n = que.size(); 

        for(int i=0; i<n-1; i++){ // rotate queue by n-1 so that last bcoms 1st;
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int result = que.front();
        que.pop();

        return result;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};