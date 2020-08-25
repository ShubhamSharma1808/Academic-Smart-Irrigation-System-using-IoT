#define moisture_pin A0
#define LDR_pin A2
#define temp_pin A4
#define pump 3

#define threshold 20

void setup()
{
  Serial.begin(9600);
  pinMode(moisture_pin, INPUT);
  pinMode(LDR_pin  , INPUT);
  pinMode(temp_pin, INPUT);
  pinMode(pump, OUTPUT);
}

void loop()
{
  int moisture_value = analogRead(moisture_pin);
  int LDR_value = analogRead(LDR_pin);
  int temp_value = analogRead(temp_pin);
  delay(1000);
  int moisture_percent = moisture_percent_func(moisture_value);
  int temp_celsius = temp_celsius_func(temp_value);
  int light_intensity = light_intensity_func(LDR_value);
  Serial.println(moisture_percent);
  Serial.println(temp_celsius);
  Serial.println(light_intensity);
}

int moisture_percent_func (int moisture_value)
{
  int moisture_percent = map(moisture_value, 1023, 200, 0, 100);
  return moisture_percent ;

}

int light_intensity_func (int LDR_value)
{
  int light_intensity = map(LDR_value, 1023, 200, 0, 100);
  return light_intensity ;

}


int temp_celsius_func (int temp_value)
{
  temp_value = (temp_value * 4.88); /* Convert adc value to equivalent voltage */
  int  temp_celsius = (temp_value / 10); /* LM35 gives output of 10mv/°C */
  return temp_celsius;
}
