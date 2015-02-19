// Set variables
int ledControl(String command);

void setup()
{
  // register the Spark function
  Spark.function("led", ledControl);
}

void loop()
{
  // this loops forever
}

// this function automagically gets called upon a matching POST request
int ledControl(String command)
{
  if(command == "red")
  {
    RGB.control(true);
    if(RGB.controlled() == true){
        RGB.color(255,0,0);
    }
    return 1;
  }
  if(command == "green")
  {
    RGB.control(true);
    if(RGB.controlled() == true){
        RGB.color(0,255,0);
    }
    return 1;
  }
  if(command == "blue")
  {
    RGB.control(true);
    if(RGB.controlled() == true){
        RGB.color(0,0,255);
    }
    return 1;
  }
  if(command == "low")
  {
    RGB.control(true);
    if(RGB.controlled() == true){
        RGB.brightness(40);
    }
    return 1;
  }
  if(command == "off")
  {
    RGB.control(false);
    return 1;
  }

  else return -1;
}

// POST to the above function like this: curl -d access_token=[TOKEN] -d "command=[COMMAND]" https://api.spark.io/v1/devices/51ff6a065067545735220187/led
