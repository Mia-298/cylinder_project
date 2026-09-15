# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:msg/AgvLoc.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AgvLoc(type):
    """Metaclass of message 'AgvLoc'."""

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
                'com_interfaces.msg.AgvLoc')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__agv_loc
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__agv_loc
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__agv_loc
            cls._TYPE_SUPPORT = module.type_support_msg__msg__agv_loc
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__agv_loc

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AgvLoc(metaclass=Metaclass_AgvLoc):
    """Message class 'AgvLoc'."""

    __slots__ = [
        '_x',
        '_y',
        '_angle',
        '_confidence',
        '_current_station',
        '_last_station',
        '_loc_method',
    ]

    _fields_and_field_types = {
        'x': 'double',
        'y': 'double',
        'angle': 'double',
        'confidence': 'double',
        'current_station': 'string',
        'last_station': 'string',
        'loc_method': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.angle = kwargs.get('angle', float())
        self.confidence = kwargs.get('confidence', float())
        self.current_station = kwargs.get('current_station', str())
        self.last_station = kwargs.get('last_station', str())
        self.loc_method = kwargs.get('loc_method', int())

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
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.angle != other.angle:
            return False
        if self.confidence != other.confidence:
            return False
        if self.current_station != other.current_station:
            return False
        if self.last_station != other.last_station:
            return False
        if self.loc_method != other.loc_method:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

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
    def loc_method(self):
        """Message field 'loc_method'."""
        return self._loc_method

    @loc_method.setter
    def loc_method(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'loc_method' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'loc_method' field must be an integer in [-2147483648, 2147483647]"
        self._loc_method = value
