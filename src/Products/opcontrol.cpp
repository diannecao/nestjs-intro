#include "main.h"

int timeOld = 0;
int timeNew = 0;
int deltaTime = 0;
int flSpeed = 0;
int blSpeed = 0;
int frSpeed = 0;
int brSpeed = 0;
int armSpeed = 0;
int clawSpeed = 0;

void opcontrol() {

 FILE* usd_file_write = fopen("/usd/rerun.txt", "w");
 fprintf(usd_file_write, "");
 fclose(usd_file_write);

 while (true) {
  int turn = controller1.get_analog(ANALOG_LEFT_Y);
  int power = controller1.get_analog(ANALOG_RIGHT_X);
  int left = power + turn;
  int right = power - turn;
  lf.move(left);
  lb.move(left);
  rf.move(right);
  rb.move(right);

  if (controller1.get_digital(DIGITAL_R1)) {
   arm.move_velocity(200);
  }
  else if (controller1.get_digital(DIGITAL_R2)) {
   arm.move_velocity(-100);
  }
  else {
   arm.move_velocity(0);
  }

  if (controller1.get_digital(DIGITAL_L1)) {
   claw.move_velocity(200);
  }
  else if (controller1.get_digital(DIGITAL_L2)) {
   claw.move_velocity(-100);
  }
  else {
   claw.move_velocity(0);
  }


  //Rerun Stuffz


  pros::delay(10);

  flSpeed = lf.get_actual_velocity();
  blSpeed = lb.get_actual_velocity();
  frSpeed = rf.get_actual_velocity();
  brSpeed = rb.get_actual_velocity();
  flapSpeed = flap.get_actual_velocity();
  hangSpeed = hang.get_target_velocity();

  FILE* usd_file_write = fopen("/usd/rerun.txt", "a");
  fprintf(usd_file_write, "lf.move_velocity(%i); \n", flSpeed);
  fprintf(usd_file_write, "lb.move_velocity(%i); \n", blSpeed);
  fprintf(usd_file_write, "rf.move_velocity(%i); \n", frSpeed);
  fprintf(usd_file_write, "rb.move_velocity(%i); \n", brSpeed);
  fprintf(usd_file_write, "flap.move_velocity(%i); \n", flapSpeed);
  fprintf(usd_file_write, "hang.move_velocity(%i); \n", hangSpeed);

  timeNew = pros::millis();
  deltaTime = timeNew - timeOld;
  timeOld = pros::millis();

  fprintf(usd_file_write, "delay(%d); \n", deltaTime);

  fclose(usd_file_write);
  
 }
}