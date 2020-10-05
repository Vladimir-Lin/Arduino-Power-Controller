//////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include "MegaPINs.h"
//////////////////////////////////////////////////////////////////////////////
// Arduino Mega 2560 Read/Write Functions
//////////////////////////////////////////////////////////////////////////////
// +| SetOutput |+
//////////////////////////////////////////////////////////////////////////////
void SetOutput ( int id                                                    ) {
  if           ( id < 0                                                    ) {
    return                                                                   ;
  }                                                                          ;
  if           ( id > 31                                                   ) {
    return                                                                   ;
  }                                                                          ;
  pinMode      ( id + 22 , OUTPUT                                          ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| SetOutput |-
//////////////////////////////////////////////////////////////////////////////
// +| SetInput |+
//////////////////////////////////////////////////////////////////////////////
void SetInput  ( int id                                                    ) {
  if           ( id < 0                                                    ) {
    return                                                                   ;
  }                                                                          ;
  if           ( id > 31                                                   ) {
    return                                                                   ;
  }                                                                          ;
  pinMode      ( id + 22 , INPUT                                           ) ;
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
  if           ( id < 0                                                    ) {
    return                                                                   ;
  }                                                                          ;
  if           ( id > 31                                                   ) {
    return                                                                   ;
  }                                                                          ;
  digitalWrite ( id + 22 , HIGH                                            ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteHigh |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteLow |+
//////////////////////////////////////////////////////////////////////////////
void WriteLow  ( int id                                                    ) {
  if           ( id < 0                                                    ) {
    return                                                                   ;
  }                                                                          ;
  if           ( id > 31                                                   ) {
    return                                                                   ;
  }                                                                          ;
  digitalWrite ( id + 22 , LOW                                             ) ;
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
  if                 ( id < 0                                              ) {
    return 0                                                                 ;
  }                                                                          ;
  if                 ( id > 31                                             ) {
    return 0                                                                 ;
  }                                                                          ;
  return digitalRead ( id + 22                                             ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| ReadValue |-
//////////////////////////////////////////////////////////////////////////////
// +| SetAnalogOutput |+
//////////////////////////////////////////////////////////////////////////////
void SetAnalogOutput ( int id                                              ) {
  if                 ( id < 0                                              ) {
    return                                                                   ;
  }                                                                          ;
  if                 ( id > 15                                             ) {
    return                                                                   ;
  }                                                                          ;
  pinMode            ( id + 54 , OUTPUT                                    ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| SetAnalogOutput |-
//////////////////////////////////////////////////////////////////////////////
// +| SetAnalogInput |+
//////////////////////////////////////////////////////////////////////////////
void SetAnalogInput  ( int id                                              ) {
  if                 ( id < 0                                              ) {
    return                                                                   ;
  }                                                                          ;
  if                 ( id > 15                                             ) {
    return                                                                   ;
  }                                                                          ;
  pinMode            ( id + 54 , INPUT                                     ) ;
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
  if             ( id < 0                                                  ) {
    return                                                                   ;
  }                                                                          ;
  if             ( id > 15                                                 ) {
    return                                                                   ;
  }                                                                          ;
  analogWrite    ( id + 54 ,    value                                      ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteAnalog |-
//////////////////////////////////////////////////////////////////////////////
// +| ReadAnalog |+
//////////////////////////////////////////////////////////////////////////////
int ReadAnalog      ( int id                                               ) {
  if                ( id < 0                                               ) {
    return 0                                                                 ;
  }                                                                          ;
  if                ( id > 15                                              ) {
    return 0                                                                 ;
  }                                                                          ;
  return analogRead ( id + 54                                              ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| ReadAnalog |-
//////////////////////////////////////////////////////////////////////////////
