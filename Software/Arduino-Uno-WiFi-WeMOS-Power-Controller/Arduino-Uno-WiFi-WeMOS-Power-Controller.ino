void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200) ;
  pinMode ( D6  , INPUT ) ;
  pinMode ( D7  , INPUT ) ;
  pinMode ( D8  , INPUT ) ;
  pinMode ( D10 , INPUT ) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  int v [ 60 ] ;
  int x [ 60 ] ;
  v  [ 0 ] = digitalRead ( D6 ) ;
  v  [ 1 ] = digitalRead ( D7 ) ;
  v  [ 2 ] = digitalRead ( D8 ) ;
  v  [ 3 ] = digitalRead ( D10 ) ;
  for (int i = 0 ; i < 4 ; i++ ) {
    Serial.print(v[i]) ;
    Serial.print(",") ;
  }
  Serial.println("") ;
  delay ( 1000 ) ;
}
