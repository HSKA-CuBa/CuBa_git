  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (TestFilter_P)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% TestFilter_P.SFunctionBuilder_P1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TestFilter_P.radtodeg_Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TestFilter_P.radtodeg1_Gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TestFilter_P.radtodeg2_Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% TestFilter_P.Sensor1_P2
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TestFilter_P.Sensor2_P2
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% TestFilter_P.Sensor1_P1
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TestFilter_P.Sensor2_P1
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    nTotSects     = 2;
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
    ;% Auto data (TestFilter_B)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% TestFilter_B.SFunctionBuilder_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TestFilter_B.SFunctionBuilder_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TestFilter_B.SFunctionBuilder_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TestFilter_B.SFunctionBuilder_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% TestFilter_B.radtodeg
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% TestFilter_B.radtodeg1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% TestFilter_B.radtodeg2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% TestFilter_B.Sensor1_o1
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TestFilter_B.Sensor1_o2
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TestFilter_B.Sensor1_o3
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% TestFilter_B.Sensor1_o4
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% TestFilter_B.Sensor1_o5
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% TestFilter_B.Sensor1_o6
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% TestFilter_B.Sensor2_o1
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% TestFilter_B.Sensor2_o2
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 7;
	
	  ;% TestFilter_B.Sensor2_o3
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 8;
	
	  ;% TestFilter_B.Sensor2_o4
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 9;
	
	  ;% TestFilter_B.Sensor2_o5
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 10;
	
	  ;% TestFilter_B.Sensor2_o6
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    sectIdxOffset = 2;
    
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
    ;% Auto data (TestFilter_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% TestFilter_DW.Sensor1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% TestFilter_DW.Sensor2_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% TestFilter_DW.SFunctionBuilder_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% TestFilter_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
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


  targMap.checksum0 = 308850644;
  targMap.checksum1 = 1332529841;
  targMap.checksum2 = 2270831634;
  targMap.checksum3 = 1956564080;

