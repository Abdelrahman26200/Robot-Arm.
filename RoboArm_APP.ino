void setup()
{ 
pinMode(Motor1_Step_Pin,OUTPUT)    ;
pinMode(Motor1_Dir_Pin,OUTPUT)     ;
pinMode(Motor1_ENA_Pin,OUTPUT) ;

pinMode(Motor2_Step_Pin,OUTPUT);
pinMode(Motor2_Dir_Pin,OUTPUT) ;
pinMode(Motor2_ENA_Pin,OUTPUT) ;

pinMode(Motor3_Step_Pin,OUTPUT);
pinMode(Motor3_Dir_Pin,OUTPUT) ;
pinMode(Motor3_ENA_Pin,OUTPUT) ;

digitalWrite(Motor1_ENA_Pin,LOW);
digitalWrite(Motor2_ENA_Pin,LOW);
digitalWrite(Motor3_ENA_Pin,LOW);

Serial.begin(9600);
}
void loop()
{
  int x =0 ,y =0,z =0;
  extern double theta ,phi , r ,alpha ;
  extern double a ;
  Serial.println("Enter the position");
  
  while(Serial.available()==0){}
  x = Serial.parseInt();
  Serial.print("x position = ");
  Serial.println(x);
  Serial.parseInt();

  while(Serial.available()==0){}
  y = Serial.parseInt();
  Serial.print("y position = ");
  Serial.println(y);
  Serial.parseInt();
  
  while(Serial.available()==0){}
  z = Serial.parseInt();
  Serial.print("z position = ");
  Serial.println(z);
  Serial.parseInt();
  
  
  Move_To(x ,y ,z);
  Serial.print("r = ");
  Serial.print(r);
  Serial.print(", theta = ");
  Serial.print(theta);
  Serial.print(", phi = ");
  Serial.print(phi);
  Serial.print(" alpha = ");
  Serial.println(alpha);
  Serial.print(" a = ");
  Serial.println(a);
 
}
