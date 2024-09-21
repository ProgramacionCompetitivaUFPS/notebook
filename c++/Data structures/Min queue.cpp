> Funciona como una queue<> que además permite hallar el elemento mínimo en O(1). Para mantener el máximo: cambiar > por <.

template<typename T>
struct mnque {
    deque<T> dq, mn;

    void push(T x) {
        dq.pb(x);
        while (mn.size() && mn.back() > x) mn.pop_back(); // o < para max
        mn.pb(x);
    }

    void pop() {
        if (dq.front() == mn.front()) mn.pop_front();
        dq.pop_front();
    }

    T min() { return mn.front(); }
};

mnque<int> q;
