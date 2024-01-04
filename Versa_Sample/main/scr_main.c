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
#define GREY_COLOR  RGB565(240, 240, 240)

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
    }; // Tardará por tanto 3 s en reproducirse -> En el timer será 150
      const uint16_t melGaOv[] = 
    {
    220, 500,
    196, 500,
    185, 500,
    175, 500,    
    0,0
    }; // Tardará por tanto 2 s en reproducirse -> En el timer será 100

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

    const uint16_t melInicio[] = 
    {
    1976, 25,
    2093, 25,
    2217, 25, 
    2349, 25,
    2489, 25,
    2637, 25,
    0,0
    };
//Control de juego general
int start_pressed = 0, start_block = 1, start_game = 0, cont_mel_p = 50, gaOv_switch = 0 ,cont_GaOv_u = 0, cont_GaOv_d = 0, ref_dib = 0;

//Provisionales


//Nave
int y_pos = 208;
int x_pos = 120;
//Disparo
int disp_switch = 0;
int disptemp;
int disp_pos_y, disp_pos_x;
int disp_bal_men = 0;
int act_rec = 0, cont_rec = 0, anim_rec = 1;

//Dash
int dash_act = 1;
int cont_dash = 0;
int cont_dash_anim = 1; 

//Fondo estrellado
int vec_est_u[5];
int vec_est_d[5];
int vec_est_t[5];
int vec_est_cu[5];
int vec_est_ci[5];
int act_u = 0, act_d = 0, act_t = 0, act_cu = 0, act_ci = 0;
int cont_est_u = 0, cont_est_d = 0, cont_est_t = 0, cont_est_cu = 0, cont_est_ci = 0;
int y_pos_est_u = 0, y_pos_est_d = 64, y_pos_est_t = 128, y_pos_est_cu = 192, y_pos_est_ci = 256; 
int vel_est = 10;
int get_pos_est = 1;



//Meteorito general // Posiciones del meteorito:[23, 47, 71, 95, 119, 143, 167, 191, 215]  
int vel_met = 8;
int cont_vel = 0;
int met_dest = 0;
//Posiciones
int metpos_x = 119, metpos_y = 0, metpos_x_d = 119, metpos_y_d = 0, metpos_x_t = 119, metpos_y_t = 0, metpos_x_cu = 119, metpos_y_cu = 0, metpos_x_ci = 119, metpos_y_ci = 0;
//Switches
int met_switch = 0, met_switch_d = 0, met_switch_t = 0, met_switch_cu = 0, met_switch_ci = 0;
int iniciomet = 0, iniciomet_d = 0, iniciomet_t = 0, iniciomet_cu = 0, iniciomet_ci = 0;
//Contador de switches
int cont_switch = 0, cont_switch_d = 20, cont_switch_t = 40, cont_switch_cu = 60, cont_switch_ci = 80;
int cont_met = 0, cont_met_d = 0, cont_met_t = 0, cont_met_cu = 0, cont_met_ci = 0; 

//Animacion flechas
int cont_fle = 0, pos_fl = 1;


//Temporizadores
int i = 0, j = 0, k = 1;
int cont = 0, cont_u = 1, cont_d = 1, cont_t = 1, cont_cu = 1, cont_ci = 1 ,cont_se = 1;  

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

  switch (button)
  {
  case EV_FULL_REDRAW:
  case EV_PARTIAL_REDRAW:         
    //Modelo de la nave
    dib_nave(&x_pos,&y_pos);
    break;

  case EV_KEY_UP_PRESS:
    if(start_game == 1){
      mov_arriba(&x_pos, &y_pos);
    }
    break;

  case EV_KEY_DOWN_PRESS:
    if(start_game == 1){
      mov_abajo(&x_pos, &y_pos);
    }   
    break;

  case EV_KEY_LEFT_PRESS:
    if(start_game == 1){
      mov_izq(&x_pos, &y_pos);
    }  
    break;

  case EV_KEY_RIGHT_PRESS:
    if(start_game == 1){
      mov_der(&x_pos,&y_pos);
    }  
    break;

  case EV_KEY_OK_PRESS:
    if(start_game == 1){
      if(disp_switch == 0 && disp_bal_men == 3 && act_rec == 0){
      act_rec = 1;
      }
    } 
    break;

  case EV_KEY_RETURN_PRESS:
    if(start_game == 1){
      if(disp_switch == 0 && disp_bal_men < 3){
        PlayMelody(melDisp);
        disp_bal_men++;
        disp_switch = 1; //Disparo en marcha
        disp_pos_y = y_pos - 20;// Guarda la posición "y" en ese instante de la punta de la nave
        disp_pos_x = x_pos - 1;// Guarda la posición "x" en ese instante de la punta de la nave
      }
    }   
    break;

  case EV_KEY_L_TRIGGER_PRESS: 
  if(start_game == 1){
    if(dash_act == 1){
      PlayMelody(melDash);
      dash_izq(&x_pos, &y_pos);
      dash_act = 0;
      borr_dash();
    }
  } 
    break;

  case EV_KEY_R_TRIGGER_PRESS:
    if(start_game == 1){
      if(dash_act == 1){
        PlayMelody(melDash);
        dash_der(&x_pos, &y_pos);
        dash_act = 0;
        borr_dash();
      }
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
    case EV_INIT: break;
    case EV_FULL_REDRAW:
    case EV_PARTIAL_REDRAW:
      // Clear screen
      LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);

      EmphasizeButton(event);
      break;
    case EV_TIMER_20MS:
      // Herramienta de debugging -> ESP_LOGI("scr_main", "ENTRADA: %d || %d", metpos_y, y_pos);

      //DIBUJA LA INTERFAZ
      if(start_pressed == 1){
      PlayMelody(melInicio);
      // Interfaz
      LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
      // Dibuja Bordes
      dib_bordes();
      //Dibuja Disparos
      dib_balas();
      //Dibuja Dash
      dib_dash();  
      start_pressed = 0;
      start_game = 1;
      ref_dib = 0;
      //Reiniciamos el contador
      rein_conts(&cont, &cont_u, &cont_d, &cont_t, &cont_cu, &cont_ci, &cont_se);
      //Reiniciamos los valores de los meteoritos
      vel_met = 8;
      cont_vel = 0;
      met_dest = 0;
      metpos_x = 119; metpos_y = 0; metpos_x_d = 119; metpos_y_d = 0; metpos_x_t = 119; metpos_y_t = 0; metpos_x_cu = 119; metpos_y_cu = 0; metpos_x_ci = 119; metpos_y_ci = 0;
      met_switch = 0; met_switch_d = 0; met_switch_t = 0; met_switch_cu = 0; met_switch_ci = 0;
      iniciomet = 0; iniciomet_d = 0; iniciomet_t = 0; iniciomet_cu = 0; iniciomet_ci = 0;
      cont_switch = 0; cont_switch_d = 20; cont_switch_t = 40; cont_switch_cu = 60; cont_switch_ci = 80;
      cont_met = 0; cont_met_d = 0; cont_met_t = 0; cont_met_cu = 0; cont_met_ci = 0; 
      }

      // EMPIZA EL JUEGO
      if(start_game == 1){
        contador(&cont, &cont_u, &cont_d, &cont_t, &cont_cu, &cont_ci, &cont_se, &met_dest, &ref_dib);
        //DISPARO
        disparo(&disp_switch, &disptemp, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos, &disp_bal_men);
        //Comprobación del disparo y el meteorito 
        recarga(&act_rec, &cont_rec, &disp_bal_men, &anim_rec);
        // Vemos si el meteorito es alcanzado por la nave o el disparo
        met_comp(&disp_switch, &met_switch, &metpos_x, &metpos_y, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos, &met_dest, &gaOv_switch);
        met_comp(&disp_switch, &met_switch_d, &metpos_x_d, &metpos_y_d, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos, &met_dest, &gaOv_switch);
        met_comp(&disp_switch, &met_switch_t, &metpos_x_t, &metpos_y_t, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos, &met_dest, &gaOv_switch);
        met_comp(&disp_switch, &met_switch_cu, &metpos_x_cu, &metpos_y_cu, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos, &met_dest, &gaOv_switch);
        met_comp(&disp_switch, &met_switch_ci, &metpos_x_ci, &metpos_y_ci, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos, &met_dest, &gaOv_switch);

        //Sale el metorito de forma aleatoria, espera 2s después de desaparecer despues de desaparecer 
        //Cada 30 segundos va más rapido
        control_vel(&cont_vel, &vel_met);

        //GENERAMOS METEORITOS
        met_anim(&cont_met, &metpos_x, &metpos_y, &met_switch, &vel_met, &cont_switch, &iniciomet);
        met_anim(&cont_met_d, &metpos_x_d, &metpos_y_d, &met_switch_d, &vel_met, &cont_switch_d, &iniciomet_d);
        met_anim(&cont_met_t, &metpos_x_t, &metpos_y_t, &met_switch_t, &vel_met, &cont_switch_t, &iniciomet_t);
        met_anim(&cont_met_cu, &metpos_x_cu, &metpos_y_cu, &met_switch_cu, &vel_met, &cont_switch_cu, &iniciomet_cu);
        met_anim(&cont_met_ci, &metpos_x_ci, &metpos_y_ci, &met_switch_ci, &vel_met, &cont_switch_ci, &iniciomet_ci); 

        dib_dash_rec(&dash_act, &cont_dash, &cont_dash_anim);//CONTROLA EL DASH

        //Dibujo del fondo estrellado
        fondo(&cont_est_u ,&act_u, &vel_est, &vec_est_u[0], &vec_est_u[1], &vec_est_u[2], &vec_est_u[3], &vec_est_u[4], &y_pos_est_u);
        fondo(&cont_est_d ,&act_d, &vel_est, &vec_est_d[0], &vec_est_d[1], &vec_est_d[2], &vec_est_d[3], &vec_est_d[4], &y_pos_est_d);
        fondo(&cont_est_t ,&act_t, &vel_est, &vec_est_t[0], &vec_est_t[1], &vec_est_t[2], &vec_est_t[3], &vec_est_t[4], &y_pos_est_t);
        fondo(&cont_est_cu ,&act_cu, &vel_est, &vec_est_cu[0], &vec_est_cu[1], &vec_est_cu[2], &vec_est_cu[3], &vec_est_cu[4], &y_pos_est_cu);
        fondo(&cont_est_ci ,&act_ci, &vel_est, &vec_est_ci[0], &vec_est_ci[1], &vec_est_ci[2], &vec_est_ci[3], &vec_est_ci[4], &y_pos_est_ci);
      }

      // GAME OVER
      if(gaOv_switch == 1){
        start_game = 0;
        if(++cont_GaOv_u == 50){
          LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
          dib_GaOv();
          y_pos = 208;
          x_pos = 120;
          dib_nave(&x_pos, &y_pos);
          PlayMelody(melGaOv);
        }
        if(++cont_GaOv_d >= 150){
          LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
          // Reinicio de variables
          cont_GaOv_u = 0;  
          cont_GaOv_d = 0;
          start_pressed = 0;
          start_block = 1; 
          cont_mel_p = 50; 
          gaOv_switch = 0;
          //Reinicio de otras variables importantes
          disp_switch = 0;
          disp_bal_men = 0;
          dash_act = 1;
          cont_dash_anim = 1;
          vel_met = 8;
        }
      }

      // PANTALLA INICIAL
      if (start_game == 0 && start_pressed == 0 && start_block == 1){
        if(++cont_mel_p >= 150){
          cont_mel_p = 0;
          PlayMelody(melPrinc);
        }
        dib_pant_princ();
        anim_flechas(&cont_fle, &pos_fl);
        dib_puntos(&cont, &cont_u, &cont_d, &cont_t, &cont_cu, &cont_ci, &cont_se, &ref_dib);
        ESP_LOGI("scr_main", "contador 3: %d", cont_t);
      }
      
      dib_nave(&x_pos,&y_pos);//REDIBUJAMOS POR SI ACASO
      
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
    if(start_block == 1){
      start_pressed = 1;
      start_block = 0;
    }
      
      break;
    case EV_KEY_SELECT_PRESS:
      // Apagar
      apagar();
      break;
    default: UIIdle();
    }
  }
}

