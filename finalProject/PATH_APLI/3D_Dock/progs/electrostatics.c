/*
This file is part of ftdock, a program for rigid-body protein-protein docking 
Copyright (C) 1997-2000 Gidon Moont

Biomolecular Modelling Laboratory
Imperial Cancer Research Fund
44 Lincoln's Inn Fields
London WC2A 3PX

+44 (0)20 7269 3348
http://www.bmm.icnet.uk/

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "structures.h"
#include <emmintrin.h>

#define pot2(_num) (\
  (_num)*(_num)\
)

#define pythagoras2(x1, y1, z1, x2, y2, z2) (\
  ( ( ( (x1) - (x2) ) * ( (x1) - (x2) ) ) + ( ( (y1) - (y2) ) * ( (y1) - (y2) ) ) + ( ( (z1) - (z2) ) * ( (z1) - (z2) ) ) )\
)

void assign_charges( struct Structure This_Structure ) {

/************/

  /* Counters */

  int	residue , atom, current_atom;

/************/

  for( residue = 1 ; residue <= This_Structure.length ; residue ++ ) {
    for( atom = 1, current_atom = 0 ; atom <= This_Structure.Residue[residue].size ; atom ++ ) {

      This_Structure.Residue[residue].Atom[atom].charge = 0.0 ;

      /* peptide backbone */

      if( strcmp( This_Structure.Residue[residue].Atom[atom].atom_name , " N  " ) == 0 ) {
        if( strcmp( This_Structure.Residue[residue].res_name , "PRO" ) == 0 ) {
          This_Structure.Residue[residue].Atom[atom].charge = -0.10 ;
        } else {
          This_Structure.Residue[residue].Atom[atom].charge =  0.55 ;
          if( residue == 1 ) This_Structure.Residue[residue].Atom[atom].charge = 1.00 ;
        }
      }

      if( strcmp( This_Structure.Residue[residue].Atom[atom].atom_name , " O  " ) == 0 ) {
        This_Structure.Residue[residue].Atom[atom].charge = -0.55 ;
        if( residue == This_Structure.length  ) This_Structure.Residue[residue].Atom[atom].charge = -1.00 ;
      }

      /* charged residues */

      if( ( strcmp( This_Structure.Residue[residue].res_name , "ARG" ) == 0 ) && ( strncmp( This_Structure.Residue[residue].Atom[atom].atom_name , " NH" , 3 ) == 0 ) ) This_Structure.Residue[residue].Atom[atom].charge =  0.50 ;
      if( ( strcmp( This_Structure.Residue[residue].res_name , "ASP" ) == 0 ) && ( strncmp( This_Structure.Residue[residue].Atom[atom].atom_name , " OD" , 3 ) == 0 ) ) This_Structure.Residue[residue].Atom[atom].charge = -0.50 ;
      if( ( strcmp( This_Structure.Residue[residue].res_name , "GLU" ) == 0 ) && ( strncmp( This_Structure.Residue[residue].Atom[atom].atom_name , " OE" , 3 ) == 0 ) ) This_Structure.Residue[residue].Atom[atom].charge = -0.50 ;
      if( ( strcmp( This_Structure.Residue[residue].res_name , "LYS" ) == 0 ) && ( strcmp( This_Structure.Residue[residue].Atom[atom].atom_name , " NZ " ) == 0 ) ) This_Structure.Residue[residue].Atom[atom].charge =  1.00 ;
      
     /* if (This_Structure.Residue[residue].Atom[atom].charge != 0.0 && current_atom == atom) {
	++current_atom;
      }
      else if (This_Structure.Residue[residue].Atom[atom].charge != 0.0){
	This_Structure.Residue[residue].Atom[++current_atom] = This_Structure.Residue[residue].Atom[atom];
      }*/
    }
    //This_Structure.Residue[residue].size = current_atom;
  }

/************/

}



/************************/



void electric_field( struct Structure This_Structure , float grid_span , int grid_size , fftw_real *grid ) {

/************/

  /* Counters */

  int residue , atom ;

  /* Co-ordinates */

  int x , y , z ;
  float x_centre , y_centre , z_centre ;

  /* Variables */

  float distance, last_distance ;
  float phi , epsilon ;
  
  float sum_centre =  (float)((float)grid_span/(float)grid_size);
  
  // FORÇAR ALINEAMENT
  float memo_center[grid_size];
  setvbuf( stdout , (char *)NULL , _IONBF , 0 ) ;

  memo_center[0] = gcentre( 0 , grid_span , grid_size ) ;
  memo_center[1] = memo_center[0] + sum_centre;
  memo_center[2] = memo_center[1] + sum_centre;
  memo_center[3] = memo_center[2] + sum_centre;
  sum_centre = sum_centre*4.0;
  
  for (z = 4; z < grid_size - 3; z += 4) {
    memo_center[z  ] = memo_center[z-4] + sum_centre;
    memo_center[z+1] = memo_center[z-3] + sum_centre;
    memo_center[z+2] = memo_center[z-2] + sum_centre;
    memo_center[z+3] = memo_center[z-1] + sum_centre;
  }
  
  sum_centre = sum_centre/4.0;
  for (; z < grid_size; z++) {
    memo_center[z  ] = memo_center[z-1] + sum_centre;
  }
  
  printf( "  electric field calculations ( one dot / one atom ) " ) ;
  for( residue = 1 ; residue <= This_Structure.length ; residue ++ ) {
    for( atom = 1 ; atom <= This_Structure.Residue[residue].size ; atom ++ ) {
      printf(".");
      
      float charge = This_Structure.Residue[residue].Atom[atom].charge;
      if( charge == 0 ) continue;
      
      float coord[3];
      coord[0] = This_Structure.Residue[residue].Atom[atom].coord[1];
      coord[1] = This_Structure.Residue[residue].Atom[atom].coord[2];
      coord[2] = This_Structure.Residue[residue].Atom[atom].coord[3];
      
      for( x = 0 ; x < grid_size ; x ++ ) {
	
        float part_pytagoras1 = pot2(coord[0] - memo_center[x]);	
	for( y = 0 ; y < grid_size ; y ++ ) {
	  
	  int index = gaddress(x,y,0,grid_size);	  
	  last_distance = 11000000;
	  
	  float part_pytagoras2 = part_pytagoras1 + pot2(coord[1] - memo_center[y]);
	  __m128 pythagoras_mask = _mm_set1_ps (part_pytagoras2);
	  __m128 coord_mask = _mm_set1_ps (coord[2]);
	  for( z = 0 ; z < grid_size ; z ++, index++ ) {
	    
	    __m128 tmp = _mm_sub_ps(coord_mask, *(__m128 *)(&memo_center[z]));
	    tmp = _mm_mul_ps(tmp, tmp) + pythagoras_mask;
	    //distance = part_pytagoras2 + pot2(coord[2] - memo_center[z]);
	    
	    if( distance < 64.0 ) {
	      
	      if( distance <= 36.0 ) { 
		distance = (distance > 4.0) ? sqrt(distance)*4.0 : 8.0; 
	      } else {
		distance = ( 38 * distance ) - ( 224 * sqrt(distance) );		
	      }
	      
	      grid[index] += ( charge / ( distance ) ) ;
	      
	    } else if (distance > last_distance){
	      break;
	    }
	    
	    last_distance = distance;
	  } 
      }
    }	
  }
}

  printf( "\n" ) ;

/************/

  return ;

}


/////
/************************/



void electric_point_charge( struct Structure This_Structure , float grid_span , int grid_size , fftw_real *grid ) {

/************/

  /* Counters */

  int	residue , atom ;

  /* Co-ordinates */

  int	x , y , z ;
  int	x_low , x_high , y_low , y_high , z_low , z_high ;

  float		a , b , c ;
  float		x_corner , y_corner , z_corner ;
  float		w ;

  /* Variables */

  float		one_span ;

/************/

  for( x = 0 ; x < grid_size ; x ++ ) {
    for( y = 0 ; y < grid_size ; y ++ ) {
      for( z = 0 ; z < grid_size ; z ++ ) {

        grid[gaddress(x,y,z,grid_size)] = (fftw_real)0 ;

      }
    }
  }

/************/

  one_span = grid_span / (float)grid_size ;

  for( residue = 1 ; residue <= This_Structure.length ; residue ++ ) {
    for( atom = 1 ; atom <= This_Structure.Residue[residue].size ; atom ++ ) {

      if( This_Structure.Residue[residue].Atom[atom].charge != 0 ) {

        x_low = gord( This_Structure.Residue[residue].Atom[atom].coord[1] - ( one_span / 2 ) , grid_span , grid_size ) ;
        y_low = gord( This_Structure.Residue[residue].Atom[atom].coord[2] - ( one_span / 2 ) , grid_span , grid_size ) ;
        z_low = gord( This_Structure.Residue[residue].Atom[atom].coord[3] - ( one_span / 2 ) , grid_span , grid_size ) ;

        x_high = x_low + 1 ;
        y_high = y_low + 1 ;
        z_high = z_low + 1 ;

        a = This_Structure.Residue[residue].Atom[atom].coord[1] - gcentre( x_low , grid_span , grid_size ) - ( one_span / 2 ) ;
        b = This_Structure.Residue[residue].Atom[atom].coord[2] - gcentre( y_low , grid_span , grid_size ) - ( one_span / 2 ) ;
        c = This_Structure.Residue[residue].Atom[atom].coord[3] - gcentre( z_low , grid_span , grid_size ) - ( one_span / 2 ) ;

        for( x = x_low ; x <= x_high  ; x ++ ) {
 
          x_corner = one_span * ( (float)( x - x_high ) + .5 ) ;

          for( y = y_low ; y <= y_high  ; y ++ ) {

            y_corner = one_span * ( (float)( y - y_high ) + .5 ) ;

            for( z = z_low ; z <= z_high  ; z ++ ) {

              z_corner = one_span * ( (float)( z - z_high ) + .5 ) ;

              w = ( ( x_corner + a ) * ( y_corner + b ) * ( z_corner + c ) ) / ( 8.0 * x_corner * y_corner * z_corner ) ;

              grid[gaddress(x,y,z,grid_size)] += (fftw_real)( w * This_Structure.Residue[residue].Atom[atom].charge ) ;

            }
          }
        }

      }

    }
  }

/************/

  return ;

}



/************************/



void electric_field_zero_core( int grid_size , fftw_real *elec_grid , fftw_real *surface_grid , float internal_value ) {

/************/

  /* Co-ordinates */

  int	x , y , z ;

/************/

  for( x = 0 ; x < grid_size ; x ++ ) {
    for( y = 0 ; y < grid_size ; y ++ ) {
      for( z = 0 ; z < grid_size ; z ++ ) {

        if( surface_grid[gaddress(x,y,z,grid_size)] == (fftw_real)internal_value ) elec_grid[gaddress(x,y,z,grid_size)] = (fftw_real)0 ;

      }
    }
  }

/************/

  return ;

}
