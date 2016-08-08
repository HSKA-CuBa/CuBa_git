function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Sensor1 */
	this.urlHashMap["BeschleunigungsAuswertung:42"] = "BeschleunigungsAuswertung.c:38,60,180&BeschleunigungsAuswertung.h:79,80,81,82,83,84,95,117,123&BeschleunigungsAuswertung_data.c:26,32";
	/* <Root>/Sensor2 */
	this.urlHashMap["BeschleunigungsAuswertung:29"] = "BeschleunigungsAuswertung.c:49,71,192&BeschleunigungsAuswertung.h:85,86,87,88,89,90,96,120,126&BeschleunigungsAuswertung_data.c:29,35";
	/* <Root>/To Workspace */
	this.urlHashMap["BeschleunigungsAuswertung:44"] = "BeschleunigungsAuswertung.h:99";
	/* <Root>/To Workspace1 */
	this.urlHashMap["BeschleunigungsAuswertung:47"] = "BeschleunigungsAuswertung.h:103";
	/* <Root>/To Workspace2 */
	this.urlHashMap["BeschleunigungsAuswertung:48"] = "BeschleunigungsAuswertung.h:107";
	/* <Root>/To Workspace3 */
	this.urlHashMap["BeschleunigungsAuswertung:49"] = "BeschleunigungsAuswertung.h:111";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "BeschleunigungsAuswertung"};
	this.sidHashMap["BeschleunigungsAuswertung"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Sensor1"] = {sid: "BeschleunigungsAuswertung:42"};
	this.sidHashMap["BeschleunigungsAuswertung:42"] = {rtwname: "<Root>/Sensor1"};
	this.rtwnameHashMap["<Root>/Sensor2"] = {sid: "BeschleunigungsAuswertung:29"};
	this.sidHashMap["BeschleunigungsAuswertung:29"] = {rtwname: "<Root>/Sensor2"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "BeschleunigungsAuswertung:50"};
	this.sidHashMap["BeschleunigungsAuswertung:50"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "BeschleunigungsAuswertung:51"};
	this.sidHashMap["BeschleunigungsAuswertung:51"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "BeschleunigungsAuswertung:52"};
	this.sidHashMap["BeschleunigungsAuswertung:52"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/Terminator3"] = {sid: "BeschleunigungsAuswertung:53"};
	this.sidHashMap["BeschleunigungsAuswertung:53"] = {rtwname: "<Root>/Terminator3"};
	this.rtwnameHashMap["<Root>/Terminator4"] = {sid: "BeschleunigungsAuswertung:55"};
	this.sidHashMap["BeschleunigungsAuswertung:55"] = {rtwname: "<Root>/Terminator4"};
	this.rtwnameHashMap["<Root>/Terminator5"] = {sid: "BeschleunigungsAuswertung:56"};
	this.sidHashMap["BeschleunigungsAuswertung:56"] = {rtwname: "<Root>/Terminator5"};
	this.rtwnameHashMap["<Root>/Terminator6"] = {sid: "BeschleunigungsAuswertung:57"};
	this.sidHashMap["BeschleunigungsAuswertung:57"] = {rtwname: "<Root>/Terminator6"};
	this.rtwnameHashMap["<Root>/Terminator7"] = {sid: "BeschleunigungsAuswertung:58"};
	this.sidHashMap["BeschleunigungsAuswertung:58"] = {rtwname: "<Root>/Terminator7"};
	this.rtwnameHashMap["<Root>/To Workspace"] = {sid: "BeschleunigungsAuswertung:44"};
	this.sidHashMap["BeschleunigungsAuswertung:44"] = {rtwname: "<Root>/To Workspace"};
	this.rtwnameHashMap["<Root>/To Workspace1"] = {sid: "BeschleunigungsAuswertung:47"};
	this.sidHashMap["BeschleunigungsAuswertung:47"] = {rtwname: "<Root>/To Workspace1"};
	this.rtwnameHashMap["<Root>/To Workspace2"] = {sid: "BeschleunigungsAuswertung:48"};
	this.sidHashMap["BeschleunigungsAuswertung:48"] = {rtwname: "<Root>/To Workspace2"};
	this.rtwnameHashMap["<Root>/To Workspace3"] = {sid: "BeschleunigungsAuswertung:49"};
	this.sidHashMap["BeschleunigungsAuswertung:49"] = {rtwname: "<Root>/To Workspace3"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
