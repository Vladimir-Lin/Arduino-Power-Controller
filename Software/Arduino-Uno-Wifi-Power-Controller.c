//////////////////////////////////////////////////////////////////////////////
// Arduino Uno WIFI WeMOS D1 R1 - WIFI Power Controller v1.0.0
//////////////////////////////////////////////////////////////////////////////
#include "EEPROM.h"
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
#include "ESP8266mDNS.h"
//////////////////////////////////////////////////////////////////////////////
bool Console = true                                                          ;
//////////////////////////////////////////////////////////////////////////////
// EEPROM Functions
//////////////////////////////////////////////////////////////////////////////
// +| WriteToEEPROM |+
//////////////////////////////////////////////////////////////////////////////
void WriteToEEPROM  ( int    address                                         ,
                      int    len                                             ,
                      char * Buffer                                          ,
                      bool   commit = true                                 ) {
  for               ( int i = 0 ; i < len ; i++                            ) {
    EEPROM . write  ( address + i , Buffer [ i ]                           ) ;
  }                                                                          ;
  if                ( commit                                               ) {
    EEPROM . commit (                                                      ) ;
  }                                                                          ;
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteToEEPROM |-
//////////////////////////////////////////////////////////////////////////////
// +| ReadFromEEPROM |+
//////////////////////////////////////////////////////////////////////////////
void ReadFromEEPROM ( int address , int len , char * Buffer                ) {
  for               ( int i = 0 ; i < len ; i++                            ) {
    Buffer [ i ] = EEPROM . read  ( address + i                            ) ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| ReadFromEEPROM |-
//////////////////////////////////////////////////////////////////////////////
// ESP-8266 WIFI Functions
//////////////////////////////////////////////////////////////////////////////
// +| SetEsp8266WifiSTA |+
//////////////////////////////////////////////////////////////////////////////
void SetEsp8266WifiSTA (                                                   ) {
  WiFi . mode          ( WIFI_STA                                          ) ;
  WiFi . disconnect    (                                                   ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| SetEsp8266WifiSTA |-
//////////////////////////////////////////////////////////////////////////////
// +| SetEsp8266WifiAP |+
//////////////////////////////////////////////////////////////////////////////
void SetEsp8266WifiAP  (                                                   ) {
  WiFi . mode          ( WIFI_AP                                           ) ;
  WiFi . disconnect    (                                                   ) ;
}
//////////////////////////////////////////////////////////////////////////////
// -| SetEsp8266WifiSTA |-
//////////////////////////////////////////////////////////////////////////////
// +| GetEsp8266WifiNetworks |+
//////////////////////////////////////////////////////////////////////////////
int GetEsp8266WifiNetworks ( )                                               {
  return WiFi . scanNetworks ( )                                             ;
}
//////////////////////////////////////////////////////////////////////////////
// -| GetEsp8266WifiNetworks |-
//////////////////////////////////////////////////////////////////////////////
// +| PrintEsp8266WifiStation |+
//////////////////////////////////////////////////////////////////////////////
int PrintEsp8266WifiStation ( int id )                                       {
  bool encrypt =   ( WiFi . encryptionType ( id ) == ENC_TYPE_NONE )         ;
  Serial . print   ( id + 1             )                                    ;
  Serial . print   ( " : "              )                                    ;
  Serial . print   ( WiFi . SSID ( id ) )                                    ;
  Serial . print   ( " ("               )                                    ;
  Serial . print   ( WiFi . RSSI ( id ) )                                    ;
  Serial . print   ( ")"                )                                    ;
  Serial . println ( encrypt ? "" : "*" )                                    ;
}
//////////////////////////////////////////////////////////////////////////////
// -| PrintEsp8266WifiStation |-
//////////////////////////////////////////////////////////////////////////////
// Arduino Uno Wifi WeMOS D1 R2 Read/Write Functions
//////////////////////////////////////////////////////////////////////////////
// +| SetOutput |+
//////////////////////////////////////////////////////////////////////////////
void SetOutput        ( int id       )                                       {
  switch              (     id       )                                       {
    case  0 : pinMode ( D0  , OUTPUT ) ; break                               ;
    case  1 : pinMode ( D1  , OUTPUT ) ; break                               ;
    case  2 : pinMode ( D2  , OUTPUT ) ; break                               ;
    case  3 : pinMode ( D3  , OUTPUT ) ; break                               ;
    case  4 : pinMode ( D4  , OUTPUT ) ; break                               ;
    case  5 : pinMode ( D5  , OUTPUT ) ; break                               ;
    case  6 : pinMode ( D6  , OUTPUT ) ; break                               ;
    case  7 : pinMode ( D7  , OUTPUT ) ; break                               ;
    case  8 : pinMode ( D8  , OUTPUT ) ; break                               ;
    case  9 : pinMode ( D9  , OUTPUT ) ; break                               ;
    case 10 : pinMode ( D10 , OUTPUT ) ; break                               ;
    case 11 : pinMode ( D11 , OUTPUT ) ; break                               ;
    case 12 : pinMode ( D12 , OUTPUT ) ; break                               ;
    case 13 : pinMode ( D13 , OUTPUT ) ; break                               ;
    case 14 : pinMode ( D14 , OUTPUT ) ; break                               ;
    case 15 : pinMode ( D15 , OUTPUT ) ; break                               ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| SetOutput |-
//////////////////////////////////////////////////////////////////////////////
// +| SetInput |+
//////////////////////////////////////////////////////////////////////////////
void SetInput         ( int id      )                                        {
  switch              (     id      )                                        {
    case  0 : pinMode ( D0  , INPUT ) ; break                                ;
    case  1 : pinMode ( D1  , INPUT ) ; break                                ;
    case  2 : pinMode ( D2  , INPUT ) ; break                                ;
    case  3 : pinMode ( D3  , INPUT ) ; break                                ;
    case  4 : pinMode ( D4  , INPUT ) ; break                                ;
    case  5 : pinMode ( D5  , INPUT ) ; break                                ;
    case  6 : pinMode ( D6  , INPUT ) ; break                                ;
    case  7 : pinMode ( D7  , INPUT ) ; break                                ;
    case  8 : pinMode ( D8  , INPUT ) ; break                                ;
    case  9 : pinMode ( D9  , INPUT ) ; break                                ;
    case 10 : pinMode ( D10 , INPUT ) ; break                                ;
    case 11 : pinMode ( D11 , INPUT ) ; break                                ;
    case 12 : pinMode ( D12 , INPUT ) ; break                                ;
    case 13 : pinMode ( D13 , INPUT ) ; break                                ;
    case 14 : pinMode ( D14 , INPUT ) ; break                                ;
    case 15 : pinMode ( D15 , INPUT ) ; break                                ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| SetInput |-
//////////////////////////////////////////////////////////////////////////////
// +| SetPin |+
//////////////////////////////////////////////////////////////////////////////
void SetPin   ( int id , int mode                                          ) {
  if          ( Console && ( id == 1 )                                     ) {
    return                                                                   ;
  }                                                                          ;
  if          ( mode == 0                                                  ) {
    SetInput  ( id                                                         ) ;
  } else                                                                     {
    SetOutput ( id                                                         ) ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| SetPin |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteHigh |+
//////////////////////////////////////////////////////////////////////////////
void WriteHigh             ( int id     )                                    {
  switch                   (     id     )                                    {
    case  0 : digitalWrite ( D0  , HIGH ) ; break                            ;
    case  1 : digitalWrite ( D1  , HIGH ) ; break                            ;
    case  2 : digitalWrite ( D2  , HIGH ) ; break                            ;
    case  3 : digitalWrite ( D3  , HIGH ) ; break                            ;
    case  4 : digitalWrite ( D4  , HIGH ) ; break                            ;
    case  5 : digitalWrite ( D5  , HIGH ) ; break                            ;
    case  6 : digitalWrite ( D6  , HIGH ) ; break                            ;
    case  7 : digitalWrite ( D7  , HIGH ) ; break                            ;
    case  8 : digitalWrite ( D8  , HIGH ) ; break                            ;
    case  9 : digitalWrite ( D9  , HIGH ) ; break                            ;
    case 10 : digitalWrite ( D10 , HIGH ) ; break                            ;
    case 11 : digitalWrite ( D11 , HIGH ) ; break                            ;
    case 12 : digitalWrite ( D12 , HIGH ) ; break                            ;
    case 13 : digitalWrite ( D13 , HIGH ) ; break                            ;
    case 14 : digitalWrite ( D14 , HIGH ) ; break                            ;
    case 15 : digitalWrite ( D15 , HIGH ) ; break                            ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteHigh |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteLow |+
//////////////////////////////////////////////////////////////////////////////
void WriteLow              ( int id    )                                     {
  switch                   (     id    )                                     {
    case  0 : digitalWrite ( D0  , LOW ) ; break                             ;
    case  1 : digitalWrite ( D1  , LOW ) ; break                             ;
    case  2 : digitalWrite ( D2  , LOW ) ; break                             ;
    case  3 : digitalWrite ( D3  , LOW ) ; break                             ;
    case  4 : digitalWrite ( D4  , LOW ) ; break                             ;
    case  5 : digitalWrite ( D5  , LOW ) ; break                             ;
    case  6 : digitalWrite ( D6  , LOW ) ; break                             ;
    case  7 : digitalWrite ( D7  , LOW ) ; break                             ;
    case  8 : digitalWrite ( D8  , LOW ) ; break                             ;
    case  9 : digitalWrite ( D9  , LOW ) ; break                             ;
    case 10 : digitalWrite ( D10 , LOW ) ; break                             ;
    case 11 : digitalWrite ( D11 , LOW ) ; break                             ;
    case 12 : digitalWrite ( D12 , LOW ) ; break                             ;
    case 13 : digitalWrite ( D13 , LOW ) ; break                             ;
    case 14 : digitalWrite ( D14 , LOW ) ; break                             ;
    case 15 : digitalWrite ( D15 , LOW ) ; break                             ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteLow |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteValue |+
//////////////////////////////////////////////////////////////////////////////
void WriteValue ( int id , int mode                                        ) {
  if            ( Console && ( id == 1 )                                   ) {
    return                                                                   ;
  }                                                                          ;
  if            ( mode == 0                                                ) {
    WriteLow    (     id                                                   ) ;
  } else                                                                     {
    WriteHigh   (     id                                                   ) ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteValue |-
//////////////////////////////////////////////////////////////////////////////
// +| ReadValue |+
//////////////////////////////////////////////////////////////////////////////
int ReadValue                    ( int id )                                  {
  if                             ( Console && ( id == 1 )                  ) {
    return 0                                                                 ;
  }                                                                          ;
  switch                         (     id )                                  {
    case  0 : return digitalRead ( D0     )                                  ;
    case  1 : return digitalRead ( D1     )                                  ;
    case  2 : return digitalRead ( D2     )                                  ;
    case  3 : return digitalRead ( D3     )                                  ;
    case  4 : return digitalRead ( D4     )                                  ;
    case  5 : return digitalRead ( D5     )                                  ;
    case  6 : return digitalRead ( D6     )                                  ;
    case  7 : return digitalRead ( D7     )                                  ;
    case  8 : return digitalRead ( D8     )                                  ;
    case  9 : return digitalRead ( D9     )                                  ;
    case 10 : return digitalRead ( D10    )                                  ;
    case 11 : return digitalRead ( D11    )                                  ;
    case 12 : return digitalRead ( D12    )                                  ;
    case 13 : return digitalRead ( D13    )                                  ;
    case 14 : return digitalRead ( D14    )                                  ;
    case 15 : return digitalRead ( D15    )                                  ;
  }                                                                          ;
  return 0                                                                   ;
}
//////////////////////////////////////////////////////////////////////////////
// -| ReadValue |-
//////////////////////////////////////////////////////////////////////////////
// +| WriteAnalog |+
//////////////////////////////////////////////////////////////////////////////
void WriteAnalog          ( int id , int value )                             {
  switch                  (     id             )                             {
    case  0 : analogWrite ( 0      ,     value ) ; break                     ;
    case  1 : analogWrite ( 1      ,     value ) ; break                     ;
    case  2 : analogWrite ( 2      ,     value ) ; break                     ;
    case  3 : analogWrite ( 3      ,     value ) ; break                     ;
    case  4 : analogWrite ( 4      ,     value ) ; break                     ;
    case  5 : analogWrite ( 5      ,     value ) ; break                     ;
  }
}
//////////////////////////////////////////////////////////////////////////////
// -| WriteAnalog |-
//////////////////////////////////////////////////////////////////////////////
// +| ReadAnalog |+
//////////////////////////////////////////////////////////////////////////////
int ReadAnalog                  ( int id )                                   {
  switch                        (     id )                                   {
    case  0 : return analogRead ( 0      )                                   ;
    case  1 : return analogRead ( 1      )                                   ;
    case  2 : return analogRead ( 2      )                                   ;
    case  3 : return analogRead ( 3      )                                   ;
    case  4 : return analogRead ( 4      )                                   ;
    case  5 : return analogRead ( 5      )                                   ;
  }                                                                          ;
  return 0                                                                   ;
}
//////////////////////////////////////////////////////////////////////////////
// -| ReadAnalog |-
//////////////////////////////////////////////////////////////////////////////
// 控制電源類別
//////////////////////////////////////////////////////////////////////////////
class PowerController
{
  public :

    PowerController ( int output , int input , int mode = 0 )
    {
      OutputPin     = output ;
      InputPin      = input  ;
      CurrentOutput = false  ;
      CurrentInput  = false  ;
      SwitchMode    = mode   ;
      SetPin ( input  , 0 )  ;
      SetPin ( output , 1 )  ;
    }

    // 0 - Switch Mode
    // 1 - Sync Mode
    // 2 - Isolate Mode

    void setSwitch  ( int mode )
    {
      SwitchMode = mode ;
    }

    bool GetInput (void)
    {
      int  v  = ReadValue ( InputPin ) ;
      CurrentInput = ( v > 0 ) ;
      return CurrentInput ;
    }

    bool Probe (void)
    {
      int  v       = ReadValue ( InputPin ) ;
      bool on      =           ( v > 0    ) ;
      bool changed = false ;
      switch ( SwitchMode ) {
        case 0 :
          if ( CurrentInput != on ) {
            CurrentInput = on ;
            Switch ( ) ;
            changed = true ;
          }
        break  ;
        case 1 :
          if ( CurrentInput != on ) {
            CurrentInput = on ;
            changed = true ;
          }
          if ( CurrentOutput != on ) {
            Turn ( on ) ;
            changed = true ;
          }
        break  ;
        case 2 :
          if ( CurrentInput != on ) {
            changed = true ;
          }
          CurrentInput = on ;
        break  ;
      }
      return changed ;
    }

    void Turn ( bool OnOff )
    {
      if ( CurrentOutput == OnOff ) {
        return ;
      }
      CurrentOutput = OnOff ;
      WriteValue ( OutputPin , OnOff ? 1 : 0 ) ;
    }

    void Switch ( void )
    {
      Turn ( CurrentOutput ? false : true ) ;
    }

    bool Power ( void )
    {
      return CurrentOutput ;
    }

    bool InputNow ( void )
    {
      return CurrentInput ;
    }

  protected :

    int  OutputPin     ;
    int  InputPin      ;
    bool CurrentOutput ;
    bool CurrentInput  ;
    int  SwitchMode    ;

  private :

} ;
//////////////////////////////////////////////////////////////////////////////
int           Debug             = 1                                          ;
int           BaudRate          = 115200                                     ;
int           EepromSize        = 4096                                       ;
bool          doDelay           = true                                       ;
unsigned int  MicrosecondsDelay = 10000                                      ;
//////////////////////////////////////////////////////////////////////////////
void LoopDelay       (                                                     ) {
  if                 ( ! doDelay                                           ) {
    return                                                                   ;
  }                                                                          ;
  delayMicroseconds  ( MicrosecondsDelay                                   ) ;
}
//////////////////////////////////////////////////////////////////////////////
// 電源控制器掃描控制點
//////////////////////////////////////////////////////////////////////////////
int  PowerProbedMillis   = 0                                                 ;
int  PowerSwitchMode     = 0                                                 ;
int  MaxPowerControllers = 8                                                 ;
char DefaultOutputValues [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }           ;
char DefaultInputValues  [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }           ;
PowerController ** PC                                                        ;
//////////////////////////////////////////////////////////////////////////////
void InitializePowerControllers ( void )                                     {
  SetOutput            (  2         ) ;
  SetOutput            (  3         ) ;
  SetOutput            (  4         ) ;
  SetOutput            (  5         ) ;
  SetOutput            (  6         ) ;
  SetOutput            (  7         ) ;
//  analogReadResolution ( 10         ) ;
  pinMode              ( A0     , INPUT ) ;
  pinMode              ( A0 + 1 , INPUT ) ;
  pinMode              ( A0 + 2 , INPUT ) ;
  pinMode              ( A0 + 3 , INPUT ) ;
  pinMode              ( A0 + 4 , INPUT ) ;
  pinMode              ( A0 + 5 , INPUT ) ;
  WriteValue           ( 2  , 0     ) ;
  WriteValue           ( 3  , 0     ) ;
  WriteValue           ( 4  , 0     ) ;
  WriteValue           ( 5  , 0     ) ;
  WriteValue           ( 6  , 0     ) ;
  WriteValue           ( 7  , 0     ) ;
/*
  int outputValue                                                            ;
  int inputValue                                                             ;
  int psw = PowerSwitchMode                                                  ;
  PC         = new PowerController * [ MaxPowerControllers ]                 ;
  for ( int i = 0 ; i < MaxPowerControllers ; i++ )                          {
    outputValue = int ( DefaultOutputValues [ i ] )                          ;
    inputValue  = int ( DefaultInputValues  [ i ] )                          ;
    PC [ i ] = new PowerController ( i + MaxPowerControllers , i , psw     ) ;
    PC [ i ] -> Turn               ( ( outputValue > 0 ) ? true : false    ) ;
    PC [ i ] -> GetInput           (                                       ) ;
  }
*/
}
//////////////////////////////////////////////////////////////////////////////

void ProbePowerControllers ( void                                          ) {
  ////////////////////////////////////////////////////////////////////////////
  int v1 = analogRead ( A0       ) ;
  int v2 = analogRead ( A0 + 1   ) ;
  int v3 = analogRead ( A0 + 2   ) ;
  int v4 = analogRead ( A0 + 3   ) ;
  int v5 = analogRead ( A0 + 4   ) ;
  int v6 = analogRead ( A0 + 5   ) ;
  Serial . print      ( "1 : "   ) ;
  Serial . print      ( v1 , DEC ) ;
  Serial . print      ( " 2 : "  ) ;
  Serial . print      ( v2 , DEC ) ;
  Serial . print      ( " 3 : "  ) ;
  Serial . print      ( v3 , DEC ) ;
  Serial . print      ( " 4 : "  ) ;
  Serial . print      ( v4 , DEC ) ;
  Serial . print      ( " 5 : "  ) ;
  Serial . print      ( v5 , DEC ) ;
  Serial . print      ( " 6 : "  ) ;
  Serial . print      ( v6 , DEC ) ;
  Serial . println    ( ""       ) ;
/*
  int  dtm = millis        (                                               ) ;
  int  dt  = dtm - PowerProbedMillis                                         ;
  bool in                                                                    ;
  bool changed = false                                                       ;
  bool pc                                                                    ;
  ////////////////////////////////////////////////////////////////////////////
  if                       ( dt < 10                                       ) {
    return                                                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  PowerProbedMillis = dtm                                                    ;
  for                      ( int i = 0 ; i < MaxPowerControllers ; i++     ) {
    pc = PC [ i ] -> Probe (                                               ) ;
    if                     ( pc                                            ) {
      changed = true                                                         ;
    }                                                                        ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  if                       ( ! changed                                     ) {
    return                                                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  for                      ( int i = 0 ; i < MaxPowerControllers ; i++     ) {
    pc = PC [ i ] -> Power    (                                            ) ;
    in = PC [ i ] -> InputNow (                                            ) ;
    DefaultOutputValues [ i ] = pc ? 1 : 0                                   ;
    DefaultInputValues  [ i ] = in ? 1 : 0                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  WriteToEEPROM            ( 192 , 8 , DefaultOutputValues                 ) ;
  WriteToEEPROM            ( 200 , 8 , DefaultInputValues                  ) ;
*/
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
bool               RewriteEEPROM   = false                                   ;
int                WifiMode        = 2                                       ;
bool               WifiConnected   = false                                   ;
int                WifiTimestamp   = 0                                       ;
char             * WifiSSID        = "Actions 7f"                            ;
char             * WifiPassword    = "0912388888"                            ;
char             * OriphaseArduino = "Oriphase"                              ;
char             * ArduinoSite     = "ArduinoPowerController"                ;
char             * SapPassword     = ""                                      ;
char             * SiteUsername    = "admin"                                 ;
char             * SitePassword    = "123456789"                             ;
bool               AssignIP        = false                                   ;
char               HostIP      [ 4 ]                                         ;
char               HostGateway [ 4 ]                                         ;
char               HostNetmask [ 4 ]                                         ;
int                WifiHttpPort    = 80                                      ;
bool               HttpInitialized = false                                   ;
ESP8266WebServer * HttpServer      = nullptr                                 ;
//////////////////////////////////////////////////////////////////////////////
IPAddress ComposeIP ( char * ip )                                            {
  return IPAddress ( ip [ 0 ] , ip [ 1 ] , ip [ 2 ] , ip [ 3 ] )             ;
}
//////////////////////////////////////////////////////////////////////////////
void WebServerEntry ( )                                                      {
  ////////////////////////////////////////////////////////////////////////////
  if ( HttpServer == nullptr )                                               {
    return                                                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  HttpServer -> send                                                         (
    200                                                                      ,
    "text/html"                                                              ,
    "Oriphase Power Controller"                                            ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void WebServerWIFI ( )                                                       {
  ////////////////////////////////////////////////////////////////////////////
  String HTML                                                                ;
  String LINE                                                                ;
  int    totalNetworks                                                       ;
  bool   encrypt                                                             ;
  ////////////////////////////////////////////////////////////////////////////
  if ( HttpServer == nullptr )                                               {
    return                                                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  totalNetworks = GetEsp8266WifiNetworks ( )                                 ;
  for ( int i = 0 ; i < totalNetworks ; i++ )                                {
    encrypt  = ( WiFi . encryptionType ( i ) == ENC_TYPE_NONE )              ;
    LINE     = String ( i + 1 , DEC         )                                ;
    LINE    += String ( " : "               )                                ;
    LINE    += String ( WiFi . SSID ( i )   )                                ;
    LINE    += String ( " ("                )                                ;
    LINE    += String ( WiFi . RSSI ( i )   )                                ;
    LINE    += String ( ")"                 )                                ;
    LINE    += String ( encrypt ? "" : " *" )                                ;
    if ( ( i + 1 ) < totalNetworks )                                         {
      LINE  += String ( "<br>\n"            )                                ;
    }                                                                        ;
    HTML    += LINE                                                          ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  HttpServer -> send ( 200 , "text/html" , HTML                            ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void WebServerAJAX      (                                                  ) {
  ////////////////////////////////////////////////////////////////////////////
  if                    ( HttpServer == nullptr                            ) {
    return                                                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  if                    ( HttpServer -> args ( ) > 0                       ) {
    if                  ( HttpServer -> hasArg ( "Method" )                ) {
      ////////////////////////////////////////////////////////////////////////
      String Method = HttpServer -> arg ( "Method" )                         ;
      ////////////////////////////////////////////////////////////////////////
      if                ( Method == "Output"                               ) {
        //////////////////////////////////////////////////////////////////////
        String MSG                                                           ;
        String ID   = HttpServer -> arg   ( "ID"   )                         ;
        String TURN = HttpServer -> arg   ( "Turn" )                         ;
        int    vId  = ID          . toInt (        )                         ;
        //////////////////////////////////////////////////////////////////////
        if ( ( vId >= 0 ) && ( vId < MaxPowerControllers ) )                 {
          ////////////////////////////////////////////////////////////////////
          bool pwm                                                           ;
          ////////////////////////////////////////////////////////////////////
          if            ( TURN == "On"                                     ) {
            PC [ vId ] -> Turn      ( true  )                                ;
          } else
          if            ( TURN == "Off"                                    ) {
            PC [ vId ] -> Turn      ( false )                                ;
          } else
          if            ( TURN == "Switch"                                 ) {
            PC [ vId ] -> Switch    (       )                                ;
          }                                                                  ;
          ////////////////////////////////////////////////////////////////////
          pwm = PC [ vId ] -> Power (       )                                ;
          ////////////////////////////////////////////////////////////////////
          if            ( pwm                                              ) {
            MSG  = "On"                                                      ;
          } else                                                             {
            MSG  = "Off"                                                     ;
          }                                                                  ;
          ////////////////////////////////////////////////////////////////////
        } else                                                               {
          MSG    = "NO"                                                      ;
        }                                                                    ;
        HttpServer -> send                                                   (
          200                                                                ,
          "text/html"                                                        ,
          MSG                                                              ) ;
        return                                                               ;
        //////////////////////////////////////////////////////////////////////
      } else
      if                ( Method == "Input"                                ) {
        //////////////////////////////////////////////////////////////////////
        String MSG                                                           ;
        String ID   = HttpServer -> arg   ( "ID"   )                         ;
        int    vId  = ID          . toInt (        )                         ;
        //////////////////////////////////////////////////////////////////////
        if ( ( vId >= 0 ) && ( vId < MaxPowerControllers ) )                 {
          bool in = PC [ vId ] -> GetInput ( )                               ;
          if ( in )                                                          {
            MSG = "High"                                                     ;
          } else                                                             {
            MSG = "Low"                                                      ;
          }                                                                  ;
        } else                                                               {
          MSG   = "NO"                                                       ;
        }                                                                    ;
        //////////////////////////////////////////////////////////////////////
        HttpServer -> send                                                   (
          200                                                                ,
          "text/html"                                                        ,
          MSG                                                              ) ;
        return                                                               ;
        //////////////////////////////////////////////////////////////////////
      } else
      if                ( Method == "Mode"                                 ) {
        //////////////////////////////////////////////////////////////////////
        String MSG                                                           ;
        String ID   = HttpServer -> arg   ( "ID"   )                         ;
        String Mode = HttpServer -> arg   ( "Mode" )                         ;
        int    vId  = ID          . toInt (        )                         ;
        int    mId  = Mode        . toInt (        )                         ;
        //////////////////////////////////////////////////////////////////////
        if ( ( vId >= 0 ) && ( vId < MaxPowerControllers ) )                 {
          PC [ vId ] -> setSwitch ( mId )                                    ;
        }                                                                    ;
        //////////////////////////////////////////////////////////////////////
        HttpServer -> send                                                   (
          200                                                                ,
          "text/html"                                                        ,
          "OK"                                                             ) ;
        return                                                               ;
        //////////////////////////////////////////////////////////////////////
      } else
      if                ( Method == "Settings"                             ) {
        //////////////////////////////////////////////////////////////////////
        String ITEM = HttpServer -> arg   ( "Item" )                         ;
        if              ( ITEM   == "Console"                              ) {
          String TURN = HttpServer -> arg   ( "Turn" )                       ;
          if            ( TURN == "On"                                     ) {
            Console = true                                                   ;
          } else                                                             {
            Console = false                                                  ;
          }                                                                  ;
          FlashEEPROM   (                                                  ) ;
        }                                                                    ;
        //////////////////////////////////////////////////////////////////////
      }                                                                      ;
      ////////////////////////////////////////////////////////////////////////
    }                                                                        ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  if                    ( HttpServer -> headers ( ) > 0                    ) {
    if                  ( Console                                          ) {
      Serial . print    ( "AJAX Headers : "                                ) ;
      Serial . println  ( HttpServer -> headers ( ) , DEC                  ) ;
    }                                                                        ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  HttpServer -> send                                                         (
    200                                                                      ,
    "text/html"                                                              ,
    "OK"                                                                   ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void WebServerNotFound ( )                                                   {
  ////////////////////////////////////////////////////////////////////////////
  if ( HttpServer == nullptr )                                               {
    return                                                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  HttpServer -> send                                                         (
    404                                                                      ,
    "text/plain"                                                             ,
    "File NOT found!"                                                      ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void ReportWIFI              (                                             ) {
  ////////////////////////////////////////////////////////////////////////////
  if                         ( ! Console                                   ) {
    return                                                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  int totalNetworks = GetEsp8266WifiNetworks ( )                             ;
  for ( int i = 0 ; i < totalNetworks ; i++ )                                {
    PrintEsp8266WifiStation ( i )                                            ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
bool isConnectionTimeout     ( void                                        ) {
  int dt = millis            (                                             ) ;
  dt -= WifiTimestamp                                                        ;
  return                     ( dt > 10000                                  ) ;
}
//////////////////////////////////////////////////////////////////////////////
void ConnectToWIFI           (                                             ) {
  ////////////////////////////////////////////////////////////////////////////
  int dt                                                                     ;
  int status                                                                 ;
  ////////////////////////////////////////////////////////////////////////////
  SetEsp8266WifiSTA          (                                             ) ;
  ////////////////////////////////////////////////////////////////////////////
  WiFi   . begin             ( WifiSSID , WifiPassword                     ) ;
  if                         ( AssignIP                                    ) {
    WiFi . config            ( ComposeIP ( HostIP      )                     , // IP Address
                               ComposeIP ( HostGateway )                     , // Gateway
                               ComposeIP ( HostNetmask )                   ) ; // Netmask
  }                                                                          ;
  WifiConnected = false                                                      ;
  WifiTimestamp = millis     (                                             ) ;
  ////////////////////////////////////////////////////////////////////////////
  do                                                                         {
    delay                    ( 100                                         ) ;
    status = WiFi . status   (                                             ) ;
    dt     = millis          (                                             ) ;
  } while ( ( status != WL_CONNECTED ) && ( ( dt-WifiTimestamp ) < 5000 )  ) ;
  ////////////////////////////////////////////////////////////////////////////
  if                         ( status == WL_CONNECTED                      ) {
    //////////////////////////////////////////////////////////////////////////
    WifiConnected = true                                                     ;
    PrepareHTTP              (                                             ) ;
    //////////////////////////////////////////////////////////////////////////
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void BuildUpSoftAP           (                                             ) {
  ////////////////////////////////////////////////////////////////////////////
  SetEsp8266WifiAP           (                                             ) ;
  ////////////////////////////////////////////////////////////////////////////
  WiFi   . begin             ( ArduinoSite , SapPassword                   ) ;
//  WiFi   . softAP            ( ArduinoSite , SapPassword                   ) ;
//  IPAddress myIP = WiFi.softAPIP();
  if                         ( MDNS . begin ( OriphaseArduino )            ) {
    MDNS . addService        ( "http" , "tcp" , 80                         ) ;
  }                                                                          ;
//  if                         ( AssignIP                                    ) {
//    WiFi . config            ( ComposeIP ( HostIP      )                     , // IP Address
//                               ComposeIP ( HostGateway )                     , // Gateway
//                               ComposeIP ( HostNetmask )                   ) ; // Netmask
//  }                                                                          ;
  WifiConnected = true                                                       ;
  WifiTimestamp = millis     (                                             ) ;
  ////////////////////////////////////////////////////////////////////////////
  if                         ( Console                                     ) {
    Serial . print           ( "Soft Access Point : "                      ) ;
    Serial . println         ( WiFi . softAPIP ( )                         ) ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void PrepareHTTP             ( void                                        ) {
  ////////////////////////////////////////////////////////////////////////////
  if                         ( ! HttpInitialized                           ) {
    HttpInitialized = true                                                   ;
    HttpServer -> on         ( "/"           , WebServerEntry              ) ;
    HttpServer -> on         ( "/index.html" , WebServerEntry              ) ;
    HttpServer -> on         ( "/WIFI"       , WebServerWIFI               ) ;
    HttpServer -> on         ( "/AJAX"       , WebServerAJAX               ) ;
    HttpServer -> onNotFound (                 WebServerNotFound           ) ;
    HttpServer -> begin      (                                             ) ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  if                         ( Console                                     ) {
    //////////////////////////////////////////////////////////////////////////
    ReportWIFI               (                                             ) ;
    //////////////////////////////////////////////////////////////////////////
    Serial . println         ( ""                                          ) ;
    Serial . print           ( "IP address: "                              ) ;
    Serial . println         ( WiFi . localIP ( )                          ) ;
    Serial . println         ( "WiFi status:"                              ) ;
    WiFi   . printDiag       ( Serial                                      ) ;
    //////////////////////////////////////////////////////////////////////////
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void SetupWIFI               (                                             ) {
  ////////////////////////////////////////////////////////////////////////////
  switch                     (  WifiMode                                   ) {
    //////////////////////////////////////////////////////////////////////////
    case 1                                                                   :
      ////////////////////////////////////////////////////////////////////////
      BuildUpSoftAP          (                                             ) ;
      HttpServer    = new ESP8266WebServer ( WifiHttpPort                  ) ;
      ////////////////////////////////////////////////////////////////////////
    break                                                                    ;
    //////////////////////////////////////////////////////////////////////////
    case 2                                                                   :
      ////////////////////////////////////////////////////////////////////////
      ConnectToWIFI          (                                             ) ;
      HttpServer    = new ESP8266WebServer ( WifiHttpPort                  ) ;
      ////////////////////////////////////////////////////////////////////////
    break                                                                    ;
    //////////////////////////////////////////////////////////////////////////
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void DoingWIFI              (                                              ) {
  ////////////////////////////////////////////////////////////////////////////
  switch                    (  WifiMode                                    ) {
    //////////////////////////////////////////////////////////////////////////
    case 1                                                                   :
      ////////////////////////////////////////////////////////////////////////
      if                    ( HttpInitialized                              ) {
        if                  ( HttpServer != nullptr                        ) {
          HttpServer -> handleClient ( )                                     ;
        }                                                                    ;
      } else                                                                 {
        PrepareHTTP         (                                              ) ;
      }                                                                      ;
      ////////////////////////////////////////////////////////////////////////
    break                                                                    ;
    //////////////////////////////////////////////////////////////////////////
    case 2                                                                   :
      ////////////////////////////////////////////////////////////////////////
      if                    ( WifiConnected                                ) {
        if                  ( HttpInitialized                              ) {
          if                ( HttpServer != nullptr                        ) {
            HttpServer -> handleClient ( )                                   ;
          }                                                                  ;
        } else                                                               {
          PrepareHTTP       (                                              ) ;
        }                                                                    ;
      } else                                                                 {
        if                  ( WiFi . status ( ) == WL_CONNECTED            ) {
          WifiConnected = true                                               ;
          PrepareHTTP       (                                              ) ;
        } else                                                               {
          if                ( isConnectionTimeout ( )                      ) {
            ConnectToWIFI   (                                              ) ;
          }                                                                  ;
        }                                                                    ;
      }                                                                      ;
      ////////////////////////////////////////////////////////////////////////
    break                                                                    ;
    //////////////////////////////////////////////////////////////////////////
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
typedef struct OriphaseConfigure                                             {
  char         Oriphase     [  8 ]                                           ; //   0
  char         Site         [ 24 ]                                           ; //   8
  char         SapPassword  [ 32 ]                                           ; //  32
  char         WifiSSID     [ 32 ]                                           ; //  64
  char         WifiPassword [ 32 ]                                           ; //  96
  char         Username     [ 32 ]                                           ; // 128
  char         Password     [ 32 ]                                           ; // 160
  char         Outputs      [  8 ]                                           ; // 192
  char         Inputs       [  8 ]                                           ; // 200
  char         IP           [  4 ]                                           ; // 208
  char         Gateway      [  4 ]                                           ; // 212
  char         Netmask      [  4 ]                                           ; // 216
  char         Debug                                                         ; // 220
  char         Console                                                       ; // 221
  char         Controllers                                                   ; // 222
  char         WifiMode                                                      ; // 223
  char         doDelay                                                       ; // 224
  char         AssignIP                                                      ; // 225
  char         SwitchMode                                                    ; // 226
  char         Something                                                     ; // 227
  int          BaudRate                                                      ; // 228
  unsigned int MicrosecondsDelay                                             ; // 232
  int          HttpPort                                                      ; // 236
}              OriphaseConfigure                                             ;
//////////////////////////////////////////////////////////////////////////////
void FlashEEPROM       ( void                                              ) {
  ////////////////////////////////////////////////////////////////////////////
  int               v                                                        ;
  OriphaseConfigure conf                                                     ;
  ////////////////////////////////////////////////////////////////////////////
  memset               ( &conf , 0 , sizeof ( OriphaseConfigure )          ) ;
  for                  ( int i = 0 ; i < 8 ; i++                           ) {
    SetPin             ( i      , 0                                        ) ;
    SetPin             ( i + 8  , 1                                        ) ;
    v = ReadValue      ( i                                                 ) ;
    DefaultOutputValues [ i ] = char ( v )                                   ;
    DefaultInputValues  [ i ] = char ( v )                                   ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  memcpy               ( conf . Oriphase     , OriphaseArduino     ,  8    ) ;
  strncpy              ( conf . Site         , ArduinoSite         , 24    ) ;
  strncpy              ( conf . SapPassword  , SapPassword         , 32    ) ;
  strncpy              ( conf . WifiSSID     , WifiSSID            , 32    ) ;
  strncpy              ( conf . WifiPassword , WifiPassword        , 32    ) ;
  strncpy              ( conf . Username     , SiteUsername        , 32    ) ;
  strncpy              ( conf . Password     , SitePassword        , 32    ) ;
  memcpy               ( conf . Outputs      , DefaultOutputValues ,  8    ) ;
  memcpy               ( conf . Inputs       , DefaultInputValues  ,  8    ) ;
  memcpy               ( conf . IP           , HostIP              ,  4    ) ;
  memcpy               ( conf . Gateway      , HostGateway         ,  4    ) ;
  memcpy               ( conf . Netmask      , HostNetmask         ,  4    ) ;
  ////////////////////////////////////////////////////////////////////////////
  conf . Debug             = char ( Debug               )                    ;
  conf . Console           = char ( Console             )                    ;
  conf . Controllers       = char ( MaxPowerControllers )                    ;
  conf . WifiMode          = char ( WifiMode            )                    ;
  conf . SwitchMode        = char ( PowerSwitchMode     )                    ;
  conf . doDelay           = doDelay  ? 1 : 0                                ;
  conf . AssignIP          = AssignIP ? 1 : 0                                ;
  conf . BaudRate          = BaudRate                                        ;
  conf . MicrosecondsDelay = MicrosecondsDelay                               ;
  conf . HttpPort          = WifiHttpPort                                    ;
  ////////////////////////////////////////////////////////////////////////////
  WriteToEEPROM        ( 0 , sizeof ( OriphaseConfigure ) , (char *) &conf ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
void ReloadEEPROM      ( void                                              ) {
  ////////////////////////////////////////////////////////////////////////////
  bool              initialized = true                                       ;
  char              OriphaseInitialized [ 9 ]                                ;
  OriphaseConfigure conf                                                     ;
  ////////////////////////////////////////////////////////////////////////////
  memset               ( &conf , 0 , sizeof ( OriphaseConfigure )          ) ;
  ////////////////////////////////////////////////////////////////////////////
  EEPROM . begin       ( EepromSize                                        ) ;
  for                  ( int i = 0 ; i < 9 ; i++                           ) {
    OriphaseInitialized [ i ] = 0                                            ;
  }                                                                          ;
  ReadFromEEPROM       ( 0 , 8 , OriphaseInitialized                       ) ;
  for                  ( int i = 0 ; i < 8 ; i++                           ) {
    if ( OriphaseInitialized [ i ] != OriphaseArduino [ i ] )                {
      initialized  = false                                                   ;
    }                                                                        ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  if                   ( ( ! initialized ) || RewriteEEPROM                ) {
    FlashEEPROM        (                                                   ) ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  memset               ( &conf , 0 , sizeof ( OriphaseConfigure )          ) ;
  ReadFromEEPROM       ( 0 , sizeof ( OriphaseConfigure ) , (char *) &conf ) ;
  ////////////////////////////////////////////////////////////////////////////
  ArduinoSite  = strdup ( conf . Site                                      ) ;
  SapPassword  = strdup ( conf . SapPassword                               ) ;
  WifiSSID     = strdup ( conf . WifiSSID                                  ) ;
  WifiPassword = strdup ( conf . WifiPassword                              ) ;
  SiteUsername = strdup ( conf . Username                                  ) ;
  SitePassword = strdup ( conf . Password                                  ) ;
  ////////////////////////////////////////////////////////////////////////////
  memcpy               ( DefaultOutputValues , conf . Outputs , 8          ) ;
  memcpy               ( DefaultInputValues  , conf . Inputs  , 8          ) ;
  memcpy               ( HostIP              , conf . IP      , 4          ) ;
  memcpy               ( HostGateway         , conf . Gateway , 4          ) ;
  memcpy               ( HostNetmask         , conf . Netmask , 4          ) ;
  ////////////////////////////////////////////////////////////////////////////
  Debug               = int ( conf . Debug                                 ) ;
  Console             = int ( conf . Console                               ) ;
  MaxPowerControllers = int ( conf . Controllers                           ) ;
  WifiMode            = int ( conf . WifiMode                              ) ;
  PowerSwitchMode     = int ( conf . SwitchMode                            ) ;
  doDelay             =     ( conf . doDelay  > 0                          ) ;
  AssignIP            =     ( conf . AssignIP > 0                          ) ;
  BaudRate            =       conf . BaudRate                                ;
  MicrosecondsDelay   =       conf . MicrosecondsDelay                       ;
  WifiHttpPort        =       conf . HttpPort                                ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
// +| setup |+
//////////////////////////////////////////////////////////////////////////////
void setup                   (                                             ) {
  ////////////////////////////////////////////////////////////////////////////
  ReloadEEPROM               (                                             ) ;
  ////////////////////////////////////////////////////////////////////////////
  if                         ( Console                                     ) {
    Serial . begin           ( BaudRate                                    ) ;
    while                    ( ! Serial                                    ) {
      delay                  ( 1                                           ) ;
    }                                                                        ;
    delay                    ( 1000                                        ) ;
    Serial . println         ( ""                                          ) ;
    Serial . println         ( "Oriphase Arduino Power Controller Bootup"  ) ;
  }                                                                          ;
  ////////////////////////////////////////////////////////////////////////////
  InitializePowerControllers (                                             ) ;
  SetupWIFI                  (                                             ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
// -| setup |-
//////////////////////////////////////////////////////////////////////////////
// +| loop |+
//////////////////////////////////////////////////////////////////////////////
void loop                      (                                           ) {
  ////////////////////////////////////////////////////////////////////////////
  ProbePowerControllers        (                                           ) ;
  DoingWIFI                    (                                           ) ;
  LoopDelay                    (                                           ) ;
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
// -| loop |-
//////////////////////////////////////////////////////////////////////////////
