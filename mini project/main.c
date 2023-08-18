//
//  main.c
//  mini project
//
//  Created by Omar Mohamed Aboelfetouh on 8/17/23.
//  Copyright © 2023 well... that's hard. All rights reserved.
//
#include <stdio.h>

#define ON 1
#define OFF 0

#define NORMAL_TEMP 25

#define NO_MOVEMENT 0

#define RED 0
#define ORANGE 1
#define GREEN 2

// Structs definition
struct car_status{
    unsigned char engineState;
    unsigned char airConditioner;
    unsigned short vehicleSpeed;
    unsigned char roomTemp;
    unsigned short engineTemp;
    unsigned char engineTemperatureControllerState;
};

struct sensors_set_menu{
    unsigned char traficLightColor;
    unsigned char roomTemp;
    unsigned short engineTemp;
};

// structures instat
struct sensors_set_menu myMenu = { RED ,NORMAL_TEMP, NORMAL_TEMP};
struct car_status myStatus = { OFF, OFF, NO_MOVEMENT,NORMAL_TEMP,NORMAL_TEMP, OFF};


// dependensies
void print_myState(){
    printf("\nthe engine state : %hhu\nthe AC state : %hhu\nthe vehicale speed is : %hu\nthe room temp is : %hhu\nthe engine temp is : %hu\nthe engine temp controller state is : %hhu\n\n", myStatus.engineState, myStatus.airConditioner, myStatus.vehicleSpeed, myStatus.roomTemp, myStatus.engineTemp, myStatus.engineTemperatureControllerState);
}

void update_room_temp(unsigned char new_temp){
    myStatus.roomTemp = new_temp;
    myMenu.roomTemp = new_temp;
}

void update_engine_temp(unsigned char new_temp){
    myStatus.engineTemp = new_temp;
    myMenu.engineTemp = new_temp;
}
// functions
void set_vehicleSpeed(){
    if (myMenu.traficLightColor == RED){
        myStatus.vehicleSpeed = 0;
    }
    else if (myMenu.traficLightColor == ORANGE){
        myStatus.vehicleSpeed = 30;
    }
    else{
        myStatus.vehicleSpeed = 100;
    }
    
}
void AC_set(){
   
    if (myStatus.roomTemp < 10 | myStatus.roomTemp > 30){
            myStatus.airConditioner = ON;
            myStatus.roomTemp = 20;
        }
        else {
            myStatus.airConditioner = OFF;
        }
}
void set_engineController(){
    if (myStatus.engineTemp < 100 | myStatus.engineTemp > 150){
        myStatus.engineTemperatureControllerState = ON;
        myStatus.engineTemp = 125;
    }
    else {
        myStatus.engineTemperatureControllerState = ON;
    }
}
void ifSpeedGreaterThan30(){
    if (myStatus.vehicleSpeed > 30){
        myStatus.airConditioner = ON;
        myStatus.roomTemp = (myStatus.roomTemp * 1.25) + 1;
    
        myStatus.engineTemperatureControllerState = ON;
        myStatus.engineTemp = (myStatus.engineTemp * 1.25) + 1;}
}
int main(int argc, const char * argv[]) {
    char input;
    do {
    printf("a. Turn on the vehicle engine\n");
    printf("b. Turn off the vehicle engine\n");
    printf("c. Quit the system\n\n");
    scanf(" %c",&input);
    if (input == 'a'){
        myStatus.engineState = ON;
        
        while (myStatus.engineState == ON){
        print_myState();
        int x;
        printf("a. Turn off the engine\n");
        printf("b. Set the traffic light color.e\n");
        printf("c. Set the room temperature (Temperature Sensor)\n");
        printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
        scanf(" %c",&input);
            switch (input) {
                case 'a':
                    myStatus.engineState = OFF;
                    break;
                case 'b':
                    
                    printf("Entire a value for the trafic lights RED : 0, ORANGE : 1, GREEN : 2\n");
                    scanf(" %d",&x);
                    myMenu.traficLightColor = x;
                    break;
                case 'c':
                    scanf(" %d",&x);
                    update_room_temp(x);
                    break;
                case 'd':
                    scanf(" %d",&x);
                    update_engine_temp(x);
                    break;
                default:
                    printf("invalid input, try again.. \n");
                    continue;
                    break;
            }
            printf(" the trafic color is ... %d\n", myMenu.traficLightColor);
            set_vehicleSpeed();
            AC_set();
            set_engineController();
            ifSpeedGreaterThan30();
            print_myState();
        }
        
    }
    if (input == 'c')
        return 0;
    if (input == 'b')
        myStatus.engineState = OFF;
    }while(myStatus.engineState == OFF);
    
    return 0;
}





// do not look at this part

void previous_main(){
    unsigned char option;
       
       do {
       printf("what do you want to do ?\nTurn ON the engine (1)\nTurn OFF the engine? (2)\nQuit the Program?(3)\n");
       
       scanf("%hhu", &option);
       
       
           while (option == 1){
               unsigned char off;
               printf("Sensors set menu:\nTurn OFF the engine (1 for off)\nSet the trafic light color (0 for red , 1 for yellow, 2 for green)\nSet the room temprature (temp sensor)\nSet the engine Temprature (engine temp sensor)\n");
               scanf("%hhu \n%hhu \n%hhu \n%hu \n" ,&off, &myMenu.traficLightColor, &myMenu.roomTemp, &myMenu.engineTemp);
               if (off == ON)
                   option = 2;
           }
           
       print_myState();
       }while (option != 3);
       // if the user chose 1...
       printf("Sensors set menu:\nTurn OFF the engine\nSet the trafic light color\nSet the room temprature (temp sensor)\nSet the engine Temprature (engine temp sensor)");
       
       
}
