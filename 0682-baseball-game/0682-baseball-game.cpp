class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (const string& op : operations) {
            if (op == "+") {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top1); 
                st.push(top1 + top2);
            } else if (op == "D") {
                st.push(st.top() * 2);
            } else if (op == "C") {
                st.pop();
            } else {
                st.push(stoi(op));
            }
        }

        int total = 0;
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }
        return total;
    }
};