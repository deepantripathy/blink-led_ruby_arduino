//first we declare a few variables 

int led=13,i=0;
char myChar= 'p';

void setup() {
  Serial.begin(9600);  
  pinMode(led,OUTPUT); //we set the pin number 13 as OUTPUT
}

//this is used to blink the led. led is ON for 1 sec and OFF for 2 sec
//this will continue for 5 times
void blink_1() {
  while(i<5){
    digitalWrite(led,HIGH);
    delay(1000);
    
    digitalWrite(led,LOW);
    delay(2000);
    i++;
  }
}

//this is used to blink the led. led is ON for 2 sec and OFF for 1 sec
//this will also go on for 5 times
void blink_2() {
  while(i<5){
    digitalWrite(led,HIGH);
    delay(2000);
    
    digitalWrite(led,LOW);
    delay(1000);
  }    
}

//this function is used when we get the character from 
//the serialport 
void get_data(char x){
    if(x== 'p'){
        blink_1();
    }
    else{
        blink_2();
    }
}

void loop() {
    //checks if any data is available on the serial 
	if( Serial.available() >0 ){
        //if there is any data then we read it
		byte data=Serial.read();
	//and then call the get_data function
        	get_data((char)data);
    }  
}
