#include <WiFi.h>

const char* ssid = "Home"; 
const char* password = "narzieagle1992@#$%";

WiFiServer server(80);
String header;

void setup() {
  Serial.begin(115200);
  
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
}

void loop(){
  WiFiClient client = server.available(); 
  
  if (client) { 
    Serial.println("New Client.");
    String currentLine = ""; 
    while (client.connected()) 
    { 
      if (client.available()) { 
        char c = client.read();
        Serial.println("Read From Client");
        Serial.write(c);
        Serial.println("*****************");
        header += c;
        if (c == '\n') { 
          if (currentLine.length() == 0) {
          
          if(header.indexOf("dXNlcjpwYXNz") >= 0) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE html>\n");
          client.println("<html>\n");
          client.println("<body>\n");
          client.println("<center>\n");
          client.println("<h1 style=\"color:blue;\">ESP32 webserver</h1>\n");
          client.println("<h2 style=\"color:green;\">Hello World Web Sever</h2>\n");
          client.println("<h2 style=\"color:blue;\">Password protected Web server</h2>\n");
          client.println("</center>\n");
          client.println("</body>\n");
          client.println("</html>");
          
          break;
          }
          
          else { 
          client.println("HTTP/1.1 401 Unauthorized");
          client.println("WWW-Authenticate: Basic realm=\"Secure\"");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<html>Authentication failed</html>");
          break;
          } 
          } else { 
          currentLine = "";
          }
        } else if (c != '\r') {
        currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    
    header = "";
    
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
}
}
