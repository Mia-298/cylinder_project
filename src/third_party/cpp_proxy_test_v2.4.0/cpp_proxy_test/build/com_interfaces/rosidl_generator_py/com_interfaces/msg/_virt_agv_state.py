# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:msg/VirtAgvState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VirtAgvState(type):
    """Metaclass of message 'VirtAgvState'."""

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
                'com_interfaces.msg.VirtAgvState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__virt_agv_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__virt_agv_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__virt_agv_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__virt_agv_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__virt_agv_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VirtAgvState(metaclass=Metaclass_VirtAgvState):
    """Message class 'VirtAgvState'."""

    __slots__ = [
        '_name',
        '_err_code',
        '_err_msg',
        '_pose_x',
        '_pose_y',
        '_angle',
        '_confidence',
        '_current_station',
        '_last_station',
        '_vel_x',
        '_vel_y',
        '_vel_ang',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'err_code': 'int32',
        'err_msg': 'string',
        'pose_x': 'double',
        'pose_y': 'double',
        'angle': 'double',
        'confidence': 'double',
        'current_station': 'string',
        'last_station': 'string',
        'vel_x': 'double',
        'vel_y': 'double',
        'vel_ang': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.err_code = kwargs.get('err_code', int())
        self.err_msg = kwargs.get('err_msg', str())
        self.pose_x = kwargs.get('pose_x', float())
        self.pose_y = kwargs.get('pose_y', float())
        self.angle = kwargs.get('angle', float())
        self.confidence = kwargs.get('confidence', float())
        self.current_station = kwargs.get('current_station', str())
        self.last_station = kwargs.get('last_station', str())
        self.vel_x = kwargs.get('vel_x', float())
        self.vel_y = kwargs.get('vel_y', float())
        self.vel_ang = kwargs.get('vel_ang', float())

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
        if self.name != other.name:
            return False
        if self.err_code != other.err_code:
            return False
        if self.err_msg != other.err_msg:
            return False
        if self.pose_x != other.pose_x:
            return False
        if self.pose_y != other.pose_y:
            return False
        if self.angle != other.angle:
            return False
        if self.confidence != other.confidence:
            return False
        if self.current_station != other.current_station:
            return False
        if self.last_station != other.last_station:
            return False
        if self.vel_x != other.vel_x:
            return False
        if self.vel_y != other.vel_y:
            return False
        if self.vel_ang != other.vel_ang:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def err_code(self):
        """Message field 'err_code'."""
        return self._err_code

    @err_code.setter
    def err_code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'err_code' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'err_code' field must be an integer in [-2147483648, 2147483647]"
        self._err_code = value

    @builtins.property
    def err_msg(self):
        """Message field 'err_msg'."""
        return self._err_msg

    @err_msg.setter
    def err_msg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'err_msg' field must be of type 'str'"
        self._err_msg = value

    @builtins.property
    def pose_x(self):
        """Message field 'pose_x'."""
        return self._pose_x

    @pose_x.setter
    def pose_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pose_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pose_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pose_x = value

    @builtins.property
    def pose_y(self):
        """Message field 'pose_y'."""
        return self._pose_y

    @pose_y.setter
    def pose_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pose_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pose_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pose_y = value

    @builtins.property
    def angle(self):
        """Message field 'angle'."""
        return self._angle

    @angle.setter
    def angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._angle = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'confidence' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._confidence = value

    @builtins.property
    def current_station(self):
        """Message field 'current_station'."""
        return self._current_station

    @current_station.setter
    def current_station(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'current_station' field must be of type 'str'"
        self._current_station = value

    @builtins.property
    def last_station(self):
        """Message field 'last_station'."""
        return self._last_station

    @last_station.setter
    def last_station(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'last_station' field must be of type 'str'"
        self._last_station = value

    @builtins.property
    def vel_x(self):
        """Message field 'vel_x'."""
        return self._vel_x

    @vel_x.setter
    def vel_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_x = value

    @builtins.property
    def vel_y(self):
        """Message field 'vel_y'."""
        return self._vel_y

    @vel_y.setter
    def vel_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_y = value

    @builtins.property
    def vel_ang(self):
        """Message field 'vel_ang'."""
        return self._vel_ang

    @vel_ang.setter
    def vel_ang(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_ang' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_ang' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_ang = value
