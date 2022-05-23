#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "vector.h"
#include "VectorIterator.h"
#include "VectorReverseIterator.h"

using namespace std;

void norm(vector<int>& c) {

    for (int i = 0; i < c.size() - 1; ++i) {
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
}

void trim(vector<int>& c, int x) {
    c.resize(x + 1);
    c[x] &= 0;
}

vector<int> add(const vector<int>& a, const vector<int>& b, int k) {
    vector<int> c(max(a.size(), b.size()) + 1);
    for (int i = 0; i < c.size(); ++i) {
        if (i < (int)a.size()) c[i] += a[i];
        if (i < (int)b.size()) c[i] += b[i];
    }
    norm(c);
    trim(c, k);
    return c;
}

int get_bit(const vector<int>& v, int b) {
    return v[b] & 1;
}

vector<int> mul(const vector<int>& a, int x, int k) {
    vector<int> b = a;
    b.push_back(0);

    for (int& i : b) {
        i *= x;
    }
    norm(b);
    trim(b, k);
    return b;
}

void gen(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<pair<int, vector<int>> >& v) {
    if (i == k) {
        n.resize(k + 1);
        if (get_bit(n, k)) v.emplace_back(k, n);
        return;
    }
    if (get_bit(n, i)) return;
    gen(n, p, k, i + 1, v);
    if (i) gen(add(n, p[i], k + 1), p, k, i + 1, v);
}



int main() {

    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    --n;

    vector<pair<int, vector<int>> > v;
    for (int k = 1; n / 2 >= v.size(); ++k) {
        vector<int> vec(k + 1);
        vector<vector<int>> p(k + 1);
        vec[k] = 1;

        p[0].push_back(1);
        trim(p[0], k + 1);

        for (int i = 0; i < k; ++i) {
            p[i + 1] = mul(p[i], 10, k + 1);
        }
        gen(vec, p, k, 0, v);

    }

    for (auto& i : v) {
        reverse(i.second.begin(), i.second.end());
    }

    std::cout << std::endl;

    sort(v.begin(), v.end());


    std::cout << std::endl;
    --n;
    vector<int> w = v[n / 2].second;
    reverse(w.begin(), w.end());
    if (n & 1) w[0] ^= 1;

    for (int k = v[n / 2].first; k >= 0; --k) {
        cout << get_bit(w, k);
    }
    cout << '\n';

    return 0;

    
}