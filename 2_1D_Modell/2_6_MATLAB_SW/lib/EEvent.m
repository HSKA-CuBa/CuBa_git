classdef EEvent < uint8
    enumeration
        EV_DEFAULT_IGNORE(0),
        EV_TRANSMIT_DATA(1),
        EV_CMD(2),
        EV_TIMER_TICK(3),
        EV_CLIENT_DISCONNECT(4)
    end
end