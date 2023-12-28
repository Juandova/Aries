//******************************************************************************
// File: scr_main.c
// Description: Main menu
// Author: Juan Ramon Vadillo (Versa Design S.L.)
// Licencia: Creative Commons No Comercial (CC BY-NC)
//
// Este archivo está sujeto a la Licencia Creative Commons No Comercial (CC BY-NC).
// Esto significa que puedes compartir, copiar, modificar y distribuir este archivo
// siempre y cuando sea para uso personal y no comercial, y siempre que se proporcione
// atribución al autor original. No se permite el uso comercial de este archivo ni la
// creación de obras derivadas sin el consentimiento expreso del autor.
//
// Para más detalles sobre la Licencia Creative Commons No Comercial (CC BY-NC), puedes
// consultar: [https://creativecommons.org/licenses/by-nc/4.0/]
//******************************************************************************

//******************************************************************************
// INCLUDES

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "global.h"
#include "hwplatform.h"
#include "tftdriver.h"
#include "scr_main.h"
#include "hwplatform.h"
#include <stdio.h>
#include "task_ui.h"
#include "misfunciones.h"

//******************************************************************************
// DEFINES & TYPEDEFS

#define RED_COLOR  RGB565(255, 0, 0)
#define GREEN_COLOR RGB565(0, 188, 0)
#define YELLOW_COLOR RGB565(255, 255, 0)
#define BLUE_COLOR RGB565(0, 0, 255)
#define WHITE_COLOR RGB565(255, 255, 255)
#define BROWN_COLOR RGB565(128, 0, 0)

//Sonidos
   const uint16_t melDisp[] = 
    {
    2400, 20,
    2000, 20,
    1800, 20,
    2200, 20,
    1600, 20,
    0,0
    };
       const uint16_t melPrinc[] = 
    {
    440, 250,
    494, 250,
    523, 250,
    1,250,
    440, 250,
    494, 250,
    523, 250,
    587, 250,
    523, 250,
    494, 250,
    440, 250,
    392, 250,    
    0,0
    };
    const uint16_t melDash[] = 
    {
    1397, 30,
    1568, 30,
    1760, 30,
    1,50,
    1397, 30,
    1568, 30,
    1760, 30,   
    0,0
    };

//Nave
int y_line = 24;
int x_line = 32;
int y_pos = 208;
int x_pos = 120;
int scale = 3;
//Disparo
int disp_switch = 0;
int disptemp;
int disp_pos_y, disp_pos_x;
int disp_bal_men = 0;
int act_rec = 0, cont_rec = 0, anim_rec = 1;

//Interfaz (posiciones en x)
int i_pos_y = 300;
int scale_i = 4;

//Posición balas
int b_u_pos = 4;
int b_d_pos = 9;
int b_t_pos = 14;

//Dash
int dash_pos = 23;
int dash_act = 1;
int cont_dash = 0;
int cont_dash_anim = 1; 

//PROVISIONALES  


//Meteorito // Posiciones del meteorito:[23, 47, 71, 95, 119, 143, 167, 191, 215]  
int metpos_x = 119, metpos_y = 0, scale_met = 2, var_comp = 0;
int met_switch = 0;
int iniciomet = 0;
int metpos_x_pos[9] = {23, 47, 71, 95, 119, 143, 167, 191, 215};
int cont_switch_f;

//Temporizadores
int i = 0, j = 0, k = 1;
int cont = 0, cont_u = 1, cont_d = 1, cont_t = 1, cont_cu = 1, cont_ci = 1 ,cont_se = 1, cont_met = 0;  

//******************************************************************************
// FUNCTIONS

//******************************************************************************
static void EmphasizeButton(tUIEvent button)
//******************************************************************************
// Description: Emphasize a button setting it to green
// Parameters: button - button to emphasize
// Returns: none
//******************************************************************************
{
// Grid
/*
   while(y_line < 240){
    LCD_DrawRectangle(y_line, 0, 1, 320, GREEN_COLOR);
    y_line=y_line + 24;
  }
    while(x_line < 320){
    LCD_DrawRectangle(0, x_line, 240, 1, GREEN_COLOR);
    x_line = x_line + 32;
  }
  */
  
  switch (button)
  {
  case EV_FULL_REDRAW:
  case EV_PARTIAL_REDRAW: 
    
    // Interfaz
    
    // Bordes
    dib_bordes();

    //Disparos
    dib_balas();

    //Dash
    dib_dash();       

    //Modelo de la nave
    dib_nave(&x_pos,&y_pos);
    
    LCD_DrawRectangle(metpos_x, y_pos - 10, 1, 20, WHITE_COLOR);
    LCD_DrawRectangle(x_pos-1, y_pos - 10, 1, 17, GREEN_COLOR);

    break;

  case EV_KEY_UP_PRESS:
    mov_arriba(&x_pos, &y_pos);
    break;

  case EV_KEY_DOWN_PRESS:
    mov_abajo(&x_pos, &y_pos);
    break;

  case EV_KEY_LEFT_PRESS:
    mov_izq(&x_pos, &y_pos);
    break;

  case EV_KEY_RIGHT_PRESS:
    mov_der(&x_pos,&y_pos);
    break;

  case EV_KEY_OK_PRESS:
    if(disp_switch == 0 && disp_bal_men == 3 && act_rec == 0){
    act_rec = 1;
    }
    break;

  case EV_KEY_RETURN_PRESS:  
    if(disp_switch == 0 && disp_bal_men < 3){
    PlayMelody(melDisp);
    disp_bal_men++;
    disp_switch = 1;
    disp_pos_y = y_pos - 20;
    disp_pos_x = x_pos - 1;
  }
    break;

  case EV_KEY_L_TRIGGER_PRESS: 
  //Diseñar dash izquierdo
  if(dash_act == 1){
    PlayMelody(melDash);
    dash_izq(&x_pos, &y_pos);
    dash_act = 0;
    borr_dash();
  }
    break;
  case EV_KEY_R_TRIGGER_PRESS:
  //Diseñar dash derecho
  if(dash_act == 1){
    PlayMelody(melDash);
    dash_der(&x_pos, &y_pos);
    dash_act = 0;
    borr_dash();
  }
    break;
  default:
    break;
  }
}

//******************************************************************************
void MainMenuScreenHandler(void)
//******************************************************************************
// Description: Main screen handler
//******************************************************************************
{
  tUIEvent event;

  UIForceFullRedraw(); // When we enter this menu, we have to force full redraw

  for (;;)
  {
    event = GetUserInterfaceEvent();
    switch (event)
    {
    case EV_INIT: break;// Initialization event
    case EV_FULL_REDRAW:
    case EV_PARTIAL_REDRAW:
      // Clear screen
      LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);

      EmphasizeButton(event);
      break;
    case EV_TIMER_20MS:
      contador(&cont, &cont_u, &cont_d, &cont_t, &cont_cu, &cont_ci, &cont_se);
      //DISPARO
      disparo(&disp_switch, &disptemp, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos, &disp_bal_men);
      //Comprobación del disparo y el meteorito 
      recarga(&act_rec, &cont_rec, &disp_bal_men, &anim_rec);

      met_comp(&disp_switch, &met_switch, &metpos_x, &metpos_y, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos);
      //ESP_LOGI("scr_main", "ENTRADA: %d || %d", metpos_y, y_pos);

      //Sale el metorito de forma aleatoria
      if (++cont_switch_f >= 100 && met_switch == 0){
        cont_switch_f = 0;
        iniciomet = 1;
      }
      if (iniciomet == 1){
        iniciomet = 0;
        met_switch = 1;
        i = rand()%10;
        metpos_x = metpos_x_pos[i];
      }
      met_anim(&cont_met, &metpos_x, &metpos_y, &met_switch);
      
      dib_dash_rec(&dash_act, &cont_dash, &cont_dash_anim);//CONTROLA EL DASH

      dib_nave(&x_pos,&y_pos);//REDIBUJAMOS POR SI ACASO
      //ESP_LOGI("scr_main", "SALIDA:  %d || %d", metpos_y, y_pos);
      break;

    case EV_KEY_UP_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_DOWN_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_LEFT_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_RIGHT_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_OK_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_RETURN_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_L_TRIGGER_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_R_TRIGGER_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_START_PRESS:
      // Apagar
      LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
      DisablePower();
      SysSleep(500);
      break;
    case EV_KEY_SELECT_PRESS:
      // Apagar
      LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
      DisablePower();
      SysSleep(500);
      break;
    default: UIIdle();
    }
  }
}

