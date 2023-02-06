#include "main.h"

static const pros::Motor RF_Motor = pros::Motor(1);
static const pros::Motor RB_Motor = pros::Motor(2);
static const pros::Motor LF_Motor = pros::Motor(11, true);
static const pros::Motor LB_Motor = pros::Motor(12, true);

inline void set_right_wheels_speed(int32_t speed) {
    RF_Motor.move(speed);
    RB_Motor.move(speed);
}

inline void set_left_wheels_speed(int32_t speed) {
    LF_Motor.move(speed);
    LB_Motor.move(speed);
}

inline void forwards(int32_t speed, int32_t distance) {
    LF_Motor.move_relative(distance, speed);
    LB_Motor.move_relative(distance, speed);
    RF_Motor.move_relative(distance, speed);
    RB_Motor.move_relative(distance, speed);

    /*while(!((LF_Motor.get_position() < distance + 10) && LB_Motor.get_position() > distance-10)) {
		pros::delay(2);
	}*/
    pros::delay(2000);
}

inline void rotate(int32_t speed, int32_t distance, bool isLeft) {
    if (isLeft) {
        LF_Motor.move_relative(distance, speed);
        LB_Motor.move_relative(distance, speed);
        RF_Motor.move_relative(-distance, speed);
        RB_Motor.move_relative(-distance, speed);
        pros::delay(3000);
        /*while(!((LF_Motor.get_position() < distance + 10) && LF_Motor.get_position() > distance-10)) {
		    pros::delay(2);
	    }*/
    }

    else {
        LF_Motor.move_relative(-distance, speed);
        LB_Motor.move_relative(-distance, speed);
        RF_Motor.move_relative(distance, speed);
        RB_Motor.move_relative(distance, speed);
    }
    

}
