# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:srv/SiemensPlcCmdInterface.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SiemensPlcCmdInterface_Request(type):
    """Metaclass of message 'SiemensPlcCmdInterface_Request'."""

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
                'com_interfaces.srv.SiemensPlcCmdInterface_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__siemens_plc_cmd_interface__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__siemens_plc_cmd_interface__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__siemens_plc_cmd_interface__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__siemens_plc_cmd_interface__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__siemens_plc_cmd_interface__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SiemensPlcCmdInterface_Request(metaclass=Metaclass_SiemensPlcCmdInterface_Request):
    """Message class 'SiemensPlcCmdInterface_Request'."""

    __slots__ = [
        '_id',
        '_pin',
        '_dpin_state',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'pin': 'uint16',
        'dpin_state': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.pin = kwargs.get('pin', int())
        self.dpin_state = kwargs.get('dpin_state', int())

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
        if self.pin != other.pin:
            return False
        if self.dpin_state != other.dpin_state:
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
    def pin(self):
        """Message field 'pin'."""
        return self._pin

    @pin.setter
    def pin(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pin' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'pin' field must be an unsigned integer in [0, 65535]"
        self._pin = value

    @builtins.property
    def dpin_state(self):
        """Message field 'dpin_state'."""
        return self._dpin_state

    @dpin_state.setter
    def dpin_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dpin_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'dpin_state' field must be an unsigned integer in [0, 255]"
        self._dpin_state = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SiemensPlcCmdInterface_Response(type):
    """Metaclass of message 'SiemensPlcCmdInterface_Response'."""

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
                'com_interfaces.srv.SiemensPlcCmdInterface_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__siemens_plc_cmd_interface__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__siemens_plc_cmd_interface__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__siemens_plc_cmd_interface__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__siemens_plc_cmd_interface__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__siemens_plc_cmd_interface__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SiemensPlcCmdInterface_Response(metaclass=Metaclass_SiemensPlcCmdInterface_Response):
    """Message class 'SiemensPlcCmdInterface_Response'."""

    __slots__ = [
        '_dpin_state',
        '_err_code',
        '_msg',
    ]

    _fields_and_field_types = {
        'dpin_state': 'uint8',
        'err_code': 'int32',
        'msg': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.dpin_state = kwargs.get('dpin_state', int())
        self.err_code = kwargs.get('err_code', int())
        self.msg = kwargs.get('msg', str())

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
        if self.dpin_state != other.dpin_state:
            return False
        if self.err_code != other.err_code:
            return False
        if self.msg != other.msg:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def dpin_state(self):
        """Message field 'dpin_state'."""
        return self._dpin_state

    @dpin_state.setter
    def dpin_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dpin_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'dpin_state' field must be an unsigned integer in [0, 255]"
        self._dpin_state = value

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


class Metaclass_SiemensPlcCmdInterface(type):
    """Metaclass of service 'SiemensPlcCmdInterface'."""

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
                'com_interfaces.srv.SiemensPlcCmdInterface')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__siemens_plc_cmd_interface

            from com_interfaces.srv import _siemens_plc_cmd_interface
            if _siemens_plc_cmd_interface.Metaclass_SiemensPlcCmdInterface_Request._TYPE_SUPPORT is None:
                _siemens_plc_cmd_interface.Metaclass_SiemensPlcCmdInterface_Request.__import_type_support__()
            if _siemens_plc_cmd_interface.Metaclass_SiemensPlcCmdInterface_Response._TYPE_SUPPORT is None:
                _siemens_plc_cmd_interface.Metaclass_SiemensPlcCmdInterface_Response.__import_type_support__()


class SiemensPlcCmdInterface(metaclass=Metaclass_SiemensPlcCmdInterface):
    from com_interfaces.srv._siemens_plc_cmd_interface import SiemensPlcCmdInterface_Request as Request
    from com_interfaces.srv._siemens_plc_cmd_interface import SiemensPlcCmdInterface_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
