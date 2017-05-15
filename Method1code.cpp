#include <stdio.h>
#include <time.h>
#include "E101.h"

//sets initial variables
float kd = 2.5;
float kp = 0.5;
float error;
float previous_error;
float proportional_signal;
float derivative_signal;
float final_signal;

int main (){
            init(); //initialises hardware
            for(;;){ //infinite loop
                        int sum = 0;
                        int points = 0;
                        take_picture();
                        for (int i = 0; i<320; i++){ //loop to find position of white line
                                    if (get_pixel(140,i,3)>80){ //if pixel is white
                                    sum = sum + i; //adds position of all white pixels
                                    points++; //counts white pixels
                                    }
                        }
                        error = (sum/points)-160; //how far the white line is from camera centre
                        if (points==0){ //if there are no white pixels, the robot will turn right
                                    set_motor(1, 126);
                                    set_motor(2, -126);
                        }
                        else{
                                    if (points > 50){ //if there are more white pixels than a single line (e.g. an intersection) chooses a path to follow
                                                int forward = 0;
                                                int left = 0;
                                                int right = 0;
                                                int fpoints = 0;
                                                int lpoints = 0;
                                                int rpoints = 0;
                                                for (int i = 0; i<320; i++){ //loop to find other paths
                                                            if (get_pixel(10,i,3)>80){ //finds forward path
                                                                        forward = forward + i;
                                                                        fpoints++;
                                                            }
                                                            if (i<240){ //side paths
                                                                        if (get_pixel(i,10,3)>80){ //finds left path
                                                                                    left = left + i;
                                                                                    lpoints++;
                                                                        }
                                                                        if (get_pixel(i,230,3)>80){ //finds right path
                                                                                    right = right + i;
                                                                                    rpoints++;
                                                                        }
                                                            }
                                                }
                                                if (rpoints > 3){ //changes error to make robot turn right
                                                            error = 160;
                                                }
                                                else if (fpoints > 3){ //changes error to make robot drive straight
                                                            error = 0;
                                                }
                                                else (lpoints > 3){ //changes error to make robot turn left
                                                            error = -160;
                                                }
                                    }
                                    if (error < 5 && error > -5){ //if line is straight ahead go straight
                                                set_motor(1, (0.5)*254); //sets left motor to half speed forward
                                                set_motor(2, (0.5)*254); //sets right motor     ''     ''
                                    }
                                    else{ //if line is not straight ahead turn toward it
                                                proportional_signal = error*kp; //number between 0 and 80
                                                derivative_signal = (error-previous_error/0.1)*kd; //number between 0 and 80
                                                final_signal = proportional_signal+derivative_signal; //adds the signals together
                                                set_motor(1, (final_signal/(160))*254); //sets left motor to a value between -255 and 255
                                                set_motor(2, (-final_signal/(160))*254); //sets right motor    ''     ''
                                    }
                        }
            sleep1(0,100000); // waits for .1 secs
            previous_error = error; //changes previous_error for next time around the loop
            }
            return 0;
} 

// motor 2 = right wheel
