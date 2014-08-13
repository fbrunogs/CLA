/*
 * linsys.h
 *
 *  Created on: Aug 12, 2014
 *      Author: bruno
 */

#ifndef LINSYS_H_
#define LINSYS_H_

#define CLA_DOUBLE    double
#define CLA_FLOAT     double
#define CLA_INT	      int

#define CLA_MAX(a, b) (a > b ? a : b)
#define CLA_MIN(a, b) (a < b ? a : b)

void copy (CLA_INT n, CLA_DOUBLE **dest, CLA_DOUBLE **src);
void CLA_lu (int n, CLA_DOUBLE **A, CLA_DOUBLE **L, CLA_DOUBLE **U);

#endif /* LINSYS_H_ */
