classdef EFilter < uint32
    enumeration
        PHI_NONE(0),
        PHI_COMP(1),
        PHI_KALMAN(2),
        PHI__D_NONE(3),
        PHI__D_KALMAN(4),
        PSI__D_NONE(5),
        PSI__D_MEAN4(6),
        PSI__D_MEAN8(7),
        PSI__D_MEAN16(8)
    end
end