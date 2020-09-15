Permite hallar el elemento minimo para todos los subarreglos de un largo fijo en O(n). Para Max queue cambiar el > por <.

struct mnque {
    deque<int> dq, mn;
    
    void push(int x) {
        dq.push_back(x);
        while (mn.size() && mn.back() > x) mn.pop_back();
        mn.push_back(x);
    }
    
    void pop() {
        if (dq.front() == mn.front()) mn.pop_front();
        dq.pop_front();
    }
    
    int min() { return mn.front(); }
};