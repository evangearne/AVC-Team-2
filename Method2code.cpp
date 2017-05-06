#include <stdio.h>
#include <time.h>
#include "E101.h"

int main (){
	init();
	int method = 0;
	while (method = 0){//line finding method
		get.picture;
		for (int i = 0;i <= 320;i = i + 10){ 
			int cam = get.pixel(i,120,3);
			int red = get.pixel(i,120,0);
			if(red >= 127.5){
				method = 1;//doWallMaze
			}else if (cam >= 127.5){
				if(i <= 150){
					//run motor right
				}else if (i >= 170){
					//run motor left
				}else if (i >= 170 && i <= 150){
					//run motor foward
				}
			}
		}
	}
	while (method = 1){//wall maze method
		
	}
}
