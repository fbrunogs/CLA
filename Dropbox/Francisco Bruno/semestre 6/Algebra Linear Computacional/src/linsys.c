/*
 * linsys.c
 *
 *  Created on: Aug 12, 2014
 *      Author: bruno
 */

#include <linsys.h>
#include <stdio.h>
#include <stdlib.h>

void copy (CLA_INT n, CLA_DOUBLE **dest, CLA_DOUBLE **src) {
	if (!dest || !src || n < 0) {
		fprintf(stderr, "copy::Problem with input arguments.\n");
		exit(EXIT_FAILURE);
	}
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dest[i][j] = src[i][j];
}

void CLA_lu (CLA_INT n, CLA_DOUBLE **A, CLA_DOUBLE **L, CLA_DOUBLE **U) {
	if (!A || !L || !U || n < 0) {
		fprintf(stderr, "CLA_lu::Problem with input arguments.\n");
		exit(EXIT_FAILURE);
	}

	int i, j, k;
	CLA_DOUBLE pivot;
	copy(n, U, A);
	for (i = 0; i < n - 1; i++) {		/* Fixes the pivot row */
		for (j = i + 1; j < n; j++) {	/* Runs along the pivot column */
			pivot = -U[j][i]/U[i][i];
			for (k = 0; k < n; k++) {	/* Updates the rows under the pivot row */
				U[j][k] += pivot * U[i][k];
			}
			L[j][i] = - pivot;
		}
	}
}
