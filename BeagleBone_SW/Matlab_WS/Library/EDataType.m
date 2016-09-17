classdef EDataType < uint8
    enumeration
        DEFAULT_IGNORE(0),
        SENSOR_DATA(1),
        MOTOR_DATA(2),
        UNFILTERED_DATA(3),
        KALMAN_DATA(4),
        COMPLEMENTARY_DATA(5)
    end
end