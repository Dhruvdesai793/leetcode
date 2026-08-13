class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> store;
        for(char c: s){
            if (!store.empty() && store.top() == c ){
                store.pop();
            }
            else store.push(c);
        }

        string result = "";
        while(!store.empty()){
            result += store.top();
            store.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};