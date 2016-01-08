#include <python2.7/Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef int Bool
//#define True 1
//#define False 0

long C_fib(long a){
	if (a < 2)
		return a;
	else
		return C_fib(a-1)+C_fib(a-2);
}

long C_sub(long a,long b){

	long output = (a - b);
	return output; 
}

long Csum(long a,long b)
{
	long output = (a + b);
	return output;
}

long Cdiv(long a,long b)
{
        float output = (a / b);
        //if( output != 0 ) return -1;
        return output;
}
static PyObject*
Pydiv(PyObject* self,PyObject* args){

        long b;
        long a;
        if (!PyArg_ParseTuple(args,"ii",&a,&b)){
                return NULL;
        }
        //if (Cdiv(a,b) < 0){
        //        PyErr_SetString(PyExc_OverflowError,"Out of range number");
        //}
        return Py_BuildValue("i",Cdiv(a,b));
}


static PyObject*
sub(PyObject* self,PyObject* args){

        long b;
	long a;
        if (!PyArg_ParseTuple(args,"ii",&a,&b)){
                return NULL;
        }
        if (C_sub(a,b) < 0){
                PyErr_SetString(PyExc_OverflowError,"Out of range number");
        }
        return Py_BuildValue("i",C_sub(a,b));
}


static PyObject*
fib(PyObject* self,PyObject* args){

	long b;
	if (!PyArg_ParseTuple(args,"i",&b)){
		return NULL;
	}
	if (C_fib(b) > 100000000000){
		PyErr_SetString(PyExc_OverflowError,"Out of range number");
	}
	return Py_BuildValue("i",C_fib(b));
}
static PyObject*
sum(PyObject* self,PyObject* args)
{
	long a;
	long b;
	if(!PyArg_ParseTuple(args,"ii",&a,&b)){
		return NULL;
	}
	if (Csum(a,b) > 10000000){
	 	PyErr_SetString(PyExc_OverflowError, "out of range number");
		return NULL;
	}
	return Py_BuildValue("i",Csum(a,b));
}
static PyObject*
version(PyObject* self)
{
	return Py_BuildValue("s","Version 1.0");
}
static PyMethodDef
sample_methods[] =
{
	{"Sum",sum,METH_VARARGS,"return calculate sum (a+b)"},
	{"Sub",sub,METH_VARARGS,"return calculate sum (a-b)"},
	{"Div",Pydiv,METH_VARARGS,"return calculate sum (a/b)"},
	{"Version",(PyCFunction)version,  METH_NOARGS,"Return the version"},
	{"Fib",fib,METH_VARARGS,"return calculate fibnacci "},
	{NULL,NULL,0,NULL}
};
PyMODINIT_FUNC
initcalcmath(void) {
	Py_InitModule("calcmath",sample_methods);
}

