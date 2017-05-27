#include <stdio.h>
#include <time.h>
#include "E101.h"

//sets initial variables
float kd = 0.2;
float kp = 0.7;
float error = 0;
float previous_error = 0;
float proportional_signal = 0;
float derivative_signal = 0;
float final_signal = 0;
bool received = false;

int main (){
            init(); //initialises hardware
            printf("initialised ");
            
            char ip [15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6',' ',' '};
            printf("ip saved\n");
            char message [24] = {'P','l','e','a','s','e'};
            printf("message saved\n");
            connect_to_server(ip, 1024);
            printf("connected\n");
            send_to_server(message);
            printf("sent please\n");
            receive_from_server(message);
            printf("received\n");
            send_to_server(message);
            printf("sent message back\n");
			printf("%s\n", message);
			
            for(;;){ //infinite loop
                        int sum = 0;
                        int points = 0;\
                        int red = 0;
                        int green = 0;
                        int blue = 0;
                        take_picture();
                        for (int i = 0; i<320; i++){ //loop to find position of white line
                                    if (get_pixel(220,i,3)>100){ //if pixel is white
                                    sum = sum + i; //adds position of all white pixels
                                    points++; //counts white pixels
                                    }
                                    if (get_pixel(220,i,0)>150){
										red++;
									}
									if (get_pixel(220,i,1)>150){
										green++;
									}
									if (get_pixel(220,i,2)>150){
										blue++;
									}
                        }
            if(points==0){
                        set_motor(1, -215);
                        set_motor(2, -235);
                        sleep1(0,400000); // waits for .4 secs
            }
            else{
                        error = (sum/points)-160; //how far the white line is from camera centre
                        printf("%f \n", error);
                        
                        proportional_signal = error*kp; //number between 0 and 80
                        
                        if(error<=10 && error>=-10){ //if line is straight ahead go straight
                                    set_motor(1, 215); //sets  motor to forward
                                    set_motor(2, 215); //sets  motor ''     ''
                        }
                        else if (error > 10){ //if line is not straight ahead turn toward it 
							
						 
                        
								set_motor(1, 215 - proportional_signal);  //subtract to create a double negative because error is negative
								set_motor(2, 225);
						}
						else if (error < -10){
                                set_motor(1,225);
								set_motor(2,215 + proportional_signal);  
                        }
            }
            
			if (red > 70 && green < 30 && blue < 30){
				set_motor(1, 175); //sets  motor to forward
                set_motor(2, 180); //sets  motor ''     ''
                sleep1(6,0); // waits for 1 secs
			}
			 
            sleep1(0,100000); // waits for .1 secs
            previous_error = error; //changes previous_error for next time around the loop
            }
            return 0;
} 

