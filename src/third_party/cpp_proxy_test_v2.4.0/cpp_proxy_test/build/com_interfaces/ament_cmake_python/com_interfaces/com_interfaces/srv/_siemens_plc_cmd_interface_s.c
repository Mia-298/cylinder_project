// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from com_interfaces:srv/SiemensPlcCmdInterface.idl
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
#include "com_interfaces/srv/detail/siemens_plc_cmd_interface__struct.h"
#include "com_interfaces/srv/detail/siemens_plc_cmd_interface__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__srv__siemens_plc_cmd_interface__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[77];
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
    assert(strncmp("com_interfaces.srv._siemens_plc_cmd_interface.SiemensPlcCmdInterface_Request", full_classname_dest, 76) == 0);
  }
  com_interfaces__srv__SiemensPlcCmdInterface_Request * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pin
    PyObject * field = PyObject_GetAttrString(_pymsg, "pin");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pin = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dpin_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "dpin_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dpin_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__srv__siemens_plc_cmd_interface__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SiemensPlcCmdInterface_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.srv._siemens_plc_cmd_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SiemensPlcCmdInterface_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__srv__SiemensPlcCmdInterface_Request * ros_message = (com_interfaces__srv__SiemensPlcCmdInterface_Request *)raw_ros_message;
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
  {  // pin
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dpin_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dpin_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dpin_state", field);
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
// #include "com_interfaces/srv/detail/siemens_plc_cmd_interface__struct.h"
// already included above
// #include "com_interfaces/srv/detail/siemens_plc_cmd_interface__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__srv__siemens_plc_cmd_interface__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[78];
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
    assert(strncmp("com_interfaces.srv._siemens_plc_cmd_interface.SiemensPlcCmdInterface_Response", full_classname_dest, 77) == 0);
  }
  com_interfaces__srv__SiemensPlcCmdInterface_Response * ros_message = _ros_message;
  {  // dpin_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "dpin_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dpin_state = (uint8_t)PyLong_AsUnsignedLong(field);
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__srv__siemens_plc_cmd_interface__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SiemensPlcCmdInterface_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.srv._siemens_plc_cmd_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SiemensPlcCmdInterface_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__srv__SiemensPlcCmdInterface_Response * ros_message = (com_interfaces__srv__SiemensPlcCmdInterface_Response *)raw_ros_message;
  {  // dpin_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dpin_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dpin_state", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
