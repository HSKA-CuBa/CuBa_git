function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["TestMotorBlock:2"] = "TestMotorBlock.h:95&TestMotorBlock_data.c:29";
	/* <Root>/Constant1 */
	this.urlHashMap["TestMotorBlock:3"] = "TestMotorBlock.h:92&TestMotorBlock_data.c:26";
	/* <Root>/S-Function Builder */
	this.urlHashMap["TestMotorBlock:1"] = "TestMotorBlock.c:37&TestMotorBlock.h:79";
	/* <Root>/Scope */
	this.urlHashMap["TestMotorBlock:4"] = "TestMotorBlock.h:86";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "TestMotorBlock"};
	this.sidHashMap["TestMotorBlock"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "TestMotorBlock:2"};
	this.sidHashMap["TestMotorBlock:2"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "TestMotorBlock:3"};
	this.sidHashMap["TestMotorBlock:3"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "TestMotorBlock:1"};
	this.sidHashMap["TestMotorBlock:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "TestMotorBlock:4"};
	this.sidHashMap["TestMotorBlock:4"] = {rtwname: "<Root>/Scope"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
