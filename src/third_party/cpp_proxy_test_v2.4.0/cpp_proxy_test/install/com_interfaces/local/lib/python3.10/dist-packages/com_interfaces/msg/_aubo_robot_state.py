# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:msg/AuboRobotState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'jt_cur_pos'
# Member 'tl_cur_pos'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AuboRobotState(type):
    """Metaclass of message 'AuboRobotState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('com_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'com_interfaces.msg.AuboRobotState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__aubo_robot_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__aubo_robot_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__aubo_robot_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__aubo_robot_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__aubo_robot_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AuboRobotState(metaclass=Metaclass_AuboRobotState):
    """Message class 'AuboRobotState'."""

    __slots__ = [
        '_robot_index',
        '_robot_name',
        '_robot_type',
        '_robot_soft_index',
        '_robot_ip',
        '_mode_type',
        '_safety_mode_type',
        '_robot_speed',
        '_jt_cur_pos',
        '_tl_cur_pos',
    ]

    _fields_and_field_types = {
        'robot_index': 'int32',
        'robot_name': 'string',
        'robot_type': 'string',
        'robot_soft_index': 'string',
        'robot_ip': 'string',
        'mode_type': 'int32',
        'safety_mode_type': 'int32',
        'robot_speed': 'double',
        'jt_cur_pos': 'double[6]',
        'tl_cur_pos': 'double[6]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_index = kwargs.get('robot_index', int())
        self.robot_name = kwargs.get('robot_name', str())
        self.robot_type = kwargs.get('robot_type', str())
        self.robot_soft_index = kwargs.get('robot_soft_index', str())
        self.robot_ip = kwargs.get('robot_ip', str())
        self.mode_type = kwargs.get('mode_type', int())
        self.safety_mode_type = kwargs.get('safety_mode_type', int())
        self.robot_speed = kwargs.get('robot_speed', float())
        if 'jt_cur_pos' not in kwargs:
            self.jt_cur_pos = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.jt_cur_pos = kwargs.get('jt_cur_pos')
        if 'tl_cur_pos' not in kwargs:
            self.tl_cur_pos = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.tl_cur_pos = kwargs.get('tl_cur_pos')

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.robot_index != other.robot_index:
            return False
        if self.robot_name != other.robot_name:
            return False
        if self.robot_type != other.robot_type:
            return False
        if self.robot_soft_index != other.robot_soft_index:
            return False
        if self.robot_ip != other.robot_ip:
            return False
        if self.mode_type != other.mode_type:
            return False
        if self.safety_mode_type != other.safety_mode_type:
            return False
        if self.robot_speed != other.robot_speed:
            return False
        if any(self.jt_cur_pos != other.jt_cur_pos):
            return False
        if any(self.tl_cur_pos != other.tl_cur_pos):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_index(self):
        """Message field 'robot_index'."""
        return self._robot_index

    @robot_index.setter
    def robot_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'robot_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'robot_index' field must be an integer in [-2147483648, 2147483647]"
        self._robot_index = value

    @builtins.property
    def robot_name(self):
        """Message field 'robot_name'."""
        return self._robot_name

    @robot_name.setter
    def robot_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot_name' field must be of type 'str'"
        self._robot_name = value

    @builtins.property
    def robot_type(self):
        """Message field 'robot_type'."""
        return self._robot_type

    @robot_type.setter
    def robot_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot_type' field must be of type 'str'"
        self._robot_type = value

    @builtins.property
    def robot_soft_index(self):
        """Message field 'robot_soft_index'."""
        return self._robot_soft_index

    @robot_soft_index.setter
    def robot_soft_index(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot_soft_index' field must be of type 'str'"
        self._robot_soft_index = value

    @builtins.property
    def robot_ip(self):
        """Message field 'robot_ip'."""
        return self._robot_ip

    @robot_ip.setter
    def robot_ip(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot_ip' field must be of type 'str'"
        self._robot_ip = value

    @builtins.property
    def mode_type(self):
        """Message field 'mode_type'."""
        return self._mode_type

    @mode_type.setter
    def mode_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode_type' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mode_type' field must be an integer in [-2147483648, 2147483647]"
        self._mode_type = value

    @builtins.property
    def safety_mode_type(self):
        """Message field 'safety_mode_type'."""
        return self._safety_mode_type

    @safety_mode_type.setter
    def safety_mode_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'safety_mode_type' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'safety_mode_type' field must be an integer in [-2147483648, 2147483647]"
        self._safety_mode_type = value

    @builtins.property
    def robot_speed(self):
        """Message field 'robot_speed'."""
        return self._robot_speed

    @robot_speed.setter
    def robot_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'robot_speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'robot_speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._robot_speed = value

    @builtins.property
    def jt_cur_pos(self):
        """Message field 'jt_cur_pos'."""
        return self._jt_cur_pos

    @jt_cur_pos.setter
    def jt_cur_pos(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'jt_cur_pos' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'jt_cur_pos' numpy.ndarray() must have a size of 6"
            self._jt_cur_pos = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 6 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'jt_cur_pos' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._jt_cur_pos = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tl_cur_pos(self):
        """Message field 'tl_cur_pos'."""
        return self._tl_cur_pos

    @tl_cur_pos.setter
    def tl_cur_pos(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'tl_cur_pos' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'tl_cur_pos' numpy.ndarray() must have a size of 6"
            self._tl_cur_pos = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 6 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'tl_cur_pos' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._tl_cur_pos = numpy.array(value, dtype=numpy.float64)
