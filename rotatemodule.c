#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static PyObject *animate(PyObject *self, PyObject *args)
{

    int x;
    int y;

    float bornx = 126.0;
    float borny = -12.0;

    if (!PyArg_ParseTuple(args, "ii",&x,&y))
        return NULL;

    int i;
    float arrayx[99];
    float arrayy[99];

    for (i=0;i<99;i++){
        arrayx[i] = bornx + (float)x/100.0*(float)i;
        arrayy[i] = borny + (float)y/100.0*(float)i;
        //array[i][1] = borny + y/100*(i*2);
    }
    //arrayx[0] = 123.0;

    

    return Py_BuildValue("[(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)(ff)]",arrayx[0],arrayy[0],arrayx[1],arrayy[1],arrayx[2],arrayy[2],arrayx[3],arrayy[3],arrayx[4],arrayy[4],arrayx[5],arrayy[5],arrayx[6],arrayy[6],arrayx[7],arrayy[7],arrayx[8],arrayy[8],arrayx[9],arrayy[9],arrayx[10],arrayy[10],arrayx[11],arrayy[11],arrayx[12],arrayy[12],arrayx[13],arrayy[13],arrayx[14],arrayy[14],arrayx[15],arrayy[15],arrayx[16],arrayy[16],arrayx[17],arrayy[17],arrayx[18],arrayy[18],arrayx[19],arrayy[19],arrayx[20],arrayy[20],arrayx[21],arrayy[21],arrayx[22],arrayy[22],arrayx[23],arrayy[23],arrayx[24],arrayy[24],arrayx[25],arrayy[25],arrayx[26],arrayy[26],arrayx[27],arrayy[27],arrayx[28],arrayy[28],arrayx[29],arrayy[29],arrayx[30],arrayy[30],arrayx[31],arrayy[31],arrayx[32],arrayy[32],arrayx[33],arrayy[33],arrayx[34],arrayy[34],arrayx[35],arrayy[35],arrayx[36],arrayy[36],arrayx[37],arrayy[37],arrayx[38],arrayy[38],arrayx[39],arrayy[39],arrayx[40],arrayy[40],arrayx[41],arrayy[41],arrayx[42],arrayy[42],arrayx[43],arrayy[43],arrayx[44],arrayy[44],arrayx[45],arrayy[45],arrayx[46],arrayy[46],arrayx[47],arrayy[47],arrayx[48],arrayy[48],arrayx[49],arrayy[49],arrayx[50],arrayy[50],arrayx[51],arrayy[51],arrayx[52],arrayy[52],arrayx[53],arrayy[53],arrayx[54],arrayy[54],arrayx[55],arrayy[55],arrayx[56],arrayy[56],arrayx[57],arrayy[57],arrayx[58],arrayy[58],arrayx[59],arrayy[59],arrayx[60],arrayy[60],arrayx[61],arrayy[61],arrayx[62],arrayy[62],arrayx[63],arrayy[63],arrayx[64],arrayy[64],arrayx[65],arrayy[65],arrayx[66],arrayy[66],arrayx[67],arrayy[67],arrayx[68],arrayy[68],arrayx[69],arrayy[69],arrayx[70],arrayy[70],arrayx[71],arrayy[71],arrayx[72],arrayy[72],arrayx[73],arrayy[73],arrayx[74],arrayy[74],arrayx[75],arrayy[75],arrayx[76],arrayy[76],arrayx[77],arrayy[77],arrayx[78],arrayy[78],arrayx[79],arrayy[79],arrayx[80],arrayy[80],arrayx[81],arrayy[81],arrayx[82],arrayy[82],arrayx[83],arrayy[83],arrayx[84],arrayy[84],arrayx[85],arrayy[85],arrayx[86],arrayy[86],arrayx[87],arrayy[87],arrayx[88],arrayy[88],arrayx[89],arrayy[89],arrayx[90],arrayy[90],arrayx[91],arrayy[91],arrayx[92],arrayy[92],arrayx[93],arrayy[93],arrayx[94],arrayy[94],arrayx[95],arrayy[95],arrayx[96],arrayy[96],arrayx[97],arrayy[97],arrayx[98],arrayy[98]);


}

static PyObject *rotate(PyObject *self, PyObject *args)
{
    double x;
    double y;

    double angle;
    double ang;
    double radius;

    if (!PyArg_ParseTuple(args, "ddddd", &x,&y,&angle,&ang,&radius))
        return NULL;

    double newx = x + cos(angle+ang) * radius;
    double newy = y - sin(angle+ang) * radius;

    return Py_BuildValue("(dd)",newx,newy);
}

static PyMethodDef methods[] = {
    {"rotate", rotate, METH_VARARGS, "Rotates around a given point"},
    {"animate", animate, METH_VARARGS, "Makes a pathline from two points"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef rotatemodule = {
    PyModuleDef_HEAD_INIT,
    "Rotate",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    methods
};

PyMODINIT_FUNC PyInit_Rotate() {
    return PyModule_Create(&rotatemodule);
};