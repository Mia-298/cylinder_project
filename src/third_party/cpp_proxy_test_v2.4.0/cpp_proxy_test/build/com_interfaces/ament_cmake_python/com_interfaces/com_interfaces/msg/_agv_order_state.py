# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:msg/AgvOrderState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AgvOrderState(type):
    """Metaclass of message 'AgvOrderState'."""

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
                'com_interfaces.msg.AgvOrderState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__agv_order_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__agv_order_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__agv_order_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__agv_order_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__agv_order_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AgvOrderState(metaclass=Metaclass_AgvOrderState):
    """Message class 'AgvOrderState'."""

    __slots__ = [
        '_id',
        '_status',
        '_actual_robot_name',
        '_current_step_index',
        '_done_step_index',
        '_step_num',
        '_step_locations',
        '_container_id',
        '_loaded',
        '_unloaded',
        '_fault',
        '_fault_reason',
        '_execution_reject',
    ]

    _fields_and_field_types = {
        'id': 'string',
        'status': 'string',
        'actual_robot_name': 'string',
        'current_step_index': 'int32',
        'done_step_index': 'int32',
        'step_num': 'int32',
        'step_locations': 'sequence<string>',
        'container_id': 'string',
        'loaded': 'boolean',
        'unloaded': 'boolean',
        'fault': 'boolean',
        'fault_reason': 'string',
        'execution_reject': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', str())
        self.status = kwargs.get('status', str())
        self.actual_robot_name = kwargs.get('actual_robot_name', str())
        self.current_step_index = kwargs.get('current_step_index', int())
        self.done_step_index = kwargs.get('done_step_index', int())
        self.step_num = kwargs.get('step_num', int())
        self.step_locations = kwargs.get('step_locations', [])
        self.container_id = kwargs.get('container_id', str())
        self.loaded = kwargs.get('loaded', bool())
        self.unloaded = kwargs.get('unloaded', bool())
        self.fault = kwargs.get('fault', bool())
        self.fault_reason = kwargs.get('fault_reason', str())
        self.execution_reject = kwargs.get('execution_reject', str())

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
        if self.id != other.id:
            return False
        if self.status != other.status:
            return False
        if self.actual_robot_name != other.actual_robot_name:
            return False
        if self.current_step_index != other.current_step_index:
            return False
        if self.done_step_index != other.done_step_index:
            return False
        if self.step_num != other.step_num:
            return False
        if self.step_locations != other.step_locations:
            return False
        if self.container_id != other.container_id:
            return False
        if self.loaded != other.loaded:
            return False
        if self.unloaded != other.unloaded:
            return False
        if self.fault != other.fault:
            return False
        if self.fault_reason != other.fault_reason:
            return False
        if self.execution_reject != other.execution_reject:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'id' field must be of type 'str'"
        self._id = value

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status' field must be of type 'str'"
        self._status = value

    @builtins.property
    def actual_robot_name(self):
        """Message field 'actual_robot_name'."""
        return self._actual_robot_name

    @actual_robot_name.setter
    def actual_robot_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'actual_robot_name' field must be of type 'str'"
        self._actual_robot_name = value

    @builtins.property
    def current_step_index(self):
        """Message field 'current_step_index'."""
        return self._current_step_index

    @current_step_index.setter
    def current_step_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_step_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'current_step_index' field must be an integer in [-2147483648, 2147483647]"
        self._current_step_index = value

    @builtins.property
    def done_step_index(self):
        """Message field 'done_step_index'."""
        return self._done_step_index

    @done_step_index.setter
    def done_step_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'done_step_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'done_step_index' field must be an integer in [-2147483648, 2147483647]"
        self._done_step_index = value

    @builtins.property
    def step_num(self):
        """Message field 'step_num'."""
        return self._step_num

    @step_num.setter
    def step_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'step_num' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'step_num' field must be an integer in [-2147483648, 2147483647]"
        self._step_num = value

    @builtins.property
    def step_locations(self):
        """Message field 'step_locations'."""
        return self._step_locations

    @step_locations.setter
    def step_locations(self, value):
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'step_locations' field must be a set or sequence and each value of type 'str'"
        self._step_locations = value

    @builtins.property
    def container_id(self):
        """Message field 'container_id'."""
        return self._container_id

    @container_id.setter
    def container_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'container_id' field must be of type 'str'"
        self._container_id = value

    @builtins.property
    def loaded(self):
        """Message field 'loaded'."""
        return self._loaded

    @loaded.setter
    def loaded(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'loaded' field must be of type 'bool'"
        self._loaded = value

    @builtins.property
    def unloaded(self):
        """Message field 'unloaded'."""
        return self._unloaded

    @unloaded.setter
    def unloaded(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'unloaded' field must be of type 'bool'"
        self._unloaded = value

    @builtins.property
    def fault(self):
        """Message field 'fault'."""
        return self._fault

    @fault.setter
    def fault(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'fault' field must be of type 'bool'"
        self._fault = value

    @builtins.property
    def fault_reason(self):
        """Message field 'fault_reason'."""
        return self._fault_reason

    @fault_reason.setter
    def fault_reason(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'fault_reason' field must be of type 'str'"
        self._fault_reason = value

    @builtins.property
    def execution_reject(self):
        """Message field 'execution_reject'."""
        return self._execution_reject

    @execution_reject.setter
    def execution_reject(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'execution_reject' field must be of type 'str'"
        self._execution_reject = value
