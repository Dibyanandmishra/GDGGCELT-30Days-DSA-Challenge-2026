// Down to Zero II

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<int> dp(1000001, INT_MAX);
bool precomputed = false;

void preprocess() {
    dp[0] = 0;

    for (int i = 1; i <= 1000000; i++) {

        // Decrease by 1
        dp[i] = min(dp[i], dp[i - 1] + 1);

        // Factor operation
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                int nxt = max(j, i / j);

                dp[i] = min(dp[i], dp[nxt] + 1);
            }
        }
    }
}

int downToZero(int n) {

    if (!precomputed) {
        preprocess();
        precomputed = true;
    }

    return dp[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(),
        not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(),
        not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}