//
// Created by Nat on 5/23/2021.
//

#ifndef SPACEGAME_STATES_H
#define SPACEGAME_STATES_H


#include <vector>
#include <SFML/Graphics.hpp>

class States
{
private:
    std::vector<bool> objectStates;
public:
    States();
    enum states {playerMovement, NORMAL, HIDDEN, FADE, LAST,HOVERED,GAMEOVER,POINT,PLAYERWIN,PLAYERTRAVEL};
    bool checkState(states state) const;
    void enableState(states state);
    void disableState(states state);

};


#endif //SPACEGAME_STATES_H
