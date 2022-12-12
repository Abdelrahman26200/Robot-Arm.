/***********************************************************/
/***********************************************************/
/**************** By  :      Group1         ****************/
/**************** Date:     6/5/2022        ****************/
/**************** Layer:      APP           ****************/
/**************** SWC :     ROBOT_ARM       ****************/
/**************** VER :       1.15          ****************/
/***********************************************************/
#ifndef ROBOARM_CONFIGURATION_H_
#define ROBOARM_CONFIGURATION_H_


/*STEP input controls the mirosteps of the motor
 *DIR input controls the spinning direction of  the  motor.
  Pulling it HIGH drives the motor clockwise and pulling it
  LOW drives the motor counterclockwise                      */
 
/* Motor 1 Controls pins */ 
#define Motor1_Step_Pin   2   
#define Motor1_Dir_Pin    3
#define Motor1_ENA_Pin    4

/* Motor 2 Controls pins */ 
#define Motor2_Step_Pin   5   
#define Motor2_Dir_Pin    6
#define Motor2_ENA_Pin    7    

/* Motor 2 Controls pins */ 
#define Motor3_Step_Pin   8   
#define Motor3_Dir_Pin    9
#define Motor3_ENA_Pin    10 

/*Limits definition*/

#define  Theta_Min_limit  0        /*Motor 1 angle */
#define  Phi_Min_limit    -25      /*Motor 2 angle */
#define  alpha_Min_limit   -45     /*Motor 3 angle */

#define  Theta_Max_limit  360      /*Motor 1 angle */
#define  Phi_Max_limit    30       /*Motor 2 angle */
#define  alpha_Max_limit   185     /*Motor 3 angle */

/*Motion delay*/
#define Motion_delay  50     /*IN MICRO SECONDS*/

/*The SUM of links lengths*/
#define link1_length   150  /*Length in mm*/
#define link2_length   150  /*Length in mm*/


#endif
