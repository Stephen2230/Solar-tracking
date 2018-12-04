
int sens1 = A0; // LRD 1 pin
float temp;
int value = 0;
float voltage;
float R1=50000.0;
float R2= 4000.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.begin("Reading voltage, light, and temperature");
  pinMode(sens1, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int val1 = analogRead(sens1); // read the value of sensor 1
  temp = analogRead(A1);
  temp = temp * 0.48828125;
  
  value = analogRead(A2);
  voltage = value * (5.0/1024)*((R1+R2)/R2);
  Serial.print("Voltage =");
  Serial.print("\t"); 
  Serial.println(voltage);

  Serial.print("Temperature: ");
  Serial.print("\t"); 
  Serial.print(temp);
  Serial.print("c"); 
  delay(1000);

  float sens1 = (float)val1 * (100 / 1024.0);
  Serial.print("sens1 = ");
  Serial.print("\t"); 
  Serial.print(sens1);
  Serial.println("%");
  Serial.println(val1);
  delay(2000);
}
