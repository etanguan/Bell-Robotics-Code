#include "main.h"

static const pros::Motor FlyWheelMotor(15, pros::E_MOTOR_GEAR_BLUE,true);
static const pros::Motor IndexMotor(14);

inline void set_flywheel_speed(int32_t speed) {
<<<<<<< HEAD
    FlyWheelMotor.move_velocity(speed); 
=======
    FlyWheelMotor.move_velocity(speed);
>>>>>>> refs/remotes/origin/master
}

inline void set_indexer_speed(int32_t speed) {
    IndexMotor.move(speed);
<<<<<<< HEAD
}
=======
}

>>>>>>> refs/remotes/origin/master
