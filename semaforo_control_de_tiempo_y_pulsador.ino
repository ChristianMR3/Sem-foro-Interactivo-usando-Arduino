#define V 13  // Se decalran los pines que se van a utilizar para los leds
#define A 12
#define R 11
#define VP 10
#define RP 9
#define boton_1 8  /// se difine el pin para el boton 
#define pot A2     // se define el pin analogico para el potenciometro
 
void setup() {
  
  pinMode(V,OUTPUT);    // se declaran los pines de salida para los leds
  pinMode(A,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(VP,OUTPUT);
  pinMode(RP,OUTPUT); 
  pinMode(boton_1,INPUT);  // se declara el pin de entrada para el boton
  
  Serial.begin(9600);
  Serial.println("Semaforo en marcha");
}

void loop(){
  digitalWrite(V,HIGH);    // se enciende el led Verde para autos
  digitalWrite(RP,HIGH);   // se enciende el led Rojo para peaton
  delay(1500);          
   if(digitalRead(boton_1) == HIGH){    //en caso de que se pulse el boton el semaforo verde de los autos comensara a parpadear 
     Serial.println("boton pulsado");
     parpadeo(500);                     // el tiempo de parpadeo sera de 1500 milisegundos
     goto flag;                         //Transfiere el flujo del programa a la etiqueta flag esto hace que salte la instruccion de retraso del samaforo
    }
  retraso();                            // funcion retraso hace que el seamforo en verde para los autos dure mas tiempo por medio del potenciometro
  parpadeo(500);                       
  flag:                                 //etiqueta flag en caso de que se presione el boton se seguira ejecutando el programa desde este punto
  digitalWrite(V,LOW);             //se apaga el led verde
  digitalWrite(A,HIGH);            // se enciende el led amarillo
  delay(1500);                     // tienen un retraso de 1500 milisegundos
  digitalWrite(RP,LOW);         // se apaga el led rojo para peatones
  digitalWrite(A,LOW);       // se apaga el led amarillo para autos
  digitalWrite(VP,HIGH);        // se enciende el led verde para peatones
  digitalWrite(R,HIGH);      // se enciende el led rojo para autos
  //retraso();              // si desea controlar el tiempo de que dura el semaforo en verde para los peatones borre las diagonales de //retraso();
  delay(1700);                // tienen un retraso de 1700 milisegundos
  parpadeopeaton(500);      //parpadea el led verde del semaforo del peaton
  digitalWrite(VP,LOW);     // se apaga el led Verde del semaforo de peaton
  digitalWrite(R,LOW);      // se apaga el led rojo del seamaforo de autos
}
  
  void parpadeo(int duracion){ //el metodo para que el led Verde de los autos haga la funcion de parpadeo
    for (int i=1; i <= 3; i++){
      digitalWrite(V,HIGH); //se enciende el LED
      delay(duracion);   //tiempo de parpadeo
      digitalWrite(V,LOW);  //se apaga el LED
      delay(duracion);
    }

  }
  void parpadeopeaton(int duracion){ //el metodo para que el led Verde de peatones haga la funcion de parpadeo
    for (int i=1; i <= 3; i++){
      digitalWrite(VP,HIGH); //se enciende el LED
      delay(duracion);   //tiempo de parpadeo
      digitalWrite(VP,LOW);  //se apaga el LED
      delay(duracion);
    }
 }

  void retraso() {
     int tiempo; 
   // Calcula el tiempo de espera.
   // 2 segundos más el tiempo que añada el potenciómetro
     tiempo = 2000 + 5 * analogRead(A2);
   // Envía por el puerto serie el tiempo de espera
   Serial.print("Tiempo peatones = ");
   Serial.println(tiempo);
   tiempo = tiempo - 1500;
   // Espera
   delay(tiempo);
  }
