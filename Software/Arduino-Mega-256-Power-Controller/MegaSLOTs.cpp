//////////////////////////////////////////////////////////////////////////////
// 控制電源類別
//////////////////////////////////////////////////////////////////////////////
#include "MegaPINs.h"
#include "MegaSLOTs.h"
//////////////////////////////////////////////////////////////////////////////
PowerController:: PowerController ( int output , int input , int mode = 0 )
{
  OutputPin     = output ;
  InputPin      = input  ;
  CurrentOutput = false  ;
  CurrentInput  = false  ;
  SwitchMode    = mode   ;
  SetPin ( input  , 0 )  ;
  SetPin ( output , 1 )  ;
}

PowerController::~PowerController ( )
{
}

// 0 - Switch Mode
// 1 - Sync Mode
// 2 - Isolate Mode
void PowerController::setSwitch  ( int mode )
{
  SwitchMode = mode ;
}

bool PowerController::GetInput (void)
{
  int  v  = ReadValue ( InputPin ) ;
  CurrentInput = ( v > 0 ) ;
  return CurrentInput ;
}

bool PowerController::Probe (void)
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

void PowerController::Turn ( bool OnOff )
{
  if ( CurrentOutput == OnOff ) {
    return ;
  }
  CurrentOutput = OnOff ;
  WriteValue ( OutputPin , OnOff ? 1 : 0 ) ;
}

void PowerController::Switch ( void )
{
  Turn ( CurrentOutput ? false : true ) ;
}

bool PowerController::Power ( void )
{
  return CurrentOutput ;
}

bool PowerController::InputNow ( void )
{
  return CurrentInput ;
}
