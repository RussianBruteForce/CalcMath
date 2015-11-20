#include <stdio.h>
#include <math.h>

#define SIZE 2
//#define SY SX

#define STEP 0.1
//#define NY NX

#define UIJ(pole, i, j, step) ( ( pole[i][j+1] - pole[i][j] ) / step )
#define U2IJ(pole, i, j, step) ( ( pole[i+1][j] - 2*pole[i][j] + pole[i-1][j]) / step*step )

#define NEW_POLE(NAME,xM,yM,xS,yS) ( NAME[(int)(xM/xS)+1][(int)(yM/yS)+1])

typedef double calc_t;

calc_t NEW_POLE(G67,SIZE,SIZE,STEP,STEP);
calc_t NEW_POLE(G68,SIZE,SIZE,STEP,STEP);
calc_t NEW_POLE(G72,SIZE,SIZE,STEP,STEP);
calc_t NEW_POLE(G90,SIZE,SIZE,STEP,STEP);
calc_t NEW_POLE(G71,SIZE,SIZE,STEP,STEP);


#define NEXT(POLE, F, step) ((F)*step + POLE[x][y])

calc_t F67(int x, int y) {
	return NEXT(G67,UIJ(G67,x,y,STEP)*(x*STEP)/(y*STEP), STEP);
}

calc_t F68(int x, int y) {
	return NEXT(G68,
		    UIJ(G68,x,y,STEP)
		    *
		    ((x*STEP)+2*(y*STEP))
		    /
		    (y*STEP),
		    STEP);
}

calc_t F72(int x, int y) {
	return NEXT(G72,
		    (exp((x*STEP))*(y*STEP)
		     -
		     exp((x*STEP))*UIJ(G72,x,y,STEP))
		    /
		    ((y*STEP)*(y*STEP))
		    , STEP);
}

calc_t F90(int x, int y) {
	return NEXT(G90,
		    (-1*UIJ(G90,x,y,STEP))
		    /
		    (2*exp(x)-y)
		    , STEP);
}

calc_t F71(int x, int y) {
	return NEXT(G71,
		    ((x*STEP - y*STEP)
		     -
		     UIJ(G71,x,y,STEP) * (y*STEP))
		    /
		    (y*STEP)
		    , STEP);
}

void print(__typeof__(G67) pole, size_t startx, size_t starty);
void fprint(FILE * f, __typeof__(G67) pole, size_t startx, size_t starty);


int main(void)
{
	FILE *out = fopen("out","w");
	fprintf(out,"\tX увеличивается вниз, Y увеличивается вправо\n");
	fprintf(out,"\tПосле номера задания указан интервал\n\n");
	// 67 ****************
	fprintf(out,"#67 1-2\n");
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G67[i][(size_t)(1/STEP)] = 1;
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G67[0][i] = 1;
	for (size_t yi = (size_t)(1/STEP); yi <= SIZE/STEP + 1; yi++) {
		for (size_t xi = 0; xi <= SIZE/STEP + 1; xi++) {
			calc_t x = xi*STEP;
			calc_t y = yi*STEP;
			if (!(y<1)) {
				G67[xi][yi+1] = F67(xi,yi);
				//				printf("P %f\n", UIJ(G67,xi,yi,STEP));
			}
		}
	}
	//print(G67, (size_t)(1/STEP));
	fprint(out, G67, 0, (size_t)(1/STEP));

	// 68 ***************
	fprintf(out,"\n\n#68\n");
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G68[i][(size_t)(1/STEP)] = 1;
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G68[0][i] = 1;
	for (size_t yi = (size_t)(1/STEP); yi <= SIZE/STEP + 1; yi++) {
		for (size_t xi = 0; xi <= SIZE/STEP + 1; xi++) {
			calc_t x = xi*STEP;
			calc_t y = yi*STEP;
			if (!(y<1)) {
				G68[xi][yi+1] = F68(xi,yi);
			}
		}
	}
	fprint(out, G68, 0, (size_t)(1/STEP));

	// 72 ***************
	fprintf(out, "\n\n#72 1-2\n");
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G72[i][(size_t)(1/STEP)] = 1;
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G72[0][i] = 1;
	for (size_t yi = (size_t)(1/STEP); yi <= SIZE/STEP + 1; yi++) {
		for (size_t xi = 0; xi <= SIZE/STEP + 1; xi++) {
			calc_t x = xi*STEP;
			calc_t y = yi*STEP;
			if (x == 0)
				G72[xi][yi] = 1;
			if (!(y<1)) {
				G72[xi][yi+1] = F72(xi,yi);
			}
		}
	}
	fprint(out, G72, 0, (size_t)(1/STEP));

	// 90 ***************
	fprintf(out,"\n\n#90 0.5-2\n");
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G90[i][(size_t)(0.5/STEP)] = 3;
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G90[0][i] = 3;
	for (size_t yi = 0.5/STEP; yi <= SIZE/STEP + 1; yi++) {
		for (size_t xi = 0; xi <= SIZE/STEP + 1; xi++) {
			calc_t x = xi*STEP;
			calc_t y = yi*STEP;

			if (x == 0)
				G90[xi][yi] = 3;
			G90[xi][yi+1] = F90(xi,yi);
		}
	}
	fprint(out, G90, 0, (size_t)(0.5/STEP));


	// 71 ***************
	fprintf(out, "\n\n#71 1-2\n");
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G71[i][(size_t)(1/STEP)] = 6;
	for (size_t i = 0; i <= SIZE/STEP; i++)
		G71[0][i] = 6;
	for (size_t yi = (size_t)(1/STEP); yi <= SIZE/STEP + 1; yi++) {
		for (size_t xi = 0; xi <= SIZE/STEP + 1; xi++) {
			calc_t x = xi*STEP;
			calc_t y = yi*STEP;
			if (x == 0)
				G71[xi][yi] = 6;
			if (!(y<1)) {
				G71[xi][yi+1] = F71(xi,yi);
			}
		}
	}
	fprint(out, G71, 0, (size_t)(1/STEP));
	fclose(out);
	return 0;
}


void print(__typeof__(G67) pole, size_t startx, size_t starty){
	for (size_t i = starty; i <= SIZE/STEP; i ++) {
		for (size_t j = startx; j <= SIZE/STEP; j ++) {
			printf("%0.3f\t", pole[j][i]);
		}
		printf("\n");
	}

}
void fprint(FILE * f, __typeof__(G67) pole, size_t startx, size_t starty){
	for (size_t i = starty; i <= SIZE/STEP; i ++) {
		for (size_t j = startx; j <= SIZE/STEP; j ++) {
			fprintf(f,"%0.3f\t", pole[j][i]);
		}
		fprintf(f,"\n");
	}

}

