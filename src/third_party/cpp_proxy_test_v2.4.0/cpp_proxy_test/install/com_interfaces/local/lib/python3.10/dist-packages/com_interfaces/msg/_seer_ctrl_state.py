# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:msg/SeerCtrlState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SeerCtrlState(type):
    """Metaclass of message 'SeerCtrlState'."""

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
                'com_interfaces.msg.SeerCtrlState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__seer_ctrl_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__seer_ctrl_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__seer_ctrl_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__seer_ctrl_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__seer_ctrl_state

            from com_interfaces.msg import AgvControl
            if AgvControl.__class__._TYPE_SUPPORT is None:
                AgvControl.__class__.__import_type_support__()

            from com_interfaces.msg import AgvGuideState
            if AgvGuideState.__class__._TYPE_SUPPORT is None:
                AgvGuideState.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SeerCtrlState(metaclass=Metaclass_SeerCtrlState):
    """Message class 'SeerCtrlState'."""

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
        '_battery_level',
        '_battery_temp',
        '_charging',
        '_voltage',
        '_current',
        '_max_charge_voltage',
        '_max_charge_current',
        '_manual_charge',
        '_auto_charge',
        '_battery_cycle',
        '_battery_user_data',
        '_guide_state',
        '_control',
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
        'battery_level': 'double',
        'battery_temp': 'double',
        'charging': 'boolean',
        'voltage': 'double',
        'current': 'double',
        'max_charge_voltage': 'double',
        'max_charge_current': 'double',
        'manual_charge': 'boolean',
        'auto_charge': 'boolean',
        'battery_cycle': 'int32',
        'battery_user_data': 'string',
        'guide_state': 'com_interfaces/AgvGuideState',
        'control': 'com_interfaces/AgvControl',
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
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'AgvGuideState'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'AgvControl'),  # noqa: E501
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
        self.battery_level = kwargs.get('battery_level', float())
        self.battery_temp = kwargs.get('battery_temp', float())
        self.charging = kwargs.get('charging', bool())
        self.voltage = kwargs.get('voltage', float())
        self.current = kwargs.get('current', float())
        self.max_charge_voltage = kwargs.get('max_charge_voltage', float())
        self.max_charge_current = kwargs.get('max_charge_current', float())
        self.manual_charge = kwargs.get('manual_charge', bool())
        self.auto_charge = kwargs.get('auto_charge', bool())
        self.battery_cycle = kwargs.get('battery_cycle', int())
        self.battery_user_data = kwargs.get('battery_user_data', str())
        from com_interfaces.msg import AgvGuideState
        self.guide_state = kwargs.get('guide_state', AgvGuideState())
        from com_interfaces.msg import AgvControl
        self.control = kwargs.get('control', AgvControl())

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
        if self.battery_level != other.battery_level:
            return False
        if self.battery_temp != other.battery_temp:
            return False
        if self.charging != other.charging:
            return False
        if self.voltage != other.voltage:
            return False
        if self.current != other.current:
            return False
        if self.max_charge_voltage != other.max_charge_voltage:
            return False
        if self.max_charge_current != other.max_charge_current:
            return False
        if self.manual_charge != other.manual_charge:
            return False
        if self.auto_charge != other.auto_charge:
            return False
        if self.battery_cycle != other.battery_cycle:
            return False
        if self.battery_user_data != other.battery_user_data:
            return False
        if self.guide_state != other.guide_state:
            return False
        if self.control != other.control:
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

    @builtins.property
    def battery_level(self):
        """Message field 'battery_level'."""
        return self._battery_level

    @battery_level.setter
    def battery_level(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery_level' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'battery_level' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._battery_level = value

    @builtins.property
    def battery_temp(self):
        """Message field 'battery_temp'."""
        return self._battery_temp

    @battery_temp.setter
    def battery_temp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery_temp' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'battery_temp' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._battery_temp = value

    @builtins.property
    def charging(self):
        """Message field 'charging'."""
        return self._charging

    @charging.setter
    def charging(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'charging' field must be of type 'bool'"
        self._charging = value

    @builtins.property
    def voltage(self):
        """Message field 'voltage'."""
        return self._voltage

    @voltage.setter
    def voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'voltage' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._voltage = value

    @builtins.property
    def current(self):
        """Message field 'current'."""
        return self._current

    @current.setter
    def current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'current' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._current = value

    @builtins.property
    def max_charge_voltage(self):
        """Message field 'max_charge_voltage'."""
        return self._max_charge_voltage

    @max_charge_voltage.setter
    def max_charge_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_charge_voltage' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_charge_voltage' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_charge_voltage = value

    @builtins.property
    def max_charge_current(self):
        """Message field 'max_charge_current'."""
        return self._max_charge_current

    @max_charge_current.setter
    def max_charge_current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_charge_current' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_charge_current' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_charge_current = value

    @builtins.property
    def manual_charge(self):
        """Message field 'manual_charge'."""
        return self._manual_charge

    @manual_charge.setter
    def manual_charge(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'manual_charge' field must be of type 'bool'"
        self._manual_charge = value

    @builtins.property
    def auto_charge(self):
        """Message field 'auto_charge'."""
        return self._auto_charge

    @auto_charge.setter
    def auto_charge(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'auto_charge' field must be of type 'bool'"
        self._auto_charge = value

    @builtins.property
    def battery_cycle(self):
        """Message field 'battery_cycle'."""
        return self._battery_cycle

    @battery_cycle.setter
    def battery_cycle(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'battery_cycle' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'battery_cycle' field must be an integer in [-2147483648, 2147483647]"
        self._battery_cycle = value

    @builtins.property
    def battery_user_data(self):
        """Message field 'battery_user_data'."""
        return self._battery_user_data

    @battery_user_data.setter
    def battery_user_data(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'battery_user_data' field must be of type 'str'"
        self._battery_user_data = value

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
