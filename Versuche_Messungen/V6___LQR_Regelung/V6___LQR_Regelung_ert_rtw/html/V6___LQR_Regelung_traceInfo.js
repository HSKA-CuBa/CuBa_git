function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Add */
	this.urlHashMap["V6___LQR_Regelung:17"] = "V6___LQR_Regelung.c:72";
	/* <Root>/Constant */
	this.urlHashMap["V6___LQR_Regelung:18"] = "V6___LQR_Regelung.h:147&V6___LQR_Regelung_data.c:57";
	/* <Root>/Constant1 */
	this.urlHashMap["V6___LQR_Regelung:46"] = "V6___LQR_Regelung.c:66&V6___LQR_Regelung.h:126&V6___LQR_Regelung_data.c:36";
	/* <Root>/Constant2 */
	this.urlHashMap["V6___LQR_Regelung:20"] = "V6___LQR_Regelung.c:67&V6___LQR_Regelung.h:120&V6___LQR_Regelung_data.c:30";
	/* <Root>/Gain */
	this.urlHashMap["V6___LQR_Regelung:21"] = "V6___LQR_Regelung.c:68&V6___LQR_Regelung.h:144&V6___LQR_Regelung_data.c:54";
	/* <Root>/Gain1 */
	this.urlHashMap["V6___LQR_Regelung:38"] = "V6___LQR_Regelung.c:69&V6___LQR_Regelung.h:129&V6___LQR_Regelung_data.c:39";
	/* <Root>/Gain2 */
	this.urlHashMap["V6___LQR_Regelung:39"] = "V6___LQR_Regelung.c:70&V6___LQR_Regelung.h:132&V6___LQR_Regelung_data.c:42";
	/* <Root>/Gain3 */
	this.urlHashMap["V6___LQR_Regelung:40"] = "V6___LQR_Regelung.c:71&V6___LQR_Regelung.h:117&V6___LQR_Regelung_data.c:26";
	/* <Root>/S-Function Builder */
	this.urlHashMap["V6___LQR_Regelung:22"] = "V6___LQR_Regelung.c:83";
	/* <Root>/S-Function Builder1 */
	this.urlHashMap["V6___LQR_Regelung:23"] = "V6___LQR_Regelung.c:62&V6___LQR_Regelung.h:97";
	/* <Root>/S-Function Builder2 */
	this.urlHashMap["V6___LQR_Regelung:25"] = "V6___LQR_Regelung.c:51,105,236&V6___LQR_Regelung.h:79,80,81,82,104,123&V6___LQR_Regelung_data.c:33";
	/* <Root>/Scope1 */
	this.urlHashMap["V6___LQR_Regelung:26"] = "V6___LQR_Regelung.h:107";
	/* <Root>/Scope2 */
	this.urlHashMap["V6___LQR_Regelung:42"] = "V6___LQR_Regelung.h:111";
	/* <Root>/Sensor1 */
	this.urlHashMap["V6___LQR_Regelung:27"] = "V6___LQR_Regelung.c:37,91,212&V6___LQR_Regelung.h:85,86,87,88,89,90,102,138,150&V6___LQR_Regelung_data.c:48,60";
	/* <Root>/Sensor2 */
	this.urlHashMap["V6___LQR_Regelung:28"] = "V6___LQR_Regelung.c:44,98,224&V6___LQR_Regelung.h:91,92,93,94,95,96,103,141,153&V6___LQR_Regelung_data.c:51,63";
	/* <Root>/Sum */
	this.urlHashMap["V6___LQR_Regelung:41"] = "V6___LQR_Regelung.c:65&V6___LQR_Regelung.h:83";
	/* <Root>/Sum1 */
	this.urlHashMap["V6___LQR_Regelung:45"] = "V6___LQR_Regelung.c:73";
	/* <Root>/radtodeg1 */
	this.urlHashMap["V6___LQR_Regelung:36"] = "V6___LQR_Regelung.c:87&V6___LQR_Regelung.h:84,135&V6___LQR_Regelung_data.c:45";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "V6___LQR_Regelung"};
	this.sidHashMap["V6___LQR_Regelung"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Add"] = {sid: "V6___LQR_Regelung:17"};
	this.sidHashMap["V6___LQR_Regelung:17"] = {rtwname: "<Root>/Add"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "V6___LQR_Regelung:18"};
	this.sidHashMap["V6___LQR_Regelung:18"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "V6___LQR_Regelung:46"};
	this.sidHashMap["V6___LQR_Regelung:46"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "V6___LQR_Regelung:20"};
	this.sidHashMap["V6___LQR_Regelung:20"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Gain"] = {sid: "V6___LQR_Regelung:21"};
	this.sidHashMap["V6___LQR_Regelung:21"] = {rtwname: "<Root>/Gain"};
	this.rtwnameHashMap["<Root>/Gain1"] = {sid: "V6___LQR_Regelung:38"};
	this.sidHashMap["V6___LQR_Regelung:38"] = {rtwname: "<Root>/Gain1"};
	this.rtwnameHashMap["<Root>/Gain2"] = {sid: "V6___LQR_Regelung:39"};
	this.sidHashMap["V6___LQR_Regelung:39"] = {rtwname: "<Root>/Gain2"};
	this.rtwnameHashMap["<Root>/Gain3"] = {sid: "V6___LQR_Regelung:40"};
	this.sidHashMap["V6___LQR_Regelung:40"] = {rtwname: "<Root>/Gain3"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "V6___LQR_Regelung:22"};
	this.sidHashMap["V6___LQR_Regelung:22"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/S-Function Builder1"] = {sid: "V6___LQR_Regelung:23"};
	this.sidHashMap["V6___LQR_Regelung:23"] = {rtwname: "<Root>/S-Function Builder1"};
	this.rtwnameHashMap["<Root>/S-Function Builder2"] = {sid: "V6___LQR_Regelung:25"};
	this.sidHashMap["V6___LQR_Regelung:25"] = {rtwname: "<Root>/S-Function Builder2"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "V6___LQR_Regelung:26"};
	this.sidHashMap["V6___LQR_Regelung:26"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<Root>/Scope2"] = {sid: "V6___LQR_Regelung:42"};
	this.sidHashMap["V6___LQR_Regelung:42"] = {rtwname: "<Root>/Scope2"};
	this.rtwnameHashMap["<Root>/Sensor1"] = {sid: "V6___LQR_Regelung:27"};
	this.sidHashMap["V6___LQR_Regelung:27"] = {rtwname: "<Root>/Sensor1"};
	this.rtwnameHashMap["<Root>/Sensor2"] = {sid: "V6___LQR_Regelung:28"};
	this.sidHashMap["V6___LQR_Regelung:28"] = {rtwname: "<Root>/Sensor2"};
	this.rtwnameHashMap["<Root>/Sum"] = {sid: "V6___LQR_Regelung:41"};
	this.sidHashMap["V6___LQR_Regelung:41"] = {rtwname: "<Root>/Sum"};
	this.rtwnameHashMap["<Root>/Sum1"] = {sid: "V6___LQR_Regelung:45"};
	this.sidHashMap["V6___LQR_Regelung:45"] = {rtwname: "<Root>/Sum1"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "V6___LQR_Regelung:29"};
	this.sidHashMap["V6___LQR_Regelung:29"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "V6___LQR_Regelung:30"};
	this.sidHashMap["V6___LQR_Regelung:30"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "V6___LQR_Regelung:31"};
	this.sidHashMap["V6___LQR_Regelung:31"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/Terminator3"] = {sid: "V6___LQR_Regelung:32"};
	this.sidHashMap["V6___LQR_Regelung:32"] = {rtwname: "<Root>/Terminator3"};
	this.rtwnameHashMap["<Root>/Terminator4"] = {sid: "V6___LQR_Regelung:33"};
	this.sidHashMap["V6___LQR_Regelung:33"] = {rtwname: "<Root>/Terminator4"};
	this.rtwnameHashMap["<Root>/Terminator5"] = {sid: "V6___LQR_Regelung:34"};
	this.sidHashMap["V6___LQR_Regelung:34"] = {rtwname: "<Root>/Terminator5"};
	this.rtwnameHashMap["<Root>/Terminator6"] = {sid: "V6___LQR_Regelung:43"};
	this.sidHashMap["V6___LQR_Regelung:43"] = {rtwname: "<Root>/Terminator6"};
	this.rtwnameHashMap["<Root>/Terminator7"] = {sid: "V6___LQR_Regelung:44"};
	this.sidHashMap["V6___LQR_Regelung:44"] = {rtwname: "<Root>/Terminator7"};
	this.rtwnameHashMap["<Root>/radtodeg1"] = {sid: "V6___LQR_Regelung:36"};
	this.sidHashMap["V6___LQR_Regelung:36"] = {rtwname: "<Root>/radtodeg1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
