// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from com_interfaces:msg/AgvOrderState.idl
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
#include "com_interfaces/msg/detail/agv_order_state__struct.h"
#include "com_interfaces/msg/detail/agv_order_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__msg__agv_order_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
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
    assert(strncmp("com_interfaces.msg._agv_order_state.AgvOrderState", full_classname_dest, 49) == 0);
  }
  com_interfaces__msg__AgvOrderState * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // status
    PyObject * field = PyObject_GetAttrString(_pymsg, "status");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->status, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // actual_robot_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "actual_robot_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->actual_robot_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // current_step_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_step_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_step_index = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // done_step_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "done_step_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->done_step_index = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // step_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->step_num = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // step_locations
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_locations");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'step_locations'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__String__Sequence__init(&(ros_message->step_locations), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create String__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      rosidl_runtime_c__String * dest = ros_message->step_locations.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyUnicode_Check(item));
        PyObject * encoded_item = PyUnicode_AsUTF8String(item);
        if (!encoded_item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        rosidl_runtime_c__String__assign(&dest[i], PyBytes_AS_STRING(encoded_item));
        Py_DECREF(encoded_item);
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // container_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "container_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->container_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // loaded
    PyObject * field = PyObject_GetAttrString(_pymsg, "loaded");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->loaded = (Py_True == field);
    Py_DECREF(field);
  }
  {  // unloaded
    PyObject * field = PyObject_GetAttrString(_pymsg, "unloaded");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->unloaded = (Py_True == field);
    Py_DECREF(field);
  }
  {  // fault
    PyObject * field = PyObject_GetAttrString(_pymsg, "fault");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->fault = (Py_True == field);
    Py_DECREF(field);
  }
  {  // fault_reason
    PyObject * field = PyObject_GetAttrString(_pymsg, "fault_reason");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->fault_reason, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // execution_reject
    PyObject * field = PyObject_GetAttrString(_pymsg, "execution_reject");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->execution_reject, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__msg__agv_order_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AgvOrderState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.msg._agv_order_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AgvOrderState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__msg__AgvOrderState * ros_message = (com_interfaces__msg__AgvOrderState *)raw_ros_message;
  {  // id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->id.data,
      strlen(ros_message->id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // status
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->status.data,
      strlen(ros_message->status.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // actual_robot_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->actual_robot_name.data,
      strlen(ros_message->actual_robot_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "actual_robot_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_step_index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->current_step_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_step_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // done_step_index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->done_step_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "done_step_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_num
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->step_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_locations
    PyObject * field = NULL;
    size_t size = ros_message->step_locations.size;
    rosidl_runtime_c__String * src = ros_message->step_locations.data;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      PyObject * decoded_item = PyUnicode_DecodeUTF8(src[i].data, strlen(src[i].data), "replace");
      if (!decoded_item) {
        return NULL;
      }
      int rc = PyList_SetItem(field, i, decoded_item);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_locations", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // container_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->container_id.data,
      strlen(ros_message->container_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "container_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // loaded
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->loaded ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "loaded", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // unloaded
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->unloaded ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "unloaded", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fault
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->fault ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fault", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fault_reason
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->fault_reason.data,
      strlen(ros_message->fault_reason.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "fault_reason", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // execution_reject
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->execution_reject.data,
      strlen(ros_message->execution_reject.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "execution_reject", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
