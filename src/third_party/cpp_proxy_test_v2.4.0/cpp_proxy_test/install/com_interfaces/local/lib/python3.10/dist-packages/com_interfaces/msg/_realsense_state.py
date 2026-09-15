# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:msg/RealsenseState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RealsenseState(type):
    """Metaclass of message 'RealsenseState'."""

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
                'com_interfaces.msg.RealsenseState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__realsense_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__realsense_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__realsense_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__realsense_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__realsense_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RealsenseState(metaclass=Metaclass_RealsenseState):
    """Message class 'RealsenseState'."""

    __slots__ = [
        '_name',
        '_err_code',
        '_err_msg',
        '_node_online',
        '_color_ready',
        '_depth_ready',
        '_aligned_depth_ready',
        '_color_info_ready',
        '_depth_info_ready',
        '_color_topic',
        '_depth_topic',
        '_aligned_depth_topic',
        '_color_info_topic',
        '_depth_info_topic',
        '_last_color_ts_ms',
        '_last_depth_ts_ms',
        '_last_aligned_depth_ts_ms',
        '_last_color_info_ts_ms',
        '_last_depth_info_ts_ms',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'err_code': 'int32',
        'err_msg': 'string',
        'node_online': 'boolean',
        'color_ready': 'boolean',
        'depth_ready': 'boolean',
        'aligned_depth_ready': 'boolean',
        'color_info_ready': 'boolean',
        'depth_info_ready': 'boolean',
        'color_topic': 'string',
        'depth_topic': 'string',
        'aligned_depth_topic': 'string',
        'color_info_topic': 'string',
        'depth_info_topic': 'string',
        'last_color_ts_ms': 'uint64',
        'last_depth_ts_ms': 'uint64',
        'last_aligned_depth_ts_ms': 'uint64',
        'last_color_info_ts_ms': 'uint64',
        'last_depth_info_ts_ms': 'uint64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.err_code = kwargs.get('err_code', int())
        self.err_msg = kwargs.get('err_msg', str())
        self.node_online = kwargs.get('node_online', bool())
        self.color_ready = kwargs.get('color_ready', bool())
        self.depth_ready = kwargs.get('depth_ready', bool())
        self.aligned_depth_ready = kwargs.get('aligned_depth_ready', bool())
        self.color_info_ready = kwargs.get('color_info_ready', bool())
        self.depth_info_ready = kwargs.get('depth_info_ready', bool())
        self.color_topic = kwargs.get('color_topic', str())
        self.depth_topic = kwargs.get('depth_topic', str())
        self.aligned_depth_topic = kwargs.get('aligned_depth_topic', str())
        self.color_info_topic = kwargs.get('color_info_topic', str())
        self.depth_info_topic = kwargs.get('depth_info_topic', str())
        self.last_color_ts_ms = kwargs.get('last_color_ts_ms', int())
        self.last_depth_ts_ms = kwargs.get('last_depth_ts_ms', int())
        self.last_aligned_depth_ts_ms = kwargs.get('last_aligned_depth_ts_ms', int())
        self.last_color_info_ts_ms = kwargs.get('last_color_info_ts_ms', int())
        self.last_depth_info_ts_ms = kwargs.get('last_depth_info_ts_ms', int())

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
        if self.node_online != other.node_online:
            return False
        if self.color_ready != other.color_ready:
            return False
        if self.depth_ready != other.depth_ready:
            return False
        if self.aligned_depth_ready != other.aligned_depth_ready:
            return False
        if self.color_info_ready != other.color_info_ready:
            return False
        if self.depth_info_ready != other.depth_info_ready:
            return False
        if self.color_topic != other.color_topic:
            return False
        if self.depth_topic != other.depth_topic:
            return False
        if self.aligned_depth_topic != other.aligned_depth_topic:
            return False
        if self.color_info_topic != other.color_info_topic:
            return False
        if self.depth_info_topic != other.depth_info_topic:
            return False
        if self.last_color_ts_ms != other.last_color_ts_ms:
            return False
        if self.last_depth_ts_ms != other.last_depth_ts_ms:
            return False
        if self.last_aligned_depth_ts_ms != other.last_aligned_depth_ts_ms:
            return False
        if self.last_color_info_ts_ms != other.last_color_info_ts_ms:
            return False
        if self.last_depth_info_ts_ms != other.last_depth_info_ts_ms:
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
    def node_online(self):
        """Message field 'node_online'."""
        return self._node_online

    @node_online.setter
    def node_online(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'node_online' field must be of type 'bool'"
        self._node_online = value

    @builtins.property
    def color_ready(self):
        """Message field 'color_ready'."""
        return self._color_ready

    @color_ready.setter
    def color_ready(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'color_ready' field must be of type 'bool'"
        self._color_ready = value

    @builtins.property
    def depth_ready(self):
        """Message field 'depth_ready'."""
        return self._depth_ready

    @depth_ready.setter
    def depth_ready(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'depth_ready' field must be of type 'bool'"
        self._depth_ready = value

    @builtins.property
    def aligned_depth_ready(self):
        """Message field 'aligned_depth_ready'."""
        return self._aligned_depth_ready

    @aligned_depth_ready.setter
    def aligned_depth_ready(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'aligned_depth_ready' field must be of type 'bool'"
        self._aligned_depth_ready = value

    @builtins.property
    def color_info_ready(self):
        """Message field 'color_info_ready'."""
        return self._color_info_ready

    @color_info_ready.setter
    def color_info_ready(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'color_info_ready' field must be of type 'bool'"
        self._color_info_ready = value

    @builtins.property
    def depth_info_ready(self):
        """Message field 'depth_info_ready'."""
        return self._depth_info_ready

    @depth_info_ready.setter
    def depth_info_ready(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'depth_info_ready' field must be of type 'bool'"
        self._depth_info_ready = value

    @builtins.property
    def color_topic(self):
        """Message field 'color_topic'."""
        return self._color_topic

    @color_topic.setter
    def color_topic(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'color_topic' field must be of type 'str'"
        self._color_topic = value

    @builtins.property
    def depth_topic(self):
        """Message field 'depth_topic'."""
        return self._depth_topic

    @depth_topic.setter
    def depth_topic(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'depth_topic' field must be of type 'str'"
        self._depth_topic = value

    @builtins.property
    def aligned_depth_topic(self):
        """Message field 'aligned_depth_topic'."""
        return self._aligned_depth_topic

    @aligned_depth_topic.setter
    def aligned_depth_topic(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'aligned_depth_topic' field must be of type 'str'"
        self._aligned_depth_topic = value

    @builtins.property
    def color_info_topic(self):
        """Message field 'color_info_topic'."""
        return self._color_info_topic

    @color_info_topic.setter
    def color_info_topic(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'color_info_topic' field must be of type 'str'"
        self._color_info_topic = value

    @builtins.property
    def depth_info_topic(self):
        """Message field 'depth_info_topic'."""
        return self._depth_info_topic

    @depth_info_topic.setter
    def depth_info_topic(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'depth_info_topic' field must be of type 'str'"
        self._depth_info_topic = value

    @builtins.property
    def last_color_ts_ms(self):
        """Message field 'last_color_ts_ms'."""
        return self._last_color_ts_ms

    @last_color_ts_ms.setter
    def last_color_ts_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'last_color_ts_ms' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'last_color_ts_ms' field must be an unsigned integer in [0, 18446744073709551615]"
        self._last_color_ts_ms = value

    @builtins.property
    def last_depth_ts_ms(self):
        """Message field 'last_depth_ts_ms'."""
        return self._last_depth_ts_ms

    @last_depth_ts_ms.setter
    def last_depth_ts_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'last_depth_ts_ms' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'last_depth_ts_ms' field must be an unsigned integer in [0, 18446744073709551615]"
        self._last_depth_ts_ms = value

    @builtins.property
    def last_aligned_depth_ts_ms(self):
        """Message field 'last_aligned_depth_ts_ms'."""
        return self._last_aligned_depth_ts_ms

    @last_aligned_depth_ts_ms.setter
    def last_aligned_depth_ts_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'last_aligned_depth_ts_ms' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'last_aligned_depth_ts_ms' field must be an unsigned integer in [0, 18446744073709551615]"
        self._last_aligned_depth_ts_ms = value

    @builtins.property
    def last_color_info_ts_ms(self):
        """Message field 'last_color_info_ts_ms'."""
        return self._last_color_info_ts_ms

    @last_color_info_ts_ms.setter
    def last_color_info_ts_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'last_color_info_ts_ms' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'last_color_info_ts_ms' field must be an unsigned integer in [0, 18446744073709551615]"
        self._last_color_info_ts_ms = value

    @builtins.property
    def last_depth_info_ts_ms(self):
        """Message field 'last_depth_info_ts_ms'."""
        return self._last_depth_info_ts_ms

    @last_depth_info_ts_ms.setter
    def last_depth_info_ts_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'last_depth_info_ts_ms' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'last_depth_info_ts_ms' field must be an unsigned integer in [0, 18446744073709551615]"
        self._last_depth_info_ts_ms = value
