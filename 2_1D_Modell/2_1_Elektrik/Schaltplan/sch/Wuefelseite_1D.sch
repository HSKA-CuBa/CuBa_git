<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="no" active="no"/>
<layer number="101" name="Patch_Top" color="12" fill="4" visible="yes" active="yes"/>
<layer number="116" name="Patch_BOT" color="9" fill="4" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="no" active="no"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="36-3-EC">
<packages>
<package name="36-3_EC">
<pad name="P$1" x="-8.89" y="2.54" drill="0.8" shape="square"/>
<pad name="P$2" x="-8.89" y="0" drill="0.8" shape="square"/>
<pad name="P$3" x="1.27" y="0" drill="0.8" shape="square"/>
<pad name="P$4" x="1.27" y="2.54" drill="0.8" shape="square"/>
<pad name="P$5" x="-8.89" y="-2.54" drill="0.8" shape="square"/>
<pad name="P$6" x="-8.89" y="-5.08" drill="0.8" shape="square"/>
<pad name="P$7" x="-8.89" y="-7.62" drill="0.8" shape="square"/>
<pad name="P$8" x="-8.89" y="-10.16" drill="0.8" shape="square"/>
<pad name="P$9" x="-8.89" y="-12.7" drill="0.8" shape="square"/>
<pad name="P$10" x="-8.89" y="-15.24" drill="0.8" shape="square"/>
<pad name="P$11" x="-8.89" y="-17.78" drill="0.8" shape="square"/>
<pad name="P$12" x="-8.89" y="-20.32" drill="0.8" shape="square"/>
<pad name="P$13" x="-8.89" y="-22.86" drill="0.8" shape="square"/>
<pad name="P$14" x="-8.89" y="-25.4" drill="0.8" shape="square"/>
<pad name="P$15" x="-8.89" y="-27.94" drill="0.8" shape="square"/>
<pad name="P$16" x="-8.89" y="-30.48" drill="0.8" shape="square"/>
<pad name="P$17" x="1.27" y="-2.54" drill="0.8" shape="square"/>
<pad name="P$18" x="1.27" y="-5.08" drill="0.8" shape="square"/>
<pad name="P$19" x="1.27" y="-7.62" drill="0.8" shape="square"/>
<pad name="P$20" x="1.27" y="-10.16" drill="0.8" shape="square"/>
<pad name="P$21" x="1.27" y="-12.7" drill="0.8" shape="square"/>
<pad name="P$22" x="1.27" y="-15.24" drill="0.8" shape="square"/>
<pad name="P$23" x="1.27" y="-17.78" drill="0.8" shape="square"/>
<pad name="P$24" x="1.27" y="-20.32" drill="0.8" shape="square"/>
<pad name="P$25" x="1.27" y="-22.86" drill="0.8" shape="square"/>
<pad name="P$26" x="1.27" y="-25.4" drill="0.8" shape="square"/>
<pad name="P$27" x="1.27" y="-27.94" drill="0.8" shape="square"/>
<rectangle x1="-6.35" y1="-33.02" x2="-1.27" y2="3.81" layer="21"/>
<pad name="P$28" x="-8.89" y="-33.02" drill="0.8" shape="square"/>
<pad name="P$29" x="1.27" y="-30.48" drill="0.8" shape="square"/>
<pad name="P$30" x="1.27" y="-33.02" drill="0.8" shape="square"/>
</package>
</packages>
<symbols>
<symbol name="36-3_EC">
<description>36-3 EC</description>
<pin name="+VCC" x="-5.08" y="-10.16" length="middle"/>
<pin name="DIGIN1" x="-5.08" y="-20.32" length="middle"/>
<pin name="DIGIN2" x="-5.08" y="-22.86" length="middle"/>
<pin name="GND@1" x="-5.08" y="-7.62" length="middle"/>
<pin name="DIGINOUT3" x="-5.08" y="-25.4" length="middle"/>
<pin name="DIGINOUT4" x="-5.08" y="-27.94" length="middle"/>
<pin name="GND@2" x="-5.08" y="-30.48" length="middle"/>
<pin name="+5VDC@1" x="-5.08" y="-33.02" length="middle"/>
<pin name="ANIN1+" x="-5.08" y="-43.18" length="middle"/>
<pin name="ANIN1-" x="-5.08" y="-45.72" length="middle"/>
<pin name="ANIN2+" x="-5.08" y="-48.26" length="middle"/>
<pin name="ANIN2-" x="-5.08" y="-50.8" length="middle"/>
<pin name="ANOUT1" x="-5.08" y="-53.34" length="middle"/>
<pin name="ANOUT2" x="-5.08" y="-55.88" length="middle"/>
<pin name="GND@3" x="-5.08" y="-58.42" length="middle"/>
<pin name="GND@4" x="-5.08" y="-68.58" length="middle"/>
<pin name="USB_DATA-" x="-5.08" y="-71.12" length="middle"/>
<pin name="USB_DATA+" x="-5.08" y="-73.66" length="middle"/>
<pin name="VBUS" x="-5.08" y="-76.2" length="middle"/>
<pin name="GND@5" x="-5.08" y="-78.74" length="middle"/>
<pin name="MOTOR_WINDING1" x="43.18" y="-7.62" length="middle" rot="R180"/>
<pin name="MOTOR_WINDING2" x="43.18" y="-10.16" length="middle" rot="R180"/>
<pin name="MOTOR_WINDING3" x="43.18" y="-12.7" length="middle" rot="R180"/>
<pin name="+5VDC@2" x="43.18" y="-15.24" length="middle" rot="R180"/>
<pin name="GND@6" x="43.18" y="-17.78" length="middle" rot="R180"/>
<pin name="HALL_SENSOR1" x="43.18" y="-20.32" length="middle" rot="R180"/>
<pin name="HALL_SENSOR2" x="43.18" y="-22.86" length="middle" rot="R180"/>
<pin name="HALL_SENSOR3" x="43.18" y="-25.4" length="middle" rot="R180"/>
<wire x1="0" y1="-2.54" x2="0" y2="-83.82" width="0.254" layer="94"/>
<wire x1="0" y1="-83.82" x2="38.1" y2="-83.82" width="0.254" layer="94"/>
<wire x1="38.1" y1="-83.82" x2="38.1" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="38.1" y2="-2.54" width="0.254" layer="94"/>
<text x="0" y="-2.54" size="1.778" layer="94">&gt;NAME</text>
<text x="0" y="-86.36" size="1.778" layer="94">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="36-3_EC">
<gates>
<gate name="G$1" symbol="36-3_EC" x="22.86" y="22.86"/>
</gates>
<devices>
<device name="" package="36-3_EC">
<connects>
<connect gate="G$1" pin="+5VDC@1" pad="P$8"/>
<connect gate="G$1" pin="+5VDC@2" pad="P$24"/>
<connect gate="G$1" pin="+VCC" pad="P$2"/>
<connect gate="G$1" pin="ANIN1+" pad="P$9"/>
<connect gate="G$1" pin="ANIN1-" pad="P$10"/>
<connect gate="G$1" pin="ANIN2+" pad="P$11"/>
<connect gate="G$1" pin="ANIN2-" pad="P$12"/>
<connect gate="G$1" pin="ANOUT1" pad="P$13"/>
<connect gate="G$1" pin="ANOUT2" pad="P$14"/>
<connect gate="G$1" pin="DIGIN1" pad="P$3"/>
<connect gate="G$1" pin="DIGIN2" pad="P$4"/>
<connect gate="G$1" pin="DIGINOUT3" pad="P$5"/>
<connect gate="G$1" pin="DIGINOUT4" pad="P$6"/>
<connect gate="G$1" pin="GND@1" pad="P$1"/>
<connect gate="G$1" pin="GND@2" pad="P$7"/>
<connect gate="G$1" pin="GND@3" pad="P$15"/>
<connect gate="G$1" pin="GND@4" pad="P$16"/>
<connect gate="G$1" pin="GND@5" pad="P$20"/>
<connect gate="G$1" pin="GND@6" pad="P$25"/>
<connect gate="G$1" pin="HALL_SENSOR1" pad="P$26"/>
<connect gate="G$1" pin="HALL_SENSOR2" pad="P$27"/>
<connect gate="G$1" pin="HALL_SENSOR3" pad="P$28"/>
<connect gate="G$1" pin="MOTOR_WINDING1" pad="P$21"/>
<connect gate="G$1" pin="MOTOR_WINDING2" pad="P$22"/>
<connect gate="G$1" pin="MOTOR_WINDING3" pad="P$23"/>
<connect gate="G$1" pin="USB_DATA+" pad="P$18"/>
<connect gate="G$1" pin="USB_DATA-" pad="P$17"/>
<connect gate="G$1" pin="VBUS" pad="P$19"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="EC-45-flat">
<packages>
<package name="EC-45-FLAT">
<rectangle x1="0" y1="-8.89" x2="7.62" y2="5.08" layer="21"/>
<pad name="P$1" x="-1.27" y="3.81" drill="0.8" shape="square"/>
<pad name="P$2" x="-1.27" y="1.27" drill="0.8" shape="square"/>
<pad name="P$3" x="-1.27" y="-1.27" drill="0.8" shape="square"/>
<pad name="P$4" x="-1.27" y="-3.81" drill="0.8" shape="square"/>
<pad name="P$5" x="-1.27" y="-6.35" drill="0.8" shape="square"/>
<pad name="P$6" x="8.89" y="3.81" drill="0.8" shape="square"/>
<pad name="P$7" x="8.89" y="1.27" drill="0.8" shape="square"/>
<pad name="P$8" x="8.89" y="-1.27" drill="0.8" shape="square"/>
<pad name="P$9" x="8.89" y="-3.81" drill="0.8" shape="square"/>
</package>
</packages>
<symbols>
<symbol name="EC-45-FLAT">
<pin name="MOTOR_WINDING1" x="-2.54" y="17.78" length="middle"/>
<pin name="MOTOR_WINDING2" x="-2.54" y="15.24" length="middle"/>
<pin name="MOTOR_WINDING3" x="-2.54" y="12.7" length="middle"/>
<pin name="+5VDC" x="-2.54" y="10.16" length="middle"/>
<pin name="GND" x="-2.54" y="7.62" length="middle"/>
<pin name="HALL_SENSOR1" x="-2.54" y="5.08" length="middle"/>
<pin name="HALL_SENSOR2" x="-2.54" y="2.54" length="middle"/>
<pin name="HALL_SENSOR3" x="-2.54" y="0" length="middle"/>
<wire x1="2.54" y1="22.86" x2="2.54" y2="-5.08" width="0.254" layer="94"/>
<wire x1="2.54" y1="-5.08" x2="30.48" y2="-5.08" width="0.254" layer="94"/>
<wire x1="30.48" y1="-5.08" x2="30.48" y2="22.86" width="0.254" layer="94"/>
<wire x1="30.48" y1="22.86" x2="2.54" y2="22.86" width="0.254" layer="94"/>
<text x="2.54" y="-7.62" size="1.778" layer="94">&gt;VALUE</text>
<text x="2.54" y="22.86" size="1.778" layer="94">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="EC-45-FLAT">
<gates>
<gate name="G$1" symbol="EC-45-FLAT" x="2.54" y="2.54"/>
</gates>
<devices>
<device name="" package="EC-45-FLAT">
<connects>
<connect gate="G$1" pin="+5VDC" pad="P$3"/>
<connect gate="G$1" pin="GND" pad="P$6"/>
<connect gate="G$1" pin="HALL_SENSOR1" pad="P$1"/>
<connect gate="G$1" pin="HALL_SENSOR2" pad="P$2"/>
<connect gate="G$1" pin="HALL_SENSOR3" pad="P$5"/>
<connect gate="G$1" pin="MOTOR_WINDING1" pad="P$7"/>
<connect gate="G$1" pin="MOTOR_WINDING2" pad="P$8"/>
<connect gate="G$1" pin="MOTOR_WINDING3" pad="P$4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="GY-521">
<packages>
<package name="GY-521">
<pad name="P$1" x="2.54" y="0" drill="0.8" shape="square"/>
<pad name="P$2" x="2.54" y="-2.54" drill="0.8" shape="square"/>
<pad name="P$3" x="2.54" y="-5.08" drill="0.8" shape="square"/>
<pad name="P$4" x="2.54" y="-7.62" drill="0.8" shape="square"/>
<pad name="P$5" x="2.54" y="-10.16" drill="0.8" shape="square"/>
<pad name="P$6" x="2.54" y="-12.7" drill="0.8" shape="square"/>
<pad name="P$7" x="2.54" y="-15.24" drill="0.8" shape="square"/>
<pad name="P$8" x="2.54" y="-17.78" drill="0.8" shape="square"/>
<rectangle x1="3.81" y1="-20.32" x2="11.43" y2="2.54" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="GY-521">
<pin name="VCC" x="5.08" y="-2.54" length="middle"/>
<pin name="GND" x="5.08" y="-5.08" length="middle"/>
<pin name="SCL" x="5.08" y="-7.62" length="middle"/>
<pin name="SDA" x="5.08" y="-10.16" length="middle"/>
<pin name="XDA" x="5.08" y="-12.7" length="middle"/>
<pin name="XCL" x="5.08" y="-15.24" length="middle"/>
<pin name="AD0" x="5.08" y="-17.78" length="middle"/>
<pin name="INT" x="5.08" y="-20.32" length="middle"/>
<wire x1="10.16" y1="2.54" x2="10.16" y2="-25.4" width="0.254" layer="94"/>
<wire x1="10.16" y1="-25.4" x2="25.4" y2="-25.4" width="0.254" layer="94"/>
<wire x1="25.4" y1="-25.4" x2="25.4" y2="2.54" width="0.254" layer="94"/>
<wire x1="25.4" y1="2.54" x2="10.16" y2="2.54" width="0.254" layer="94"/>
<text x="10.16" y="-27.94" size="1.778" layer="94">&gt;VALUE</text>
<text x="10.16" y="2.54" size="1.778" layer="94">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="GY-521">
<gates>
<gate name="G$1" symbol="GY-521" x="-2.54" y="-5.08"/>
</gates>
<devices>
<device name="" package="GY-521">
<connects>
<connect gate="G$1" pin="AD0" pad="P$7"/>
<connect gate="G$1" pin="GND" pad="P$2"/>
<connect gate="G$1" pin="INT" pad="P$8"/>
<connect gate="G$1" pin="SCL" pad="P$3"/>
<connect gate="G$1" pin="SDA" pad="P$4"/>
<connect gate="G$1" pin="VCC" pad="P$1"/>
<connect gate="G$1" pin="XCL" pad="P$6"/>
<connect gate="G$1" pin="XDA" pad="P$5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="HS-82MG">
<packages>
<package name="HS-82MG">
<pad name="P$1" x="3.81" y="1.27" drill="0.8" shape="square"/>
<pad name="P$2" x="3.81" y="-1.27" drill="0.8" shape="square"/>
<pad name="P$3" x="3.81" y="-3.81" drill="0.8" shape="square"/>
<rectangle x1="5.08" y1="-6.35" x2="10.16" y2="3.81" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="HS-82MG">
<pin name="GND" x="7.62" y="-2.54" length="middle"/>
<pin name="PWM" x="7.62" y="-5.08" length="middle"/>
<pin name="+5VDC" x="7.62" y="-7.62" length="middle"/>
<wire x1="12.7" y1="2.54" x2="12.7" y2="-12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="-12.7" x2="27.94" y2="-12.7" width="0.254" layer="94"/>
<wire x1="27.94" y1="-12.7" x2="27.94" y2="2.54" width="0.254" layer="94"/>
<wire x1="27.94" y1="2.54" x2="12.7" y2="2.54" width="0.254" layer="94"/>
<text x="12.7" y="-15.24" size="1.778" layer="94">&gt;VALUE</text>
<text x="12.7" y="2.54" size="1.778" layer="94">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="HS-82MG">
<gates>
<gate name="G$1" symbol="HS-82MG" x="0" y="-5.08"/>
</gates>
<devices>
<device name="" package="HS-82MG">
<connects>
<connect gate="G$1" pin="+5VDC" pad="P$1"/>
<connect gate="G$1" pin="GND" pad="P$2"/>
<connect gate="G$1" pin="PWM" pad="P$3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="POWER_SUPPLY">
<packages>
<package name="POWER_SUPPLY">
<pad name="P$1" x="-6.35" y="3.81" drill="0.8" shape="square"/>
<pad name="P$2" x="-6.35" y="2.54" drill="0.8" shape="square"/>
<pad name="P$3" x="-6.35" y="1.27" drill="0.8" shape="square"/>
<pad name="P$4" x="-6.35" y="0" drill="0.8" shape="square"/>
<rectangle x1="-5.08" y1="-1.27" x2="-1.27" y2="5.08" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="POWER_SUPPLY">
<pin name="GND" x="-7.62" y="5.08" length="middle" rot="R180"/>
<pin name="+12-36VDC" x="-7.62" y="2.54" length="middle" rot="R180"/>
<pin name="+5VDC" x="-7.62" y="0" length="middle" rot="R180"/>
<wire x1="-12.7" y1="10.16" x2="-12.7" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-5.08" x2="-35.56" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-35.56" y1="-5.08" x2="-35.56" y2="10.16" width="0.254" layer="94"/>
<wire x1="-35.56" y1="10.16" x2="-12.7" y2="10.16" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="POWER_SUPPLY">
<gates>
<gate name="G$1" symbol="POWER_SUPPLY" x="38.1" y="-12.7"/>
</gates>
<devices>
<device name="" package="POWER_SUPPLY">
<connects>
<connect gate="G$1" pin="+12-36VDC" pad="P$3"/>
<connect gate="G$1" pin="+5VDC" pad="P$2"/>
<connect gate="G$1" pin="GND" pad="P$4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="BeagleBoneBlack">
<packages>
<package name="BEAGLEBONE">
<pad name="P$1" x="-6.35" y="3.81" drill="0.8" shape="square"/>
<pad name="P$2" x="-6.35" y="1.27" drill="0.8" shape="square"/>
<pad name="P$3" x="-6.35" y="-1.27" drill="0.8" shape="square"/>
<pad name="P$4" x="-6.35" y="-3.81" drill="0.8" shape="square"/>
<pad name="P$5" x="-6.35" y="-6.35" drill="0.8" shape="square"/>
<pad name="P$6" x="-6.35" y="-8.89" drill="0.8" shape="square"/>
<pad name="P$7" x="-6.35" y="-11.43" drill="0.8" shape="square"/>
<pad name="P$8" x="-6.35" y="-13.97" drill="0.8" shape="square"/>
<pad name="P$9" x="-6.35" y="-16.51" drill="0.8" shape="square"/>
<pad name="P$10" x="-6.35" y="-19.05" drill="0.8" shape="square"/>
<pad name="P$11" x="-6.35" y="6.35" drill="0.8" shape="square"/>
<pad name="P$12" x="-6.35" y="8.89" drill="0.8" shape="square"/>
<pad name="P$13" x="-6.35" y="11.43" drill="0.8" shape="square"/>
<pad name="P$14" x="-6.35" y="-21.59" drill="0.8" shape="square"/>
<pad name="P$15" x="-6.35" y="-24.13" drill="0.8" shape="square"/>
<pad name="P$16" x="-6.35" y="-26.67" drill="0.8" shape="square"/>
<pad name="P$17" x="-6.35" y="-29.21" drill="0.8" shape="square"/>
<pad name="P$18" x="-6.35" y="-31.75" drill="0.8" shape="square"/>
<pad name="P$19" x="-6.35" y="-34.29" drill="0.8" shape="square"/>
<pad name="P$20" x="-6.35" y="-36.83" drill="0.8" shape="square"/>
<pad name="P$21" x="-6.35" y="-39.37" drill="0.8" shape="square"/>
<pad name="P$22" x="-6.35" y="-41.91" drill="0.8" shape="square"/>
<pad name="P$23" x="-6.35" y="-44.45" drill="0.8" shape="square"/>
<pad name="P$24" x="-6.35" y="-46.99" drill="0.8" shape="square"/>
<pad name="P$25" x="3.81" y="-46.99" drill="0.8" shape="square"/>
<pad name="P$26" x="3.81" y="-44.45" drill="0.8" shape="square"/>
<pad name="P$27" x="3.81" y="-41.91" drill="0.8" shape="square"/>
<pad name="P$28" x="3.81" y="-39.37" drill="0.8" shape="square"/>
<pad name="P$29" x="3.81" y="-36.83" drill="0.8" shape="square"/>
<pad name="P$30" x="3.81" y="-34.29" drill="0.8" shape="square"/>
<pad name="P$31" x="3.81" y="-31.75" drill="0.8" shape="square"/>
<pad name="P$32" x="3.81" y="-29.21" drill="0.8" shape="square"/>
<pad name="P$33" x="3.81" y="-26.67" drill="0.8" shape="square"/>
<pad name="P$34" x="3.81" y="-24.13" drill="0.8" shape="square"/>
<pad name="P$35" x="3.81" y="-21.59" drill="0.8" shape="square"/>
<pad name="P$36" x="3.81" y="-19.05" drill="0.8" shape="square"/>
<pad name="P$37" x="3.81" y="-16.51" drill="0.8" shape="square"/>
<pad name="P$38" x="3.81" y="-13.97" drill="0.8" shape="square"/>
<pad name="P$39" x="3.81" y="-11.43" drill="0.8" shape="square"/>
<pad name="P$40" x="3.81" y="-8.89" drill="0.8" shape="square"/>
<pad name="P$41" x="3.81" y="-6.35" drill="0.8" shape="square"/>
<pad name="P$42" x="3.81" y="-3.81" drill="0.8" shape="square"/>
<pad name="P$43" x="3.81" y="-1.27" drill="0.8" shape="square"/>
<pad name="P$44" x="3.81" y="1.27" drill="0.8" shape="square"/>
<pad name="P$45" x="3.81" y="3.81" drill="0.8" shape="square"/>
<pad name="P$46" x="3.81" y="6.35" drill="0.8" shape="square"/>
<pad name="P$47" x="3.81" y="8.89" drill="0.8" shape="square"/>
<pad name="P$48" x="3.81" y="11.43" drill="0.8" shape="square"/>
<rectangle x1="-3.81" y1="-49.53" x2="1.27" y2="13.97" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="BEAGLEBONE">
<wire x1="2.54" y1="22.86" x2="2.54" y2="-43.18" width="0.254" layer="94"/>
<wire x1="2.54" y1="-43.18" x2="40.64" y2="-43.18" width="0.254" layer="94"/>
<wire x1="40.64" y1="-43.18" x2="40.64" y2="22.86" width="0.254" layer="94"/>
<wire x1="40.64" y1="22.86" x2="2.54" y2="22.86" width="0.254" layer="94"/>
<pin name="GND@1" x="-2.54" y="17.78" length="middle"/>
<pin name="GND@4" x="45.72" y="17.78" length="middle" rot="R180"/>
<pin name="DC_3.3V@1" x="-2.54" y="15.24" length="middle"/>
<pin name="DC_3.3V@2" x="45.72" y="15.24" length="middle" rot="R180"/>
<pin name="VDD_5V@1" x="-2.54" y="12.7" length="middle"/>
<pin name="VDD_5V@2" x="45.72" y="12.7" length="middle" rot="R180"/>
<pin name="SYS_5V@1" x="-2.54" y="10.16" length="middle"/>
<pin name="SYS_5V@2" x="45.72" y="10.16" length="middle" rot="R180"/>
<pin name="PWR_BUT" x="-2.54" y="7.62" length="middle"/>
<pin name="SYS_RESET" x="45.72" y="7.62" length="middle" rot="R180"/>
<pin name="UART4_RXD" x="-2.54" y="5.08" length="middle"/>
<pin name="GPIO1_28" x="45.72" y="5.08" length="middle" rot="R180"/>
<pin name="UART4_TXD" x="-2.54" y="2.54" length="middle"/>
<pin name="EHRPWM1A" x="45.72" y="2.54" length="middle" rot="R180"/>
<pin name="GPIO1_16" x="-2.54" y="0" length="middle"/>
<pin name="EHRPWM1B" x="45.72" y="0" length="middle" rot="R180"/>
<pin name="I2C1_SCL" x="-2.54" y="-2.54" length="middle"/>
<pin name="I2C1_SDA" x="45.72" y="-2.54" length="middle" rot="R180"/>
<pin name="I2C2_SCL" x="-2.54" y="-5.08" length="middle"/>
<pin name="I2C2_SDA" x="45.72" y="-5.08" length="middle" rot="R180"/>
<pin name="UART2_TXD" x="-2.54" y="-7.62" length="middle"/>
<pin name="UART2_RXD" x="45.72" y="-7.62" length="middle" rot="R180"/>
<pin name="GPIO1_17" x="-2.54" y="-10.16" length="middle"/>
<pin name="UART1_TXD" x="45.72" y="-10.16" length="middle" rot="R180"/>
<pin name="GPIO3_21" x="-2.54" y="-12.7" length="middle"/>
<pin name="UART1_RXD" x="45.72" y="-12.7" length="middle" rot="R180"/>
<pin name="GPIO3_19" x="-2.54" y="-15.24" length="middle"/>
<pin name="SPI1_CS0" x="45.72" y="-15.24" length="middle" rot="R180"/>
<pin name="SPI1_D0" x="-2.54" y="-17.78" length="middle"/>
<pin name="SPI1_D1" x="45.72" y="-17.78" length="middle" rot="R180"/>
<pin name="SPI1_SCLK" x="-2.54" y="-20.32" length="middle"/>
<pin name="VADC" x="45.72" y="-20.32" length="middle" rot="R180"/>
<pin name="AIN4" x="-2.54" y="-22.86" length="middle"/>
<pin name="AGND" x="45.72" y="-22.86" length="middle" rot="R180"/>
<pin name="AIN6" x="-2.54" y="-25.4" length="middle"/>
<pin name="AIN5" x="45.72" y="-25.4" length="middle" rot="R180"/>
<pin name="AIN2" x="-2.54" y="-27.94" length="middle"/>
<pin name="AIN3" x="45.72" y="-27.94" length="middle" rot="R180"/>
<pin name="AIN0" x="-2.54" y="-30.48" length="middle"/>
<pin name="AIN1" x="45.72" y="-30.48" length="middle" rot="R180"/>
<pin name="GPIO3_20" x="-2.54" y="-33.02" length="middle"/>
<pin name="GPIO0_7" x="45.72" y="-33.02" length="middle" rot="R180"/>
<pin name="GND@2" x="-2.54" y="-35.56" length="middle"/>
<pin name="GND@5" x="45.72" y="-35.56" length="middle" rot="R180"/>
<pin name="GND@3" x="-2.54" y="-38.1" length="middle"/>
<pin name="GND@6" x="45.72" y="-38.1" length="middle" rot="R180"/>
<text x="2.54" y="22.86" size="1.27" layer="94">&gt;NAME</text>
<text x="2.54" y="-45.72" size="1.27" layer="94">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="BEAGLEBONE" uservalue="yes">
<gates>
<gate name="G$1" symbol="BEAGLEBONE" x="-22.86" y="15.24"/>
</gates>
<devices>
<device name="" package="BEAGLEBONE">
<connects>
<connect gate="G$1" pin="AGND" pad="P$34"/>
<connect gate="G$1" pin="AIN0" pad="P$39"/>
<connect gate="G$1" pin="AIN1" pad="P$40"/>
<connect gate="G$1" pin="AIN2" pad="P$37"/>
<connect gate="G$1" pin="AIN3" pad="P$38"/>
<connect gate="G$1" pin="AIN4" pad="P$33"/>
<connect gate="G$1" pin="AIN5" pad="P$36"/>
<connect gate="G$1" pin="AIN6" pad="P$35"/>
<connect gate="G$1" pin="DC_3.3V@1" pad="P$3"/>
<connect gate="G$1" pin="DC_3.3V@2" pad="P$4"/>
<connect gate="G$1" pin="EHRPWM1A" pad="P$14"/>
<connect gate="G$1" pin="EHRPWM1B" pad="P$16"/>
<connect gate="G$1" pin="GND@1" pad="P$1"/>
<connect gate="G$1" pin="GND@2" pad="P$43"/>
<connect gate="G$1" pin="GND@3" pad="P$45"/>
<connect gate="G$1" pin="GND@4" pad="P$2"/>
<connect gate="G$1" pin="GND@5" pad="P$44"/>
<connect gate="G$1" pin="GND@6" pad="P$46"/>
<connect gate="G$1" pin="GPIO0_7" pad="P$42"/>
<connect gate="G$1" pin="GPIO1_16" pad="P$15"/>
<connect gate="G$1" pin="GPIO1_17" pad="P$23"/>
<connect gate="G$1" pin="GPIO1_28" pad="P$12"/>
<connect gate="G$1" pin="GPIO3_19" pad="P$27"/>
<connect gate="G$1" pin="GPIO3_20" pad="P$41"/>
<connect gate="G$1" pin="GPIO3_21" pad="P$25"/>
<connect gate="G$1" pin="I2C1_SCL" pad="P$17"/>
<connect gate="G$1" pin="I2C1_SDA" pad="P$18"/>
<connect gate="G$1" pin="I2C2_SCL" pad="P$19"/>
<connect gate="G$1" pin="I2C2_SDA" pad="P$20"/>
<connect gate="G$1" pin="PWR_BUT" pad="P$9"/>
<connect gate="G$1" pin="SPI1_CS0" pad="P$28"/>
<connect gate="G$1" pin="SPI1_D0" pad="P$29"/>
<connect gate="G$1" pin="SPI1_D1" pad="P$30"/>
<connect gate="G$1" pin="SPI1_SCLK" pad="P$31"/>
<connect gate="G$1" pin="SYS_5V@1" pad="P$7"/>
<connect gate="G$1" pin="SYS_5V@2" pad="P$8"/>
<connect gate="G$1" pin="SYS_RESET" pad="P$10"/>
<connect gate="G$1" pin="UART1_RXD" pad="P$26"/>
<connect gate="G$1" pin="UART1_TXD" pad="P$24"/>
<connect gate="G$1" pin="UART2_RXD" pad="P$22"/>
<connect gate="G$1" pin="UART2_TXD" pad="P$21"/>
<connect gate="G$1" pin="UART4_RXD" pad="P$11"/>
<connect gate="G$1" pin="UART4_TXD" pad="P$13"/>
<connect gate="G$1" pin="VADC" pad="P$32"/>
<connect gate="G$1" pin="VDD_5V@1" pad="P$5"/>
<connect gate="G$1" pin="VDD_5V@2" pad="P$6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="BeagleBoneBlack2">
<packages>
<package name="BEAGLEBONE">
<pad name="P$1" x="-6.35" y="3.81" drill="0.8" shape="square"/>
<pad name="P$2" x="-6.35" y="1.27" drill="0.8" shape="square"/>
<pad name="P$3" x="-6.35" y="-1.27" drill="0.8" shape="square"/>
<pad name="P$4" x="-6.35" y="-3.81" drill="0.8" shape="square"/>
<pad name="P$5" x="-6.35" y="-6.35" drill="0.8" shape="square"/>
<pad name="P$6" x="-6.35" y="-8.89" drill="0.8" shape="square"/>
<pad name="P$7" x="-6.35" y="-11.43" drill="0.8" shape="square"/>
<pad name="P$8" x="-6.35" y="-13.97" drill="0.8" shape="square"/>
<pad name="P$9" x="-6.35" y="-16.51" drill="0.8" shape="square"/>
<pad name="P$10" x="-6.35" y="-19.05" drill="0.8" shape="square"/>
<pad name="P$11" x="-6.35" y="6.35" drill="0.8" shape="square"/>
<pad name="P$12" x="-6.35" y="8.89" drill="0.8" shape="square"/>
<pad name="P$13" x="-6.35" y="11.43" drill="0.8" shape="square"/>
<pad name="P$14" x="-6.35" y="-21.59" drill="0.8" shape="square"/>
<pad name="P$15" x="-6.35" y="-24.13" drill="0.8" shape="square"/>
<pad name="P$16" x="-6.35" y="-26.67" drill="0.8" shape="square"/>
<pad name="P$17" x="-6.35" y="-29.21" drill="0.8" shape="square"/>
<pad name="P$18" x="-6.35" y="-31.75" drill="0.8" shape="square"/>
<pad name="P$19" x="-6.35" y="-34.29" drill="0.8" shape="square"/>
<pad name="P$20" x="-6.35" y="-36.83" drill="0.8" shape="square"/>
<pad name="P$21" x="-6.35" y="-39.37" drill="0.8" shape="square"/>
<pad name="P$22" x="-6.35" y="-41.91" drill="0.8" shape="square"/>
<pad name="P$23" x="-6.35" y="-44.45" drill="0.8" shape="square"/>
<pad name="P$24" x="-6.35" y="-46.99" drill="0.8" shape="square"/>
<pad name="P$25" x="3.81" y="-46.99" drill="0.8" shape="square"/>
<pad name="P$26" x="3.81" y="-44.45" drill="0.8" shape="square"/>
<pad name="P$27" x="3.81" y="-41.91" drill="0.8" shape="square"/>
<pad name="P$28" x="3.81" y="-39.37" drill="0.8" shape="square"/>
<pad name="P$29" x="3.81" y="-36.83" drill="0.8" shape="square"/>
<pad name="P$30" x="3.81" y="-34.29" drill="0.8" shape="square"/>
<pad name="P$31" x="3.81" y="-31.75" drill="0.8" shape="square"/>
<pad name="P$32" x="3.81" y="-29.21" drill="0.8" shape="square"/>
<pad name="P$33" x="3.81" y="-26.67" drill="0.8" shape="square"/>
<pad name="P$34" x="3.81" y="-24.13" drill="0.8" shape="square"/>
<pad name="P$35" x="3.81" y="-21.59" drill="0.8" shape="square"/>
<pad name="P$36" x="3.81" y="-19.05" drill="0.8" shape="square"/>
<pad name="P$37" x="3.81" y="-16.51" drill="0.8" shape="square"/>
<pad name="P$38" x="3.81" y="-13.97" drill="0.8" shape="square"/>
<pad name="P$39" x="3.81" y="-11.43" drill="0.8" shape="square"/>
<pad name="P$40" x="3.81" y="-8.89" drill="0.8" shape="square"/>
<pad name="P$41" x="3.81" y="-6.35" drill="0.8" shape="square"/>
<pad name="P$42" x="3.81" y="-3.81" drill="0.8" shape="square"/>
<pad name="P$43" x="3.81" y="-1.27" drill="0.8" shape="square"/>
<pad name="P$44" x="3.81" y="1.27" drill="0.8" shape="square"/>
<pad name="P$45" x="3.81" y="3.81" drill="0.8" shape="square"/>
<pad name="P$46" x="3.81" y="6.35" drill="0.8" shape="square"/>
<pad name="P$47" x="3.81" y="8.89" drill="0.8" shape="square"/>
<pad name="P$48" x="3.81" y="11.43" drill="0.8" shape="square"/>
<rectangle x1="-3.81" y1="-49.53" x2="1.27" y2="13.97" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="BEAGLEBONE">
<wire x1="2.54" y1="22.86" x2="2.54" y2="-43.18" width="0.254" layer="94"/>
<wire x1="2.54" y1="-43.18" x2="40.64" y2="-43.18" width="0.254" layer="94"/>
<wire x1="40.64" y1="-43.18" x2="40.64" y2="22.86" width="0.254" layer="94"/>
<wire x1="40.64" y1="22.86" x2="2.54" y2="22.86" width="0.254" layer="94"/>
<pin name="GND@1" x="-2.54" y="17.78" length="middle"/>
<pin name="GND@2" x="45.72" y="17.78" length="middle" rot="R180"/>
<pin name="GPIO1_6" x="-2.54" y="15.24" length="middle"/>
<pin name="GPIO1_7" x="45.72" y="15.24" length="middle" rot="R180"/>
<pin name="GPIO1_2" x="-2.54" y="12.7" length="middle"/>
<pin name="GPIO1_3" x="45.72" y="12.7" length="middle" rot="R180"/>
<pin name="GPIO2_2" x="-2.54" y="10.16" length="middle"/>
<pin name="GPIO2_3" x="45.72" y="10.16" length="middle" rot="R180"/>
<pin name="TIMER5" x="-2.54" y="7.62" length="middle"/>
<pin name="TIMER6" x="45.72" y="7.62" length="middle" rot="R180"/>
<pin name="GPIO1_13" x="-2.54" y="5.08" length="middle"/>
<pin name="GPIO1_12" x="45.72" y="5.08" length="middle" rot="R180"/>
<pin name="EHRPWM2B" x="-2.54" y="2.54" length="middle"/>
<pin name="GPIO0_26" x="45.72" y="2.54" length="middle" rot="R180"/>
<pin name="GPIO1_15" x="-2.54" y="0" length="middle"/>
<pin name="GPIO1_14" x="45.72" y="0" length="middle" rot="R180"/>
<pin name="GPIO0_27" x="-2.54" y="-2.54" length="middle"/>
<pin name="GPIO2_1" x="45.72" y="-2.54" length="middle" rot="R180"/>
<pin name="EHRPWM2A" x="-2.54" y="-5.08" length="middle"/>
<pin name="GPIO1_31" x="45.72" y="-5.08" length="middle" rot="R180"/>
<pin name="GPIO1_30" x="-2.54" y="-7.62" length="middle"/>
<pin name="GPIO1_5" x="45.72" y="-7.62" length="middle" rot="R180"/>
<pin name="GPIO1_4" x="-2.54" y="-10.16" length="middle"/>
<pin name="GPIO1_1" x="45.72" y="-10.16" length="middle" rot="R180"/>
<pin name="GPIO1_0" x="-2.54" y="-12.7" length="middle"/>
<pin name="GPIO1_29" x="45.72" y="-12.7" length="middle" rot="R180"/>
<pin name="GPIO2_22" x="-2.54" y="-15.24" length="middle"/>
<pin name="GPIO2_24" x="45.72" y="-15.24" length="middle" rot="R180"/>
<pin name="GPIO2_23" x="-2.54" y="-17.78" length="middle"/>
<pin name="GPIO2_25" x="45.72" y="-17.78" length="middle" rot="R180"/>
<pin name="UART5_CTSN" x="-2.54" y="-20.32" length="middle"/>
<pin name="UART5_RTSN" x="45.72" y="-20.32" length="middle" rot="R180"/>
<pin name="UART4_RTSN" x="-2.54" y="-22.86" length="middle"/>
<pin name="UART3_RTSN" x="45.72" y="-22.86" length="middle" rot="R180"/>
<pin name="UART4_CTSN" x="-2.54" y="-25.4" length="middle"/>
<pin name="UART3_CTSN" x="45.72" y="-25.4" length="middle" rot="R180"/>
<pin name="UART5_TXD" x="-2.54" y="-27.94" length="middle"/>
<pin name="UART5_RXD" x="45.72" y="-27.94" length="middle" rot="R180"/>
<pin name="GPIO2_12" x="-2.54" y="-30.48" length="middle"/>
<pin name="GPIO2_13" x="45.72" y="-30.48" length="middle" rot="R180"/>
<pin name="GPIO2_10" x="-2.54" y="-33.02" length="middle"/>
<pin name="GPIO2_11" x="45.72" y="-33.02" length="middle" rot="R180"/>
<pin name="GPIO2_8" x="-2.54" y="-35.56" length="middle"/>
<pin name="GPIO2_9" x="45.72" y="-35.56" length="middle" rot="R180"/>
<pin name="GPIO2_6" x="-2.54" y="-38.1" length="middle"/>
<pin name="GPIO2_7" x="45.72" y="-38.1" length="middle" rot="R180"/>
<text x="2.54" y="22.86" size="1.27" layer="94">&gt;NAME</text>
<text x="2.54" y="-45.72" size="1.27" layer="94">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="BEAGLEBONE" uservalue="yes">
<gates>
<gate name="G$1" symbol="BEAGLEBONE" x="-22.86" y="15.24"/>
</gates>
<devices>
<device name="" package="BEAGLEBONE">
<connects>
<connect gate="G$1" pin="EHRPWM2A" pad="P$19"/>
<connect gate="G$1" pin="EHRPWM2B" pad="P$13"/>
<connect gate="G$1" pin="GND@1" pad="P$1"/>
<connect gate="G$1" pin="GND@2" pad="P$2"/>
<connect gate="G$1" pin="GPIO0_26" pad="P$14"/>
<connect gate="G$1" pin="GPIO0_27" pad="P$17"/>
<connect gate="G$1" pin="GPIO1_0" pad="P$25"/>
<connect gate="G$1" pin="GPIO1_1" pad="P$24"/>
<connect gate="G$1" pin="GPIO1_12" pad="P$12"/>
<connect gate="G$1" pin="GPIO1_13" pad="P$11"/>
<connect gate="G$1" pin="GPIO1_14" pad="P$16"/>
<connect gate="G$1" pin="GPIO1_15" pad="P$15"/>
<connect gate="G$1" pin="GPIO1_2" pad="P$5"/>
<connect gate="G$1" pin="GPIO1_29" pad="P$26"/>
<connect gate="G$1" pin="GPIO1_3" pad="P$6"/>
<connect gate="G$1" pin="GPIO1_30" pad="P$21"/>
<connect gate="G$1" pin="GPIO1_31" pad="P$20"/>
<connect gate="G$1" pin="GPIO1_4" pad="P$23"/>
<connect gate="G$1" pin="GPIO1_5" pad="P$22"/>
<connect gate="G$1" pin="GPIO1_6" pad="P$3"/>
<connect gate="G$1" pin="GPIO1_7" pad="P$4"/>
<connect gate="G$1" pin="GPIO2_1" pad="P$18"/>
<connect gate="G$1" pin="GPIO2_10" pad="P$41"/>
<connect gate="G$1" pin="GPIO2_11" pad="P$42"/>
<connect gate="G$1" pin="GPIO2_12" pad="P$39"/>
<connect gate="G$1" pin="GPIO2_13" pad="P$40"/>
<connect gate="G$1" pin="GPIO2_2" pad="P$7"/>
<connect gate="G$1" pin="GPIO2_22" pad="P$27"/>
<connect gate="G$1" pin="GPIO2_23" pad="P$29"/>
<connect gate="G$1" pin="GPIO2_24" pad="P$28"/>
<connect gate="G$1" pin="GPIO2_25" pad="P$30"/>
<connect gate="G$1" pin="GPIO2_3" pad="P$8"/>
<connect gate="G$1" pin="GPIO2_6" pad="P$45"/>
<connect gate="G$1" pin="GPIO2_7" pad="P$46"/>
<connect gate="G$1" pin="GPIO2_8" pad="P$43"/>
<connect gate="G$1" pin="GPIO2_9" pad="P$44"/>
<connect gate="G$1" pin="TIMER5" pad="P$9"/>
<connect gate="G$1" pin="TIMER6" pad="P$10"/>
<connect gate="G$1" pin="UART3_CTSN" pad="P$36"/>
<connect gate="G$1" pin="UART3_RTSN" pad="P$34"/>
<connect gate="G$1" pin="UART4_CTSN" pad="P$35"/>
<connect gate="G$1" pin="UART4_RTSN" pad="P$33"/>
<connect gate="G$1" pin="UART5_CTSN" pad="P$31"/>
<connect gate="G$1" pin="UART5_RTSN" pad="P$32"/>
<connect gate="G$1" pin="UART5_RXD" pad="P$38"/>
<connect gate="G$1" pin="UART5_TXD" pad="P$37"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="36-3-EC" deviceset="36-3_EC" device=""/>
<part name="U$2" library="EC-45-flat" deviceset="EC-45-FLAT" device=""/>
<part name="U$7" library="GY-521" deviceset="GY-521" device=""/>
<part name="U$8" library="GY-521" deviceset="GY-521" device=""/>
<part name="U$9" library="HS-82MG" deviceset="HS-82MG" device=""/>
<part name="U$10" library="POWER_SUPPLY" deviceset="POWER_SUPPLY" device=""/>
<part name="U$5" library="BeagleBoneBlack" deviceset="BEAGLEBONE" device="" value="BBB_X1"/>
<part name="U$6" library="BeagleBoneBlack2" deviceset="BEAGLEBONE" device="" value="BBB_X2"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="109.22" y="83.82"/>
<instance part="U$2" gate="G$1" x="175.26" y="58.42"/>
<instance part="U$7" gate="G$1" x="99.06" y="-17.78"/>
<instance part="U$8" gate="G$1" x="99.06" y="-55.88"/>
<instance part="U$9" gate="G$1" x="96.52" y="-99.06"/>
<instance part="U$10" gate="G$1" x="-76.2" y="71.12"/>
<instance part="U$5" gate="G$1" x="-30.48" y="33.02"/>
<instance part="U$6" gate="G$1" x="-30.48" y="-53.34"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="MOTOR_WINDING1"/>
<pinref part="U$2" gate="G$1" pin="MOTOR_WINDING1"/>
<wire x1="152.4" y1="76.2" x2="172.72" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="MOTOR_WINDING2"/>
<pinref part="U$2" gate="G$1" pin="MOTOR_WINDING2"/>
<wire x1="152.4" y1="73.66" x2="172.72" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="MOTOR_WINDING3"/>
<pinref part="U$2" gate="G$1" pin="MOTOR_WINDING3"/>
<wire x1="152.4" y1="71.12" x2="172.72" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="+5VDC@2"/>
<pinref part="U$2" gate="G$1" pin="+5VDC"/>
<wire x1="152.4" y1="68.58" x2="172.72" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND@6"/>
<pinref part="U$2" gate="G$1" pin="GND"/>
<wire x1="152.4" y1="66.04" x2="172.72" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="HALL_SENSOR1"/>
<pinref part="U$2" gate="G$1" pin="HALL_SENSOR1"/>
<wire x1="152.4" y1="63.5" x2="172.72" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="HALL_SENSOR2"/>
<pinref part="U$2" gate="G$1" pin="HALL_SENSOR2"/>
<wire x1="152.4" y1="60.96" x2="172.72" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="HALL_SENSOR3"/>
<pinref part="U$2" gate="G$1" pin="HALL_SENSOR3"/>
<wire x1="152.4" y1="58.42" x2="172.72" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="U$10" gate="G$1" pin="+12-36VDC"/>
<pinref part="U$1" gate="G$1" pin="+VCC"/>
<wire x1="-83.82" y1="73.66" x2="104.14" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="VDD_3V3" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="DC_3.3V@1"/>
<wire x1="-33.02" y1="48.26" x2="-53.34" y2="48.26" width="0.1524" layer="91"/>
<label x="-48.26" y="48.26" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="83.82" y1="-20.32" x2="104.14" y2="-20.32" width="0.1524" layer="91"/>
<label x="88.9" y="-20.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="VCC"/>
<wire x1="104.14" y1="-58.42" x2="83.82" y2="-58.42" width="0.1524" layer="91"/>
<label x="88.9" y="-58.42" size="1.778" layer="95"/>
</segment>
</net>
<net name="I2C_SCL" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="I2C2_SCL"/>
<wire x1="-33.02" y1="27.94" x2="-53.34" y2="27.94" width="0.1524" layer="91"/>
<label x="-48.26" y="27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$7" gate="G$1" pin="SCL"/>
<wire x1="104.14" y1="-25.4" x2="83.82" y2="-25.4" width="0.1524" layer="91"/>
<label x="88.9" y="-25.4" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="SCL"/>
<wire x1="104.14" y1="-63.5" x2="83.82" y2="-63.5" width="0.1524" layer="91"/>
<label x="88.9" y="-63.5" size="1.778" layer="95"/>
</segment>
</net>
<net name="ADC_EC" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="AIN0"/>
<wire x1="-33.02" y1="2.54" x2="-53.34" y2="2.54" width="0.1524" layer="91"/>
<label x="-48.26" y="2.54" size="1.778" layer="95"/>
<pinref part="U$1" gate="G$1" pin="ANOUT2"/>
<wire x1="104.14" y1="27.94" x2="53.34" y2="27.94" width="0.1524" layer="91"/>
<wire x1="53.34" y1="27.94" x2="53.34" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="53.34" y1="-17.78" x2="-53.34" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-53.34" y1="-17.78" x2="-53.34" y2="2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="PWM_SERVO" class="0">
<segment>
<wire x1="35.56" y1="33.02" x2="15.24" y2="33.02" width="0.1524" layer="91"/>
<label x="20.32" y="33.02" size="1.778" layer="95"/>
<pinref part="U$5" gate="G$1" pin="EHRPWM1B"/>
</segment>
<segment>
<pinref part="U$9" gate="G$1" pin="PWM"/>
<wire x1="104.14" y1="-104.14" x2="83.82" y2="-104.14" width="0.1524" layer="91"/>
<label x="88.9" y="-104.14" size="1.778" layer="95"/>
</segment>
</net>
<net name="I2C_SDA" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="I2C2_SDA"/>
<wire x1="15.24" y1="27.94" x2="35.56" y2="27.94" width="0.1524" layer="91"/>
<label x="20.32" y="27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$7" gate="G$1" pin="SDA"/>
<wire x1="104.14" y1="-27.94" x2="83.82" y2="-27.94" width="0.1524" layer="91"/>
<label x="88.9" y="-27.94" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="SDA"/>
<wire x1="104.14" y1="-66.04" x2="83.82" y2="-66.04" width="0.1524" layer="91"/>
<label x="88.9" y="-66.04" size="1.778" layer="95"/>
</segment>
</net>
<net name="ENABLE_EC" class="0">
<segment>
<wire x1="-53.34" y1="-43.18" x2="-33.02" y2="-43.18" width="0.1524" layer="91"/>
<label x="-50.8" y="-43.18" size="1.778" layer="95"/>
<pinref part="U$6" gate="G$1" pin="GPIO2_2"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="DIGIN2"/>
<wire x1="104.14" y1="60.96" x2="83.82" y2="60.96" width="0.1524" layer="91"/>
<label x="86.36" y="60.96" size="1.778" layer="95"/>
</segment>
</net>
<net name="PWM_EC" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="EHRPWM2B"/>
<wire x1="-33.02" y1="-50.8" x2="-53.34" y2="-50.8" width="0.1524" layer="91"/>
<label x="-50.8" y="-50.8" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="DIGIN1"/>
<wire x1="104.14" y1="63.5" x2="83.82" y2="63.5" width="0.1524" layer="91"/>
<label x="86.36" y="63.5" size="1.778" layer="95"/>
</segment>
</net>
<net name="DIRECTION_EC" class="0">
<segment>
<wire x1="35.56" y1="-43.18" x2="15.24" y2="-43.18" width="0.1524" layer="91"/>
<label x="17.78" y="-43.18" size="1.778" layer="95"/>
<pinref part="U$6" gate="G$1" pin="GPIO2_3"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="DIGINOUT3"/>
<wire x1="104.14" y1="58.42" x2="83.82" y2="58.42" width="0.1524" layer="91"/>
<label x="86.36" y="58.42" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND@1"/>
<wire x1="60.96" y1="76.2" x2="104.14" y2="76.2" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="GND@2"/>
<wire x1="104.14" y1="53.34" x2="60.96" y2="53.34" width="0.1524" layer="91"/>
<wire x1="60.96" y1="53.34" x2="60.96" y2="76.2" width="0.1524" layer="91"/>
<junction x="60.96" y="76.2"/>
<pinref part="U$10" gate="G$1" pin="GND"/>
<wire x1="-83.82" y1="76.2" x2="-63.5" y2="76.2" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="GND@1"/>
<wire x1="-63.5" y1="76.2" x2="60.96" y2="76.2" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="50.8" x2="-63.5" y2="50.8" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="50.8" x2="-63.5" y2="76.2" width="0.1524" layer="91"/>
<junction x="-63.5" y="76.2"/>
<pinref part="U$6" gate="G$1" pin="GND@1"/>
<wire x1="-33.02" y1="-35.56" x2="-63.5" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="-35.56" x2="-63.5" y2="50.8" width="0.1524" layer="91"/>
<junction x="-63.5" y="50.8"/>
</segment>
<segment>
<pinref part="U$7" gate="G$1" pin="GND"/>
<wire x1="104.14" y1="-22.86" x2="83.82" y2="-22.86" width="0.1524" layer="91"/>
<label x="88.9" y="-22.86" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="GND"/>
<wire x1="104.14" y1="-60.96" x2="83.82" y2="-60.96" width="0.1524" layer="91"/>
<label x="88.9" y="-60.96" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$9" gate="G$1" pin="GND"/>
<wire x1="104.14" y1="-101.6" x2="83.82" y2="-101.6" width="0.1524" layer="91"/>
<label x="88.9" y="-101.6" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND@3"/>
<wire x1="104.14" y1="25.4" x2="83.82" y2="25.4" width="0.1524" layer="91"/>
<label x="86.36" y="25.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U$9" gate="G$1" pin="+5VDC"/>
<wire x1="104.14" y1="-106.68" x2="-71.12" y2="-106.68" width="0.1524" layer="91"/>
<pinref part="U$10" gate="G$1" pin="+5VDC"/>
<wire x1="-83.82" y1="71.12" x2="-71.12" y2="71.12" width="0.1524" layer="91"/>
<wire x1="-71.12" y1="71.12" x2="53.34" y2="71.12" width="0.1524" layer="91"/>
<wire x1="53.34" y1="71.12" x2="53.34" y2="50.8" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="+5VDC@1"/>
<wire x1="53.34" y1="50.8" x2="104.14" y2="50.8" width="0.1524" layer="91"/>
<wire x1="-71.12" y1="-106.68" x2="-71.12" y2="71.12" width="0.1524" layer="91"/>
<junction x="-71.12" y="71.12"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>