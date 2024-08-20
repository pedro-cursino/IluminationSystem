// Código usado para acender o LED por 1 minuto quando receber a requisição http://SEU-IP/LED_ON

#include <ESP8266WiFi.h>

const char* ssid = "NOME_DA_REDE";
const char* password = "SENHA_DA_REDE";

const int ledPin = D1; // Pino que esta o LED(GPIO5)

WiFiServer server(80);
bool ledState = false;

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
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

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client.");
    String request = client.readStringUntil('\r');
    Serial.println("Recebendo solicitação HTTP:");
    Serial.println(request);

    if (request.indexOf("/LED_ON") != -1) {
      ledState = true;
      digitalWrite(ledPin, HIGH);
      Serial.println("LED aceso.");
      delay(60000);  // LED aceso por 60 segundos
      digitalWrite(ledPin, LOW);
      ledState = false;
      Serial.println("LED apagado.");
    }

    client.flush();
    client.stop();
  }
}
