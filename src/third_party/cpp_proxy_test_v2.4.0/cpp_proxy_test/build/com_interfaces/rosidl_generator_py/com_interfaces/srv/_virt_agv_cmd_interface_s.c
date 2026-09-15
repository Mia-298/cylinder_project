// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from com_interfaces:srv/VirtAgvCmdInterface.idl
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
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.h"
#include "com_interfaces/srv/detail/virt_agv_cmd_interface__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__srv__virt_agv_cmd_interface__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[71];
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
    assert(strncmp("com_interfaces.srv._virt_agv_cmd_interface.VirtAgvCmdInterface_Request", full_classname_dest, 70) == 0);
  }
  com_interfaces__srv__VirtAgvCmdInterface_Request * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // station
    PyObject * field = PyObject_GetAttrString(_pymsg, "station");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->station, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // station_list
    PyObject * field = PyObject_GetAttrString(_pymsg, "station_list");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'station_list'");
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
      if (!rosidl_runtime_c__String__Sequence__init(&(ros_message->station_list), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create String__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      rosidl_runtime_c__String * dest = ros_message->station_list.data;
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
  {  // manual_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "manual_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->manual_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // manual_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "manual_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->manual_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // manual_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "manual_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->manual_w = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // manual_duration
    PyObject * field = PyObject_GetAttrString(_pymsg, "manual_duration");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->manual_duration = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__srv__virt_agv_cmd_interface__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of VirtAgvCmdInterface_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.srv._virt_agv_cmd_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "VirtAgvCmdInterface_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__srv__VirtAgvCmdInterface_Request * ros_message = (com_interfaces__srv__VirtAgvCmdInterface_Request *)raw_ros_message;
  {  // id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // station
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->station.data,
      strlen(ros_message->station.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "station", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // station_list
    PyObject * field = NULL;
    size_t size = ros_message->station_list.size;
    rosidl_runtime_c__String * src = ros_message->station_list.data;
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
      int rc = PyObject_SetAttrString(_pymessage, "station_list", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // manual_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->manual_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "manual_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // manual_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->manual_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "manual_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // manual_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->manual_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "manual_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // manual_duration
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->manual_duration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "manual_duration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__struct.h"
// already included above
// #include "com_interfaces/srv/detail/virt_agv_cmd_interface__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "com_interfaces/msg/detail/agv_station__functions.h"
// end nested array functions include
bool com_interfaces__msg__agv_station__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * com_interfaces__msg__agv_station__convert_to_py(void * raw_ros_message);
bool com_interfaces__msg__agv_station__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * com_interfaces__msg__agv_station__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__srv__virt_agv_cmd_interface__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[72];
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
    assert(strncmp("com_interfaces.srv._virt_agv_cmd_interface.VirtAgvCmdInterface_Response", full_classname_dest, 71) == 0);
  }
  com_interfaces__srv__VirtAgvCmdInterface_Response * ros_message = _ros_message;
  {  // err_code
    PyObject * field = PyObject_GetAttrString(_pymsg, "err_code");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->err_code = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // msg
    PyObject * field = PyObject_GetAttrString(_pymsg, "msg");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->msg, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // task_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->task_status = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // task_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->task_type = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // target_station
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_station");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->target_station, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // current_station
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_station");
    if (!field) {
      return false;
    }
    if (!com_interfaces__msg__agv_station__convert_from_py(field, &ros_message->current_station)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // station_list
    PyObject * field = PyObject_GetAttrString(_pymsg, "station_list");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'station_list'");
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
    if (!com_interfaces__msg__AgvStation__Sequence__init(&(ros_message->station_list), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create com_interfaces__msg__AgvStation__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    com_interfaces__msg__AgvStation * dest = ros_message->station_list.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!com_interfaces__msg__agv_station__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__srv__virt_agv_cmd_interface__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of VirtAgvCmdInterface_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.srv._virt_agv_cmd_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "VirtAgvCmdInterface_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__srv__VirtAgvCmdInterface_Response * ros_message = (com_interfaces__srv__VirtAgvCmdInterface_Response *)raw_ros_message;
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
  {  // msg
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->msg.data,
      strlen(ros_message->msg.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "msg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->task_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // task_type
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->task_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_station
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->target_station.data,
      strlen(ros_message->target_station.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_station", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_station
    PyObject * field = NULL;
    field = com_interfaces__msg__agv_station__convert_to_py(&ros_message->current_station);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_station", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // station_list
    PyObject * field = NULL;
    size_t size = ros_message->station_list.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    com_interfaces__msg__AgvStation * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->station_list.data[i]);
      PyObject * pyitem = com_interfaces__msg__agv_station__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "station_list", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
