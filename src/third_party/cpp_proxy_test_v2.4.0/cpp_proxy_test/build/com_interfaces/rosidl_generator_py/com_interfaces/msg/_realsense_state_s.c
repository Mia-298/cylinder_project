// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from com_interfaces:msg/RealsenseState.idl
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
#include "com_interfaces/msg/detail/realsense_state__struct.h"
#include "com_interfaces/msg/detail/realsense_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__msg__realsense_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[51];
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
    assert(strncmp("com_interfaces.msg._realsense_state.RealsenseState", full_classname_dest, 50) == 0);
  }
  com_interfaces__msg__RealsenseState * ros_message = _ros_message;
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // err_code
    PyObject * field = PyObject_GetAttrString(_pymsg, "err_code");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->err_code = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // err_msg
    PyObject * field = PyObject_GetAttrString(_pymsg, "err_msg");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->err_msg, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // node_online
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_online");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->node_online = (Py_True == field);
    Py_DECREF(field);
  }
  {  // color_ready
    PyObject * field = PyObject_GetAttrString(_pymsg, "color_ready");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->color_ready = (Py_True == field);
    Py_DECREF(field);
  }
  {  // depth_ready
    PyObject * field = PyObject_GetAttrString(_pymsg, "depth_ready");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->depth_ready = (Py_True == field);
    Py_DECREF(field);
  }
  {  // aligned_depth_ready
    PyObject * field = PyObject_GetAttrString(_pymsg, "aligned_depth_ready");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->aligned_depth_ready = (Py_True == field);
    Py_DECREF(field);
  }
  {  // color_info_ready
    PyObject * field = PyObject_GetAttrString(_pymsg, "color_info_ready");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->color_info_ready = (Py_True == field);
    Py_DECREF(field);
  }
  {  // depth_info_ready
    PyObject * field = PyObject_GetAttrString(_pymsg, "depth_info_ready");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->depth_info_ready = (Py_True == field);
    Py_DECREF(field);
  }
  {  // color_topic
    PyObject * field = PyObject_GetAttrString(_pymsg, "color_topic");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->color_topic, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // depth_topic
    PyObject * field = PyObject_GetAttrString(_pymsg, "depth_topic");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->depth_topic, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // aligned_depth_topic
    PyObject * field = PyObject_GetAttrString(_pymsg, "aligned_depth_topic");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->aligned_depth_topic, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // color_info_topic
    PyObject * field = PyObject_GetAttrString(_pymsg, "color_info_topic");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->color_info_topic, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // depth_info_topic
    PyObject * field = PyObject_GetAttrString(_pymsg, "depth_info_topic");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->depth_info_topic, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // last_color_ts_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_color_ts_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->last_color_ts_ms = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // last_depth_ts_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_depth_ts_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->last_depth_ts_ms = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // last_aligned_depth_ts_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_aligned_depth_ts_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->last_aligned_depth_ts_ms = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // last_color_info_ts_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_color_info_ts_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->last_color_info_ts_ms = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // last_depth_info_ts_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_depth_info_ts_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->last_depth_info_ts_ms = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__msg__realsense_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RealsenseState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.msg._realsense_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RealsenseState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__msg__RealsenseState * ros_message = (com_interfaces__msg__RealsenseState *)raw_ros_message;
  {  // name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->name.data,
      strlen(ros_message->name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // err_code
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->err_code);
    {
      int rc = PyObject_SetAttrString(_pymessage, "err_code", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // err_msg
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->err_msg.data,
      strlen(ros_message->err_msg.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "err_msg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // node_online
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->node_online ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_online", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // color_ready
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->color_ready ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "color_ready", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // depth_ready
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->depth_ready ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "depth_ready", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aligned_depth_ready
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->aligned_depth_ready ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "aligned_depth_ready", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // color_info_ready
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->color_info_ready ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "color_info_ready", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // depth_info_ready
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->depth_info_ready ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "depth_info_ready", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // color_topic
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->color_topic.data,
      strlen(ros_message->color_topic.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "color_topic", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // depth_topic
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->depth_topic.data,
      strlen(ros_message->depth_topic.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "depth_topic", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // aligned_depth_topic
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->aligned_depth_topic.data,
      strlen(ros_message->aligned_depth_topic.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "aligned_depth_topic", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // color_info_topic
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->color_info_topic.data,
      strlen(ros_message->color_info_topic.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "color_info_topic", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // depth_info_topic
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->depth_info_topic.data,
      strlen(ros_message->depth_info_topic.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "depth_info_topic", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_color_ts_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->last_color_ts_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_color_ts_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_depth_ts_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->last_depth_ts_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_depth_ts_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_aligned_depth_ts_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->last_aligned_depth_ts_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_aligned_depth_ts_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_color_info_ts_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->last_color_info_ts_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_color_info_ts_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_depth_info_ts_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->last_depth_info_ts_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_depth_info_ts_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
