# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:srv/SeerCtrlCmdInterface.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SeerCtrlCmdInterface_Request(type):
    """Metaclass of message 'SeerCtrlCmdInterface_Request'."""

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
                'com_interfaces.srv.SeerCtrlCmdInterface_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__seer_ctrl_cmd_interface__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__seer_ctrl_cmd_interface__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__seer_ctrl_cmd_interface__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__seer_ctrl_cmd_interface__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__seer_ctrl_cmd_interface__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SeerCtrlCmdInterface_Request(metaclass=Metaclass_SeerCtrlCmdInterface_Request):
    """Message class 'SeerCtrlCmdInterface_Request'."""

    __slots__ = [
        '_id',
        '_station',
        '_station_list',
        '_manual_x',
        '_manual_y',
        '_manual_w',
        '_manual_duration',
        '_nick_name',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'station': 'string',
        'station_list': 'sequence<string>',
        'manual_x': 'float',
        'manual_y': 'float',
        'manual_w': 'float',
        'manual_duration': 'int32',
        'nick_name': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.station = kwargs.get('station', str())
        self.station_list = kwargs.get('station_list', [])
        self.manual_x = kwargs.get('manual_x', float())
        self.manual_y = kwargs.get('manual_y', float())
        self.manual_w = kwargs.get('manual_w', float())
        self.manual_duration = kwargs.get('manual_duration', int())
        self.nick_name = kwargs.get('nick_name', str())

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
        if self.station != other.station:
            return False
        if self.station_list != other.station_list:
            return False
        if self.manual_x != other.manual_x:
            return False
        if self.manual_y != other.manual_y:
            return False
        if self.manual_w != other.manual_w:
            return False
        if self.manual_duration != other.manual_duration:
            return False
        if self.nick_name != other.nick_name:
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
    def station(self):
        """Message field 'station'."""
        return self._station

    @station.setter
    def station(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'station' field must be of type 'str'"
        self._station = value

    @builtins.property
    def station_list(self):
        """Message field 'station_list'."""
        return self._station_list

    @station_list.setter
    def station_list(self, value):
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
                "The 'station_list' field must be a set or sequence and each value of type 'str'"
        self._station_list = value

    @builtins.property
    def manual_x(self):
        """Message field 'manual_x'."""
        return self._manual_x

    @manual_x.setter
    def manual_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'manual_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'manual_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._manual_x = value

    @builtins.property
    def manual_y(self):
        """Message field 'manual_y'."""
        return self._manual_y

    @manual_y.setter
    def manual_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'manual_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'manual_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._manual_y = value

    @builtins.property
    def manual_w(self):
        """Message field 'manual_w'."""
        return self._manual_w

    @manual_w.setter
    def manual_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'manual_w' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'manual_w' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._manual_w = value

    @builtins.property
    def manual_duration(self):
        """Message field 'manual_duration'."""
        return self._manual_duration

    @manual_duration.setter
    def manual_duration(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'manual_duration' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'manual_duration' field must be an integer in [-2147483648, 2147483647]"
        self._manual_duration = value

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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SeerCtrlCmdInterface_Response(type):
    """Metaclass of message 'SeerCtrlCmdInterface_Response'."""

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
                'com_interfaces.srv.SeerCtrlCmdInterface_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__seer_ctrl_cmd_interface__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__seer_ctrl_cmd_interface__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__seer_ctrl_cmd_interface__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__seer_ctrl_cmd_interface__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__seer_ctrl_cmd_interface__response

            from com_interfaces.msg import AgvControl
            if AgvControl.__class__._TYPE_SUPPORT is None:
                AgvControl.__class__.__import_type_support__()

            from com_interfaces.msg import AgvGuideState
            if AgvGuideState.__class__._TYPE_SUPPORT is None:
                AgvGuideState.__class__.__import_type_support__()

            from com_interfaces.msg import AgvLoc
            if AgvLoc.__class__._TYPE_SUPPORT is None:
                AgvLoc.__class__.__import_type_support__()

            from com_interfaces.msg import AgvStation
            if AgvStation.__class__._TYPE_SUPPORT is None:
                AgvStation.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SeerCtrlCmdInterface_Response(metaclass=Metaclass_SeerCtrlCmdInterface_Response):
    """Message class 'SeerCtrlCmdInterface_Response'."""

    __slots__ = [
        '_err_code',
        '_msg',
        '_guide_state',
        '_control',
        '_loc',
        '_current_station',
        '_station_list',
    ]

    _fields_and_field_types = {
        'err_code': 'int32',
        'msg': 'string',
        'guide_state': 'com_interfaces/AgvGuideState',
        'control': 'com_interfaces/AgvControl',
        'loc': 'com_interfaces/AgvLoc',
        'current_station': 'com_interfaces/AgvStation',
        'station_list': 'sequence<com_interfaces/AgvStation>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'AgvGuideState'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'AgvControl'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'AgvLoc'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'AgvStation'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'AgvStation')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.err_code = kwargs.get('err_code', int())
        self.msg = kwargs.get('msg', str())
        from com_interfaces.msg import AgvGuideState
        self.guide_state = kwargs.get('guide_state', AgvGuideState())
        from com_interfaces.msg import AgvControl
        self.control = kwargs.get('control', AgvControl())
        from com_interfaces.msg import AgvLoc
        self.loc = kwargs.get('loc', AgvLoc())
        from com_interfaces.msg import AgvStation
        self.current_station = kwargs.get('current_station', AgvStation())
        self.station_list = kwargs.get('station_list', [])

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
        if self.guide_state != other.guide_state:
            return False
        if self.control != other.control:
            return False
        if self.loc != other.loc:
            return False
        if self.current_station != other.current_station:
            return False
        if self.station_list != other.station_list:
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
    def guide_state(self):
        """Message field 'guide_state'."""
        return self._guide_state

    @guide_state.setter
    def guide_state(self, value):
        if __debug__:
            from com_interfaces.msg import AgvGuideState
            assert \
                isinstance(value, AgvGuideState), \
                "The 'guide_state' field must be a sub message of type 'AgvGuideState'"
        self._guide_state = value

    @builtins.property
    def control(self):
        """Message field 'control'."""
        return self._control

    @control.setter
    def control(self, value):
        if __debug__:
            from com_interfaces.msg import AgvControl
            assert \
                isinstance(value, AgvControl), \
                "The 'control' field must be a sub message of type 'AgvControl'"
        self._control = value

    @builtins.property
    def loc(self):
        """Message field 'loc'."""
        return self._loc

    @loc.setter
    def loc(self, value):
        if __debug__:
            from com_interfaces.msg import AgvLoc
            assert \
                isinstance(value, AgvLoc), \
                "The 'loc' field must be a sub message of type 'AgvLoc'"
        self._loc = value

    @builtins.property
    def current_station(self):
        """Message field 'current_station'."""
        return self._current_station

    @current_station.setter
    def current_station(self, value):
        if __debug__:
            from com_interfaces.msg import AgvStation
            assert \
                isinstance(value, AgvStation), \
                "The 'current_station' field must be a sub message of type 'AgvStation'"
        self._current_station = value

    @builtins.property
    def station_list(self):
        """Message field 'station_list'."""
        return self._station_list

    @station_list.setter
    def station_list(self, value):
        if __debug__:
            from com_interfaces.msg import AgvStation
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
                 all(isinstance(v, AgvStation) for v in value) and
                 True), \
                "The 'station_list' field must be a set or sequence and each value of type 'AgvStation'"
        self._station_list = value


class Metaclass_SeerCtrlCmdInterface(type):
    """Metaclass of service 'SeerCtrlCmdInterface'."""

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
                'com_interfaces.srv.SeerCtrlCmdInterface')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__seer_ctrl_cmd_interface

            from com_interfaces.srv import _seer_ctrl_cmd_interface
            if _seer_ctrl_cmd_interface.Metaclass_SeerCtrlCmdInterface_Request._TYPE_SUPPORT is None:
                _seer_ctrl_cmd_interface.Metaclass_SeerCtrlCmdInterface_Request.__import_type_support__()
            if _seer_ctrl_cmd_interface.Metaclass_SeerCtrlCmdInterface_Response._TYPE_SUPPORT is None:
                _seer_ctrl_cmd_interface.Metaclass_SeerCtrlCmdInterface_Response.__import_type_support__()


class SeerCtrlCmdInterface(metaclass=Metaclass_SeerCtrlCmdInterface):
    from com_interfaces.srv._seer_ctrl_cmd_interface import SeerCtrlCmdInterface_Request as Request
    from com_interfaces.srv._seer_ctrl_cmd_interface import SeerCtrlCmdInterface_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
