#ifndef POLYGONISE_H
#define POLYGONISE_H

typedef struct {
   double x,y,z;
} XYZ;

typedef struct {
   XYZ p[3];
} TRIANGLE;

typedef struct {
   XYZ p[8];
   double val[8];
} GRIDCELL;

XYZ VertexInterp(double isolevel,XYZ p1,XYZ p2,double valp1,double valp2);
int Polygonise(GRIDCELL grid,double isolevel,TRIANGLE *triangles);

#endif
