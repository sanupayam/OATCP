#include <bits/stdc++.h>

using namespace std;

// Function to generate subsequences of a string
vector<string> generateSubsequences(const string &str, string current, int index, int length)
{
    vector<string> result;

    // Base case: if desired length of subsequence is achieved
    if (length == 0)
    {
        result.push_back(current);
        return result;
    }

    // Base case: if index exceeds string length
    if (index == str.length())
    {
        return result;
    }

    // Recursive call including current character
    vector<string> withCurrent = generateSubsequences(str, current + str[index], index + 1, length - 1);
    result.insert(result.end(), withCurrent.begin(), withCurrent.end());

    // Recursive call excluding current character
    vector<string> withoutCurrent = generateSubsequences(str, current, index + 1, length);
    result.insert(result.end(), withoutCurrent.begin(), withoutCurrent.end());

    return result;
}

int main()
{
    ifstream infile;
    infile.open("input.txt"); // Open input file
    int n; 
    set<string> uniqueSubsequences; 
    cin >> n; 
    vector<vector<string>> allSubsequences; 
    ofstream outfile;
    outfile.open("out.txt"); // Open output file
    for (int i = 0; i < n; i++)
    {
        string inputString; 
        cin >> inputString; 
        infile >> inputString; 
        outfile << "\n";
        vector<string> ans;
        for (int len = 1; len <= 4; ++len) 
        {
            vector<string> subs = generateSubsequences(inputString, "", 0, len); // Generate subsequences
            for (int j = 0; j < subs.size(); j++)
            {
               
                if (uniqueSubsequences.find(subs[j]) == uniqueSubsequences.end())
                {
                    ans.push_back(subs[j]);
                    uniqueSubsequences.insert(subs[j]);
                }
            }
        }
        allSubsequences.push_back(ans); 
    }
   
    for (int i = 0; i < allSubsequences.size(); i++)
    {
        for (int j = 0; j < allSubsequences[i].size(); j++)
        {
            cout << allSubsequences[i][j] << endl; 
            outfile << allSubsequences[i][j]; 
            outfile << "\n"; 
        }
        outfile << "\n"; 
    }
    cout << "\n"; 
    outfile << "\n"; 
    outfile << "\n"; 
    infile.close(); 
    outfile.close(); 

    return 0;
}
