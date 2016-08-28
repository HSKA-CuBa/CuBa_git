function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Abs */
	this.urlHashMap["V6___LQR_Regelung:48"] = "V6___LQR_Regelung.c:71";
	/* <Root>/Add */
	this.urlHashMap["V6___LQR_Regelung:17"] = "V6___LQR_Regelung.c:84";
	/* <Root>/Constant2 */
	this.urlHashMap["V6___LQR_Regelung:20"] = "V6___LQR_Regelung.c:81&V6___LQR_Regelung.h:132&V6___LQR_Regelung_data.c:33";
	/* <Root>/Gain */
	this.urlHashMap["V6___LQR_Regelung:21"] = "V6___LQR_Regelung.c:83&V6___LQR_Regelung.h:165&V6___LQR_Regelung_data.c:66";
	/* <Root>/Gain1 */
	this.urlHashMap["V6___LQR_Regelung:38"] = "V6___LQR_Regelung.c:92&V6___LQR_Regelung.h:144&V6___LQR_Regelung_data.c:45";
	/* <Root>/Gain2 */
	this.urlHashMap["V6___LQR_Regelung:39"] = "V6___LQR_Regelung.c:93&V6___LQR_Regelung.h:147&V6___LQR_Regelung_data.c:48";
	/* <Root>/Gain3 */
	this.urlHashMap["V6___LQR_Regelung:40"] = "V6___LQR_Regelung.c:94&V6___LQR_Regelung.h:126&V6___LQR_Regelung_data.c:26";
	/* <Root>/S-Function Builder */
	this.urlHashMap["V6___LQR_Regelung:22"] = "V6___LQR_Regelung.c:101";
	/* <Root>/S-Function Builder1 */
	this.urlHashMap["V6___LQR_Regelung:23"] = "V6___LQR_Regelung.c:77&V6___LQR_Regelung.h:101";
	/* <Root>/S-Function Builder2 */
	this.urlHashMap["V6___LQR_Regelung:51"] = "V6___LQR_Regelung.c:53,130,261&V6___LQR_Regelung.h:81,82,83,84,109,141&V6___LQR_Regelung_data.c:42";
	/* <Root>/Sensor1 */
	this.urlHashMap["V6___LQR_Regelung:27"] = "V6___LQR_Regelung.c:39,116,237&V6___LQR_Regelung.h:89,90,91,92,93,94,107,159,168&V6___LQR_Regelung_data.c:60,69";
	/* <Root>/Sensor2 */
	this.urlHashMap["V6___LQR_Regelung:28"] = "V6___LQR_Regelung.c:46,123,249&V6___LQR_Regelung.h:95,96,97,98,99,100,108,162,171&V6___LQR_Regelung_data.c:63,72";
	/* <Root>/Sum */
	this.urlHashMap["V6___LQR_Regelung:41"] = "V6___LQR_Regelung.c:91&V6___LQR_Regelung.h:85";
	/* <Root>/WinkelOffset */
	this.urlHashMap["V6___LQR_Regelung:47"] = "V6___LQR_Regelung.c:64";
	/* <Root>/WinkelOffset1 */
	this.urlHashMap["V6___LQR_Regelung:53"] = "V6___LQR_Regelung.c:80&V6___LQR_Regelung.h:80";
	/* <Root>/phi_COG_Offset */
	this.urlHashMap["V6___LQR_Regelung:46"] = "V6___LQR_Regelung.c:65&V6___LQR_Regelung.h:138&V6___LQR_Regelung_data.c:39";
	/* <Root>/phi_COG_Offset1 */
	this.urlHashMap["V6___LQR_Regelung:54"] = "V6___LQR_Regelung.c:82&V6___LQR_Regelung.h:135&V6___LQR_Regelung_data.c:36";
	/* <Root>/phi__d_scope */
	this.urlHashMap["V6___LQR_Regelung:57"] = "V6___LQR_Regelung.h:112";
	/* <Root>/phi_scope */
	this.urlHashMap["V6___LQR_Regelung:26"] = "V6___LQR_Regelung.h:116";
	/* <Root>/psi__d_scope */
	this.urlHashMap["V6___LQR_Regelung:52"] = "V6___LQR_Regelung.h:120";
	/* <Root>/radtodeg1 */
	this.urlHashMap["V6___LQR_Regelung:36"] = "V6___LQR_Regelung.c:112&V6___LQR_Regelung.h:88,156&V6___LQR_Regelung_data.c:57";
	/* <Root>/radtodeg2 */
	this.urlHashMap["V6___LQR_Regelung:55"] = "V6___LQR_Regelung.c:108&V6___LQR_Regelung.h:87,153&V6___LQR_Regelung_data.c:54";
	/* <Root>/radtodeg3 */
	this.urlHashMap["V6___LQR_Regelung:56"] = "V6___LQR_Regelung.c:104&V6___LQR_Regelung.h:86,150&V6___LQR_Regelung_data.c:51";
	/* <S1>/Compare */
	this.urlHashMap["V6___LQR_Regelung:49:2"] = "V6___LQR_Regelung.c:70&V6___LQR_Regelung.h:102";
	/* <S1>/Constant */
	this.urlHashMap["V6___LQR_Regelung:49:3"] = "V6___LQR_Regelung.c:72&V6___LQR_Regelung.h:129&V6___LQR_Regelung_data.c:30";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "V6___LQR_Regelung"};
	this.sidHashMap["V6___LQR_Regelung"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "V6___LQR_Regelung:49"};
	this.sidHashMap["V6___LQR_Regelung:49"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Abs"] = {sid: "V6___LQR_Regelung:48"};
	this.sidHashMap["V6___LQR_Regelung:48"] = {rtwname: "<Root>/Abs"};
	this.rtwnameHashMap["<Root>/Add"] = {sid: "V6___LQR_Regelung:17"};
	this.sidHashMap["V6___LQR_Regelung:17"] = {rtwname: "<Root>/Add"};
	this.rtwnameHashMap["<Root>/BalanceArea"] = {sid: "V6___LQR_Regelung:49"};
	this.sidHashMap["V6___LQR_Regelung:49"] = {rtwname: "<Root>/BalanceArea"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "V6___LQR_Regelung:20"};
	this.sidHashMap["V6___LQR_Regelung:20"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Gain"] = {sid: "V6___LQR_Regelung:21"};
	this.sidHashMap["V6___LQR_Regelung:21"] = {rtwname: "<Root>/Gain"};
	this.rtwnameHashMap["<Root>/Gain1"] = {sid: "V6___LQR_Regelung:38"};
	this.sidHashMap["V6___LQR_Regelung:38"] = {rtwname: "<Root>/Gain1"};
	this.rtwnameHashMap["<Root>/Gain2"] = {sid: "V6___LQR_Regelung:39"};
	this.sidHashMap["V6___LQR_Regelung:39"] = {rtwname: "<Root>/Gain2"};
	this.rtwnameHashMap["<Root>/Gain3"] = {sid: "V6___LQR_Regelung:40"};
	this.sidHashMap["V6___LQR_Regelung:40"] = {rtwname: "<Root>/Gain3"};
	this.rtwnameHashMap["<Root>/S-Function Builder"] = {sid: "V6___LQR_Regelung:22"};
	this.sidHashMap["V6___LQR_Regelung:22"] = {rtwname: "<Root>/S-Function Builder"};
	this.rtwnameHashMap["<Root>/S-Function Builder1"] = {sid: "V6___LQR_Regelung:23"};
	this.sidHashMap["V6___LQR_Regelung:23"] = {rtwname: "<Root>/S-Function Builder1"};
	this.rtwnameHashMap["<Root>/S-Function Builder2"] = {sid: "V6___LQR_Regelung:51"};
	this.sidHashMap["V6___LQR_Regelung:51"] = {rtwname: "<Root>/S-Function Builder2"};
	this.rtwnameHashMap["<Root>/Sensor1"] = {sid: "V6___LQR_Regelung:27"};
	this.sidHashMap["V6___LQR_Regelung:27"] = {rtwname: "<Root>/Sensor1"};
	this.rtwnameHashMap["<Root>/Sensor2"] = {sid: "V6___LQR_Regelung:28"};
	this.sidHashMap["V6___LQR_Regelung:28"] = {rtwname: "<Root>/Sensor2"};
	this.rtwnameHashMap["<Root>/Sum"] = {sid: "V6___LQR_Regelung:41"};
	this.sidHashMap["V6___LQR_Regelung:41"] = {rtwname: "<Root>/Sum"};
	this.rtwnameHashMap["<Root>/T1"] = {sid: "V6___LQR_Regelung:34"};
	this.sidHashMap["V6___LQR_Regelung:34"] = {rtwname: "<Root>/T1"};
	this.rtwnameHashMap["<Root>/T2"] = {sid: "V6___LQR_Regelung:33"};
	this.sidHashMap["V6___LQR_Regelung:33"] = {rtwname: "<Root>/T2"};
	this.rtwnameHashMap["<Root>/T3"] = {sid: "V6___LQR_Regelung:32"};
	this.sidHashMap["V6___LQR_Regelung:32"] = {rtwname: "<Root>/T3"};
	this.rtwnameHashMap["<Root>/T4"] = {sid: "V6___LQR_Regelung:31"};
	this.sidHashMap["V6___LQR_Regelung:31"] = {rtwname: "<Root>/T4"};
	this.rtwnameHashMap["<Root>/T5"] = {sid: "V6___LQR_Regelung:30"};
	this.sidHashMap["V6___LQR_Regelung:30"] = {rtwname: "<Root>/T5"};
	this.rtwnameHashMap["<Root>/T6"] = {sid: "V6___LQR_Regelung:29"};
	this.sidHashMap["V6___LQR_Regelung:29"] = {rtwname: "<Root>/T6"};
	this.rtwnameHashMap["<Root>/WinkelOffset"] = {sid: "V6___LQR_Regelung:47"};
	this.sidHashMap["V6___LQR_Regelung:47"] = {rtwname: "<Root>/WinkelOffset"};
	this.rtwnameHashMap["<Root>/WinkelOffset1"] = {sid: "V6___LQR_Regelung:53"};
	this.sidHashMap["V6___LQR_Regelung:53"] = {rtwname: "<Root>/WinkelOffset1"};
	this.rtwnameHashMap["<Root>/phi_COG_Offset"] = {sid: "V6___LQR_Regelung:46"};
	this.sidHashMap["V6___LQR_Regelung:46"] = {rtwname: "<Root>/phi_COG_Offset"};
	this.rtwnameHashMap["<Root>/phi_COG_Offset1"] = {sid: "V6___LQR_Regelung:54"};
	this.sidHashMap["V6___LQR_Regelung:54"] = {rtwname: "<Root>/phi_COG_Offset1"};
	this.rtwnameHashMap["<Root>/phi__d_scope"] = {sid: "V6___LQR_Regelung:57"};
	this.sidHashMap["V6___LQR_Regelung:57"] = {rtwname: "<Root>/phi__d_scope"};
	this.rtwnameHashMap["<Root>/phi_scope"] = {sid: "V6___LQR_Regelung:26"};
	this.sidHashMap["V6___LQR_Regelung:26"] = {rtwname: "<Root>/phi_scope"};
	this.rtwnameHashMap["<Root>/psi__d_scope"] = {sid: "V6___LQR_Regelung:52"};
	this.sidHashMap["V6___LQR_Regelung:52"] = {rtwname: "<Root>/psi__d_scope"};
	this.rtwnameHashMap["<Root>/radtodeg1"] = {sid: "V6___LQR_Regelung:36"};
	this.sidHashMap["V6___LQR_Regelung:36"] = {rtwname: "<Root>/radtodeg1"};
	this.rtwnameHashMap["<Root>/radtodeg2"] = {sid: "V6___LQR_Regelung:55"};
	this.sidHashMap["V6___LQR_Regelung:55"] = {rtwname: "<Root>/radtodeg2"};
	this.rtwnameHashMap["<Root>/radtodeg3"] = {sid: "V6___LQR_Regelung:56"};
	this.sidHashMap["V6___LQR_Regelung:56"] = {rtwname: "<Root>/radtodeg3"};
	this.rtwnameHashMap["<S1>/u"] = {sid: "V6___LQR_Regelung:49:1"};
	this.sidHashMap["V6___LQR_Regelung:49:1"] = {rtwname: "<S1>/u"};
	this.rtwnameHashMap["<S1>/Compare"] = {sid: "V6___LQR_Regelung:49:2"};
	this.sidHashMap["V6___LQR_Regelung:49:2"] = {rtwname: "<S1>/Compare"};
	this.rtwnameHashMap["<S1>/Constant"] = {sid: "V6___LQR_Regelung:49:3"};
	this.sidHashMap["V6___LQR_Regelung:49:3"] = {rtwname: "<S1>/Constant"};
	this.rtwnameHashMap["<S1>/y"] = {sid: "V6___LQR_Regelung:49:4"};
	this.sidHashMap["V6___LQR_Regelung:49:4"] = {rtwname: "<S1>/y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
