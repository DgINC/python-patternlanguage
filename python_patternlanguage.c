#include <Python.h>

/*
 * Implements an example function.
 */
PyDoc_STRVAR(python_patternlanguage_example_doc, "example(obj, number)\
\
Example function");

PyObject *python_patternlanguage_example(PyObject *self, PyObject *args, PyObject *kwargs) {
    /* Shared references that do not need Py_DECREF before returning. */
    PyObject *obj = NULL;
    int number = 0;

    /* Parse positional and keyword arguments */
    static char* keywords[] = { "obj", "number", NULL };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "Oi", keywords, &obj, &number)) {
        return NULL;
    }

    /* Function implementation starts here */

    if (number < 0) {
        PyErr_SetObject(PyExc_ValueError, obj);
        return NULL;    /* return NULL indicates error */
    }

    Py_RETURN_NONE;
}

/*
 * List of functions to add to python_patternlanguage in exec_python_patternlanguage().
 */
static PyMethodDef python_patternlanguage_functions[] = {
    { "example", (PyCFunction)python_patternlanguage_example, METH_VARARGS | METH_KEYWORDS, python_patternlanguage_example_doc },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize python_patternlanguage. May be called multiple times, so avoid
 * using static state.
 */
int exec_python_patternlanguage(PyObject *module) {
    PyModule_AddFunctions(module, python_patternlanguage_functions);

    PyModule_AddStringConstant(module, "__author__", "dginc");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2023);

    return 0; /* success */
}

/*
 * Documentation for python_patternlanguage.
 */
PyDoc_STRVAR(python_patternlanguage_doc, "The python_patternlanguage module");


static PyModuleDef_Slot python_patternlanguage_slots[] = {
    { Py_mod_exec, exec_python_patternlanguage },
    { 0, NULL }
};

static PyModuleDef python_patternlanguage_def = {
    PyModuleDef_HEAD_INIT,
    "python_patternlanguage",
    python_patternlanguage_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    python_patternlanguage_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_python_patternlanguage() {
    return PyModuleDef_Init(&python_patternlanguage_def);
}
