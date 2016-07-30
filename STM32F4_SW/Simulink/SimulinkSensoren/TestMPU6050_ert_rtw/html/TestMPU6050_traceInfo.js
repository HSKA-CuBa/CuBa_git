function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/S-Function Builder2 */
	this.urlHashMap["TestMPU6050:29"] = "TestMPU6050.c:37,46,149&TestMPU6050.h:79,80,81,82,83,84,89,98,101&TestMPU6050_data.c:26,29";
	/* <Root>/Scope */
	this.urlHashMap["TestMPU6050:30"] = "TestMPU6050.h:92";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "TestMPU6050"};
	this.sidHashMap["TestMPU6050"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/S-Function Builder2"] = {sid: "TestMPU6050:29"};
	this.sidHashMap["TestMPU6050:29"] = {rtwname: "<Root>/S-Function Builder2"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "TestMPU6050:30"};
	this.sidHashMap["TestMPU6050:30"] = {rtwname: "<Root>/Scope"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
