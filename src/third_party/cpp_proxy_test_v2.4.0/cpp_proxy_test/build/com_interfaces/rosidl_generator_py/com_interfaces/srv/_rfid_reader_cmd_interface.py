# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:srv/RfidReaderCmdInterface.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RfidReaderCmdInterface_Request(type):
    """Metaclass of message 'RfidReaderCmdInterface_Request'."""

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
                'com_interfaces.srv.RfidReaderCmdInterface_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__rfid_reader_cmd_interface__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__rfid_reader_cmd_interface__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__rfid_reader_cmd_interface__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__rfid_reader_cmd_interface__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__rfid_reader_cmd_interface__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RfidReaderCmdInterface_Request(metaclass=Metaclass_RfidReaderCmdInterface_Request):
    """Message class 'RfidReaderCmdInterface_Request'."""

    __slots__ = [
        '_id',
        '_power',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'power': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.power = kwargs.get('power', int())

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
        if self.power != other.power:
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
    def power(self):
        """Message field 'power'."""
        return self._power

    @power.setter
    def power(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'power' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'power' field must be an integer in [-2147483648, 2147483647]"
        self._power = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RfidReaderCmdInterface_Response(type):
    """Metaclass of message 'RfidReaderCmdInterface_Response'."""

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
                'com_interfaces.srv.RfidReaderCmdInterface_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__rfid_reader_cmd_interface__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__rfid_reader_cmd_interface__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__rfid_reader_cmd_interface__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__rfid_reader_cmd_interface__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__rfid_reader_cmd_interface__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RfidReaderCmdInterface_Response(metaclass=Metaclass_RfidReaderCmdInterface_Response):
    """Message class 'RfidReaderCmdInterface_Response'."""

    __slots__ = [
        '_err_code',
        '_msg',
        '_data',
    ]

    _fields_and_field_types = {
        'err_code': 'int32',
        'msg': 'string',
        'data': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.err_code = kwargs.get('err_code', int())
        self.msg = kwargs.get('msg', str())
        self.data = kwargs.get('data', str())

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
        if self.data != other.data:
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
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'data' field must be of type 'str'"
        self._data = value


class Metaclass_RfidReaderCmdInterface(type):
    """Metaclass of service 'RfidReaderCmdInterface'."""

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
                'com_interfaces.srv.RfidReaderCmdInterface')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__rfid_reader_cmd_interface

            from com_interfaces.srv import _rfid_reader_cmd_interface
            if _rfid_reader_cmd_interface.Metaclass_RfidReaderCmdInterface_Request._TYPE_SUPPORT is None:
                _rfid_reader_cmd_interface.Metaclass_RfidReaderCmdInterface_Request.__import_type_support__()
            if _rfid_reader_cmd_interface.Metaclass_RfidReaderCmdInterface_Response._TYPE_SUPPORT is None:
                _rfid_reader_cmd_interface.Metaclass_RfidReaderCmdInterface_Response.__import_type_support__()


class RfidReaderCmdInterface(metaclass=Metaclass_RfidReaderCmdInterface):
    from com_interfaces.srv._rfid_reader_cmd_interface import RfidReaderCmdInterface_Request as Request
    from com_interfaces.srv._rfid_reader_cmd_interface import RfidReaderCmdInterface_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
