#define V 13  // Se decalran los pines que se van a utilizar para los leds
#define A 12
#define R 11
#define VP 10
#define RP 9

void setup() {
  
  pinMode(V,OUTPUT);    // se declaran los pines de salida para los leds
  pinMode(A,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(VP,OUTPUT);
  pinMode(RP,OUTPUT); 
}

void loop(){
  digitalWrite(V,HIGH);    // se enciende el led Verde para autos
  digitalWrite(RP,HIGH);   // se enciende el led Rojo para peaton
  delay(1500);          
  parpadeo(500);                       
  digitalWrite(V,LOW);             //se apaga el led verde
  digitalWrite(A,HIGH);            // se enciende el led amarillo
  delay(1500);                     // tienen un retraso de 1500 milisegundos
  digitalWrite(RP,LOW);         // se apaga el led rojo para peatones
  digitalWrite(A,LOW);       // se apaga el led amarillo para autos
  digitalWrite(VP,HIGH);        // se enciende el led verde para peatones
  digitalWrite(R,HIGH);      // se enciende el led rojo para autos
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
