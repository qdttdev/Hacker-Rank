// How to copy elements from vector to a stack:
// https://stackoverflow.com/questions/34452633/copy-elements-from-stdvector-into-stdstack-c

// How to erase duplicates in vector:
// https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// APPROACH: We will store the 'ranked' score inside a stack (smallest score at top)
// and compare it with the smallest score of the player to decide ranking. We will
// pop the smallest 'ranked' score if the smallest player's score is GREATER than the
// smallest 'ranked' score. We use the 'ranked' stack size to keep track of the ranking.

// RANKED:  60, 75, 80, 90, 100 (Stack: top --> bottom)
// PLAYER:  50, 65, 77, 90, 102 (Vector: begin --> end)

// i = 0:   Compare 50 >= 60 (False)    --> size = 5 (same)     --> 6
// RANKED REMAINED: 60, 75, 80, 90, 100

// i = 1:   Compare 65 >= 60 (True)     --> size = 4 (pop 60)
//          Compare 65 >= 75 (False)    --> size = 4 (same)     --> 5
// RANKED REMAINED: 75, 80, 90, 100

// i = 2:   Compare 77 >= 75 (True)     --> size = 3 (pop 75)
//          Compare 77 >= 80 (False)    --> size = 3 (same)     --> 4
// RANKED REMAINED: 80, 90, 100

// i = 3:   Compare 90 >= 80 (True)     --> size = 2 (pop 80)
//          Compare 90 >= 90 (True)     --> size = 1 (pop 90)
//          Compare 90 >= 100 (False)   --> size = 1 (same)     --> 2
// RANKED REMAINED: 100

// i = 4:   Compare 102 >= 100 (True)   --> size = 0 (pop 100)  --> 1

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) 
{
    vector<int> playerRank;
    
    // Remove duplicates inside 'ranked' vector
    ranked.erase( unique(ranked.begin(), ranked.end()), ranked.end() );
    
    // Store 'ranked' into a stack called 'rankedStack'
    stack<int, vector<int>> rankedStack(ranked);
    
    // Loops through the player's score to decide their rank
    for(int i = 0; i < player.size(); i++)
    {
        // Compare player's smallest score with the smallest score in 'rankedStack'
        // If the player's smallest score is GREATER than the smallest ranked score
        // then their ranked is ABOVE the smallest ranked score.
        while(!rankedStack.empty() && (player[i] >= rankedStack.top()))
        {           
            // Since the player's score are in ascending order, it is guaranteed
            // that the next player's score is greater than the previous one,
            // thus, we can pop the top-position score in rankedStack
            // and use it as a way to keep track of the ranking.
            rankedStack.pop();
        }
        playerRank.push_back(rankedStack.size()+1);
    }
    
    return playerRank;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
