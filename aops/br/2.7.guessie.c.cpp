#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int find_max_score(const string& guessie_answers, 
                   const vector<int>& friend_scores,
                   const vector<string>& friend_answers) {
    int n_questions = guessie_answers.length();
    
    // For each position, track if it must be True (1), must be False (0), or could be either (-1)
    vector<bool> must_be_true(n_questions, false);
    vector<bool> must_be_false(n_questions, false);
    
    // For each friend's answers and score
    for (int f = 0; f < friend_scores.size(); f++) {
        int score = friend_scores[f];
        const string& answers = friend_answers[f];
        
        // Count matching and non-matching positions with Guessie
        vector<int> matching_positions;
        vector<int> non_matching_positions;
        
        for (int i = 0; i < n_questions; i++) {
            if (answers[i] == guessie_answers[i]) {
                matching_positions.push_back(i);
            } else {
                non_matching_positions.push_back(i);
            }
        }
        
        // Try all possible distributions of correct answers
        for (int correct_matching = max(0, score - (int)non_matching_positions.size());
             correct_matching <= min(score, (int)matching_positions.size());
             correct_matching++) {
            
            int correct_non_matching = score - correct_matching;
            
            // If this distribution is possible
            if (correct_non_matching <= non_matching_positions.size()) {
                // For positions where answers match:
                // If correct_matching of them are right, others must be wrong
                if (correct_matching == matching_positions.size()) {
                    for (int pos : matching_positions) {
                        must_be_true[pos] = true;
                    }
                } else if (correct_matching == 0) {
                    for (int pos : matching_positions) {
                        must_be_false[pos] = true;
                    }
                }
                
                // Similar for non-matching positions
                if (correct_non_matching == non_matching_positions.size()) {
                    for (int pos : non_matching_positions) {
                        must_be_false[pos] = true;
                    }
                } else if (correct_non_matching == 0) {
                    for (int pos : non_matching_positions) {
                        must_be_true[pos] = true;
                    }
                }
            }
        }
    }
    
    // Calculate Guessie's maximum possible score
    int max_score = 0;
    for (int i = 0; i < n_questions; i++) {
        // Check for contradictions
        if (!(must_be_true[i] && must_be_false[i])) {
            if (must_be_true[i]) {
                max_score++;
            } else if (!must_be_false[i]) {  // Could be either - assume correct for maximum
                max_score++;
            }
        }
    }
    
    return max_score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read input
    int N;
    cin >> N;
    
    string guessie_answers;
    cin >> guessie_answers;
    
    vector<int> friend_scores(N);
    vector<string> friend_answers(N);
    
    for (int i = 0; i < N; i++) {
        cin >> friend_scores[i] >> friend_answers[i];
    }
    
    // Calculate and print result
    int result = find_max_score(guessie_answers, friend_scores, friend_answers);
    cout << result << endl;
    
    return 0;
}