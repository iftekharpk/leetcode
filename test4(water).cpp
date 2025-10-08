#include <bits/stdc++.h>
using namespace std;

pair<int,int> mx_w_h(vector<int>& height) {
    int n = height.size();

    
    int maxh = *max_element(height.begin(), height.end());
    int secondmaxh = INT_MIN;

    for (int h : height) {
        if (h != maxh) {
            secondmaxh = max(secondmaxh, h);
        }
    }

 
    if (secondmaxh == INT_MIN) 
    secondmaxh = maxh;

    int leftidx = n, rightidx = n;

    for (int i = 0; i < n; i++) {
        if (height[i] >= secondmaxh) {
            for (int j = i + 1; j < n; j++) {
                if (height[j] >= secondmaxh && min(height[i], height[j]) == secondmaxh) {
                    if (i < leftidx || (i == leftidx && j < rightidx)) {
                        leftidx = i;
                        rightidx = j;
                    }
                }
            }
        }
    }

    return {leftidx, rightidx};
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> height(n);
        for(int i = 0; i < n; i++) cin >> height[i];

        pair<int,int> res = mx_w_h(height);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
