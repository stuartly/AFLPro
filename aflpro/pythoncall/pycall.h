//+--------------------------------------------------------------------------+
//| This file is subject to the terms and conditions defined in file         |
//| 'LICENSE.txt', which is part of this source code package.                |
//|--------------------------------------------------------------------------|
//| Copyright (c) 2017 Liang ZOU and contributors                            |
//| See the full list at https://github.com/liangdzou/pycall/contributors    |
//|--------------------------------------------------------------------------|
//| pycall.h -- a header file for pycall project                             |
//|                                                                          |
//| Author:   Liang, ZOU                                                     |
//|                                                                          |
//| Purpose:  Expose a list of APIs to users                                 |
//+--------------------------------------------------------------------------+

#include <Python.h>

PyObject * pycall(const char * py_module, const char * py_func,
                  const char * format, ...);
