/*
 * Connects to a WiFi network and prints out the IP/MAC address.
 */

#include <Arduino.h>
// reference the ESP WiFi headers
#include <ESP8266WiFi.h>

#define STATUS_LED 13

// update with you network SSID and password
const char* ssid     = "IoT_Network";
const char* password = "IoT_Password";

void connectWiFi()
{
  Serial.printf("\nConnecting to %s\n", ssid);

  // Connect to a WiFi network
  WiFi.begin(ssid, password);
  // Wait until the connection is established
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
}

void printWiFiDetails()
{
  // print the IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP: ");
  Serial.println(ip);

  // print the gateway address:
  IPAddress gatewayIp = WiFi.gatewayIP();
  Serial.print("Gateway: ");
  Serial.println(gatewayIp);

  // print the MAC address
  String mac = WiFi.macAddress();
  Serial.print("MAC: ");
  Serial.println(mac);
}

void setup()
{
  // connect the serial port
  Serial.begin(115200);

  // initialize the status LED
  pinMode(STATUS_LED, OUTPUT);

  connectWiFi();
  printWiFiDetails();
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    // LED off - indicate that we are not connected
    digitalWrite(STATUS_LED, LOW);

    Serial.println("WiFi not connected.");
    delay(1000);
    return;
  }

  // LED on - indicate that we are connected
  digitalWrite(STATUS_LED, HIGH);
}
