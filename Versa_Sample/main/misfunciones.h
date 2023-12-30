//******************************************************************************
//Aqui se añadiran las funciones personales
//******************************************************************************

#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

//******************************************************************************
// INCLUDES

#include <stdint.h>

//******************************************************************************
// FUNCTIONS

//******************************************************************************
// NAVE
void mov_arriba(int *n, int *m);
void mov_abajo(int *n, int *m);
void mov_izq(int *n, int *m);
void mov_der(int *n, int *m);
void dash_izq(int *n, int *m);
void dash_der(int *n, int *m);
void dib_nave(int *n, int *m);
void borr_nave(int *n, int *m);
void disparo(int *a, int *b, int *c, int *d, int *e, int *f, int *g);
void recarga(int *a, int *b, int *c, int *d);
void comp_nav();

//******************************************************************************
// METEORITO
void dib_met(int *n, int *m);
void borr_met(int *n, int *m);
void met_anim(int *a, int *b, int *c, int *d, int *e, int *f, int *g);
void met_comp(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *k);
void control_vel(int *a, int *b);

//******************************************************************************
// INTERFAZ
  //Balas
void dib_bal_un();
void dib_bal_do();
void dib_bal_tr();
void dib_balas();
void borr_bal_un();
void borr_bal_do();
void borr_bal_tr();
void rec_bal_un();
void rec_bal_do();
void rec_bal_tr();
void fondo(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h, int *j);
  //Dash
void dib_dash();
void borr_dash();
void dib_dash_rec(int *a, int *b, int *c);

  //Bordes
void dib_bordes();
  
  //Numeros
void borr_num_ant(int *n, int*m);
void dib_cero(int n_pos_x, int n_pos_y);
void dib_uno(int n_pos_x, int n_pos_y);
void dib_dos(int n_pos_x, int n_pos_y);
void dib_tres(int n_pos_x, int n_pos_y);
void dib_cuatro(int n_pos_x, int n_pos_y);
void dib_cinco(int n_pos_x, int n_pos_y);
void dib_seis(int n_pos_x, int n_pos_y);
void dib_siete(int n_pos_x, int n_pos_y);
void dib_ocho(int n_pos_x, int n_pos_y);
void dib_nueve(int n_pos_x, int n_pos_y);
void contador(int *a, int *b, int *c, int *d, int *e, int *f, int *g, int *h);

#endif
