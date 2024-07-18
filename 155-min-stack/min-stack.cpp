class MinStack {
public:
    stack<int> st;
    stack<int> mini;
    MinStack() {}

    void push(int val) {
        if (st.empty())
            mini.push(val);
        else {
            cout << "miniminum val" << st.top() << "  " << val << endl;
            mini.push(min(mini.top(), val));
        }
        st.push(val);
        cout << "push  " << val << endl;
    }

    void pop() {
        cout << st.top() << "  " << mini.top() << endl;
        st.pop();
        mini.pop();
    }

    int top() {
        cout << st.top();
        return st.top();
    }

    int getMin() {
        cout << mini.top();

        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */