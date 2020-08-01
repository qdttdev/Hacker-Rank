#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*************************************************************

    4 5         n = number of attendees = 4 (rows)
                m = number of topics    = 5 (cols)

    10101    (1)
    11100    (2)
    11010    (3)
    00101    (4)

    -----------------------------------------------------------

                            [OR]
    (1,2)   = (1) = 10101 = 11101 = 4 topics
            = (2) = 11100

    (1,3)   = (1) = 10101 = 11111 = 5 topics ***
            = (3) = 11010

    (1,4)   = (1) = 10101 = 10101 = 3 topics
            = (4) = 00101

    (2,3)   = (2) = 11100 = 11110 = 4 topics
            = (3) = 11010

    (2,4)   = (2) = 11100 = 11101 = 4 topics
            = (4) = 00101

    (3,4)   = (3) = 11010 = 11111 = 5 topics ***
            = (4) = 00101

    --> ANSWER: [5,2]   --> Max 5 topics
                        --> Max 2 teams

    ---------------------------------------------------------

    OBJECTIVE:  Compare each column elements between rows
                and output max topic known.

*************************************************************/

// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> topic) 
{
    vector<int> maxTopicsAndTeam;
    vector<int> maxTopicKnowList;
    int topicKnow = 0;
    int maxTopic = 0;
    int maxTeam = 1;

    // Goes through (1,_) (2,_) (3,_)
    for(int i = 0; i < topic.size() - 1; i++)
    {
        // Goes through (_,2) (_,3) (_,4)
        for(int j = i+1; j < topic.size(); j++)
        {
            // Compares column elements between rows
            for(int k = 0; k < topic[0].size(); k++)
            {
                if(topic[i][k] == '1' || topic [j][k] == '1')
                {
                    topicKnow++;
                }
            }

            maxTopicKnowList.push_back(topicKnow);
            topicKnow = 0;
        }
    }
    
    // Find maxTopic and maxTeam
    for(int i = 0; i < maxTopicKnowList.size(); i++)
    {
        if(maxTopic == maxTopicKnowList[i])
        {
            maxTeam++;
        }
        else if(maxTopic < maxTopicKnowList[i])
        {
            maxTopic = maxTopicKnowList[i];
            maxTeam = 1;
        }
    }
    
    maxTopicsAndTeam.push_back(maxTopic);
    maxTopicsAndTeam.push_back(maxTeam);

    return maxTopicsAndTeam; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

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

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
