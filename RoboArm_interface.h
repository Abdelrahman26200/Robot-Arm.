/***********************************************************/
/***********************************************************/
/**************** By  :      Group1         ****************/
/**************** Date:     6/5/2022        ****************/
/**************** Layer:      APP           ****************/
/**************** SWC :     ROBOT_ARM       ****************/
/**************** VER :       1.15          ****************/
/***********************************************************/
#ifndef ROBOARM_INTERFACE_H_
#define ROBOARM_INTERFACE_H_



void Crtsian_to_polar(int* X ,int* Y,int* Z); /*transfer from Cartesian to Spherical polar coodinates*/
void Det_alpha_Value(void);                     /* Determining alpha value */

void Move_Motor1(char dir);                    /*Moving around z axis*/
void Move_Motor2(char dir);                    /*Moving link 1 */
void Move_Motor3(char dir);                    /*Moving link 2 */
  
void Move_To(int r ,int phi ,int theta);      /* Moving to the required position */

#endif
