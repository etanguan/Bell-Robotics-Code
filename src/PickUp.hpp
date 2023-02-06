#include "main.h"

static const pros::Motor PickUp(5);

inline void set_intake_speed(int32_t speed) {
    PickUp.move(speed);
}