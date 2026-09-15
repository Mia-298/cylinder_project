// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from com_interfaces:msg/SeerCtrlState.idl
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
#include "com_interfaces/msg/detail/seer_ctrl_state__struct.h"
#include "com_interfaces/msg/detail/seer_ctrl_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

bool com_interfaces__msg__agv_guide_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * com_interfaces__msg__agv_guide_state__convert_to_py(void * raw_ros_message);
bool com_interfaces__msg__agv_control__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * com_interfaces__msg__agv_control__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__msg__seer_ctrl_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("com_interfaces.msg._seer_ctrl_state.SeerCtrlState", full_classname_dest, 49) == 0);
  }
  com_interfaces__msg__SeerCtrlState * ros_message = _ros_message;
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
  {  // pose_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pose_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pose_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pose_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // confidence
    PyObject * field = PyObject_GetAttrString(_pymsg, "confidence");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->confidence = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_station
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_station");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->current_station, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // last_station
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_station");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->last_station, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // vel_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_ang
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_ang");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_ang = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // battery_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_level");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->battery_level = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // battery_temp
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_temp");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->battery_temp = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // charging
    PyObject * field = PyObject_GetAttrString(_pymsg, "charging");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->charging = (Py_True == field);
    Py_DECREF(field);
  }
  {  // voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->voltage = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current
    PyObject * field = PyObject_GetAttrString(_pymsg, "current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_charge_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_charge_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_charge_voltage = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_charge_current
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_charge_current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_charge_current = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // manual_charge
    PyObject * field = PyObject_GetAttrString(_pymsg, "manual_charge");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->manual_charge = (Py_True == field);
    Py_DECREF(field);
  }
  {  // auto_charge
    PyObject * field = PyObject_GetAttrString(_pymsg, "auto_charge");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->auto_charge = (Py_True == field);
    Py_DECREF(field);
  }
  {  // battery_cycle
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_cycle");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->battery_cycle = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // battery_user_data
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_user_data");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->battery_user_data, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // guide_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "guide_state");
    if (!field) {
      return false;
    }
    if (!com_interfaces__msg__agv_guide_state__convert_from_py(field, &ros_message->guide_state)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // control
    PyObject * field = PyObject_GetAttrString(_pymsg, "control");
    if (!field) {
      return false;
    }
    if (!com_interfaces__msg__agv_control__convert_from_py(field, &ros_message->control)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__msg__seer_ctrl_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SeerCtrlState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.msg._seer_ctrl_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SeerCtrlState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__msg__SeerCtrlState * ros_message = (com_interfaces__msg__SeerCtrlState *)raw_ros_message;
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
  {  // pose_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pose_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pose_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // confidence
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->confidence);
    {
      int rc = PyObject_SetAttrString(_pymessage, "confidence", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_station
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->current_station.data,
      strlen(ros_message->current_station.data),
      "replace");
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
  {  // last_station
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->last_station.data,
      strlen(ros_message->last_station.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_station", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_ang
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_ang);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_ang", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_level
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->battery_level);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_temp
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->battery_temp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_temp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // charging
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->charging ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "charging", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_charge_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_charge_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_charge_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_charge_current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_charge_current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_charge_current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // manual_charge
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->manual_charge ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "manual_charge", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // auto_charge
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->auto_charge ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "auto_charge", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_cycle
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->battery_cycle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_cycle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_user_data
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->battery_user_data.data,
      strlen(ros_message->battery_user_data.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_user_data", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // guide_state
    PyObject * field = NULL;
    field = com_interfaces__msg__agv_guide_state__convert_to_py(&ros_message->guide_state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "guide_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // control
    PyObject * field = NULL;
    field = com_interfaces__msg__agv_control__convert_to_py(&ros_message->control);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "control", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
