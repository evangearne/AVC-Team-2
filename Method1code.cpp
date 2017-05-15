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
                                    if (get_pixel(10,i,3)>80){ //if pixel is white
                                    sum = sum + i; //adds position of all white pixels
                                    points++; //counts white pixels
                                    }
                        }
            if(points==0){
                        set_motor(1, 126);
                        set_motor(2, -126);
            }
            else{
                        error = (sum/points)-160; //how far the white line is from camera centre
                        if(error==0){ //if line is straight ahead go straight
                                    set_motor(1, (0.5)*254); //sets  motor to half speed forward
                                    set_motor(2, (0.5)*254); //sets  motor     ''     ''
                        }
                        else{ //if line is not straight ahead turn toward it
                                    proportional_signal = error*kp; //number between 0 and 80
                                    derivative_signal = (error-previous_error/0.1)*kd; //number between 0 and 80
                                    final_signal = proportional_signal+derivative_signal; //adds the signals together
                                    set_motor(1, (final_signal/(160))*254); //sets  motor to a value between -255 and 255
                                    set_motor(2, (-final_signal/(160))*254); //sets  motor    ''     ''
                        }
            }
            sleep1(0,100000); // waits for .1 secs
            previous_error = error; //changes previous_error for next time around the loop
            }
            return 0;
} 
