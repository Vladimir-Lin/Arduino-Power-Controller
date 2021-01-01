void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200) ;
  pinMode ( D2  , OUTPUT ) ;
  pinMode ( D3  , OUTPUT ) ;
  pinMode ( D4  , OUTPUT ) ;
  // pinMode ( D5  , OUTPUT ) ;
  pinMode ( D6  , INPUT_PULLUP ) ;
  pinMode ( D7  , INPUT_PULLUP ) ;
  pinMode ( D8  , INPUT_PULLUP ) ;
  // pinMode ( D10 , INPUT_PULLUP ) ;
  digitalWrite ( D2  , HIGH ) ;
  digitalWrite ( D3  , HIGH ) ;
  digitalWrite ( D4  , HIGH ) ;
  // digitalWrite ( D5  , HIGH ) ;
  Serial.print("0 : ") ; Serial.println(D0) ;
  Serial.print("1 : ") ; Serial.println(D1) ;
  Serial.print("2 : ") ; Serial.println(D2) ;
  Serial.print("3 : ") ; Serial.println(D3) ;
  Serial.print("4 : ") ; Serial.println(D4) ;
  Serial.print("5 : ") ; Serial.println(D5) ;
  Serial.print("6 : ") ; Serial.println(D6) ;
  Serial.print("7 : ") ; Serial.println(D7) ;
  Serial.print("8 : ") ; Serial.println(D8) ;
  Serial.print("9 : ") ; Serial.println(D9) ;
  Serial.print("10 : ") ; Serial.println(D10) ;
  Serial.print("11 : ") ; Serial.println(D11) ;
  Serial.print("12 : ") ; Serial.println(D12) ;
  Serial.print("13 : ") ; Serial.println(D13) ;
  Serial.print("14 : ") ; Serial.println(D14) ;
  Serial.print("15 : ") ; Serial.println(D15) ;
}

int atSwitch = 0 ;

void loop() {
  int v [ 60 ] ;
  int x [ 60 ] ;
  v  [ 0 ] = digitalRead ( D6 ) ;
  v  [ 1 ] = digitalRead ( D7 ) ;
  v  [ 2 ] = digitalRead ( D8 ) ;
  // v  [ 3 ] = digitalRead ( D10 ) ;
  for (int i = 0 ; i < 3 ; i++ ) {
    Serial.print(v[i]) ;
    Serial.print(",") ;
  }
  Serial.println("") ;
  switch ( atSwitch ) {
    case 0 :
      digitalWrite ( D2  , LOW  ) ;
      digitalWrite ( D3  , HIGH ) ;
      digitalWrite ( D4  , HIGH ) ;
      // digitalWrite ( D5  , LOW  ) ;
    break ;
    case 1 :
      digitalWrite ( D2  , HIGH ) ;
      digitalWrite ( D3  , LOW  ) ;
      digitalWrite ( D4  , HIGH ) ;
      // digitalWrite ( D5  , LOW  ) ;
    break ;
    case 2 :
      digitalWrite ( D2  , HIGH ) ;
      digitalWrite ( D3  , HIGH ) ;
      digitalWrite ( D4  , LOW  ) ;
      // digitalWrite ( D5  , LOW  ) ;
    break ;
    case 3 :
      digitalWrite ( D2  , LOW  ) ;
      digitalWrite ( D3  , LOW  ) ;
      digitalWrite ( D4  , LOW  ) ;
      // digitalWrite ( D5  , HIGH ) ;
    break ;
  }
  atSwitch = ( atSwitch + 1 ) % 3 ;
  delay ( 1000 ) ;
}
