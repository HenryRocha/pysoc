#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *PysocError;
PyObject *pysoc_bubble_sort(PyObject *self, PyObject *args);
PyObject *pysoc_print_int(PyObject *self, PyObject *args);
PyObject *pysoc_print(PyObject *self, PyObject *args);
PyObject *pysoc_return_1(PyObject *self, PyObject *args);
PyObject *pysoc_return_true(PyObject *self, PyObject *args);
PyObject *pysoc_raise_pysoc_error(PyObject *self, PyObject *args);

static PyMethodDef PysocMethods[] = {
    {"bubble_sort", pysoc_bubble_sort, METH_VARARGS, "Bubble sort in c"},
    {"print", pysoc_print, METH_NOARGS, "Print from c"},
    {"print_int", pysoc_print_int, METH_VARARGS, "Print integer from c"},
    {"return_1", pysoc_return_1, METH_NOARGS, "Returns 1"},
    {"return_true", pysoc_return_true, METH_NOARGS, "Returns True"},
    {"raise_pysoc_error", pysoc_raise_pysoc_error, METH_NOARGS, "Raises PysocError"},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef pysocmodule = {PyModuleDef_HEAD_INIT, "pysoc", /* name of module */
                                         NULL, /* module documentation, may be NULL */
                                         -1,   /* size of per-interpreter state of the module, or -1
                                                  if the module keeps state in global variables. */
                                         PysocMethods};
