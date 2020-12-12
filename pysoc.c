#define PY_SSIZE_T_CLEAN
#include "pysoc.h"
#include <Python.h>
#include <stdbool.h>

static void bubble_sort(long v[], long n) {
    for (ssize_t i = n - 1; i > 0; i--) {
        bool swapped = false;

        for (ssize_t j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                long temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

PyObject *pysoc_bubble_sort(PyObject *self, PyObject *args) {
    PyObject *int_list;
    if (!PyArg_ParseTuple(args, "O", &int_list)) return NULL;
    Py_ssize_t n = PyObject_Length(int_list);
    if (n == -1) return NULL;

    long v[n];
    for (Py_ssize_t i = 0; i < n; i++) {
        PyObject *val = PyList_GetItem(int_list, i);
        long lval = PyLong_AsLong(val);
        if (lval == -1) return NULL;
        v[i] = lval;
    }

    bubble_sort(v, n);

    PyObject *ret_list = PyList_New(n);

    for (Py_ssize_t i = 0; i < n; i++) {
        PyObject *pl = PyLong_FromLong(v[i]); // Py_BuildValue("i", v[i]);
        if (pl == NULL) return NULL;

        if (PyList_SetItem(ret_list, i, pl) == -1) return NULL;
        /* if (PyList_Append(ret_list, pl) == -1) return NULL; */
    }

    return ret_list;
}

PyObject *pysoc_print(PyObject *self, PyObject *args) {
    /* if (!PyArg_ParseTuple(args, "")) return NULL; */
    printf("Print from C!\n");
    return Py_None;
}

PyObject *pysoc_print_int(PyObject *self, PyObject *args) {

    /* int *i = malloc(sizeof(int)); */
    int i;

    if (!PyArg_ParseTuple(args, "i", &i)) return NULL;
    printf("Print from C! -- %i\n", i);
    /* printf("Print from C! -- %i\n", *i); */
    return Py_None;
}

PyObject *pysoc_return_1(PyObject *self, PyObject *args) { return PyLong_FromLong(1l); }

PyObject *pysoc_return_true(PyObject *self, PyObject *args) { return Py_True; }

PyObject *pysoc_raise_pysoc_error(PyObject *self, PyObject *args) {
    PyErr_SetString(PysocError, "Error from C");
    return NULL;
}

PyMODINIT_FUNC PyInit_pysoc(void) {
    PyObject *m = PyModule_Create(&pysocmodule);
    if (m == NULL) return NULL;

    PysocError = PyErr_NewException("pysoc.PysocError", NULL, NULL);
    Py_XINCREF(PysocError);
    if (PyModule_AddObject(m, "PysocError", PysocError) < 0) {
        Py_XDECREF(PysocError);
        Py_CLEAR(PysocError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
