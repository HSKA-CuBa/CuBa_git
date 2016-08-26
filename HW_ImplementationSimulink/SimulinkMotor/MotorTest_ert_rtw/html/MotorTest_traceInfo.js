function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Add */
	this.urlHashMap["MotorTest:5"] = "MotorTest.c:40&MotorTest.h:79";
	/* <Root>/Constant */
	this.urlHashMap["MotorTest:1"] = "MotorTest.h:102&MotorTest_data.c:35";
	/* <Root>/Constant1 */
	this.urlHashMap["MotorTest:2"] = "MotorTest.h:96&MotorTest_data.c:29";
	/* <Root>/Constant2 */
	this.urlHashMap["MotorTest:6"] = "MotorTest.c:41&MotorTest.h:93&MotorTest_data.c:26";
	/* <Root>/Gain */
	this.urlHashMap["MotorTest:7"] = "MotorTest.c:42&MotorTest.h:99&MotorTest_data.c:32";
	/* <Root>/S-Function Builder */
	this.urlHashMap["MotorTest:3"] = "MotorTest.c:47";
	/* <Root>/S-Function Builder1 */
	this.urlHashMap["MotorTest:9"] = "MotorTest.c:37&MotorTest.h:80";
	/* <Root>/Scope */
	this.urlHashMap["MotorTest:4"] = "MotorTest.h:87";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "MotorTest"};
	this.sidHashMap["MotorTest"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Add"] = {sid: "MotorTest:5"};
	this.sidHashMap["MotorTest:5"] = {rtwname: "<Root>/Add"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "MotorTest:1"};
	this.sidHashMap["MotorTest:1"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "MotorTest:2"};
	this.sidHashMap["MotorTest:2"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "MotorTest:6"};
	this.sidHashMap["MotorTest:6"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Gain"] = {sid: "MotorTest:7"};
	this.sidHashMap["MotorTest:7"] = {rtwname: "<Root>/Gain"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "MotorTest:3"};
	this.sidHashMap["MotorTest:3"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/S-Function Builder1"] = {sid: "MotorTest:9"};
	this.sidHashMap["MotorTest:9"] = {rtwname: "<Root>/S-Function Builder1"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "MotorTest:4"};
	this.sidHashMap["MotorTest:4"] = {rtwname: "<Root>/Scope"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
