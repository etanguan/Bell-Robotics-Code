#include "main.h"

static const pros::Motor Endgame(20);

inline void set_endgame_speed(int32_t speed) {
    Endgame.move(speed);
}