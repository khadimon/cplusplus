#ifndef C_PLUS_PLUS_CLASSES_H
#define C_PLUS_PLUS_CLASSES_H

#include <string>

using namespace std;

class Player {
public:
    Player() {
        this->name = "No name";
        this->skill = 0;
    };

    void SetName(string n) {
        this->name = n;
    }

    void SetSkill(int s) {
        this->skill = s;
    }

    string GetName() {
        return this->name;
    }

    int GetSkill() {
        return this->skill;
    }

private:
    string name;
    int skill;
};

#endif //C_PLUS_PLUS_CLASSES_H
