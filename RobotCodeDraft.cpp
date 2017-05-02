#include <stdio.h>
#include <time.h>
#include "E101.h"

int main (){
	init();
	while (true){
		//Run Camera method
		get.picture;
		for (int x = 0;x <= 100;x = x + 10){
			int cam = get.pixel(x,y,3);
			int methodRed = get.pixel((xPixelSize/2),y,0);
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
