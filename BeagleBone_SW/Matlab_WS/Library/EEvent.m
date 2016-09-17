classdef EEvent < uint8
    enumeration
        EV_DEFAULT_IGNORE(0),
        EV_REQUEST_RUN(1),
        EV_REQUEST_STANDBY(2),
        EV_REQUEST_TX_DATA(3),
        EV_SET_TORQUE(4)
    end
end