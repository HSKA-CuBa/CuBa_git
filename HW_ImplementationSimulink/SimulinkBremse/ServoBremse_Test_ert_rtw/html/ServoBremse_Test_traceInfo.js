function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["ServoBremse_Test:2"] = "ServoBremse_Test.h:80&ServoBremse_Test_data.c:26";
	/* <Root>/S-Function Builder */
	this.urlHashMap["ServoBremse_Test:1"] = "ServoBremse_Test.c:31";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "ServoBremse_Test"};
	this.sidHashMap["ServoBremse_Test"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "ServoBremse_Test:2"};
	this.sidHashMap["ServoBremse_Test:2"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "ServoBremse_Test:1"};
	this.sidHashMap["ServoBremse_Test:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
