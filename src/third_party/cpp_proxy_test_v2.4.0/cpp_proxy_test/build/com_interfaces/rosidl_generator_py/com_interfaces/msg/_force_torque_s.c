// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from com_interfaces:msg/ForceTorque.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "com_interfaces/msg/detail/force_torque__struct.h"
#include "com_interfaces/msg/detail/force_torque__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__msg__force_torque__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("com_interfaces.msg._force_torque.ForceTorque", full_classname_dest, 44) == 0);
  }
  com_interfaces__msg__ForceTorque * ros_message = _ros_message;
  {  // fx
    PyObject * field = PyObject_GetAttrString(_pymsg, "fx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fx = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fy
    PyObject * field = PyObject_GetAttrString(_pymsg, "fy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fy = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fz
    PyObject * field = PyObject_GetAttrString(_pymsg, "fz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fz = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tx
    PyObject * field = PyObject_GetAttrString(_pymsg, "tx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tx = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ty
    PyObject * field = PyObject_GetAttrString(_pymsg, "ty");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ty = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tz
    PyObject * field = PyObject_GetAttrString(_pymsg, "tz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tz = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__msg__force_torque__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ForceTorque */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.msg._force_torque");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ForceTorque");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__msg__ForceTorque * ros_message = (com_interfaces__msg__ForceTorque *)raw_ros_message;
  {  // fx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ty
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ty);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ty", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
