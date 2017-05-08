#include <stdio.h>
#include <time.h>
#include "E101.h"

int main (){
            init();
            for(;;){
                float kd = 5;
                float kp = 0.5;
                int x = 0;
                int sum = 0;
                int error = 0;
                int previous_error;
                int proportional_signal;
                int derivative_signal;
                int final_signal;
                int points;
                take_picture();
                for (int i = 0; i<320; i++){
                    if (get_pixel(x,10,3)>150){
                        sum = sum + x;
                        points++;
                    }
                    x++;
                }
                error = (sum/points)-160;
                sleep1(0,100000);
                if(error==0){
                    set_motor(1, (0.5)*255);
                    set_motor(2, (0.5)*255);
                }
                else{
                    proportional_signal = error*kp;
                    derivative_signal = (error-previous_error/0.1)*kd;
                    previous_error = error;
                    final_signal = (proportional_signal+derivative_signal)/2;
                    set_motor(1, (final_signal/(160*kp))*255);
                    set_motor(2, (final_signal/(160*kp))*255);
                }

            }
} 
