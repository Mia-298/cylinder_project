# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:srv/AuboCmdInterface.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'position'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AuboCmdInterface_Request(type):
    """Metaclass of message 'AuboCmdInterface_Request'."""

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
                'com_interfaces.srv.AuboCmdInterface_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__aubo_cmd_interface__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__aubo_cmd_interface__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__aubo_cmd_interface__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__aubo_cmd_interface__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__aubo_cmd_interface__request

            from com_interfaces.msg import JointPoint
            if JointPoint.__class__._TYPE_SUPPORT is None:
                JointPoint.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AuboCmdInterface_Request(metaclass=Metaclass_AuboCmdInterface_Request):
    """Message class 'AuboCmdInterface_Request'."""

    __slots__ = [
        '_id',
        '_en',
        '_joint_or_desc',
        '_position',
        '_axid',
        '_dir',
        '_deg',
        '_speed',
        '_acc',
        '_tool',
        '_mode',
        '_register_index',
        '_register_value',
        '_input_or_output',
        '_io_index',
        '_io_value',
        '_program',
        '_interval',
        '_filename',
        '_joint_path',
        '_gripper_index',
        '_act',
        '_gripper_pos',
        '_gripper_vel',
        '_gripper_force',
        '_max_time',
        '_gripper_block',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'en': 'boolean',
        'joint_or_desc': 'boolean',
        'position': 'double[6]',
        'axid': 'uint8',
        'dir': 'uint8',
        'deg': 'double',
        'speed': 'double',
        'acc': 'double',
        'tool': 'int32',
        'mode': 'int32',
        'register_index': 'int32',
        'register_value': 'double',
        'input_or_output': 'boolean',
        'io_index': 'int32',
        'io_value': 'boolean',
        'program': 'string',
        'interval': 'int32',
        'filename': 'string',
        'joint_path': 'sequence<com_interfaces/JointPoint>',
        'gripper_index': 'int32',
        'act': 'uint8',
        'gripper_pos': 'int32',
        'gripper_vel': 'int32',
        'gripper_force': 'int32',
        'max_time': 'int32',
        'gripper_block': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'JointPoint')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.en = kwargs.get('en', bool())
        self.joint_or_desc = kwargs.get('joint_or_desc', bool())
        if 'position' not in kwargs:
            self.position = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.position = kwargs.get('position')
        self.axid = kwargs.get('axid', int())
        self.dir = kwargs.get('dir', int())
        self.deg = kwargs.get('deg', float())
        self.speed = kwargs.get('speed', float())
        self.acc = kwargs.get('acc', float())
        self.tool = kwargs.get('tool', int())
        self.mode = kwargs.get('mode', int())
        self.register_index = kwargs.get('register_index', int())
        self.register_value = kwargs.get('register_value', float())
        self.input_or_output = kwargs.get('input_or_output', bool())
        self.io_index = kwargs.get('io_index', int())
        self.io_value = kwargs.get('io_value', bool())
        self.program = kwargs.get('program', str())
        self.interval = kwargs.get('interval', int())
        self.filename = kwargs.get('filename', str())
        self.joint_path = kwargs.get('joint_path', [])
        self.gripper_index = kwargs.get('gripper_index', int())
        self.act = kwargs.get('act', int())
        self.gripper_pos = kwargs.get('gripper_pos', int())
        self.gripper_vel = kwargs.get('gripper_vel', int())
        self.gripper_force = kwargs.get('gripper_force', int())
        self.max_time = kwargs.get('max_time', int())
        self.gripper_block = kwargs.get('gripper_block', int())

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
        if self.en != other.en:
            return False
        if self.joint_or_desc != other.joint_or_desc:
            return False
        if any(self.position != other.position):
            return False
        if self.axid != other.axid:
            return False
        if self.dir != other.dir:
            return False
        if self.deg != other.deg:
            return False
        if self.speed != other.speed:
            return False
        if self.acc != other.acc:
            return False
        if self.tool != other.tool:
            return False
        if self.mode != other.mode:
            return False
        if self.register_index != other.register_index:
            return False
        if self.register_value != other.register_value:
            return False
        if self.input_or_output != other.input_or_output:
            return False
        if self.io_index != other.io_index:
            return False
        if self.io_value != other.io_value:
            return False
        if self.program != other.program:
            return False
        if self.interval != other.interval:
            return False
        if self.filename != other.filename:
            return False
        if self.joint_path != other.joint_path:
            return False
        if self.gripper_index != other.gripper_index:
            return False
        if self.act != other.act:
            return False
        if self.gripper_pos != other.gripper_pos:
            return False
        if self.gripper_vel != other.gripper_vel:
            return False
        if self.gripper_force != other.gripper_force:
            return False
        if self.max_time != other.max_time:
            return False
        if self.gripper_block != other.gripper_block:
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
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id' field must be an integer in [-2147483648, 2147483647]"
        self._id = value

    @builtins.property
    def en(self):
        """Message field 'en'."""
        return self._en

    @en.setter
    def en(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'en' field must be of type 'bool'"
        self._en = value

    @builtins.property
    def joint_or_desc(self):
        """Message field 'joint_or_desc'."""
        return self._joint_or_desc

    @joint_or_desc.setter
    def joint_or_desc(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'joint_or_desc' field must be of type 'bool'"
        self._joint_or_desc = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'position' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'position' numpy.ndarray() must have a size of 6"
            self._position = value
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
                "The 'position' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._position = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def axid(self):
        """Message field 'axid'."""
        return self._axid

    @axid.setter
    def axid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'axid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'axid' field must be an unsigned integer in [0, 255]"
        self._axid = value

    @builtins.property  # noqa: A003
    def dir(self):  # noqa: A003
        """Message field 'dir'."""
        return self._dir

    @dir.setter  # noqa: A003
    def dir(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dir' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'dir' field must be an unsigned integer in [0, 255]"
        self._dir = value

    @builtins.property
    def deg(self):
        """Message field 'deg'."""
        return self._deg

    @deg.setter
    def deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'deg' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'deg' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._deg = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed = value

    @builtins.property
    def acc(self):
        """Message field 'acc'."""
        return self._acc

    @acc.setter
    def acc(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'acc' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'acc' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._acc = value

    @builtins.property
    def tool(self):
        """Message field 'tool'."""
        return self._tool

    @tool.setter
    def tool(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tool' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'tool' field must be an integer in [-2147483648, 2147483647]"
        self._tool = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mode' field must be an integer in [-2147483648, 2147483647]"
        self._mode = value

    @builtins.property
    def register_index(self):
        """Message field 'register_index'."""
        return self._register_index

    @register_index.setter
    def register_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'register_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'register_index' field must be an integer in [-2147483648, 2147483647]"
        self._register_index = value

    @builtins.property
    def register_value(self):
        """Message field 'register_value'."""
        return self._register_value

    @register_value.setter
    def register_value(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'register_value' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'register_value' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._register_value = value

    @builtins.property
    def input_or_output(self):
        """Message field 'input_or_output'."""
        return self._input_or_output

    @input_or_output.setter
    def input_or_output(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'input_or_output' field must be of type 'bool'"
        self._input_or_output = value

    @builtins.property
    def io_index(self):
        """Message field 'io_index'."""
        return self._io_index

    @io_index.setter
    def io_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'io_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'io_index' field must be an integer in [-2147483648, 2147483647]"
        self._io_index = value

    @builtins.property
    def io_value(self):
        """Message field 'io_value'."""
        return self._io_value

    @io_value.setter
    def io_value(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'io_value' field must be of type 'bool'"
        self._io_value = value

    @builtins.property
    def program(self):
        """Message field 'program'."""
        return self._program

    @program.setter
    def program(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'program' field must be of type 'str'"
        self._program = value

    @builtins.property
    def interval(self):
        """Message field 'interval'."""
        return self._interval

    @interval.setter
    def interval(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'interval' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'interval' field must be an integer in [-2147483648, 2147483647]"
        self._interval = value

    @builtins.property
    def filename(self):
        """Message field 'filename'."""
        return self._filename

    @filename.setter
    def filename(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'filename' field must be of type 'str'"
        self._filename = value

    @builtins.property
    def joint_path(self):
        """Message field 'joint_path'."""
        return self._joint_path

    @joint_path.setter
    def joint_path(self, value):
        if __debug__:
            from com_interfaces.msg import JointPoint
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
                 all(isinstance(v, JointPoint) for v in value) and
                 True), \
                "The 'joint_path' field must be a set or sequence and each value of type 'JointPoint'"
        self._joint_path = value

    @builtins.property
    def gripper_index(self):
        """Message field 'gripper_index'."""
        return self._gripper_index

    @gripper_index.setter
    def gripper_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gripper_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gripper_index' field must be an integer in [-2147483648, 2147483647]"
        self._gripper_index = value

    @builtins.property
    def act(self):
        """Message field 'act'."""
        return self._act

    @act.setter
    def act(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'act' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'act' field must be an unsigned integer in [0, 255]"
        self._act = value

    @builtins.property
    def gripper_pos(self):
        """Message field 'gripper_pos'."""
        return self._gripper_pos

    @gripper_pos.setter
    def gripper_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gripper_pos' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gripper_pos' field must be an integer in [-2147483648, 2147483647]"
        self._gripper_pos = value

    @builtins.property
    def gripper_vel(self):
        """Message field 'gripper_vel'."""
        return self._gripper_vel

    @gripper_vel.setter
    def gripper_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gripper_vel' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gripper_vel' field must be an integer in [-2147483648, 2147483647]"
        self._gripper_vel = value

    @builtins.property
    def gripper_force(self):
        """Message field 'gripper_force'."""
        return self._gripper_force

    @gripper_force.setter
    def gripper_force(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gripper_force' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gripper_force' field must be an integer in [-2147483648, 2147483647]"
        self._gripper_force = value

    @builtins.property
    def max_time(self):
        """Message field 'max_time'."""
        return self._max_time

    @max_time.setter
    def max_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_time' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'max_time' field must be an integer in [-2147483648, 2147483647]"
        self._max_time = value

    @builtins.property
    def gripper_block(self):
        """Message field 'gripper_block'."""
        return self._gripper_block

    @gripper_block.setter
    def gripper_block(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gripper_block' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gripper_block' field must be an unsigned integer in [0, 255]"
        self._gripper_block = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# Member 'jt_pos'
# Member 'tl_pos'
# already imported above
# import numpy

# already imported above
# import rosidl_parser.definition


class Metaclass_AuboCmdInterface_Response(type):
    """Metaclass of message 'AuboCmdInterface_Response'."""

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
                'com_interfaces.srv.AuboCmdInterface_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__aubo_cmd_interface__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__aubo_cmd_interface__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__aubo_cmd_interface__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__aubo_cmd_interface__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__aubo_cmd_interface__response

            from com_interfaces.msg import AuboRobotState
            if AuboRobotState.__class__._TYPE_SUPPORT is None:
                AuboRobotState.__class__.__import_type_support__()

            from com_interfaces.msg import ForceTorque
            if ForceTorque.__class__._TYPE_SUPPORT is None:
                ForceTorque.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AuboCmdInterface_Response(metaclass=Metaclass_AuboCmdInterface_Response):
    """Message class 'AuboCmdInterface_Response'."""

    __slots__ = [
        '_err_code',
        '_msg',
        '_pub_state',
        '_register_val',
        '_io_val',
        '_jt_pos',
        '_tl_pos',
        '_ft',
    ]

    _fields_and_field_types = {
        'err_code': 'int32',
        'msg': 'string',
        'pub_state': 'com_interfaces/AuboRobotState',
        'register_val': 'double',
        'io_val': 'boolean',
        'jt_pos': 'double[6]',
        'tl_pos': 'double[6]',
        'ft': 'com_interfaces/ForceTorque',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'AuboRobotState'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'ForceTorque'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.err_code = kwargs.get('err_code', int())
        self.msg = kwargs.get('msg', str())
        from com_interfaces.msg import AuboRobotState
        self.pub_state = kwargs.get('pub_state', AuboRobotState())
        self.register_val = kwargs.get('register_val', float())
        self.io_val = kwargs.get('io_val', bool())
        if 'jt_pos' not in kwargs:
            self.jt_pos = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.jt_pos = kwargs.get('jt_pos')
        if 'tl_pos' not in kwargs:
            self.tl_pos = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.tl_pos = kwargs.get('tl_pos')
        from com_interfaces.msg import ForceTorque
        self.ft = kwargs.get('ft', ForceTorque())

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
        if self.err_code != other.err_code:
            return False
        if self.msg != other.msg:
            return False
        if self.pub_state != other.pub_state:
            return False
        if self.register_val != other.register_val:
            return False
        if self.io_val != other.io_val:
            return False
        if any(self.jt_pos != other.jt_pos):
            return False
        if any(self.tl_pos != other.tl_pos):
            return False
        if self.ft != other.ft:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def msg(self):
        """Message field 'msg'."""
        return self._msg

    @msg.setter
    def msg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'msg' field must be of type 'str'"
        self._msg = value

    @builtins.property
    def pub_state(self):
        """Message field 'pub_state'."""
        return self._pub_state

    @pub_state.setter
    def pub_state(self, value):
        if __debug__:
            from com_interfaces.msg import AuboRobotState
            assert \
                isinstance(value, AuboRobotState), \
                "The 'pub_state' field must be a sub message of type 'AuboRobotState'"
        self._pub_state = value

    @builtins.property
    def register_val(self):
        """Message field 'register_val'."""
        return self._register_val

    @register_val.setter
    def register_val(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'register_val' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'register_val' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._register_val = value

    @builtins.property
    def io_val(self):
        """Message field 'io_val'."""
        return self._io_val

    @io_val.setter
    def io_val(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'io_val' field must be of type 'bool'"
        self._io_val = value

    @builtins.property
    def jt_pos(self):
        """Message field 'jt_pos'."""
        return self._jt_pos

    @jt_pos.setter
    def jt_pos(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'jt_pos' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'jt_pos' numpy.ndarray() must have a size of 6"
            self._jt_pos = value
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
                "The 'jt_pos' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._jt_pos = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tl_pos(self):
        """Message field 'tl_pos'."""
        return self._tl_pos

    @tl_pos.setter
    def tl_pos(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'tl_pos' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'tl_pos' numpy.ndarray() must have a size of 6"
            self._tl_pos = value
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
                "The 'tl_pos' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._tl_pos = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def ft(self):
        """Message field 'ft'."""
        return self._ft

    @ft.setter
    def ft(self, value):
        if __debug__:
            from com_interfaces.msg import ForceTorque
            assert \
                isinstance(value, ForceTorque), \
                "The 'ft' field must be a sub message of type 'ForceTorque'"
        self._ft = value


class Metaclass_AuboCmdInterface(type):
    """Metaclass of service 'AuboCmdInterface'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('com_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'com_interfaces.srv.AuboCmdInterface')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__aubo_cmd_interface

            from com_interfaces.srv import _aubo_cmd_interface
            if _aubo_cmd_interface.Metaclass_AuboCmdInterface_Request._TYPE_SUPPORT is None:
                _aubo_cmd_interface.Metaclass_AuboCmdInterface_Request.__import_type_support__()
            if _aubo_cmd_interface.Metaclass_AuboCmdInterface_Response._TYPE_SUPPORT is None:
                _aubo_cmd_interface.Metaclass_AuboCmdInterface_Response.__import_type_support__()


class AuboCmdInterface(metaclass=Metaclass_AuboCmdInterface):
    from com_interfaces.srv._aubo_cmd_interface import AuboCmdInterface_Request as Request
    from com_interfaces.srv._aubo_cmd_interface import AuboCmdInterface_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
