// Queue using Two Stacks

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    stack<int> inStack, outStack;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            inStack.push(x);
        }
        else if (type == 2) {
            if (outStack.empty()) {
                while (!inStack.empty()) {
                    outStack.push(inStack.top());
                    inStack.pop();
                }
            }
            if (!outStack.empty()) {
                outStack.pop();
            }
        }
        else if (type == 3) {
            if (outStack.empty()) {
                while (!inStack.empty()) {
                    outStack.push(inStack.top());
                    inStack.pop();
                }
            }
            cout << outStack.top() << endl;
        }
    }

    return 0;
}
