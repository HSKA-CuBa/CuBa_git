function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/S-Function Builder */
	this.urlHashMap["TestFilter:11"] = "TestFilter.c:51,85,202&TestFilter.h:79,80,81,82,104,113&TestFilter_data.c:26";
	/* <Root>/Scope1 */
	this.urlHashMap["TestFilter:10"] = "TestFilter.h:107";
	/* <Root>/Sensor1 */
	this.urlHashMap["TestFilter:2"] = "TestFilter.c:37,71,178&TestFilter.h:86,87,88,89,90,91,102,125,131&TestFilter_data.c:38,44";
	/* <Root>/Sensor2 */
	this.urlHashMap["TestFilter:3"] = "TestFilter.c:44,78,190&TestFilter.h:92,93,94,95,96,97,103,128,134&TestFilter_data.c:41,47";
	/* <Root>/radtodeg */
	this.urlHashMap["TestFilter:18"] = "TestFilter.c:59&TestFilter.h:83,116&TestFilter_data.c:29";
	/* <Root>/radtodeg1 */
	this.urlHashMap["TestFilter:19"] = "TestFilter.c:63&TestFilter.h:84,119&TestFilter_data.c:32";
	/* <Root>/radtodeg2 */
	this.urlHashMap["TestFilter:20"] = "TestFilter.c:67&TestFilter.h:85,122&TestFilter_data.c:35";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "TestFilter"};
	this.sidHashMap["TestFilter"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "TestFilter:11"};
	this.sidHashMap["TestFilter:11"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "TestFilter:10"};
	this.sidHashMap["TestFilter:10"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<Root>/Sensor1"] = {sid: "TestFilter:2"};
	this.sidHashMap["TestFilter:2"] = {rtwname: "<Root>/Sensor1"};
	this.rtwnameHashMap["<Root>/Sensor2"] = {sid: "TestFilter:3"};
	this.sidHashMap["TestFilter:3"] = {rtwname: "<Root>/Sensor2"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "TestFilter:12"};
	this.sidHashMap["TestFilter:12"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "TestFilter:13"};
	this.sidHashMap["TestFilter:13"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "TestFilter:14"};
	this.sidHashMap["TestFilter:14"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/Terminator3"] = {sid: "TestFilter:15"};
	this.sidHashMap["TestFilter:15"] = {rtwname: "<Root>/Terminator3"};
	this.rtwnameHashMap["<Root>/Terminator4"] = {sid: "TestFilter:16"};
	this.sidHashMap["TestFilter:16"] = {rtwname: "<Root>/Terminator4"};
	this.rtwnameHashMap["<Root>/Terminator5"] = {sid: "TestFilter:17"};
	this.sidHashMap["TestFilter:17"] = {rtwname: "<Root>/Terminator5"};
	this.rtwnameHashMap["<Root>/radtodeg"] = {sid: "TestFilter:18"};
	this.sidHashMap["TestFilter:18"] = {rtwname: "<Root>/radtodeg"};
	this.rtwnameHashMap["<Root>/radtodeg1"] = {sid: "TestFilter:19"};
	this.sidHashMap["TestFilter:19"] = {rtwname: "<Root>/radtodeg1"};
	this.rtwnameHashMap["<Root>/radtodeg2"] = {sid: "TestFilter:20"};
	this.sidHashMap["TestFilter:20"] = {rtwname: "<Root>/radtodeg2"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
