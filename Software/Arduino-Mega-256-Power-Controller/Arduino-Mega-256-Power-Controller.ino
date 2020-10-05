//////////////////////////////////////////////////////////////////////////////
#include "Arduino-Power-Controller-PINs.c"
#include "Arduino-Power-Controller-SLOTs.c"
#include "Arduino-Power-Controller-EPROM.c"
#include "Arduino-Wifi-Power-Controller.c"

//////////////////////////////////////////////////////////////////////////////
// Arduino Mega 2560 Read/Write Functions
//////////////////////////////////////////////////////////////////////////////
// +| SetOutput |+
//////////////////////////////////////////////////////////////////////////////
void SetOutput ( int id                                                    ) {
  if           ( id < 22                                                   ) {
    return                                                                   ;
  }                                                                          ;
  if           ( id > 53                                                   ) {
    return                                                                   ;
  }                                                                          ;
  pinMode      ( id , OUTPUT                                               ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| SetOutput |-
//////////////////////////////////////////////////////////////////////////////
// +| SetInput |+
//////////////////////////////////////////////////////////////////////////////
void SetInput  ( int id                                                    ) {
  if           ( id < 22                                                   ) {
    return                                                                   ;
  }                                                                          ;
  if           ( id > 53                                                   ) {
    return                                                                   ;
  }                                                                          ;
  pinMode      ( id , INPUT                                                ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| SetInput |-
//////////////////////////////////////////////////////////////////////////////
// +| SetPin |+
//////////////////////////////////////////////////////////////////////////////
void SetPin     ( int id , int mode                                        ) {
  switch        (              mode                                        ) {
    case 0                                                                   :
      SetInput  ( id                                                       ) ;
    break                                                                    ;
    case 1                                                                   :
      SetOutput ( id                                                       ) ;
    break                                                                    ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| SetPin |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteHigh |+
//////////////////////////////////////////////////////////////////////////////
void WriteHigh ( int id                                                    ) {
  if           ( id < 22                                                   ) {
    return                                                                   ;
  }                                                                          ;
  if           ( id > 53                                                   ) {
    return                                                                   ;
  }                                                                          ;
  digitalWrite ( id , HIGH                                                 ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteHigh |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteLow |+
//////////////////////////////////////////////////////////////////////////////
void WriteLow  ( int id                                                    ) {
  if           ( id < 22                                                   ) {
    return                                                                   ;
  }                                                                          ;
  if           ( id > 53                                                   ) {
    return                                                                   ;
  }                                                                          ;
  digitalWrite ( id , LOW                                                  ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteLow |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteValue |+
//////////////////////////////////////////////////////////////////////////////
void WriteValue ( int id , int mode                                        ) {
  switch        (              mode                                        ) {
    case 0                                                                   :
      WriteLow  (     id                                                   ) ;
    break                                                                    ;
    case 1                                                                   :
      WriteHigh (     id                                                   ) ;
    break                                                                    ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteValue |-
//////////////////////////////////////////////////////////////////////////////
// +| ReadValue |+
//////////////////////////////////////////////////////////////////////////////
int ReadValue        ( int id                                              ) {
  if                 ( id < 22                                             ) {
    return 0                                                                 ;
  }                                                                          ;
  if                 ( id > 53                                             ) {
    return 0                                                                 ;
  }                                                                          ;
  return digitalRead ( id                                                  ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| ReadValue |-
//////////////////////////////////////////////////////////////////////////////
// +| SetAnalogOutput |+
//////////////////////////////////////////////////////////////////////////////
void SetAnalogOutput ( int id                                              ) {
  if                 ( id < 54                                             ) {
    return                                                                   ;
  }                                                                          ;
  if                 ( id > 69                                             ) {
    return                                                                   ;
  }                                                                          ;
  pinMode            ( id , OUTPUT                                         ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| SetAnalogOutput |-
//////////////////////////////////////////////////////////////////////////////
// +| SetAnalogInput |+
//////////////////////////////////////////////////////////////////////////////
void SetAnalogInput  ( int id                                              ) {
  if                 ( id < 54                                             ) {
    return                                                                   ;
  }                                                                          ;
  if                 ( id > 69                                             ) {
    return                                                                   ;
  }                                                                          ;
  pinMode            ( id , INPUT                                          ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| SetAnalogInput |-
//////////////////////////////////////////////////////////////////////////////
// +| SetAnalogPin |+
//////////////////////////////////////////////////////////////////////////////
void SetAnalogPin     ( int id , int mode                                  ) {
  switch              (              mode                                  ) {
    case 0                                                                   :
      SetAnalogInput  ( id                                                 ) ;
    break                                                                    ;
    case 1                                                                   :
      SetAnalogOutput ( id                                                 ) ;
    break                                                                    ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| SetAnalogPin |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteAnalog |+
//////////////////////////////////////////////////////////////////////////////
void WriteAnalog ( int id , int value                                      ) {
  if             ( id < 54                                                 ) {
    return                                                                   ;
  }                                                                          ;
  if             ( id > 69                                                 ) {
    return                                                                   ;
  }                                                                          ;
  analogWrite    ( id     ,     value                                      ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteAnalog |-
//////////////////////////////////////////////////////////////////////////////
// +| ReadAnalog |+
//////////////////////////////////////////////////////////////////////////////
int ReadAnalog      ( int id                                               ) {
  if                ( id < 54                                              ) {
    return 0                                                                 ;
  }                                                                          ;
  if                ( id > 69                                              ) {
    return 0                                                                 ;
  }                                                                          ;
  return analogRead ( id                                                   ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| ReadAnalog |-
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
void setup                   (                                             ) {
  ////////////////////////////////////////////////////////////////////////////
  Serial . begin             ( 115200                                      ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
// -| setup |-
//////////////////////////////////////////////////////////////////////////////
// +| loop |+
//////////////////////////////////////////////////////////////////////////////
void loop                      (                                           ) {
  ////////////////////////////////////////////////////////////////////////////
  Serial . println ( "Hello" ) ;
  delay ( 1000 ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
// -| loop |-
//////////////////////////////////////////////////////////////////////////////