#include <Python.h>
 
static PyObject* copy_to_py_list(const int *arr, int n)
{
    PyObject *plist, *pitem;

    plist = PyList_New(n);
    if (!plist)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        pitem = PyLong_FromLong(arr[i]);
        if (!pitem)
        {
            Py_DECREF(plist);
            return NULL;
        }        

        PyList_SET_ITEM(plist, i, pitem);
    }

    return plist;
}
 
PyObject* fibon(PyObject *self, PyObject *args)
{
    PyObject *plist;
    int n;
    if (!PyArg_ParseTuple(args,"i", &n))
        return NULL;
    int *pbuf = malloc(n * sizeof(int));
    if (!pbuf)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            pbuf[i] = 0;
        if (i == 1)
            pbuf[i] = 1;
        if (i > 1)
            pbuf[i] = pbuf[i - 1] + pbuf[i - 2];
    }
    
    plist = copy_to_py_list(pbuf, n);
    free(pbuf);
       
    return plist;
}

PyObject* move_elements(PyObject *self, PyObject *args)
{
    PyObject *plist, *iterator, *item;
    PyObject *arr1;
    int i, n, bad_data;
    
    if (!PyArg_ParseTuple(args, "O", &arr1))
        return NULL;

    iterator = PyObject_GetIter(arr1);
    if (!iterator)
    {
        PyErr_SetString(PyExc_TypeError, "Cant get iterator");

        return NULL;
    }

    n = 0;
    bad_data = 0;
    while ((item = PyIter_Next(iterator)) && !bad_data)
    {
        if (!PyFloat_Check(item) && !PyLong_Check(item))
        {
            bad_data = 1;
        }
        else
        {
            n++;
        }

        Py_DECREF(item);
    }

    Py_DECREF(iterator);

    if (bad_data)
    {
        Py_DECREF(arr1);

        PyErr_SetString(PyExc_TypeError, "Bad arguments (only numbers are required)");

        return NULL;
    }

    int *arr1_1 = calloc(n,sizeof(int));
    if (!arr1_1)
        return NULL;
    iterator = PyObject_GetIter(arr1);

    i = 0;
    while ((item = PyIter_Next(iterator)))
    {
        arr1_1[i] = PyLong_AsLong(item);
        i++;
        Py_DECREF(item);
    }
    
    int *arr2 = calloc(n,sizeof(int));
    if (!arr2)
        return NULL;
    
    int counter = 0;
    int flag;
    for(int i = 0; i < n; i++)
    {
        flag = 1;
        for(int j = 0; j < counter; j++)
        {
            if (arr2[j] == arr1_1[i])
            {
                flag = 0;
                break;
            }                
        }
        if (flag)
        {
            arr2[counter] = arr1_1[i];
            counter++;
        }
    }
    
    plist = copy_to_py_list(arr2, n);
    free(arr1_1);
    free(arr2);
       
    return plist;
}

 
static PyMethodDef func_methods[] = 
{
    { "fibon", fibon, METH_VARARGS, "fibon(who) -- return \"Hello who\"" },
    { "move_elements", move_elements, METH_VARARGS, "move_elements(who) -- return \"Hello who\"" },
    { NULL, 0, 0, NULL }
};
 
 
static struct PyModuleDef func_module = 
{
    PyModuleDef_HEAD_INIT,
    "func",
    NULL,
    -1,
    func_methods
};
 
PyMODINIT_FUNC PyInit_func(void)
{
    return PyModule_Create(&func_module);
}