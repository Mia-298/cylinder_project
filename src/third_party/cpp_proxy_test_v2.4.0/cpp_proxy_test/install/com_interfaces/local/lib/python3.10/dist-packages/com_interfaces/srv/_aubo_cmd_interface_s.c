// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from com_interfaces:srv/AuboCmdInterface.idl
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
#include "com_interfaces/srv/detail/aubo_cmd_interface__struct.h"
#include "com_interfaces/srv/detail/aubo_cmd_interface__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

// Nested array functions includes
#include "com_interfaces/msg/detail/joint_point__functions.h"
// end nested array functions include
bool com_interfaces__msg__joint_point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * com_interfaces__msg__joint_point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__srv__aubo_cmd_interface__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
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
    assert(strncmp("com_interfaces.srv._aubo_cmd_interface.AuboCmdInterface_Request", full_classname_dest, 63) == 0);
  }
  com_interfaces__srv__AuboCmdInterface_Request * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // en
    PyObject * field = PyObject_GetAttrString(_pymsg, "en");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->en = (Py_True == field);
    Py_DECREF(field);
  }
  {  // joint_or_desc
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_or_desc");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->joint_or_desc = (Py_True == field);
    Py_DECREF(field);
  }
  {  // position
    PyObject * field = PyObject_GetAttrString(_pymsg, "position");
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
      double * dest = ros_message->position;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // axid
    PyObject * field = PyObject_GetAttrString(_pymsg, "axid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->axid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dir
    PyObject * field = PyObject_GetAttrString(_pymsg, "dir");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dir = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // deg
    PyObject * field = PyObject_GetAttrString(_pymsg, "deg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->deg = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "acc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->acc = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tool
    PyObject * field = PyObject_GetAttrString(_pymsg, "tool");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tool = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // register_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "register_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->register_index = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // register_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "register_value");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->register_value = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // input_or_output
    PyObject * field = PyObject_GetAttrString(_pymsg, "input_or_output");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->input_or_output = (Py_True == field);
    Py_DECREF(field);
  }
  {  // io_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "io_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->io_index = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // io_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "io_value");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->io_value = (Py_True == field);
    Py_DECREF(field);
  }
  {  // program
    PyObject * field = PyObject_GetAttrString(_pymsg, "program");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->program, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // interval
    PyObject * field = PyObject_GetAttrString(_pymsg, "interval");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->interval = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // filename
    PyObject * field = PyObject_GetAttrString(_pymsg, "filename");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->filename, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // joint_path
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_path");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'joint_path'");
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
    if (!com_interfaces__msg__JointPoint__Sequence__init(&(ros_message->joint_path), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create com_interfaces__msg__JointPoint__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    com_interfaces__msg__JointPoint * dest = ros_message->joint_path.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!com_interfaces__msg__joint_point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // gripper_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_index = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // act
    PyObject * field = PyObject_GetAttrString(_pymsg, "act");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->act = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gripper_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_pos");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_pos = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gripper_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_vel");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_vel = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gripper_force
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_force");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_force = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // max_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_time = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // gripper_block
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_block");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_block = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__srv__aubo_cmd_interface__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AuboCmdInterface_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.srv._aubo_cmd_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AuboCmdInterface_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__srv__AuboCmdInterface_Request * ros_message = (com_interfaces__srv__AuboCmdInterface_Request *)raw_ros_message;
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
  {  // en
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->en ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "en", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_or_desc
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->joint_or_desc ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "joint_or_desc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "position");
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
    double * src = &(ros_message->position[0]);
    memcpy(dst, src, 6 * sizeof(double));
    Py_DECREF(field);
  }
  {  // axid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->axid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "axid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dir
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dir);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dir", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // deg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->deg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "deg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // acc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->acc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "acc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tool
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->tool);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tool", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // register_index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->register_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "register_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // register_value
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->register_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "register_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // input_or_output
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->input_or_output ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "input_or_output", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // io_index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->io_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "io_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // io_value
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->io_value ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "io_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // program
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->program.data,
      strlen(ros_message->program.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "program", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // interval
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->interval);
    {
      int rc = PyObject_SetAttrString(_pymessage, "interval", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // filename
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->filename.data,
      strlen(ros_message->filename.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "filename", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_path
    PyObject * field = NULL;
    size_t size = ros_message->joint_path.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    com_interfaces__msg__JointPoint * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->joint_path.data[i]);
      PyObject * pyitem = com_interfaces__msg__joint_point__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "joint_path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gripper_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // act
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->act);
    {
      int rc = PyObject_SetAttrString(_pymessage, "act", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_pos
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gripper_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_vel
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gripper_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_force
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->gripper_force);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_force", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_time
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->max_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_block
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gripper_block);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_block", field);
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
// #include "com_interfaces/srv/detail/aubo_cmd_interface__struct.h"
// already included above
// #include "com_interfaces/srv/detail/aubo_cmd_interface__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

bool com_interfaces__msg__aubo_robot_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * com_interfaces__msg__aubo_robot_state__convert_to_py(void * raw_ros_message);
bool com_interfaces__msg__force_torque__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * com_interfaces__msg__force_torque__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool com_interfaces__srv__aubo_cmd_interface__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
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
    assert(strncmp("com_interfaces.srv._aubo_cmd_interface.AuboCmdInterface_Response", full_classname_dest, 64) == 0);
  }
  com_interfaces__srv__AuboCmdInterface_Response * ros_message = _ros_message;
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
  {  // pub_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "pub_state");
    if (!field) {
      return false;
    }
    if (!com_interfaces__msg__aubo_robot_state__convert_from_py(field, &ros_message->pub_state)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // register_val
    PyObject * field = PyObject_GetAttrString(_pymsg, "register_val");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->register_val = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // io_val
    PyObject * field = PyObject_GetAttrString(_pymsg, "io_val");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->io_val = (Py_True == field);
    Py_DECREF(field);
  }
  {  // jt_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "jt_pos");
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
      double * dest = ros_message->jt_pos;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // tl_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "tl_pos");
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
      double * dest = ros_message->tl_pos;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // ft
    PyObject * field = PyObject_GetAttrString(_pymsg, "ft");
    if (!field) {
      return false;
    }
    if (!com_interfaces__msg__force_torque__convert_from_py(field, &ros_message->ft)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * com_interfaces__srv__aubo_cmd_interface__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AuboCmdInterface_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("com_interfaces.srv._aubo_cmd_interface");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AuboCmdInterface_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  com_interfaces__srv__AuboCmdInterface_Response * ros_message = (com_interfaces__srv__AuboCmdInterface_Response *)raw_ros_message;
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
  {  // pub_state
    PyObject * field = NULL;
    field = com_interfaces__msg__aubo_robot_state__convert_to_py(&ros_message->pub_state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pub_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // register_val
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->register_val);
    {
      int rc = PyObject_SetAttrString(_pymessage, "register_val", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // io_val
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->io_val ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "io_val", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // jt_pos
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "jt_pos");
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
    double * src = &(ros_message->jt_pos[0]);
    memcpy(dst, src, 6 * sizeof(double));
    Py_DECREF(field);
  }
  {  // tl_pos
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "tl_pos");
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
    double * src = &(ros_message->tl_pos[0]);
    memcpy(dst, src, 6 * sizeof(double));
    Py_DECREF(field);
  }
  {  // ft
    PyObject * field = NULL;
    field = com_interfaces__msg__force_torque__convert_to_py(&ros_message->ft);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "ft", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
