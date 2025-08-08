#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s, int K) {
        int n = s.length();
        vector<int> diff(n + 1, 0);  // Difference array for O(N) solution
        
        // For each infected person, mark the range they affect using difference array
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                int left = max(0, i - K);
                int right = min(n - 1, i + K);
                diff[left]++;      // Start of infection range
                diff[right + 1]--; // End of infection range + 1
            }
        }
        
        // Calculate actual infections using prefix sum
        int count = 0;
        int current = 0;
        for(int i = 0; i < n; i++) {
            current += diff[i];
            if(current > 0) count++;   
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    
    // Test Example 1
    string s1 = "00100100";
    int K1 = 1;
    cout << "Input: s = \"" << s1 << "\", K = " << K1 << endl;
    cout << "Output: " << sol.solve(s1, K1) << endl;
    cout << "Explanation: Person at index 2 and 5 are initially infected." << endl;
    cout << "Person 2 infects range [1,3]. Person 5 infects range [4,6]." << endl;
    cout << "Final infected positions: 1,2,3,4,5,6 = 6 people" << endl;
    cout << endl;
    
    // Test Example 2
    string s2 = "0010100";
    int K2 = 1;
    cout << "Input: s = \"" << s2 << "\", K = " << K2 << endl;
    cout << "Output: " << sol.solve(s2, K2) << endl;
    cout << "Explanation: Person at index 2 and 4 are initially infected." << endl;
    cout << "Person 2 infects range [1,3]. Person 4 infects range [3,5]." << endl;
    cout << "Final infected positions: 1,2,3,4,5 = 5 people" << endl;
    cout << endl;
    
    // Large test case to show efficiency
    string s3 = "100000000000000000000000000001";
    int K3 = 5;
    cout << "Large Test:" << endl;
    cout << "Input: s = \"" << s3 << "\", K = " << K3 << endl;
    cout << "Output: " << sol.solve(s3, K3) << endl;
    cout << endl;
    
    return 0;
}