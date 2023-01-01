/*

1. Khadichabonu Valieva
2. Emily Robinson

Assignment: Activity 5

*/


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "classes.h"
#include "helpers.h"

using namespace std;

Player parsePlayerFromLine(string line) {
    Player player = Player();
    string name;
    string skill;
    bool nameFound = false;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',' || line[i] == ';') {
            nameFound = true;
            continue;
        }

        if (!nameFound) {
            name += line[i];
        } else {
            skill += line[i];
        }
    }

    player.SetName(name);
    player.SetSkill(stoi(skill));
    return player;
}

int main() {
    vector<Player> queue = vector<Player>();
    string filename = "../players.csv";

    string line;
    ifstream file;
    file.open(filename);

    if (file.is_open()) {
        while (getline(file, line)) {
            queue.push_back(parsePlayerFromLine(line));
        }
        file.close();
    } else {
        cout << "Unable to open file";
        return 0;
    }

    vector<Player> sortedQueue = SortQueue(queue);

    vector<Player> team1 = vector<Player>();
    vector<Player> team2 = vector<Player>();

    for (int i = 0; i < sortedQueue.size(); i++) {
        if (i % 2 == 0) {
            team1.push_back(sortedQueue[i]);
        }else{
            team2.push_back(sortedQueue[i]);
        }
    }

    showTeams(team1, team2);

    file.close();
    return 0;
}
