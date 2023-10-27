//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n = S.size(); 
        int stringlent = substring(S);
        return (n - stringlent); 
    }
    
     int substring(string S) { 
        int n = S.size(); 
        int L[n][n]; 
        for (int i = 0; i < n; i++) 
        {    
            L[i][i] = 1;
        }
        for (int colm = 2; colm<= n; colm++) 
        { 
            for (int i = 0; i < n - colm + 1; i++) { 
                int j = i + colm - 1; 
                // If the characters at both positions are same and the length is 2
                if (S[i] == S[j] && colm == 2) 
                    L[i][j] = 2; 
                // If the characters at both positions are same
                else if (S[i] == S[j]) 
                    L[i][j] = L[i + 1][j - 1] + 2; 
                // If the characters at both positions are different
                else
                    L[i][j] = max(L[i][j - 1], L[i + 1][j]); 
            } 
        } 
        // Returning the length of the longest palindromic subsequence
        return L[0][n - 1]; 
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends