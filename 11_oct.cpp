
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    //    method 1
        // int count=0;
        // int f=flowers.size();
        // int p=people.size();
        // vector<int> ans;
        // int i=0;

        // while(i<p)
        // {
        //     int index=people[i];
        //     for(int j=0;j<f;j++)
        //     {
        //         if(index>=flowers[j][0] && index<=flowers[j][1] )
        //         {
        //             count++;
        //         }
        //     }
        //     ans.push_back(count);
        //     count=0;
        //     i++;
        // }
        // return ans;

        // try 2
        vector<int> st, bl; // Initialize vectors to store start and bloom times.
        int n = flowers.size();

        // Extract start and bloom times from the flowers array and store them in separate vectors.
        for (auto i : flowers) {
            int x = i[0];
            int y = i[1];
            st.push_back(x);
            bl.push_back(y);
        }

        // Sort the start and bloom time vectors in ascending order.
        sort(st.begin(), st.end());
        sort(bl.begin(), bl.end());

        vector<int> v; // Initialize a result vector to store bloom statuses.

        // Iterate through each person's bloom time.
        for (int i = 0; i < people.size(); i++) {
            // Calculate the number of flowers blooming at or before the person's bloom time.
            int p = st.size() - (upper_bound(st.begin(), st.end(), people[i]) - st.begin());

            // Calculate the number of flowers blooming at or after the person's bloom time.
            int q = bl.size() - (lower_bound(bl.begin(), bl.end(), people[i]) - bl.begin());

            // Calculate the bloom status for the person and store it in the result vector.
            v.push_back(q - p);
        }

        return v; 
    }
};