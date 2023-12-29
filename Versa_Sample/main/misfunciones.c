#define RED_COLOR  RGB565(255, 0, 0)
#define GREEN_COLOR RGB565(0, 188, 0)
#define YELLOW_COLOR RGB565(255, 255, 0)
#define BLUE_COLOR RGB565(0, 0, 255)
#define WHITE_COLOR RGB565(255, 255, 255)
#define BROWN_COLOR RGB565(128, 0, 0)
#define ORANGE_COLOR RGB565(255,165,0)
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

//******************************************************************************
// FUNCTIONS
   const uint16_t melDest[] = 
    {
    127, 20,
    107, 20,
    90, 20,
    80, 20,
    97, 20,
    127, 20,
    90, 20,
    60, 20,
    0,0
    };
//******************************************************************************
//NAVE

void dib_nave(int *n, int *m){
  int x_pos_f = *n, y_pos_f = *m;
  LCD_DrawRectangle(x_pos_f-(1*3)-1, y_pos_f-(5*3), 3*3, 2*3, RED_COLOR); // Rectangulo superior
  LCD_DrawRectangle(x_pos_f-(2*3)-1, y_pos_f-(3*3), 5*3, 5*3, RED_COLOR); // Tronco de la nave
  LCD_DrawRectangle(x_pos_f-(0*3)-1, y_pos_f-(7*3), 1*3, 12*3, RED_COLOR); // Línea de central
  LCD_DrawRectangle(x_pos_f-(0*3)-1, y_pos_f-(4*3), 1*3, 3*3, BLUE_COLOR); // Ventana de Arriba
  LCD_DrawRectangle(x_pos_f-(5*3)-1, y_pos_f+(2*3), 11*3, 2*3, RED_COLOR); // Rectangulo inferior
  LCD_DrawRectangle(x_pos_f-(6*3)-1, y_pos_f+(3*3), 2*3, 2*3, RED_COLOR); // Cuadrado de las patas izquierdo
  LCD_DrawRectangle(x_pos_f+(5*3)-1, y_pos_f+(3*3), 2*3, 2*3, RED_COLOR); // Cuadrado de las patas derecho
  LCD_DrawRectangle(x_pos_f-(7*3)-1, y_pos_f+(4*3), 2*3, 2*3, RED_COLOR); // Cuadrado de las patas izquierdo 2
  LCD_DrawRectangle(x_pos_f+(6*3)-1, y_pos_f+(4*3), 2*3, 2*3, RED_COLOR); // Cuadrado de las patas derecho 2
  LCD_DrawRectangle(x_pos_f-(4*3)-1, y_pos_f+(1*3), 1*3, 1*3, RED_COLOR); // Cañón izquierdo
  LCD_DrawRectangle(x_pos_f+(4*3)-1, y_pos_f+(1*3), 1*3, 1*3, RED_COLOR); // Cañón derecho
  LCD_DrawRectangle(x_pos_f-(2*3)-1, y_pos_f+(4*3), 5*3, 1*3, RED_COLOR); // Rectangulo del culo 1
  LCD_DrawRectangle(x_pos_f-(1*3)-1, y_pos_f+(5*3), 3*3, 1*3, RED_COLOR); // Rectangulo del culo 2
  //LCD_DrawRectangle(x_pos_f-(7*3)-1, y_pos_f+(4*3), 44, 3, WHITE_COLOR); //Prueba hitbox horizontal
  //LCD_DrawRectangle(x_pos_f-(0*3)-1, y_pos_f-(7*3), 1*3, 12*3, WHITE_COLOR); //Prueba hitbox vertical
  *n = x_pos_f;
  *m = y_pos_f;

}

void borr_nave(int *n, int *m){
  int x_pos_f = *n, y_pos_f = *m;
  LCD_DrawRectangle(x_pos_f-(1*3)-1, y_pos_f-(5*3), 3*3, 2*3, 0); // Rectangulo superior
  LCD_DrawRectangle(x_pos_f-(2*3)-1, y_pos_f-(3*3), 5*3, 5*3, 0); // Tronco de la nave
  LCD_DrawRectangle(x_pos_f-(0*3)-1, y_pos_f-(7*3), 1*3, 12*3, 0); // Línea de central
  LCD_DrawRectangle(x_pos_f-(0*3)-1, y_pos_f-(4*3), 1*3, 3*3, 0); // Ventana de Arriba
  LCD_DrawRectangle(x_pos_f-(5*3)-1, y_pos_f+(2*3), 11*3, 2*3, 0); // Rectangulo inferior
  LCD_DrawRectangle(x_pos_f-(6*3)-1, y_pos_f+(3*3), 2*3, 2*3, 0); // Cuadrado de las patas izquierdo
  LCD_DrawRectangle(x_pos_f+(5*3)-1, y_pos_f+(3*3), 2*3, 2*3, 0); // Cuadrado de las patas derecho
  LCD_DrawRectangle(x_pos_f-(7*3)-1, y_pos_f+(4*3), 2*3, 2*3, 0); // Cuadrado de las patas izquierdo 2
  LCD_DrawRectangle(x_pos_f+(6*3)-1, y_pos_f+(4*3), 2*3, 2*3, 0); // Cuadrado de las patas derecho 2
  LCD_DrawRectangle(x_pos_f-(4*3)-1, y_pos_f+(1*3), 1*3, 1*3, 0); // Cañón izquierdo
  LCD_DrawRectangle(x_pos_f+(4*3)-1, y_pos_f+(1*3), 1*3, 1*3, 0); // Cañón derecho
  LCD_DrawRectangle(x_pos_f-(2*3)-1, y_pos_f+(4*3), 5*3, 1*3, 0); // Rectangulo del culo 1
  LCD_DrawRectangle(x_pos_f-(1*3)-1, y_pos_f+(5*3), 3*3, 1*3, 0); // Rectangulo del culo 2
  
  *n = x_pos_f;
  *m = y_pos_f;

}

void mov_arriba(int *n, int *m){
  int x_pos_f = *n, y_pos_f = *m;
    if(y_pos_f >= 64 ){
      //Dibujo de la nave
      borr_nave(&x_pos_f,&y_pos_f);
      y_pos_f = y_pos_f - 32;
      dib_nave(&x_pos_f,&y_pos_f);
    }

  *n = x_pos_f;
  *m = y_pos_f;
}

void mov_abajo(int *n, int *m){
  int x_pos_f = *n, y_pos_f = *m;
  if(y_pos_f <= 224 ){
    borr_nave(&x_pos_f,&y_pos_f);
    y_pos_f = y_pos_f + 32;
    dib_nave(&x_pos_f,&y_pos_f);
  }
  *n = x_pos_f;
  *m = y_pos_f;
}

void mov_izq(int *n, int *m){
  int x_pos_f = *n, y_pos_f = *m;
  if(x_pos_f >= 48 ){
  
    //Dibujo de la nave
    borr_nave(&x_pos_f,&y_pos_f);
    x_pos_f = x_pos_f - 24;
    dib_nave(&x_pos_f,&y_pos_f);
  }
  *n = x_pos_f;
  *m = y_pos_f;  
}

void mov_der(int *n, int *m){
  int x_pos_f = *n, y_pos_f = *m;
  if(x_pos_f <= 192 ){
    //Dibujo de la nave
    borr_nave(&x_pos_f,&y_pos_f);
    x_pos_f = x_pos_f + 24;
    dib_nave(&x_pos_f,&y_pos_f);

  }
  *n = x_pos_f;
  *m = y_pos_f;  
}

void dash_izq(int *n, int *m){
  int x_pos_f = *n, y_pos_f = *m;
  if(x_pos_f >= 72 ){
    //Dibujo de la nave
    borr_nave(&x_pos_f,&y_pos_f);
    x_pos_f = x_pos_f - 48;
    dib_nave(&x_pos_f,&y_pos_f);
  }

  if(x_pos_f == 48){
    //Dibujo de la nave
    borr_nave(&x_pos_f,&y_pos_f);
    x_pos_f = x_pos_f - 24;
    dib_nave(&x_pos_f,&y_pos_f);
  }
  *n = x_pos_f;
  *m = y_pos_f;  
}

void dash_der(int *n, int *m){
  int x_pos_f = *n, y_pos_f = *m;
  if(x_pos_f <= 168 ){
    borr_nave(&x_pos_f,&y_pos_f);
    x_pos_f = x_pos_f + 48;
    dib_nave(&x_pos_f,&y_pos_f);
  }

  if(x_pos_f == 192){  
    borr_nave(&x_pos_f,&y_pos_f);
    x_pos_f = x_pos_f + 24;
    dib_nave(&x_pos_f,&y_pos_f);
  }
  *n = x_pos_f;
  *m = y_pos_f;  
}


//******************************************************************************
//METEORITO
void dib_met(int *n, int *m){
  int metpos_x = *n;
  int metpos_y = *m;
  LCD_DrawRectangle(metpos_x-(8*2), metpos_y-(3*2), 16*2, 6*2, BROWN_COLOR);//<-rectangulo del medio 
  LCD_DrawRectangle(metpos_x-(7*2), metpos_y-(5*2), (16-2)*2, 2*2, BROWN_COLOR);//<-rectangulo superior 2
  LCD_DrawRectangle(metpos_x-(7*2), metpos_y+(3*2), (16-2)*2, 2*2, BROWN_COLOR);//<-rectangulo inferior 2
  LCD_DrawRectangle(metpos_x-(6*2), metpos_y-(6*2), (16-4)*2, 1*2, BROWN_COLOR);//<-rectangulo superior 3
  LCD_DrawRectangle(metpos_x-(6*2), metpos_y+(5*2), (16-4)*2, 1*2, BROWN_COLOR);//<-rectangulo inferior 3
  LCD_DrawRectangle(metpos_x-(5*2), metpos_y-(7*2), (16-6)*2, 1*2, BROWN_COLOR);//<-rectangulo superior 4
  LCD_DrawRectangle(metpos_x-(5*2), metpos_y+(6*2), (16-6)*2, 1*2, BROWN_COLOR);//<-rectangulo inferior 4
  LCD_DrawRectangle(metpos_x-(3*2), metpos_y-(8*2), (16-10)*2, 1*2, BROWN_COLOR);//<-rectangulo superior 5
  LCD_DrawRectangle(metpos_x-(3*2), metpos_y+(7*2), (16-10)*2, 1*2, BROWN_COLOR);//<-rectangulo inferior 5
  *n = metpos_x;
  *m = metpos_y; 
}
void borr_met(int *n, int *m){
  int metpos_x = *n;
  int metpos_y = *m;
  LCD_DrawRectangle(metpos_x-(8*2), metpos_y-(3*2), 16*2, 6*2, 0);//<-rectangulo del medio 
  LCD_DrawRectangle(metpos_x-(7*2), metpos_y-(5*2), (16-2)*2, 2*2, 0);//<-rectangulo superior 2
  LCD_DrawRectangle(metpos_x-(7*2), metpos_y+(3*2), (16-2)*2, 2*2, 0);//<-rectangulo inferior 2
  LCD_DrawRectangle(metpos_x-(6*2), metpos_y-(6*2), (16-4)*2, 1*2, 0);//<-rectangulo superior 3
  LCD_DrawRectangle(metpos_x-(6*2), metpos_y+(5*2), (16-4)*2, 1*2, 0);//<-rectangulo inferior 3
  LCD_DrawRectangle(metpos_x-(5*2), metpos_y-(7*2), (16-6)*2, 1*2, 0);//<-rectangulo superior 4
  LCD_DrawRectangle(metpos_x-(5*2), metpos_y+(6*2), (16-6)*2, 1*2, 0);//<-rectangulo inferior 4
  LCD_DrawRectangle(metpos_x-(3*2), metpos_y-(8*2), (16-10)*2, 1*2, 0);//<-rectangulo superior 5
  LCD_DrawRectangle(metpos_x-(3*2), metpos_y+(7*2), (16-10)*2, 1*2, 0);//<-rectangulo inferior 5
  *n = metpos_x;
  *m = metpos_y; 
}

void met_anim(int *a, int *b, int *c, int *d){
  int cont_met_f = *a;
  int metpos_x_f = *b;
  int metpos_y_f = *c;
  int met_switch_f = *d;
  
  if(met_switch_f == 1){
    if(++cont_met_f >= 2){
      cont_met_f = 0;
      borr_met(&metpos_x_f, &metpos_y_f);
      //Velocidad máxima 26 // Mínima 10
      metpos_y_f = metpos_y_f + 8;
      dib_met(&metpos_x_f, &metpos_y_f);
    }
  }
  if(metpos_y_f > 258){
    met_switch_f = 0;
    borr_met(&metpos_x_f, &metpos_y_f);
  }
  if(met_switch_f == 0){
    metpos_y_f = 0;
  }      
  *a = cont_met_f;
  *b = metpos_x_f;
  *c = metpos_y_f;
  *d = met_switch_f; 
}

void met_comp(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *k){

  int disp_switch_f = *a;
  int met_switch_f = *b;
  int metpos_x_f = *c;
  int metpos_y_f = *d;
  int disp_pos_x_f = *e;
  int disp_pos_y_f = *f;
  int x_pos_f = *g;
  int y_pos_f = *h;
  int var_comp_f, i, j;
  int met_dest_f = *k;
  int vec_met_y_f[20], vec_disp_f[6], vec_nav_y_f[16];
  //Sonido

  //COMPARACIÓN DE DISPARO
  
  if(disp_switch_f==1 && met_switch_f==1){ 
  for(i = 0;i <= 19;i++){
    var_comp_f = metpos_y_f - 10;
    vec_met_y_f[i] = var_comp_f + i;	
  }
  for(j = 0;j<=5;j++){
    vec_disp_f[j] = disp_pos_y_f + j;
  }
  for(i = 0;i <= 19;i++){
    for(j = 0;j <= 5;j++){
      if(vec_met_y_f[i] == vec_disp_f[j] && metpos_x_f == disp_pos_x_f){
        //Eliminar asteroide
        borr_met(&metpos_x_f, &metpos_y_f);
        //Frenar disparo
        LCD_DrawRectangle(disp_pos_x_f, disp_pos_y_f, 1*3, 2*3, 0);
        //Añadir puntos
        met_dest_f = 1;
        disp_switch_f = 0;
        met_switch_f = 0;
        PlayMelody(melDest);       
        //PARA EVITAR EL BORRADO DE LA NAVE
        dib_nave(&x_pos_f,&y_pos_f);
        }
      }
    }
  }

  //COMPARACION CON LA NAVE

 
  if(met_switch_f == 1){
    if(metpos_x_f == (x_pos_f - 1)){
      for(i = 0;i <= 19;i++){
        var_comp_f = metpos_y_f - 10;
        vec_met_y_f[i] = var_comp_f + i;	
      }
      for(j = 0;j <=15 ;j++){
        var_comp_f = y_pos_f - 8;
        vec_nav_y_f[j] = var_comp_f + j;
        
      }
      for(i = 0;i <= 19;i++){
        for(j = 0;j <= 15;j++){
          if(vec_met_y_f[i] == vec_nav_y_f[j]){
            LCD_DrawRectangle(metpos_x_f,metpos_y_f,1,10,WHITE_COLOR);
            LCD_DrawRectangle(x_pos_f - 1,y_pos_f,1,10,WHITE_COLOR);
            met_switch_f = 0;
            borr_met(&metpos_x_f,&metpos_y_f);
            dib_nave(&x_pos_f,&y_pos_f);
          }
        }	
      }
    }
  }  
  
  
 *a = disp_switch_f;
 *b = met_switch_f;
 *c = metpos_x_f;
 *d = metpos_y_f;
 *e = disp_pos_x_f;
 *f = disp_pos_y_f;
 *g = x_pos_f;
 *h = y_pos_f;
 *k = met_dest_f;
}

//******************************************************************************
//INTERFAZ

//FONDO
void fondo(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *j){//genera las estrellas en el fondo
  int cont_est_f = *a;
  int act_u_f = *b;
  int vel_est_f = *c;
  int vec_est_f[5];
  vec_est_f[0] = *d;
  vec_est_f[1] = *e;
  vec_est_f[2] = *f;
  vec_est_f[3] = *g;
  vec_est_f[4] = *h;
  int i = 0, var_comp = 0;
  int y_pos_est_f = *j;

  if(++cont_est_f >= 10){
    cont_est_f = 0;
    if (act_u_f == 0){
      for(i=0;i<4;i++){
        vec_est_f[i] = esp_random()%201 + 20;
        LCD_DrawRectangle(vec_est_f[i], y_pos_est_f, 2, 2, WHITE_COLOR);
      }
      act_u_f = 1;
    }

    if (act_u_f == 1){
      var_comp = y_pos_est_f + vel_est_f;
      for(i=0;i<4;i++){
        LCD_DrawRectangle(vec_est_f[i], y_pos_est_f, 2, 2, 0);
        LCD_DrawRectangle(vec_est_f[i], var_comp, 2, 2, WHITE_COLOR);
      }
      y_pos_est_f = var_comp;
    }

    if(y_pos_est_f > 268){
      for(i=0;i<4;i++){
        LCD_DrawRectangle(vec_est_f[i], y_pos_est_f, 2, 2, 0);
      }
      y_pos_est_f = 0;
      act_u_f = 0;
    }
  }
  *a = cont_est_f;
  *b = act_u_f;
  *c = vel_est_f;
  *d = vec_est_f[0];
  *e = vec_est_f[1];
  *f = vec_est_f[2];
  *g = vec_est_f[3];
  *h = vec_est_f[4];
  *j = y_pos_est_f;
}

//BORDES
void dib_bordes(){
  LCD_DrawRectangle(0, 283, 240, 37, 0);//Borrado de lo anterior(cuadrado negro)
  LCD_DrawRectangle(0, 283, 240, 4, GREEN_COLOR);//Línea horizontal 1
  LCD_DrawRectangle(0, 283, 4, 37, GREEN_COLOR);//Borde izquierdo
  LCD_DrawRectangle(236, 284, 4, 37, GREEN_COLOR);//Borde derecho
  LCD_DrawRectangle(0, 316, 240, 4, GREEN_COLOR);//Borde bajo
  LCD_DrawRectangle(68, 283, 4, 37, GREEN_COLOR);//Pared 1
  LCD_DrawRectangle(116, 283, 4, 37, GREEN_COLOR);//Pared 2

}

//BALAS
void dib_bal_un(){
  LCD_DrawRectangle((4)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Centro
  LCD_DrawRectangle((4 - 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado izquierdo
  LCD_DrawRectangle((4 + 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado derecho
}
void dib_bal_do(){
  LCD_DrawRectangle((9)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Centro
  LCD_DrawRectangle((9 - 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado izquierdo
  LCD_DrawRectangle((9 + 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado derecho
}
void dib_bal_tr(){
  LCD_DrawRectangle((14)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Centro
  LCD_DrawRectangle((14 - 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado izquierdo
  LCD_DrawRectangle((14 + 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado derecho
}

void dib_balas(){//Dibuja las tres balas a la vez
  dib_bal_un();
  dib_bal_do();
  dib_bal_tr();
}

//Borrar balas
void borr_bal_un(){
  LCD_DrawRectangle((4)*4, 300 - (2*4), 1*4, 5*4, 0);// Centro
  LCD_DrawRectangle((4 - 1)*4, 300 - (1*4), 1*4, 3*4, 0);// Lado izquierdo
  LCD_DrawRectangle((4 + 1)*4, 300 - (1*4), 1*4, 3*4, 0);// Lado derecho
}
void borr_bal_do(){
  LCD_DrawRectangle((9)*4, 300 - (2*4), 1*4, 5*4, 0);// Centro
  LCD_DrawRectangle((9 - 1)*4, 300 - (1*4), 1*4, 3*4, 0);// Lado izquierdo
  LCD_DrawRectangle((9 + 1)*4, 300 - (1*4), 1*4, 3*4, 0);// Lado derecho
}
void borr_bal_tr(){
  LCD_DrawRectangle((14)*4, 300 - (2*4), 1*4, 5*4, 0);// Centro
  LCD_DrawRectangle((14 - 1)*4, 300 - (1*4), 1*4, 3*4, 0);// Lado izquierdo
  LCD_DrawRectangle((14 + 1)*4, 300 - (1*4), 1*4, 3*4, 0);// Lado derecho
}

//Recarga de balas
void rec_bal_un(){
  LCD_DrawRectangle((4)*4, 300 - (2*4), 1*4, 5*4, ORANGE_COLOR);// Centro
  LCD_DrawRectangle((4 - 1)*4, 300 - (1*4), 1*4, 3*4, ORANGE_COLOR);// Lado izquierdo
  LCD_DrawRectangle((4 + 1)*4, 300 - (1*4), 1*4, 3*4, ORANGE_COLOR);// Lado derecho
}
void rec_bal_do(){
  LCD_DrawRectangle((9)*4, 300 - (2*4), 1*4, 5*4, ORANGE_COLOR);// Centro
  LCD_DrawRectangle((9 - 1)*4, 300 - (1*4), 1*4, 3*4, ORANGE_COLOR);// Lado izquierdo
  LCD_DrawRectangle((9 + 1)*4, 300 - (1*4), 1*4, 3*4, ORANGE_COLOR);// Lado derecho
}
void rec_bal_tr(){
  LCD_DrawRectangle((14)*4, 300 - (2*4), 1*4, 5*4, ORANGE_COLOR);// Centro
  LCD_DrawRectangle((14 - 1)*4, 300 - (1*4), 1*4, 3*4, ORANGE_COLOR);// Lado izquierdo
  LCD_DrawRectangle((14 + 1)*4, 300 - (1*4), 1*4, 3*4, ORANGE_COLOR);// Lado derecho
}

// Manejo de balas

void disparo(int *a, int *b, int *c, int *d, int *e, int *f, int *g){
  int disp_switch_f = *a;
  int disptemp_f = *b;
  int disp_pos_x_f = *c;
  int disp_pos_y_f = *d;
  int x_pos_f = *e;
  int y_pos_f = *f;
  int disp_bal_men_f = *g;
  
  if(disp_switch_f==1){//Borrar disparo anterior
    switch(disp_bal_men_f){
    case 1: 
    borr_bal_un();
    break;
    case 2: 
    borr_bal_do();
    break;
    case 3:
    borr_bal_tr();
    break;
  }
    if(++disptemp_f >= 2 && disp_bal_men_f < 4){//Dibujar y mover disparo
      disptemp_f = 0;
      LCD_DrawRectangle(disp_pos_x_f, disp_pos_y_f, 3, 6, 0);
      disp_pos_y_f = disp_pos_y_f - 8;
      LCD_DrawRectangle(disp_pos_x_f, disp_pos_y_f, 3, 6, YELLOW_COLOR);
      //Dibujamos otra nave por si se solapa
      dib_nave(&x_pos_f, &y_pos_f);
      if(disp_pos_y_f < 0){
        LCD_DrawRectangle(disp_pos_x_f, disp_pos_y_f, 3, 6, 0);
        disp_switch_f = 0;
      } 
    }   
  }
  if(disp_switch_f == 0){ //Devuelve la posición 0,0 para evitar errores
    disp_pos_x_f = 0;
    disp_pos_y_f = 0;
  }

  *a = disp_switch_f;
  *b = disptemp_f;
  *c = disp_pos_x_f;
  *d = disp_pos_y_f;
  *e = x_pos_f;
  *f = y_pos_f;
  *g = disp_bal_men_f;
}

void recarga(int *a, int *b, int *c, int *d){
  int act_rec_f = *a;
  int cont_rec_f = *b;
  int disp_bal_men_f = *c;
  int anim_rec_f = *d;
  if(++cont_rec_f >= 50 && act_rec_f == 1){
    cont_rec_f = 0;
    switch(anim_rec_f){
    case 1: 
    rec_bal_un();
    anim_rec_f++;
    break;
    case 2: 
    rec_bal_do();
    anim_rec_f++;
    break;
    case 3:
    rec_bal_tr();
    anim_rec_f++;
    break;
    case 4:
    dib_balas();
    act_rec_f = 0;
    disp_bal_men_f = 0;
    anim_rec_f = 1;
    break;  
    }
  }
  *a = act_rec_f;
  *b = cont_rec_f;
  *c = disp_bal_men_f;
  *d = anim_rec_f;
}
//DASH

void  dib_dash(){
  LCD_DrawRectangle((23 - 4)*4, 300, 9*4, 1*4, GREEN_COLOR);// Línea centro
  LCD_DrawRectangle((23 - 2)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Ld1
  LCD_DrawRectangle((23 - 3)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Ld2
  LCD_DrawRectangle((23 + 2)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Li1
  LCD_DrawRectangle((23 + 3)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Li2
}

void  borr_dash(){
  LCD_DrawRectangle((23 - 4)*4, 300, 9*4, 1*4, 0);// Línea centro
  LCD_DrawRectangle((23 - 2)*4, 300 - (2*4), 1*4, 5*4, 0);// Ld1
  LCD_DrawRectangle((23 - 3)*4, 300 - (1*4), 1*4, 3*4, 0);// Ld2
  LCD_DrawRectangle((23 + 2)*4, 300 - (2*4), 1*4, 5*4, 0);// Li1
  LCD_DrawRectangle((23 + 3)*4, 300 - (1*4), 1*4, 3*4, 0);// Li2
}

void  dib_dash_rec(int *a, int *b, int *c){//Manejo y animacion del dash
  int dash_act_f = *a;
  int cont_dash_f = *b;
  int cont_dash_anim_f = *c; 

  if(++cont_dash_f >= 50 && dash_act_f == 0){ //aumentara 1 valor por segundo -> animación
    cont_dash_f = 0;
    // CONTADOR DASH (Recarga)
    switch(cont_dash_anim_f){
      case 1: 
      LCD_DrawRectangle((23 - 4)*4, 300, 9*4, 1*4, ORANGE_COLOR);// Línea centro
      cont_dash_anim_f++;
      break;
      case 2: 
      LCD_DrawRectangle((23 - 3)*4, 300 - (1*4), 1*4, 3*4, ORANGE_COLOR);// Ld2
      cont_dash_anim_f++;
      break;
      case 3:
      LCD_DrawRectangle((23 - 2)*4, 300 - (2*4), 1*4, 5*4, ORANGE_COLOR);// Ld1
      cont_dash_anim_f++;
      break;
      case 4:
      LCD_DrawRectangle((23 + 2)*4, 300 - (2*4), 1*4, 5*4, ORANGE_COLOR);// Li1
      cont_dash_anim_f++;
      break;
      case 5:
      dib_dash();
      cont_dash_anim_f = 1;
      dash_act_f = 1;
      break;
    }
  }
  *a = dash_act_f; 
  *b = cont_dash_f; 
  *c = cont_dash_anim_f; 
}

//NUMEROS
void borr_num_ant(int *n, int*m){ // BORRA EL NUMERO ANTERIOR
  int n_pos_x = *n;  
  int n_pos_y = *m;
LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 5*4, 0);
  *n = n_pos_x; 
  *m = n_pos_y;
}

void dib_cero(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (1*4), 1*4, 3*4, WHITE_COLOR);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (1*4), 1*4, 3*4, WHITE_COLOR);
}

void dib_uno(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle(n_pos_x*4, n_pos_y - (1*4), 1*4, 1*4, WHITE_COLOR);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);
}

void dib_dos(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);//unión arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 1*4, 3*4, WHITE_COLOR);              //unión abajo
}

void dib_tres(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
}

void dib_cuatro(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der    
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);// media barra lateral izq
}

void dib_cinco(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);//unión arriba
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y, 1*4, 3*4, WHITE_COLOR);              //unión abajo
}

void dib_seis(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);//unión arriba
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y, 1*4, 3*4, WHITE_COLOR);              //unión abajo
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 1*4, 3*4, WHITE_COLOR);              //unión abajo
}

void dib_siete(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle(n_pos_x*4, n_pos_y, 2*4, 1*4, WHITE_COLOR);              // barra medio
}

void dib_ocho(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo    
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// media barra lateral izq
}

void dib_nueve(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio   
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);// media barra lateral izq
}

//******************************************************************************
//CONTADOR
void contador(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h){
  int cont = *a;
  int cont_u = *b;
  int cont_d = *c;
  int cont_t = *d;
  int cont_cu = *e;
  int cont_ci = *f;
  int cont_se = *g;
  int met_dest_f = *h;
  int var_comp_u = 0, var_comp_d = 0;
  if(++cont >= 50 || met_dest_f == 1 || met_dest_f == 2 || met_dest_f == 3){ //aumentara 1 valor por segundo
    cont = 0;
    if(met_dest_f == 1){
      var_comp_u = cont_u;
      var_comp_d = cont_d;
      cont_u = 10;
      cont_d = 10;
    }
    if(met_dest_f == 2){
      var_comp_u = cont_u;
      cont_u = 10;
    }


  // CONTADOR 1
    switch(cont_u){
      case 1:
      dib_uno(56, 300);
      cont_u++;
      break;
      case 2:
      dib_dos(56, 300);
      cont_u++;
      break;
      case 3:
      dib_tres(56, 300);
      cont_u++;
      break;
      case 4:
      dib_cuatro(56, 300);
      cont_u++;
      break;
      case 5:
      dib_cinco(56, 300);
      cont_u++;
      break;
      case 6:
      dib_seis(56, 300);
      cont_u++;
      break;
      case 7:
      dib_siete(56, 300);
      cont_u++;
      break;
      case 8:
      dib_ocho(56, 300);
      cont_u++;
      break;
      case 9:
      dib_nueve(56, 300);
      cont_u++;
      break;
      case 10:
      dib_cero(56, 300);
      cont_u = 1;
  // CONTADOR  2
        switch(cont_d){
        case 1:
        dib_uno(52, 300);
        cont_d++;
        break;
        case 2:
        dib_dos(52, 300);
        cont_d++;
        break;
        case 3:
        dib_tres(52, 300);
        cont_d++;
        break;
        case 4:
        dib_cuatro(52, 300);
        cont_d++;
        break;
        case 5:
        dib_cinco(52, 300);
        cont_d++;
        break;
        case 6:
        dib_seis(52, 300);
        cont_d++;
        break;
        case 7:
        dib_siete(52, 300);
        cont_d++;
        break;
        case 8:
        dib_ocho(52, 300);
        cont_d++;
        break;
        case 9:
        dib_nueve(52, 300);
        cont_d++;
        break;
        case 10:
        dib_cero(52, 300);
        cont_d = 1;
  //CONTADOR 3
        switch(cont_t){
          case 1:
          dib_uno(48, 300);
          cont_t++;
          break;
          case 2:
          dib_dos(48, 300);
          cont_t++;
          break;
          case 3:
          dib_tres(48, 300);
          cont_t++;
          break;
          case 4:
          dib_cuatro(48, 300);
          cont_t++;
          break;
          case 5:
          dib_cinco(48, 300);
          cont_t++;
          break;
          case 6:
          dib_seis(48, 300);
          cont_t++;
          break;
          case 7:
          dib_siete(48, 300);
          cont_t++;
          break;
          case 8:
          dib_ocho(48, 300);
          cont_t++;
          break;
          case 9:
          dib_nueve(48, 300);
          cont_t++;
          break;
          case 10:
          dib_cero(48, 300);
          cont_t = 1;
  // CONTADOR 4
            switch(cont_cu){
              case 1:
              dib_uno(44, 300);
              cont_cu++;
              break;
              case 2:
              dib_dos(44, 300);
              cont_cu++;
              break;
              case 3:
              dib_tres(44, 300);
              cont_cu++;
              break;
              case 4:
              dib_cuatro(44, 300);
              cont_cu++;
              break;
              case 5:
              dib_cinco(44, 300);
              cont_cu++;
              break;
              case 6:
              dib_seis(44, 300);
              cont_cu++;
              break;
              case 7:
              dib_siete(44, 300);
              cont_cu++;
              break;
              case 8:
              dib_ocho(44, 300);
              cont_cu++;
              break;
              case 9:
              dib_nueve(44, 300);
              cont_cu++;
              break;
              case 10:
              dib_cero(44, 300);
              cont_cu = 1;
  // CONTADOR 5
                switch(cont_ci){
                  case 1:
                  dib_uno(40, 300);
                  cont_ci++;
                  break;
                  case 2:
                  dib_dos(40, 300);
                  cont_ci++;
                  break;
                  case 3:
                  dib_tres(40, 300);
                  cont_ci++;
                  break;
                  case 4:
                  dib_cuatro(40, 300);
                  cont_ci++;
                  break;
                  case 5:
                  dib_cinco(40, 300);
                  cont_ci++;
                  break;
                  case 6:
                  dib_seis(40, 300);
                  cont_ci++;
                  break;
                  case 7:
                  dib_siete(40, 300);
                  cont_ci++;
                  break;
                  case 8:
                  dib_ocho(40, 300);
                  cont_ci++;
                  break;
                  case 9:
                  dib_nueve(40, 300);
                  cont_ci++;
                  break;
                  case 10:
                  dib_cero(40, 300);
                  cont_ci = 1;
  // CONTADOR 6
                switch(cont_se){
                  case 1:
                  dib_uno(36, 300);
                  cont_se++;
                  break;
                  case 2:
                  dib_dos(36, 300);
                  cont_se++;
                  break;
                  case 3:
                  dib_tres(36, 300);
                  cont_se++;
                  break;
                  case 4:
                  dib_cuatro(36, 300);
                  cont_se++;
                  break;
                  case 5:
                  dib_cinco(36, 300);
                  cont_se++;
                  break;
                  case 6:
                  dib_seis(36, 300);
                  cont_se++;
                  break;
                  case 7:
                  dib_siete(36, 300);
                  cont_se++;
                  break;
                  case 8:
                  dib_ocho(36, 300);
                  cont_se++;
                  break;
                  case 9:
                  dib_nueve(36, 300);
                  cont_se++;
                  break;
                  case 10:
                  dib_cero(36, 300);
                  cont_se = 1;
                  break;
                }
                break;  
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      }
    
    if(met_dest_f == 3){
      met_dest_f = 0;
    } 
    if(met_dest_f == 2){
      cont_u = var_comp_u;
      met_dest_f = 3;
    }
    if(met_dest_f == 1){
      cont_u = var_comp_u;
      cont_d = var_comp_d;
      met_dest_f = 2;
    }
  }
  *a = cont;
  *b = cont_u;
  *c = cont_d;
  *d = cont_t;
  *e = cont_cu;
  *f = cont_ci;
  *g = cont_se;
  *h = met_dest_f;
}