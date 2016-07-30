function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/S-Function Builder2 */
	this.urlHashMap["SingleBlockSensoren:29"] = "SingleBlockSensoren.c:38,45,150&SingleBlockSensoren.h:79,80,85,94&SingleBlockSensoren_data.c:26";
	/* <Root>/Scope */
	this.urlHashMap["SingleBlockSensoren:30"] = "SingleBlockSensoren.h:88";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "SingleBlockSensoren"};
	this.sidHashMap["SingleBlockSensoren"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/S-Function Builder2"] = {sid: "SingleBlockSensoren:29"};
	this.sidHashMap["SingleBlockSensoren:29"] = {rtwname: "<Root>/S-Function Builder2"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "SingleBlockSensoren:30"};
	this.sidHashMap["SingleBlockSensoren:30"] = {rtwname: "<Root>/Scope"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
