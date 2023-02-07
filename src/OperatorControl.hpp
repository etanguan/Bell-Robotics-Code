#include "main.h"

#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"

#include "Motors.hpp"
#include "PickUp.hpp"
#include "FlyWheel.hpp"
#include "EndGame.hpp"

<<<<<<< HEAD
=======
inline void on_auton(){
    forwards(90 , 1000);
}

>>>>>>> refs/remotes/origin/master
inline void on_operator_control(pros::Controller Controller) {

    int CurFlywheelSpeed = 0;
    bool directionToggle = false;

    while (true) {
        
        if (Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
            directionToggle = !directionToggle;
        }

        if (!directionToggle){
            set_right_wheels_speed(Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
            set_left_wheels_speed(Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
        }
        else {
            set_right_wheels_speed(-Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
            set_left_wheels_speed(-Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
        }

        if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            set_intake_speed(127);
        }
        else if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
            set_intake_speed(-127);

        }
        else {
            set_intake_speed(0);
        }

       

        if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            set_indexer_speed(90);
        }
        else if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
            set_indexer_speed(-90);

        }
        else {
            set_indexer_speed(0);
        }

        if (Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            if (CurFlywheelSpeed) {
                CurFlywheelSpeed = 0;
                set_flywheel_speed(CurFlywheelSpeed);
            }
            else {
                CurFlywheelSpeed = 450;
                set_flywheel_speed(CurFlywheelSpeed);
            }
        }

        if (Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
            CurFlywheelSpeed += 50;
            set_flywheel_speed((CurFlywheelSpeed));
        }

        if (Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            CurFlywheelSpeed -= 50;
            set_flywheel_speed((CurFlywheelSpeed));
        }

        if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
            set_endgame_speed(50);
        }
        else {
            set_endgame_speed(0);
        }
    }
}