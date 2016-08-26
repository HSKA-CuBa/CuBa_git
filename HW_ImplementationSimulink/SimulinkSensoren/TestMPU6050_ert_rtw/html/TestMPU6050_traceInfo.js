function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Scope */
	this.urlHashMap["TestMPU6050:1"] = "TestMPU6050.h:99";
	/* <Root>/Scope1 */
	this.urlHashMap["TestMPU6050:10"] = "TestMPU6050.h:103";
	/* <Root>/Sensor1 */
	this.urlHashMap["TestMPU6050:2"] = "TestMPU6050.c:37,51,151&TestMPU6050.h:79,80,81,82,83,84,95,109,115&TestMPU6050_data.c:26,32";
	/* <Root>/Sensor2 */
	this.urlHashMap["TestMPU6050:3"] = "TestMPU6050.c:44,58,163&TestMPU6050.h:85,86,87,88,89,90,96,112,118&TestMPU6050_data.c:29,35";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "TestMPU6050"};
	this.sidHashMap["TestMPU6050"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "TestMPU6050:1"};
	this.sidHashMap["TestMPU6050:1"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "TestMPU6050:10"};
	this.sidHashMap["TestMPU6050:10"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<Root>/Sensor1"] = {sid: "TestMPU6050:2"};
	this.sidHashMap["TestMPU6050:2"] = {rtwname: "<Root>/Sensor1"};
	this.rtwnameHashMap["<Root>/Sensor2"] = {sid: "TestMPU6050:3"};
	this.sidHashMap["TestMPU6050:3"] = {rtwname: "<Root>/Sensor2"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
