/*
 WiFi Web Server LED Blink

 A simple web server that lets you blink an LED via the web.
 This sketch will print the IP address of your WiFi Shield (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to turn on and off the LED on pin 5.

 If the IP address of your shield is yourAddress:
 http://yourAddress/H turns the LED on
 http://yourAddress/L turns it off

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * LED attached to pin 5

 created for arduino 25 Nov 2012
 by Tom Igoe

ported for sparkfun esp32 
31.01.2017 by Jan Hendrik Berlin
 
 */
/////////////////////////////////////////////////////////////////
#define DEBUG 0
#define in1  12
#define in2  14
#define in3  27
#define in4  26
#define mC1  25
#define mC2  33
#define iFRight  32
#define iFLeft  35
//////////////////////////////////////////////////////////////////
#include <WiFi.h>

const char* ssid     = "CodeItWithMe";
const char* password = "code1991";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    pinMode(5, OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();
    



//////////////////////////////////////////

  #ifdef DEBUG
    Serial.begin(115200);
   #endif
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(mC1, OUTPUT);
  pinMode(mC2, OUTPUT);
  pinMode(iFRight, INPUT);
  pinMode(iFLeft, INPUT);

  stopMotor();
  vaccumOff();
///////////////////////////////////////////
}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println(" <style> a:link, a:visited {  background-color: #f44336;  color: white; padding: 14px 25px; width: 100%; height: 50%; text-align: center; text-decoration: none;  display: inline-block} a:hover, a:active { background-color: red; }</style>");

            // the content of the HTTP response follows the header:
            client.print("<a href=\"/autoMove\">Auto Move</a><br>");
            client.print("<a href=\"/Stop\">Stop</a><br>");
            client.print("<button href=\"/autoMove\">Move by itself</button>");
            client.print("<button href=\"/Stop\">Stop</button>");
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /autoMove")) {
          autoMove();
        }
        if (currentLine.endsWith("GET /Stop")) {
          stopMotor();
          vaccumOff();// GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
void backward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void left()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void foward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stopMotor()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void vaccumOn()
{
  digitalWrite(mC1, HIGH);
}
void vaccumOff()
{
  digitalWrite(mC1, LOW);
}
void autoMove()
{
  #ifdef DEBUG
    delay(50);
    Serial.println("Right:"+String(digitalRead(iFRight)));
    Serial.println("Left:"+iFLeft);
    #endif
   foward();
   vaccumOn();
   if (digitalRead(iFRight) == 0 || digitalRead(iFLeft) == 0)
   {
    stopMotor();
    delay(100);
    backward();
    delay(250);
    right();
    delay(250);
   }
   delay(10);  
}
