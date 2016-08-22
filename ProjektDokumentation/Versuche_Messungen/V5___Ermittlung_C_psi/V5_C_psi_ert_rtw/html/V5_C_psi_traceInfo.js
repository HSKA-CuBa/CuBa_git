function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["V5_C_psi:2"] = "V5_C_psi.h:95&V5_C_psi_data.c:29";
	/* <Root>/Constant1 */
	this.urlHashMap["V5_C_psi:3"] = "V5_C_psi.h:92&V5_C_psi_data.c:26";
	/* <Root>/S-Function Builder */
	this.urlHashMap["V5_C_psi:1"] = "V5_C_psi.c:37&V5_C_psi.h:79";
	/* <Root>/To Workspace */
	this.urlHashMap["V5_C_psi:7"] = "V5_C_psi.h:86";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "V5_C_psi"};
	this.sidHashMap["V5_C_psi"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "V5_C_psi:2"};
	this.sidHashMap["V5_C_psi:2"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "V5_C_psi:3"};
	this.sidHashMap["V5_C_psi:3"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "V5_C_psi:1"};
	this.sidHashMap["V5_C_psi:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/To Workspace"] = {sid: "V5_C_psi:7"};
	this.sidHashMap["V5_C_psi:7"] = {rtwname: "<Root>/To Workspace"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
