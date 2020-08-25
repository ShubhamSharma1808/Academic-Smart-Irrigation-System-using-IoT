
#define moisture_value_pin A0
#define tank 7
#define LDR_pin A2
#define temp_pin A4
#define pump 5

#define threshold 700

void setup()
{
  Serial.begin(9600);
  pinMode(moisture_value_pin, INPUT);
  pinMode(LDR_pin  , INPUT);
  pinMode(temp_pin, INPUT);
  pinMode(tank, INPUT);
  pinMode(pump, OUTPUT);
}

void loop()
{
  int moisture_value = analogRead(moisture_value_pin);
  int LDR_value = analogRead(LDR_pin);
  int temp_value = analogRead(temp_pin);
  int water_level = digitalRead(tank);


  int light_intensity = map(LDR_value, 0, 400, 0, 100);
  temp_value = (temp_value * 4.88); /* Convert adc value to equivalent voltage */
  int  temp_celsius = (temp_value / 10); /* LM35 gives output of 10mv/°C */


  for (int i = 0; i <= 7; i++)
  {
    Serial.println(" ");
  }


  if (moisture_value > 700)  // for dry soil
  {

    digitalWrite(pump, HIGH);
    Serial.print("Soil : ");
    Serial.println("DRY");
    Serial.print("Temperature : ");
    Serial.print(temp_celsius);
    Serial.println(" C ");
    Serial.print("Light Intensity : ");
    Serial.print(light_intensity);
    Serial.println("%");
    Serial.print("PUMP ON");

  }
  /* else
    {
     digitalWrite(pump, LOW);
     Serial.print("Soil : ");
     Serial.println("DRY");
     Serial.print("Temperature : ");
     Serial.print(temp_celsius);
     Serial.println(" C ");
     Serial.print("Light Intensity : ");
     Serial.print(light_intensity);
     Serial.println("%");
     Serial.print("CONTAINER EMPTY");
    }*/

  if (moisture_value >= 300 && moisture_value <= 700) //for Moist Soil
  {
    digitalWrite(pump, LOW);
    Serial.print("Soil : ");
    Serial.println("MOIST");
    Serial.print("Temperature : ");
    Serial.print(temp_celsius);
    Serial.println(" C ");
    Serial.print("Light Intensity : ");
    Serial.print(light_intensity);
    Serial.println("%");
    Serial.print("PUMP OFF");
   /* if (Serial.available())
    {
      char data = Serial.read();
      switch (data)
      {
        case 'W':
          digitalWrite(pump, HIGH);
          delay(1000);
          break;
        case 'N':
          digitalWrite(pump, LOW);
          break;
      }
    }*/
  }
  if (moisture_value < 300)  // For Soggy soil
  {
    digitalWrite(pump, LOW);
    Serial.print("Soil : ");
    Serial.println("SOGGY");
    Serial.print("Temperature : ");
    Serial.print(temp_celsius);
    Serial.println(" C ");
    Serial.print("Light Intensity : ");
    Serial.print(light_intensity);
    Serial.println("%");
    Serial.print("PUMP OFF");
    /*char data = Serial.read();
    switch (data)
    {
      case 'W':
        digitalWrite(pump, HIGH);
        delay(1000);
        break;
      case 'N':
        digitalWrite(pump, LOW);
        break;

    }*/
  }

  delay(1000);
}
