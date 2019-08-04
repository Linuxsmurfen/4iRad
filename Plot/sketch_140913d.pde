/*
  Plots analog inputs as read in from Arudino

  d.jurnove 2009
*/

import processing.serial.*;

Serial myPort;
final int linefeed = 10;

//maximum number of sensors to display
final int maxSensors = 6;

//raw analog input values from controller
int raw[];
int rawMin[];
int rawMax[];

//values scaled to fit screen
float scaledVal[];
float scaledMin[];
float scaledMax[];
float prevScaledVal[];

//min/max values of analog input from controller
final int minAnalogVal = 0;
final int maxAnalogVal = 1024;

//colors used to draw sensor graphs
color colors[];

int xCursor = 0;

//length of each line segment in graph, 1=1 pixel
final int plotLineLength = 1;

PFont myFont;
final int fontSize = 12;

final int drawDelay = 10;

boolean madeContact = false;


void setup() {
  //println( Serial.list() );
  
  myPort = new Serial(this, Serial.list()[2], 9600);  
  myPort.bufferUntil(linefeed);
  
  //initialize raw vars
  raw = new int[maxSensors];
  rawMin = new int[maxSensors];
  for (int i = 0; i<rawMin.length; i++) {
    rawMin[i] = 2147483647;
  }
  rawMax = new int[maxSensors];

  //initialize scaled vars
  scaledVal = new float[maxSensors];
  scaledMin = new float[maxSensors];
  for (int i = 0; i<scaledMin.length; i++) {
    scaledMin[i] = 2147483647 ;
  }
  scaledMax = new float[maxSensors];

  prevScaledVal = new float[maxSensors];

  //set colors used for each sensor display
  colors = new color[maxSensors];
  colors[0] = color(255, 0, 0); //red
  colors[1] = color(0, 255, 0); //green
  colors[2] = color(0, 0, 255); //blue
  colors[3] = color(255, 255, 0); //yellow
  colors[4] = color(0, 255, 255); //teal
  colors[5] = color(255, 0, 255); //purple
  
  //println(PFont.list());
  PFont myFont = createFont(PFont.list()[12], fontSize);
  textFont(myFont);
      
  size(1200, 600);
  background(102);
}

void draw() {
  stroke(102);
  fill(102);
  
  //erases text area
  rect(0,0,300,170);  
    
  if(madeContact==false) {
    //start handshake w/controller
    myPort.write('\r');
  } else {
  
    fill(255);
    
    //draw text header
    text("Analog Input Monitor v1.0", 2, fontSize);
    
    //draw text output for each sensor
    for (int i = 0; i < raw.length; i++) {  
      fill(colors[i]);
      text("        Analog Sensor " + i + ":" , 2, fontSize*(2*(i+1)));
      text("               Raw: " + raw[i] + "       Min: " + rawMin[i] + "       Max: " + rawMax[i], 2, fontSize*(2*(i+1)+1));
    }
    
    //draw each graph line segment
    for (int i = 0; i < scaledVal.length; i++) {
      stroke(colors[i]);      
      
      //current value
      line(xCursor, height-prevScaledVal[i], xCursor + plotLineLength, height-scaledVal[i]);   
      
      //min value
      //line(xCursor, height-scaledMin[i], xCursor + plotLineLength, height-scaledMin[i]);
      
      //max value
      //line(xCursor, height-scaledMax[i], xCursor + plotLineLength, height-scaledMax[i]);
      
      prevScaledVal[i] = scaledVal[i];
    }
    
    xCursor+=plotLineLength;
    
    if (xCursor > width ) {
      background(102);
      xCursor = 0;
    }
    
    delay(drawDelay);
  }
}


void serialEvent(Serial myPort) {
 
  madeContact = true;

  String rawInput = myPort.readStringUntil(linefeed);

  if (rawInput != null) {
    rawInput = trim(rawInput);
    
    int sensors[] = int(split(rawInput, ','));
    
    //print("raw: ");
    //read in raw sensor values
    for (int i=0; i<sensors.length; i++) {
        raw[i] = sensors[i];
        rawMin[i] = min(rawMin[i], raw[i]);
        rawMax[i] = max(rawMax[i], raw[i]);
        //print(i + ": " + raw[i] + "\t(" + rawMin[i] + "|" + rawMax[i] +")\t");
    }
    println();
    
    //print("scaled: ");
    //scale raw sensor values
    for (int i=0; i<sensors.length; i++) {      
      scaledVal[i] = height * (raw[i] - minAnalogVal) / maxAnalogVal;
      scaledMin[i] = height * (rawMin[i] - minAnalogVal) / maxAnalogVal;
      scaledMax[i] = height * (rawMax[i] - minAnalogVal) / maxAnalogVal;
      //print(i + ": " + scaledVal[i] + "\t(" + scaledMin[i] + "|" + scaledMax[i] +")\t");
    }
    //println();
  }

  //request more data from controller 
  myPort.write('\r'); 
}
