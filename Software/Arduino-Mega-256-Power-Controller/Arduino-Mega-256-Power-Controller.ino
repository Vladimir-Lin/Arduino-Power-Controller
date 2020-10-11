//////////////////////////////////////////////////////////////////////////////
#include <AitkMegaPINs.h>
#include <AitkMegaSLOTs.h>
#include <AitkMegaEEPROM.h>
#include <AitkMegaESP8266.h>
#include <AitkMegaWebServer.h>
#include <AitkMegaPowerBox.h>
//////////////////////////////////////////////////////////////////////////////
PowerBox  PB                                                                 ;
WebServer HTTP = WebServer ( new ESP8266 ( Serial3 , 9600 ) )                ;
//////////////////////////////////////////////////////////////////////////////
void setup     (                                                           ) {
  ////////////////////////////////////////////////////////////////////////////
  Serial . begin ( 115200 ) ;
  ////////////////////////////////////////////////////////////////////////////

  if ( HTTP . exists ( ) ) {
    Serial . println ( "WiFi Exists" ) ;
  } else {
    Serial . println ( "WiFi Not Exists" ) ;
  }
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
// -| setup |-
//////////////////////////////////////////////////////////////////////////////
// +| loop |+
//////////////////////////////////////////////////////////////////////////////
void loop     (                                                            ) {
  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
// -| loop |-
//////////////////////////////////////////////////////////////////////////////
