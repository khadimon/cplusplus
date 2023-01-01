#ifndef C_PLUS_PLUS_HELPERS_H
#define C_PLUS_PLUS_HELPERS_H

#include <vector>
#include "classes.h"

using namespace std;

int GetLongestNameInTeam(vector<Player> team) {
    int maxLength = 0;
    for (int i = 0; i < team.size(); i++) {
        if (team[i].GetName().length() > maxLength) {
            maxLength = team[i].GetName().length();
        }
    }

    return maxLength;
}

void showTeams(vector<Player> team1, vector<Player> team2) {
    int LNT1 = GetLongestNameInTeam(team1);
    int LNT2 = GetLongestNameInTeam(team2);
    int offset = 10;
    int trailingOffset = 7;
    int leadingOffset = 5;

    int totalSkillT1 = 0;
    int totalSkillT2 = 0;

    cout << setw(leadingOffset + LNT1) << "Team 1";
    cout << setw(offset) << " ";
    cout << setw(trailingOffset + LNT2 - 2) << "Team 2";
    cout << endl;
    cout << setfill('-') << setw(leadingOffset + LNT1 + offset + LNT2 + trailingOffset) << '-' << endl;

    for (int i = 0; i < team1.size(); i++) {
        cout << setfill(' ') << setw(leadingOffset + LNT1) << team1[i].GetName();
        cout << setw(offset) << " ";
        cout << setw(LNT2 + leadingOffset) << team2[i].GetName();
        cout << endl;

        totalSkillT1 += team1[i].GetSkill();
        totalSkillT2 += team2[i].GetSkill();
    }
    cout << setfill('-') << setw(leadingOffset + LNT1 + offset + LNT2 + trailingOffset) << '-' << endl;

    cout << setfill(' ') << setw(leadingOffset + LNT1 - 2) << "T1 Skill: " << totalSkillT1;
    cout << setw(offset) << " ";
    cout << setw(LNT2 + leadingOffset - 2) << "T2 Skill: " << totalSkillT2;
}

vector<Player> SortQueue(vector<Player> queue) {
    vector<Player> result = vector<Player>();

    for (int i = 0; i < queue.size(); i++) {
        bool isInserted = false;
        for (int j = 0; j < result.size(); j++) {
            if (result[j].GetSkill() < queue[i].GetSkill()) {
                result.insert(result.begin() + j, queue[i]);
                isInserted = true;
                break;
            }
        }
        if (!isInserted) {
            result.push_back(queue[i]);
        }
    }

    return result;
}

#endif //C_PLUS_PLUS_HELPERS_H
