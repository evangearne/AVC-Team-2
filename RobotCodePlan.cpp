#include <stdio.h>
#include <time.h>
#include "E101.h"

int main (){
	int x = 0;
	int y = 0;
	int xPixelSize = 0;
	int add = 0;
	init();
	while (true){
		//Run Camera method
		get.picture;
		while (x <= pixelSize){
			int cam = get.pixel(x,y,3);
			int methodRed = get.pixel((xPixelSize/2),y,0);
			x = x + add;
			if (cam >= 127.5){
				//Run motor forward for a specified time
			}
			else if (methodRed >= 127.5){
				//Run IR method
			}else{
				if (x <= (pixelSize/2)){
					//turn robot right
				}
				else{
					//turn robot left
				}
			}
		}
	}
}
