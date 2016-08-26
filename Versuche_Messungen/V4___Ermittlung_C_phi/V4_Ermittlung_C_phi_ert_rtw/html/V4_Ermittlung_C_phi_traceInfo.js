function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Scope */
	this.urlHashMap["V4_Ermittlung_C_phi:63"] = "V4_Ermittlung_C_phi.h:99";
	/* <Root>/Sensor1 */
	this.urlHashMap["V4_Ermittlung_C_phi:42"] = "V4_Ermittlung_C_phi.c:38,52,164&V4_Ermittlung_C_phi.h:79,80,81,82,83,84,95,105,111&V4_Ermittlung_C_phi_data.c:26,32";
	/* <Root>/Sensor2 */
	this.urlHashMap["V4_Ermittlung_C_phi:29"] = "V4_Ermittlung_C_phi.c:45,59,176&V4_Ermittlung_C_phi.h:85,86,87,88,89,90,96,108,114&V4_Ermittlung_C_phi_data.c:29,35";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "V4_Ermittlung_C_phi"};
	this.sidHashMap["V4_Ermittlung_C_phi"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "V4_Ermittlung_C_phi:63"};
	this.sidHashMap["V4_Ermittlung_C_phi:63"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Sensor1"] = {sid: "V4_Ermittlung_C_phi:42"};
	this.sidHashMap["V4_Ermittlung_C_phi:42"] = {rtwname: "<Root>/Sensor1"};
	this.rtwnameHashMap["<Root>/Sensor2"] = {sid: "V4_Ermittlung_C_phi:29"};
	this.sidHashMap["V4_Ermittlung_C_phi:29"] = {rtwname: "<Root>/Sensor2"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "V4_Ermittlung_C_phi:50"};
	this.sidHashMap["V4_Ermittlung_C_phi:50"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "V4_Ermittlung_C_phi:51"};
	this.sidHashMap["V4_Ermittlung_C_phi:51"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "V4_Ermittlung_C_phi:61"};
	this.sidHashMap["V4_Ermittlung_C_phi:61"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/Terminator4"] = {sid: "V4_Ermittlung_C_phi:55"};
	this.sidHashMap["V4_Ermittlung_C_phi:55"] = {rtwname: "<Root>/Terminator4"};
	this.rtwnameHashMap["<Root>/Terminator5"] = {sid: "V4_Ermittlung_C_phi:56"};
	this.sidHashMap["V4_Ermittlung_C_phi:56"] = {rtwname: "<Root>/Terminator5"};
	this.rtwnameHashMap["<Root>/Terminator6"] = {sid: "V4_Ermittlung_C_phi:57"};
	this.sidHashMap["V4_Ermittlung_C_phi:57"] = {rtwname: "<Root>/Terminator6"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
