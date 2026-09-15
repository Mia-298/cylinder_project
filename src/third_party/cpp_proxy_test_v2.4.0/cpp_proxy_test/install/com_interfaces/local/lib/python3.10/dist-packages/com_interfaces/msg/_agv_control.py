# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:msg/AgvControl.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AgvControl(type):
    """Metaclass of message 'AgvControl'."""

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
                'com_interfaces.msg.AgvControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__agv_control
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__agv_control
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__agv_control
            cls._TYPE_SUPPORT = module.type_support_msg__msg__agv_control
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__agv_control

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AgvControl(metaclass=Metaclass_AgvControl):
    """Message class 'AgvControl'."""

    __slots__ = [
        '_locked',
        '_ip',
        '_port',
        '_type',
        '_nick_name',
        '_time',
        '_desc',
    ]

    _fields_and_field_types = {
        'locked': 'boolean',
        'ip': 'string',
        'port': 'int32',
        'type': 'uint8',
        'nick_name': 'string',
        'time': 'int64',
        'desc': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.locked = kwargs.get('locked', bool())
        self.ip = kwargs.get('ip', str())
        self.port = kwargs.get('port', int())
        self.type = kwargs.get('type', int())
        self.nick_name = kwargs.get('nick_name', str())
        self.time = kwargs.get('time', int())
        self.desc = kwargs.get('desc', str())

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
        if self.locked != other.locked:
            return False
        if self.ip != other.ip:
            return False
        if self.port != other.port:
            return False
        if self.type != other.type:
            return False
        if self.nick_name != other.nick_name:
            return False
        if self.time != other.time:
            return False
        if self.desc != other.desc:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def locked(self):
        """Message field 'locked'."""
        return self._locked

    @locked.setter
    def locked(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'locked' field must be of type 'bool'"
        self._locked = value

    @builtins.property
    def ip(self):
        """Message field 'ip'."""
        return self._ip

    @ip.setter
    def ip(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'ip' field must be of type 'str'"
        self._ip = value

    @builtins.property
    def port(self):
        """Message field 'port'."""
        return self._port

    @port.setter
    def port(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'port' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'port' field must be an integer in [-2147483648, 2147483647]"
        self._port = value

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'type' field must be an unsigned integer in [0, 255]"
        self._type = value

    @builtins.property
    def nick_name(self):
        """Message field 'nick_name'."""
        return self._nick_name

    @nick_name.setter
    def nick_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'nick_name' field must be of type 'str'"
        self._nick_name = value

    @builtins.property
    def time(self):
        """Message field 'time'."""
        return self._time

    @time.setter
    def time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'time' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._time = value

    @builtins.property
    def desc(self):
        """Message field 'desc'."""
        return self._desc

    @desc.setter
    def desc(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'desc' field must be of type 'str'"
        self._desc = value
