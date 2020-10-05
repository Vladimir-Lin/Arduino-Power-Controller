//////////////////////////////////////////////////////////////////////////////
// 控制電源類別
//////////////////////////////////////////////////////////////////////////////
#ifndef _MEGA_SLOTS_H__
#define _MEGA_SLOTS_H__

class PowerController
{
  public :

      PowerController ( int output , int input , int mode = 0 ) ;
    ~ PowerController (                                       ) ;
    void setSwitch    ( int mode                              ) ;
    bool GetInput     ( void                                  ) ;
    bool Probe        ( void                                  ) ;
    void Turn         ( bool OnOff                            ) ;
    void Switch       ( void                                  ) ;
    bool Power        ( void                                  ) ;
    bool InputNow     ( void                                  ) ;

  protected :

    int  OutputPin     ;
    int  InputPin      ;
    bool CurrentOutput ;
    bool CurrentInput  ;
    int  SwitchMode    ;

  private :

} ;

#endif
