#include <stdio.h>
#include <time.h>
#include "E101.h"

int main (){
	init();
	while (true){
		//Run Camera method
		get.picture;
		for (int x = 0;x <= 100;x = x + 10){ //This loop should only be to find where the white line is. Your way could work but only if we were reading from one point and it probably wouldn't be very reliable. It would also be better to use a completely different variable for the for loop, "i" for instance and keep the "x" variable inside the loop. Also if you use "<=" it will loop one time more than stated, just use "<".
			int cam = get.pixel(x,y,3);
			int methodRed = get.pixel((xPixelSize/2),y,0); //methodRed only needs to be used once each time we move and so should be outside of the "cam" loop, preferably before.
			if (cam >= 127.5){
				//Run motor forward for a specified time
			}
			else if (methodRed >= 127.5){
				//Run IR method
			}else{
				if (x <= (pixelSize/2)){
					//turn robot right for a specified time
				}
				else{
					//turn robot left for a specified time
				}
			}
		}
	}
}
