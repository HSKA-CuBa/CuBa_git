function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Constant */
	this.urlHashMap["V3_AusgleichsPolynomPsi__d:2"] = "V3_AusgleichsPolynomPsi__d.h:95&V3_AusgleichsPolynomPsi__d_data.c:29";
	/* <Root>/Constant1 */
	this.urlHashMap["V3_AusgleichsPolynomPsi__d:3"] = "V3_AusgleichsPolynomPsi__d.h:92&V3_AusgleichsPolynomPsi__d_data.c:26";
	/* <Root>/S-Function Builder */
	this.urlHashMap["V3_AusgleichsPolynomPsi__d:1"] = "V3_AusgleichsPolynomPsi__d.c:38";
	/* <Root>/S-Function Builder1 */
	this.urlHashMap["V3_AusgleichsPolynomPsi__d:8"] = "V3_AusgleichsPolynomPsi__d.c:42&V3_AusgleichsPolynomPsi__d.h:79";
	/* <Root>/To Workspace */
	this.urlHashMap["V3_AusgleichsPolynomPsi__d:7"] = "V3_AusgleichsPolynomPsi__d.h:86";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "V3_AusgleichsPolynomPsi__d"};
	this.sidHashMap["V3_AusgleichsPolynomPsi__d"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "V3_AusgleichsPolynomPsi__d:2"};
	this.sidHashMap["V3_AusgleichsPolynomPsi__d:2"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "V3_AusgleichsPolynomPsi__d:3"};
	this.sidHashMap["V3_AusgleichsPolynomPsi__d:3"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "V3_AusgleichsPolynomPsi__d:1"};
	this.sidHashMap["V3_AusgleichsPolynomPsi__d:1"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/S-Function Builder1"] = {sid: "V3_AusgleichsPolynomPsi__d:8"};
	this.sidHashMap["V3_AusgleichsPolynomPsi__d:8"] = {rtwname: "<Root>/S-Function Builder1"};
	this.rtwnameHashMap["<Root>/To Workspace"] = {sid: "V3_AusgleichsPolynomPsi__d:7"};
	this.sidHashMap["V3_AusgleichsPolynomPsi__d:7"] = {rtwname: "<Root>/To Workspace"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
