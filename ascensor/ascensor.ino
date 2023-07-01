#include<Servo.h>
// Motor A

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int v1=0;
int v2=0;
int v3=0;

const int pwmPin = 12; // Servo3 pin3 PWM
Servo servo;


void setup ()
{
  Serial.begin(9600);
  //servo en 0
  pinMode (pwmPin, OUTPUT); 
  servo.attach(pwmPin);
 // Declaramos todos los pines como salidas
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);


  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);

  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
}

void Adelante ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 60); //Velocidad motor A
 //Direccion motor B
}


void Atras ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 60); //Velocidad motor A
 //Direccion motor B
}

void Parar ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 0); //Velocidad motor A
 //Direccion motor B
}

void loop ()
{

  int p1 = digitalRead(2);
  int p2 = digitalRead(3);
  int p3 = digitalRead(4);

  int f1 = digitalRead(5);
  int f2 = digitalRead(6);
  int f3 = digitalRead(7);
  
  // print out the value you read:
  Serial.print(p1);
  Serial.print(" -- ");
  Serial.print(p2);
  Serial.print(" -- ");
  Serial.print(p3);
   Serial.print(" sss ");

    Serial.print(f1);
    Serial.print(" -- ");
    Serial.print(f2);
    Serial.print(" -- ");
    Serial.println(f3);


//logica

///////////////////////////////////////////////// piso 1
 if (p1==0 & p2==1 & p3==1)
  {
  // abajo
  v1=1;
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 60); //Velocidad motor A
  Serial.println("Atras 1");
  servo.write(0);
  }
  //////////////////////////////////////////////// piso 2 arriba
 if (p1==1 & p2==0 & p3==1 & f1==0)
  {
    //arriba
    v2=1;
     digitalWrite (IN1, HIGH);
     digitalWrite (IN2, LOW);
     analogWrite (ENA, 60); //Velocidad motor A
     Serial.println("arriba piso 2");
     servo.write(0);
  }
  //////////////////////////////////////////////// piso 2 abajo
 if (p1==1 & p2==0 & p3==1 & f3==0)
  {
    //abajo
    v2=1;
     digitalWrite (IN1, LOW);
     digitalWrite (IN2, HIGH);
     analogWrite (ENA, 60); //Velocidad motor A
     Serial.println("abajo piso 2");
     servo.write(0);
  }


  /////////////////////////////////////////////// piso 3
 if (p1==1 & p2==1 & p3==0 )
  {
    //arriba
    v3=1;
      digitalWrite (IN1, HIGH);
     digitalWrite (IN2, LOW);
     analogWrite (ENA, 60); //Velocidad motor A
     Serial.println("Adelante 3");    
     servo.write(0);
  }

//condicion 1
   if (v1==1 & f1==0)
  {
     Parar ();
     Serial.println("Parar 1");  
     servo.write(100);
     
     v1=0;  
  }  

   if (v2==1 & f2==0)
  {
     Parar ();
     Serial.println("Parar 2");  
     servo.write(100);  
     v2=0;
  }  
     if (v3==1 & f3==0)
  {
     Parar ();
     Serial.println("Parar 3"); 
     servo.write(100);
     v3=0;   
  }  


 delay(300);

  }