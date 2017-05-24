
    if(get_pixel(120,160,0)>180){
      set_motor(1, 230);
      set_motor(2, 230);
      sleep1(3,0);
      for(;;){ // 1 is front, 2 is left, 3 is right for this example
        if(read digital(1) == 1 && read digital(2) == 1 && read digital(3) == 1){ // if walls all around, back up and turn right slightly
          set_motor(1, -200);
          set_motor(2, -210);
        }
        if else(read digital(1) == 1 && read digital(2) == 1 && read digital(3) == 0){ //if wall infront and gap to right, turn right
          set_motor(1, 240);
          set_motor(2, 200);
        }
        if else(read digital(1) == 1 && read digital(2) == 0 && read digital(3) == 0){ //if wall infront and gap to right, turn right
          set_motor(1, 240);
          set_motor(2, 200);
        }
        if else(read digital(1) == 0 && read digital(2) == 1 && read digital(3) == 1){ //if walls on both sides but no wall infront, go straight
          set_motor(1, 220);
          set_motor(2, 220);
        }
        if else(read digital(1) == 0 && read digital(2) == 1 && read digital(3) == 0){ //if wall to left but no wall infront, go straight
          set_motor(1, 220);
          set_motor(2, 220);
        }
        if else(read digital(1) == 0 && read digital(2) == 0 && read digital(3) == 1){ //if wall to right but no wall infront, go straight
          set_motor(1, 220);
          set_motor(2, 220);
        }
        if else(read digital(1) == 0 && read digital(2) == 0 && read digital(3) == 0){ //if no walls, go straight
          set_motor(1, 220);
          set_motor(2, 220);
        }
        else(read digital(1) == 1 && read digital(2) == 0 && read digital(3) == 1){ //if wall infront and to right, turn left
          set_motor(1, 200);
          set_motor(2, 240);
        }
