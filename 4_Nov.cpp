class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxTimeToLeft = 0;
        int maxTimeToRight = 0;

        for (int i=0;i<left.size();i++) {
            maxTimeToLeft = max(maxTimeToLeft, left[i]);
        }

        for (int i=0;i<right.size();i++) {
            maxTimeToRight = max(maxTimeToRight, n - right[i]);
        }
        return max(maxTimeToLeft, maxTimeToRight);
    }
};