function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["V7___Aufspringen:4"] = "V7___Aufspringen.c:51&V7___Aufspringen.h:101&V7___Aufspringen_data.c:41";
	/* <Root>/Constant1 */
	this.urlHashMap["V7___Aufspringen:5"] = "V7___Aufspringen.c:52&V7___Aufspringen.h:98&V7___Aufspringen_data.c:38";
	/* <Root>/Constant2 */
	this.urlHashMap["V7___Aufspringen:13"] = "V7___Aufspringen.h:89&V7___Aufspringen_data.c:29";
	/* <Root>/Constant3 */
	this.urlHashMap["V7___Aufspringen:8"] = "V7___Aufspringen.c:35,53&V7___Aufspringen.h:86&V7___Aufspringen_data.c:26";
	/* <Root>/Constant4 */
	this.urlHashMap["V7___Aufspringen:9"] = "V7___Aufspringen.c:36&V7___Aufspringen.h:95&V7___Aufspringen_data.c:35";
	/* <Root>/Constant5 */
	this.urlHashMap["V7___Aufspringen:10"] = "V7___Aufspringen.c:37&V7___Aufspringen.h:92&V7___Aufspringen_data.c:32";
	/* <Root>/Multiport
Switch */
	this.urlHashMap["V7___Aufspringen:7"] = "V7___Aufspringen.c:50,61&V7___Aufspringen.h:80";
	/* <Root>/Multiport
Switch1 */
	this.urlHashMap["V7___Aufspringen:12"] = "V7___Aufspringen.c:34,45&V7___Aufspringen.h:79";
	/* <Root>/S-Function Builder */
	this.urlHashMap["V7___Aufspringen:1"] = "V7___Aufspringen.c:47";
	/* <Root>/S-Function Builder1 */
	this.urlHashMap["V7___Aufspringen:2"] = "V7___Aufspringen.c:63";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "V7___Aufspringen"};
	this.sidHashMap["V7___Aufspringen"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "V7___Aufspringen:4"};
	this.sidHashMap["V7___Aufspringen:4"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "V7___Aufspringen:5"};
	this.sidHashMap["V7___Aufspringen:5"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "V7___Aufspringen:13"};
	this.sidHashMap["V7___Aufspringen:13"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Constant3"] = {sid: "V7___Aufspringen:8"};
	this.sidHashMap["V7___Aufspringen:8"] = {rtwname: "<Root>/Constant3"};
	this.rtwnameHashMap["<Root>/Constant4"] = {sid: "V7___Aufspringen:9"};
	this.sidHashMap["V7___Aufspringen:9"] = {rtwname: "<Root>/Constant4"};
	this.rtwnameHashMap["<Root>/Constant5"] = {sid: "V7___Aufspringen:10"};
	this.sidHashMap["V7___Aufspringen:10"] = {rtwname: "<Root>/Constant5"};
	this.rtwnameHashMap["<Root>/Multiport Switch"] = {sid: "V7___Aufspringen:7"};
	this.sidHashMap["V7___Aufspringen:7"] = {rtwname: "<Root>/Multiport Switch"};
	this.rtwnameHashMap["<Root>/Multiport Switch1"] = {sid: "V7___Aufspringen:12"};
	this.sidHashMap["V7___Aufspringen:12"] = {rtwname: "<Root>/Multiport Switch1"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "V7___Aufspringen:1"};
	this.sidHashMap["V7___Aufspringen:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/S-Function Builder1"] = {sid: "V7___Aufspringen:2"};
	this.sidHashMap["V7___Aufspringen:2"] = {rtwname: "<Root>/S-Function Builder1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
