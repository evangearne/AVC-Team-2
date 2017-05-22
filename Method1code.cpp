#include <stdio.h>
#include <time.h>
#include "E101.h"

//sets initial variables
float kd = 2.5;
float kp = 0.5;
float error = 0;
float previous_error = 0;
float proportional_signal = 0;
float derivative_signal = 0;
float final_signal = 0;
bool received = false;

/**
extern "C" int init(int d_lev);
extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[24]);
extern "C" int receive_from_server(char message[24]);
*/

int main (){
            init(); //initialises hardware
            printf("initialised ");
            
            char ip [15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6',' ',' '};
            printf("ip saved ");
            char message [24] = {'P','l','e','a','s','e'};
            printf("message saved ");
            connect_to_server(ip, 1024);
            printf("connected ");
            receive_from_server(message); //this may be buggy!
   printf("received ");
            send_to_server(message);
            printf("sent ");
printf("%s", message);
sleep1(0,300000); //waits .3 sec
            for(;;){ //infinite loop
                        int sum = 0;
                        int points = 0;
                        take_picture();
                        for (int i = 0; i<320; i++){ //loop to find position of white line
                                    if (get_pixel(10,i,3)>50){ //if pixel is white
                                    sum = sum + i; //adds position of all white pixels
                                    points++; //counts white pixels
                                    }
                        }
            if(points==0){
              //          set_motor(1, 50);
                //        set_motor(2, -50);
            }
            else{
                        error = (sum/points)-160; //how far the white line is from camera centre
                        printf("%f \n", error);
                        proportional_signal = error*kp; //number between 0 and 80
                        derivative_signal = (error-previous_error)*kd; //number between 0 and 80
                        final_signal = proportional_signal+derivative_signal; //adds the signals together
                        
                        if(error<=10 && error>=-10){ //if line is straight ahead go straight
                                    set_motor(1, 30); //sets  motor to forward
                                    set_motor(2, 30); //sets  motor ''     ''
                        }
                        else if (error > 10){ //if line is not straight ahead turn toward it 

                                    //set_motor(1, (final_signal/(160))*30); //sets  motor to a value between -255 and 255
                                    //set_motor(2, (final_signal/(160))*15); //sets  motor    ''     ''
set_motor(1, 20 + proportional_signal);
set_motor(2, 20);
}
else if (error < -10){
                                set_motor(1,20);
set_motor(2,20 - proportional_signal);  
// set_motor(1, (final_signal/(160))*15);
                                    // set_motor(2, (final_signal/(160))*30);
                        }
            }
       
            sleep1(0,100000); // waits for .1 secs
            previous_error = error; //changes previous_error for next time around the loop
            }
            return 0;
} 
//sudo g++ -o Team2 Team2.cpp -le101
