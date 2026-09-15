# generated from rosidl_generator_py/resource/_idl.py.em
# with input from com_interfaces:srv/VisionEngineCmdInterface.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'desc'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VisionEngineCmdInterface_Request(type):
    """Metaclass of message 'VisionEngineCmdInterface_Request'."""

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
                'com_interfaces.srv.VisionEngineCmdInterface_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__vision_engine_cmd_interface__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__vision_engine_cmd_interface__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__vision_engine_cmd_interface__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__vision_engine_cmd_interface__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__vision_engine_cmd_interface__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VisionEngineCmdInterface_Request(metaclass=Metaclass_VisionEngineCmdInterface_Request):
    """Message class 'VisionEngineCmdInterface_Request'."""

    __slots__ = [
        '_id',
        '_desc',
        '_model_path',
        '_input_height',
        '_input_width',
        '_confidence_threshold',
        '_nms_threshold',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'desc': 'double[6]',
        'model_path': 'string',
        'input_height': 'int32',
        'input_width': 'int32',
        'confidence_threshold': 'double',
        'nms_threshold': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        if 'desc' not in kwargs:
            self.desc = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.desc = kwargs.get('desc')
        self.model_path = kwargs.get('model_path', str())
        self.input_height = kwargs.get('input_height', int())
        self.input_width = kwargs.get('input_width', int())
        self.confidence_threshold = kwargs.get('confidence_threshold', float())
        self.nms_threshold = kwargs.get('nms_threshold', float())

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
        if any(self.desc != other.desc):
            return False
        if self.model_path != other.model_path:
            return False
        if self.input_height != other.input_height:
            return False
        if self.input_width != other.input_width:
            return False
        if self.confidence_threshold != other.confidence_threshold:
            return False
        if self.nms_threshold != other.nms_threshold:
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
    def desc(self):
        """Message field 'desc'."""
        return self._desc

    @desc.setter
    def desc(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'desc' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'desc' numpy.ndarray() must have a size of 6"
            self._desc = value
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
                "The 'desc' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._desc = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def model_path(self):
        """Message field 'model_path'."""
        return self._model_path

    @model_path.setter
    def model_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'model_path' field must be of type 'str'"
        self._model_path = value

    @builtins.property
    def input_height(self):
        """Message field 'input_height'."""
        return self._input_height

    @input_height.setter
    def input_height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'input_height' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'input_height' field must be an integer in [-2147483648, 2147483647]"
        self._input_height = value

    @builtins.property
    def input_width(self):
        """Message field 'input_width'."""
        return self._input_width

    @input_width.setter
    def input_width(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'input_width' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'input_width' field must be an integer in [-2147483648, 2147483647]"
        self._input_width = value

    @builtins.property
    def confidence_threshold(self):
        """Message field 'confidence_threshold'."""
        return self._confidence_threshold

    @confidence_threshold.setter
    def confidence_threshold(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence_threshold' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'confidence_threshold' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._confidence_threshold = value

    @builtins.property
    def nms_threshold(self):
        """Message field 'nms_threshold'."""
        return self._nms_threshold

    @nms_threshold.setter
    def nms_threshold(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'nms_threshold' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'nms_threshold' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._nms_threshold = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_VisionEngineCmdInterface_Response(type):
    """Metaclass of message 'VisionEngineCmdInterface_Response'."""

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
                'com_interfaces.srv.VisionEngineCmdInterface_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__vision_engine_cmd_interface__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__vision_engine_cmd_interface__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__vision_engine_cmd_interface__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__vision_engine_cmd_interface__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__vision_engine_cmd_interface__response

            from com_interfaces.msg import SphereLoc
            if SphereLoc.__class__._TYPE_SUPPORT is None:
                SphereLoc.__class__.__import_type_support__()

            from com_interfaces.msg import YoloResult
            if YoloResult.__class__._TYPE_SUPPORT is None:
                YoloResult.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VisionEngineCmdInterface_Response(metaclass=Metaclass_VisionEngineCmdInterface_Response):
    """Message class 'VisionEngineCmdInterface_Response'."""

    __slots__ = [
        '_err_code',
        '_msg',
        '_results',
        '_sphere_loc',
    ]

    _fields_and_field_types = {
        'err_code': 'int32',
        'msg': 'string',
        'results': 'sequence<com_interfaces/YoloResult>',
        'sphere_loc': 'com_interfaces/SphereLoc',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'YoloResult')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['com_interfaces', 'msg'], 'SphereLoc'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.err_code = kwargs.get('err_code', int())
        self.msg = kwargs.get('msg', str())
        self.results = kwargs.get('results', [])
        from com_interfaces.msg import SphereLoc
        self.sphere_loc = kwargs.get('sphere_loc', SphereLoc())

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
        if self.results != other.results:
            return False
        if self.sphere_loc != other.sphere_loc:
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
    def results(self):
        """Message field 'results'."""
        return self._results

    @results.setter
    def results(self, value):
        if __debug__:
            from com_interfaces.msg import YoloResult
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
                 all(isinstance(v, YoloResult) for v in value) and
                 True), \
                "The 'results' field must be a set or sequence and each value of type 'YoloResult'"
        self._results = value

    @builtins.property
    def sphere_loc(self):
        """Message field 'sphere_loc'."""
        return self._sphere_loc

    @sphere_loc.setter
    def sphere_loc(self, value):
        if __debug__:
            from com_interfaces.msg import SphereLoc
            assert \
                isinstance(value, SphereLoc), \
                "The 'sphere_loc' field must be a sub message of type 'SphereLoc'"
        self._sphere_loc = value


class Metaclass_VisionEngineCmdInterface(type):
    """Metaclass of service 'VisionEngineCmdInterface'."""

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
                'com_interfaces.srv.VisionEngineCmdInterface')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__vision_engine_cmd_interface

            from com_interfaces.srv import _vision_engine_cmd_interface
            if _vision_engine_cmd_interface.Metaclass_VisionEngineCmdInterface_Request._TYPE_SUPPORT is None:
                _vision_engine_cmd_interface.Metaclass_VisionEngineCmdInterface_Request.__import_type_support__()
            if _vision_engine_cmd_interface.Metaclass_VisionEngineCmdInterface_Response._TYPE_SUPPORT is None:
                _vision_engine_cmd_interface.Metaclass_VisionEngineCmdInterface_Response.__import_type_support__()


class VisionEngineCmdInterface(metaclass=Metaclass_VisionEngineCmdInterface):
    from com_interfaces.srv._vision_engine_cmd_interface import VisionEngineCmdInterface_Request as Request
    from com_interfaces.srv._vision_engine_cmd_interface import VisionEngineCmdInterface_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
