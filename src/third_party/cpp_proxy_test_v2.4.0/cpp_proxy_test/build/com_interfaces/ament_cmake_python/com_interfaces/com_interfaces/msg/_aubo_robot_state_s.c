// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from com_interfaces:msg/AuboRobotState.idl
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
#include "com_interfaces/msg/detail/aubo_robot_state__struct.h"
#include "com_interfaces/msg/detail/aubo_robot_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__msg__aubo_robot_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
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
    assert(strncmp("com_interfaces.msg._aubo_robot_state.AuboRobotState", full_classname_dest, 51) == 0);
  }
  com_interfaces__msg__AuboRobotState * ros_message = _ros_message;
  {  // robot_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->robot_index = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // robot_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->robot_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // robot_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->robot_type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // robot_soft_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_soft_index");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->robot_soft_index, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // robot_ip
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_ip");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->robot_ip, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // mode_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode_type = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // safety_mode_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "safety_mode_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->safety_mode_type = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // robot_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->robot_speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // jt_cur_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "jt_cur_pos");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 6;
      double * dest = ros_message->jt_cur_pos;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // tl_cur_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "tl_cur_pos");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 6;
      double * dest = ros_message->tl_cur_pos;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__msg__aubo_robot_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AuboRobotState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.msg._aubo_robot_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AuboRobotState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__msg__AuboRobotState * ros_message = (com_interfaces__msg__AuboRobotState *)raw_ros_message;
  {  // robot_index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->robot_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->robot_name.data,
      strlen(ros_message->robot_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->robot_type.data,
      strlen(ros_message->robot_type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_soft_index
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->robot_soft_index.data,
      strlen(ros_message->robot_soft_index.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_soft_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_ip
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->robot_ip.data,
      strlen(ros_message->robot_ip.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_ip", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode_type
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->mode_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // safety_mode_type
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->safety_mode_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "safety_mode_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->robot_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // jt_cur_pos
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "jt_cur_pos");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->jt_cur_pos[0]);
    memcpy(dst, src, 6 * sizeof(double));
    Py_DECREF(field);
  }
  {  // tl_cur_pos
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "tl_cur_pos");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->tl_cur_pos[0]);
    memcpy(dst, src, 6 * sizeof(double));
    Py_DECREF(field);
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
