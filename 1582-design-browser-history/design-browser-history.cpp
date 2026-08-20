class BrowserHistory {
public:
    stack<string> backk;
    stack<string> frwd;
    string curr;
    BrowserHistory(string homepage) { curr = homepage; }

    void visit(string url) {
        backk.push(curr);
        curr = url;
        frwd = stack<string>();
    }

    string back(int steps) {
        while (steps > 0 && !backk.empty()) {
            frwd.push(curr);
            curr = backk.top();
            backk.pop();
            steps--;
        }
        return curr;
    }

    string forward(int steps) {
        while (steps > 0 && !frwd.empty()) {
            backk.push(curr);
            curr = frwd.top();
            frwd.pop();
            steps--;
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */