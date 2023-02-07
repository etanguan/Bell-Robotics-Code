#include "main.h"

#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"

#include "Motors.hpp"

#include "PickUp.hpp"
#include "FlyWheel.hpp"

inline void on_autonomous() {
    set_intake_speed(127);
    forwards(30, 600);
    rotate(10, 100, true);
    set_flywheel_speed(500);
    rotate(20, 725, true);
    pros::delay(2000);
    set_intake_speed(0);
    set_indexer_speed(60);
    pros::delay(2000);
}