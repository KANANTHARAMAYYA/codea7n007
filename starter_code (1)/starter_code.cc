#include <bits/stdc++.h>
using namespace std;

vector<int> GetHIndexScore(vector<int> citations) {
  vector<int> h_index;
  map<int,int> m;
  for(auto x : citations)
    m[x] += 1;
  h_index.push_back(1);
  for(int i = 1; i < citations.size(); ++i){
    int thresold = i + 1;
    int temp = 0;
    int temp_max = INT_MIN;
    while(thresold >= 1 and thresold > h_index[i-1]){
      temp = 0;
      for(int j = i; j >= 0; j--){
        if(citations[j] >= thresold)
          temp+=1;
      }
      thresold--;
      temp_max = max(temp_max,temp);
    }
    h_index.push_back(temp_max);
  }
  return h_index;
}

int main() {
  int tests;
  cin >> tests;
  for (int test_case = 1; test_case <= tests; test_case++) {
    // Get number of papers for this test case
    int paper_count;
    cin >> paper_count;
    // Get number of citations for each paper
    vector<int> citations(paper_count);
    for (int i = 0; i < paper_count; i++) {
      cin >> citations[i];
    }
    vector<int> answer = GetHIndexScore(citations);
    cout << "Case #" << test_case << ": ";
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
