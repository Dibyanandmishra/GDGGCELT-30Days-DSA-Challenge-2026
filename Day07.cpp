// Median Updates

// The median of M numbers is defined as the middle number after sorting them in order if M is odd. Or it is the average of the middle two numbers if M is even. You start with an empty number list. Then, you can add numbers to the list, or remove existing numbers from it. After each add or remove operation, output the median.

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void median(vector<char> s, vector<int> X) {
    multiset<long long> lower, upper;

    auto rebalance = [&]() {
        while (!lower.empty() && !upper.empty() &&
               *lower.rbegin() > *upper.begin()) {
            long long lo = *lower.rbegin();
            long long up = *upper.begin();
            lower.erase(lower.find(lo));
            upper.erase(upper.begin());
            lower.insert(up);
            upper.insert(lo);
        }
        while (lower.size() > upper.size() + 1) {
            long long lo = *lower.rbegin();
            lower.erase(lower.find(lo));
            upper.insert(lo);
        }
        while (upper.size() > lower.size()) {
            long long up = *upper.begin();
            upper.erase(upper.begin());
            lower.insert(up);
        }
    };

    auto printMedian = [&]() {
        long long total = (long long)(lower.size() + upper.size());
        if (total == 0) {
            cout << "Wrong!\n";
            return;
        }
        if (total % 2 == 1) {
            cout << *lower.rbegin() << "\n";
        } else {
            long long lo = *lower.rbegin();
            long long up = *upper.begin();
            long long sum = lo + up;
            if (sum % 2 == 0) {
                cout << sum / 2 << "\n";
            } else {
                long long half;
                if (sum > 0) {
                    half = sum / 2; 
                } else {
                    half = (sum - 1) / 2;  
                    half = sum / 2; 
                }
                if (sum < 0) {
                    
                    cout << half << ".5\n"; 
                } else {
                    cout << half << ".5\n";
                }
            }
        }
    };
    auto printMedianClean = [&]() {
        long long total = (long long)(lower.size() + upper.size());
        if (total == 0) {
            cout << "Wrong!\n";
            return;
        }
        if (total % 2 == 1) {
            cout << *lower.rbegin() << "\n";
        } else {
            long long lo = *lower.rbegin();
            long long up = *upper.begin();
            long long sum = lo + up;
            if (sum % 2 == 0) {
                cout << sum / 2 << "\n";
            } else {
                if (sum > 0) {
                    cout << sum/2 << ".5\n"; 
                } else if (sum == -1) {
                    cout << "-0.5\n";   
                } else {
                    cout << sum/2 << ".5\n";
                }
            }
        }
    };

    int n = s.size();
    for (int i = 0; i < n; i++) {
        char op = s[i];
        long long x = X[i];

        if (op == 'a') {
            if (lower.empty() || x <= *lower.rbegin())
                lower.insert(x);
            else
                upper.insert(x);
            rebalance();
            printMedianClean();
        } else {
            auto it_lo = lower.find(x);
            auto it_up = upper.find(x);

            if (it_lo == lower.end() && it_up == upper.end()) {
                cout << "Wrong!\n";
                continue;
            }

            if (it_lo != lower.end())
                lower.erase(it_lo);
            else
                upper.erase(it_up);

            rebalance();
            printMedianClean();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for (int i = 0; i < N; i++) {
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s, X);
    return 0;
}