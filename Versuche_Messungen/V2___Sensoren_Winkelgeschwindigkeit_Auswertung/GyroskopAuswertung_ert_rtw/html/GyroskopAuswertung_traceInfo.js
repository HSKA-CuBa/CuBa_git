function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Sensor1 */
	this.urlHashMap["GyroskopAuswertung:42"] = "GyroskopAuswertung.c:38,52,164&GyroskopAuswertung.h:79,80,81,82,83,84,95,109,115&GyroskopAuswertung_data.c:26,32";
	/* <Root>/Sensor2 */
	this.urlHashMap["GyroskopAuswertung:29"] = "GyroskopAuswertung.c:45,59,176&GyroskopAuswertung.h:85,86,87,88,89,90,96,112,118&GyroskopAuswertung_data.c:29,35";
	/* <Root>/To Workspace1 */
	this.urlHashMap["GyroskopAuswertung:64"] = "GyroskopAuswertung.h:103";
	/* <Root>/To Workspace4 */
	this.urlHashMap["GyroskopAuswertung:59"] = "GyroskopAuswertung.h:99";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "GyroskopAuswertung"};
	this.sidHashMap["GyroskopAuswertung"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Sensor1"] = {sid: "GyroskopAuswertung:42"};
	this.sidHashMap["GyroskopAuswertung:42"] = {rtwname: "<Root>/Sensor1"};
	this.rtwnameHashMap["<Root>/Sensor2"] = {sid: "GyroskopAuswertung:29"};
	this.sidHashMap["GyroskopAuswertung:29"] = {rtwname: "<Root>/Sensor2"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "GyroskopAuswertung:50"};
	this.sidHashMap["GyroskopAuswertung:50"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "GyroskopAuswertung:51"};
	this.sidHashMap["GyroskopAuswertung:51"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator10"] = {sid: "GyroskopAuswertung:63"};
	this.sidHashMap["GyroskopAuswertung:63"] = {rtwname: "<Root>/Terminator10"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "GyroskopAuswertung:52"};
	this.sidHashMap["GyroskopAuswertung:52"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/Terminator3"] = {sid: "GyroskopAuswertung:60"};
	this.sidHashMap["GyroskopAuswertung:60"] = {rtwname: "<Root>/Terminator3"};
	this.rtwnameHashMap["<Root>/Terminator4"] = {sid: "GyroskopAuswertung:55"};
	this.sidHashMap["GyroskopAuswertung:55"] = {rtwname: "<Root>/Terminator4"};
	this.rtwnameHashMap["<Root>/Terminator5"] = {sid: "GyroskopAuswertung:56"};
	this.sidHashMap["GyroskopAuswertung:56"] = {rtwname: "<Root>/Terminator5"};
	this.rtwnameHashMap["<Root>/Terminator6"] = {sid: "GyroskopAuswertung:57"};
	this.sidHashMap["GyroskopAuswertung:57"] = {rtwname: "<Root>/Terminator6"};
	this.rtwnameHashMap["<Root>/Terminator8"] = {sid: "GyroskopAuswertung:61"};
	this.sidHashMap["GyroskopAuswertung:61"] = {rtwname: "<Root>/Terminator8"};
	this.rtwnameHashMap["<Root>/Terminator9"] = {sid: "GyroskopAuswertung:62"};
	this.sidHashMap["GyroskopAuswertung:62"] = {rtwname: "<Root>/Terminator9"};
	this.rtwnameHashMap["<Root>/To Workspace1"] = {sid: "GyroskopAuswertung:64"};
	this.sidHashMap["GyroskopAuswertung:64"] = {rtwname: "<Root>/To Workspace1"};
	this.rtwnameHashMap["<Root>/To Workspace4"] = {sid: "GyroskopAuswertung:59"};
	this.sidHashMap["GyroskopAuswertung:59"] = {rtwname: "<Root>/To Workspace4"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
