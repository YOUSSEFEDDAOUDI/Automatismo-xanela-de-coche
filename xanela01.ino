

// Define los pines pines de entrada y salida necesarios para controlar los relés de los motores 
const int pinReleAbrir = 11; // Pin para el relé del motor 1 (bajar)
const int pinReleCerrar = 12; // Pin para el relé del motor 2 (subir)
const int pinPulsador = 10; // Pin para el pulsador

// Define las constantes para los estados de los relés
const int RELE_ENCENDIDO = LOW; // Los relés se activan con LOW

void setup() {
  // Inicializa los pines
  pinMode(pinReleAbrir, OUTPUT);
  pinMode(pinReleCerrar, OUTPUT);
  pinMode(pinPulsador, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
                   // Verifica si el pulsador está presionado
  if (digitalRead(pinPulsador) == 1) {
    abrirOcerrarVentana(); // Llama a la función para bajar o subir
    delay(70); // Espera un tiempo para evitar rebotes del pulsador
    while (digitalRead(pinPulsador) == 1){
     Serial.println("pulsador premido.");
      delay(20);
      {
        Serial.println("pulsador suelto.");
        }
      delay(20);
      
    } 
  }
}

                            // Función para bajar o subir la ventana
void abrirOcerrarVentana() // Determina si la ventana está abierta o cerrada
{
  if (digitalRead(pinReleAbrir) == RELE_ENCENDIDO) // Si la ventana está abierta, ciérrala
  {
   
    digitalWrite(pinReleAbrir, !RELE_ENCENDIDO); // Apaga el relé de bajar
    digitalWrite(pinReleCerrar, RELE_ENCENDIDO); // Enciende el relé de subir
  } else {
    
    digitalWrite(pinReleAbrir, RELE_ENCENDIDO); // Enciende el relé de bajar
    digitalWrite(pinReleCerrar, !RELE_ENCENDIDO); // Apaga el relé de subir
  }
}
