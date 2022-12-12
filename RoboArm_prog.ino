/***********************************************************/
/***********************************************************/
/**************** By  :      Group1         ****************/
/**************** Date:     6/5/2022        ****************/
/**************** Layer:      APP           ****************/
/**************** SWC :     ROBOT_ARM       ****************/
/**************** VER :       1.15          ****************/
/***********************************************************/
#include "RoboArm_interface.h"
#include "RoboArm_configuration.h"
#include "RoboArm_private.h"

double r=0 ,theta =0 , phi =0 ,alpha =0  ;     /*The current position*/
double r0=0 ,theta0 =0 , phi0 =0 , alpha0 =0;  /*The last position*/
double  a=0;
void Crtsian_to_polar(double x ,double y,double z)
{
  r0 = r; theta0 = theta; phi0 = phi; alpha0 = alpha ;

  /* Determine r */
   r = sqrt(( sq(x)+sq(y)+sq(z) ))                ;

  /* Determine Theta */
  theta = (sq(x)+sq(y))      ;
  theta = sqrt( theta )      ;
  theta = ( theta / z )      ;
  theta = atan( theta )      ; 
  theta = ((180/pi)*theta)   ;
  
  /* Determine PHI */
  phi = ( y / x )            ;
  phi = atan ( phi )         ; 
  phi =((180/pi)*phi)        ;
}

void Det_alpha_Value(void)         /* Determining alpha value */
{
  
    alpha0 = alpha ;
    a = ((sq(r)/(45000)));
    a= 1-a ;
    alpha = (acos(a));
    alpha =((180/pi)*alpha);
}

void Move_Motor1(char dir)        /*Moving around z axis*/
{  
   digitalWrite(Motor1_Dir_Pin,dir);
   digitalWrite(Motor1_Step_Pin,HIGH);
   delayMicroseconds(Motion_delay);
   digitalWrite(Motor1_Step_Pin,LOW);

}

void Move_Motor2(char dir)         /*Moving link 1 */
{  
   digitalWrite(Motor2_Dir_Pin,dir);
   digitalWrite(Motor3_Dir_Pin,dir);
   digitalWrite(Motor2_Step_Pin,HIGH);
   digitalWrite(Motor3_Step_Pin,HIGH);
   delayMicroseconds(Motion_delay);
   digitalWrite(Motor2_Step_Pin,LOW);
   digitalWrite(Motor3_Step_Pin,LOW);
}


void Move_Motor3(char dir)         /*Moving link 2 */
{  
   digitalWrite(Motor3_Dir_Pin,dir);
   digitalWrite(Motor3_Step_Pin,HIGH);
   delayMicroseconds(Motion_delay);
   digitalWrite(Motor3_Step_Pin,LOW);

}

void Move_To(int x ,int y ,int z) /* Moving to the required position */
{
  int D_theta =0 , D_phi =0 , D_alpha =0 ;
  int dir1,dir2,dir3 ;
  int M1_Steps=0 ,M2_Steps=0 ,M3_Steps=0;
  int C1 =0 ,C2 =0 ,C3 = 0 ;
  
  /*Get angels values*/
  Crtsian_to_polar(x,y,z);
  Det_alpha_Value();

  if (theta < Theta_Min_limit && theta > Theta_Max_limit ) 
  {Serial.println("OUT OF SCOPE!!");return ;}
  
  if (phi < Phi_Min_limit && phi > Phi_Max_limit ) 
  {Serial.println("OUT OF SCOPE!!");return ;}
  
  if (alpha < alpha_Min_limit && alpha > alpha_Max_limit ) 
  {Serial.println("OUT OF SCOPE!!");return ;}
  
  /*Determining POSITION DIFFERENCE*/
  D_theta  = theta - theta0 ;
  D_phi    = phi - phi0 ;
  D_alpha  = alpha - alpha0 ; 
  
  /*Determining Motors directions*/
  if(D_theta < 0) {D_theta *(-1);dir1= COUNTER_CLOCK_WISE;}
  else dir1= CLOCK_WISE ;
  
  if(D_phi < 0) {D_phi *(-1);dir2= COUNTER_CLOCK_WISE;}
  else dir2= CLOCK_WISE;

  if(D_alpha < 0) {D_alpha *(-1);dir3= COUNTER_CLOCK_WISE;}
  else dir3= CLOCK_WISE;

  /*Determining number of steps to each motor*/
  M1_Steps = (D_theta/ 1.8);
  M2_Steps = (D_phi / 1.8);
  M3_Steps = (D_alpha/1.8);
  
  while( C1 != M1_Steps || C2 != M2_Steps || C3 != M3_Steps)
  {
    if(C1 != M1_Steps ) {Move_Motor1(dir1);C1++;}
    else digitalWrite(Motor1_Step_Pin,LOW);
    
    if(C2 != M2_Steps ) {Move_Motor2(dir2);C2++;}
    else digitalWrite(Motor2_Step_Pin,LOW);

    if(C3 != M2_Steps ) {Move_Motor3(dir3);C3++;}
    else digitalWrite(Motor3_Step_Pin,LOW);
  }
}
