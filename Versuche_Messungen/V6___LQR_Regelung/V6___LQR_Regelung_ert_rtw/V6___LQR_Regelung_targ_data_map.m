  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (V6___LQR_Regelung_P)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_P.Kd
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% V6___LQR_Regelung_P.Constant2_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_P.SFunctionBuilder2_P1
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% V6___LQR_Regelung_P.Constant1_Value
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% V6___LQR_Regelung_P.Gain1_Gain
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% V6___LQR_Regelung_P.Gain2_Gain
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% V6___LQR_Regelung_P.radtodeg1_Gain
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_P.Sensor1_P2
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% V6___LQR_Regelung_P.Sensor2_P2
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_P.Gain_Gain
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_P.Constant_Value
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% V6___LQR_Regelung_P.Sensor1_P1
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% V6___LQR_Regelung_P.Sensor2_P1
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (V6___LQR_Regelung_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_B.SFunctionBuilder2_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% V6___LQR_Regelung_B.SFunctionBuilder2_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% V6___LQR_Regelung_B.SFunctionBuilder2_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% V6___LQR_Regelung_B.SFunctionBuilder2_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% V6___LQR_Regelung_B.Sum
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% V6___LQR_Regelung_B.radtodeg1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_B.Sensor1_o1
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% V6___LQR_Regelung_B.Sensor1_o2
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% V6___LQR_Regelung_B.Sensor1_o3
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% V6___LQR_Regelung_B.Sensor1_o4
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% V6___LQR_Regelung_B.Sensor1_o5
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% V6___LQR_Regelung_B.Sensor1_o6
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% V6___LQR_Regelung_B.Sensor2_o1
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% V6___LQR_Regelung_B.Sensor2_o2
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% V6___LQR_Regelung_B.Sensor2_o3
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% V6___LQR_Regelung_B.Sensor2_o4
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% V6___LQR_Regelung_B.Sensor2_o5
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 10;
	
	  ;% V6___LQR_Regelung_B.Sensor2_o6
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_B.SFunctionBuilder1
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (V6___LQR_Regelung_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_DW.Sensor1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% V6___LQR_Regelung_DW.Sensor2_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% V6___LQR_Regelung_DW.SFunctionBuilder2_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% V6___LQR_Regelung_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% V6___LQR_Regelung_DW.Scope2_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3390264252;
  targMap.checksum1 = 4287730889;
  targMap.checksum2 = 2368429964;
  targMap.checksum3 = 1379560705;

