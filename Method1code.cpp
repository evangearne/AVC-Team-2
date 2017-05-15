#include <stdio.h>
#include <time.h>
#include "E101.h"

//sets initial variables
float kd = 5;
float kp = 0.25;
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
                        char take_picture();
                        for (int i = 0; i<320; i++){ //loop to find position of white line
                                    if (get_pixel(i,10,3)>150){ //if pixel is white
                                    sum = sum + i; //adds position of all white pixels
                                    points++; //counts white pixels
                                    }
                        }
            error = (sum/points)-160; //how far the white line is from camera centre
            sleep1(0,100000); // waits for .1 secs
            if(error==0){ //if line is straight ahead go straight
                        set_motor(1, (0.5)*255); //sets left motor to half speed forward
                        set_motor(2, (-0.5)*255); //sets right motor     ''     ''
                        }
            else{ //if line is not straight ahead turn toward it
                        proportional_signal = error*kp; //number between 0 and 80
                        derivative_signal = (error-previous_error/0.1)*kd; //number between 0 and 80
                        final_signal = proportional_signal+derivative_signal; //adds the signals together
                        set_motor(1, (final_signal/(160))*255); //sets left motor to a value between -255 and 255
                        set_motor(2, (final_signal/(160))*255); //sets right motor    ''     ''
                        }
            previous_error = error; //changes previous_error for next time around the loop
            }
} 
