#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <string>
class Move {
private:
    std::string moveName;
protected:
    std::vector<std::string> strongerAgainst;

public:
    virtual std::string getName() const;
    virtual std::vector<std::string> getStrongerAgainst() = 0;
};
#endif