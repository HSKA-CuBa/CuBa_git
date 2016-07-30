function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["TestSTMSupportPackage:1"] = "TestSTMSupportPackage.c:36&TestSTMSupportPackage.h:86&TestSTMSupportPackage_data.c:26";
	/* <Root>/GPIO Write */
	this.urlHashMap["TestSTMSupportPackage:2"] = "TestSTMSupportPackage.c:35,142";
	/* <Root>/S-Function Builder */
	this.urlHashMap["TestSTMSupportPackage:3"] = "TestSTMSupportPackage.c:40,44,146&TestSTMSupportPackage.h:80";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "TestSTMSupportPackage"};
	this.sidHashMap["TestSTMSupportPackage"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "TestSTMSupportPackage:1"};
	this.sidHashMap["TestSTMSupportPackage:1"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/GPIO Write"] = {sid: "TestSTMSupportPackage:2"};
	this.sidHashMap["TestSTMSupportPackage:2"] = {rtwname: "<Root>/GPIO Write"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "TestSTMSupportPackage:3"};
	this.sidHashMap["TestSTMSupportPackage:3"] = {rtwname: "<Root>/S-Function Builder"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
