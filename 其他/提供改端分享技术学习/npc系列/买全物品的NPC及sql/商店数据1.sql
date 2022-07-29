/*
MySQL Data Transfer
Source Host: localhost
Source Database: odinms
Target Host: localhost
Target Database: odinms
Date: 2008-9-12 ���� 07:59:27
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for shops
-- ----------------------------
CREATE TABLE `shops` ( `shopid` int(10) unsigned NOT NULL auto_increment,
 `npcid` int(11) NOT NULL default '0', PRIMARY KEY  (`shopid`)
) ENGINE=InnoDB AUTO_INCREMENT=10070 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `shops` VALUES ('1', '11000');
INSERT INTO `shops` VALUES ('2', '11100');
INSERT INTO `shops` VALUES ('3', '21000');
INSERT INTO `shops` VALUES ('4', '1001000');
INSERT INTO `shops` VALUES ('5', '1001001');
INSERT INTO `shops` VALUES ('6', '1001100');
INSERT INTO `shops` VALUES ('7', '1011000');
INSERT INTO `shops` VALUES ('8', '1011001');
INSERT INTO `shops` VALUES ('9', '1011100');
INSERT INTO `shops` VALUES ('10', '1021000');
INSERT INTO `shops` VALUES ('11', '1021001');
INSERT INTO `shops` VALUES ('12', '1021100');
INSERT INTO `shops` VALUES ('13', '1031000');
INSERT INTO `shops` VALUES ('14', '1031001');
INSERT INTO `shops` VALUES ('15', '1031100');
INSERT INTO `shops` VALUES ('16', '1051000');
INSERT INTO `shops` VALUES ('17', '1051001');
INSERT INTO `shops` VALUES ('18', '1051002');
INSERT INTO `shops` VALUES ('19', '1061001');
INSERT INTO `shops` VALUES ('20', '1061002');
INSERT INTO `shops` VALUES ('21', '1032103');
INSERT INTO `shops` VALUES ('22', '1052104');
INSERT INTO `shops` VALUES ('23', '1081000');
INSERT INTO `shops` VALUES ('24', '9201058');
INSERT INTO `shops` VALUES ('25', '9201059');
INSERT INTO `shops` VALUES ('26', '9201060');
INSERT INTO `shops` VALUES ('32', '9201020');
INSERT INTO `shops` VALUES ('33', '2012003');
INSERT INTO `shops` VALUES ('34', '2012004');
INSERT INTO `shops` VALUES ('35', '2012005');
INSERT INTO `shops` VALUES ('36', '2020001');
INSERT INTO `shops` VALUES ('37', '2022000');
INSERT INTO `shops` VALUES ('38', '2022001');
INSERT INTO `shops` VALUES ('39', '2030009');
INSERT INTO `shops` VALUES ('40', '2060003');
INSERT INTO `shops` VALUES ('41', '2060004');
INSERT INTO `shops` VALUES ('42', '2060007');
INSERT INTO `shops` VALUES ('43', '2070001');
INSERT INTO `shops` VALUES ('44', '2070002');
INSERT INTO `shops` VALUES ('45', '2070003');
INSERT INTO `shops` VALUES ('46', '2022002');
INSERT INTO `shops` VALUES ('47', '2040051');
INSERT INTO `shops` VALUES ('48', '2041002');
INSERT INTO `shops` VALUES ('49', '2041003');
INSERT INTO `shops` VALUES ('50', '2041006');
INSERT INTO `shops` VALUES ('51', '2050000');
INSERT INTO `shops` VALUES ('52', '2050003');
INSERT INTO `shops` VALUES ('53', '2051000');
INSERT INTO `shops` VALUES ('54', '2040049');
INSERT INTO `shops` VALUES ('55', '2041016');
INSERT INTO `shops` VALUES ('56', '9020000');
INSERT INTO `shops` VALUES ('70', '1012004');
INSERT INTO `shops` VALUES ('71', '9120019');
INSERT INTO `shops` VALUES ('72', '9120002');
INSERT INTO `shops` VALUES ('73', '9120000');
INSERT INTO `shops` VALUES ('74', '9120001');
INSERT INTO `shops` VALUES ('75', '9110003');
INSERT INTO `shops` VALUES ('76', '9110001');
INSERT INTO `shops` VALUES ('77', '9110006');
INSERT INTO `shops` VALUES ('78', '9110005');
INSERT INTO `shops` VALUES ('79', '9110007');
INSERT INTO `shops` VALUES ('80', '9110004');
INSERT INTO `shops` VALUES ('81', '1012004');
INSERT INTO `shops` VALUES ('82', '2010004');
INSERT INTO `shops` VALUES ('83', '2041014');
INSERT INTO `shops` VALUES ('84', '2080004');
INSERT INTO `shops` VALUES ('85', '9110004');
INSERT INTO `shops` VALUES ('10000', '2082002');
INSERT INTO `shops` VALUES ('10001', '2082002');
INSERT INTO `shops` VALUES ('10002', '2082002');
INSERT INTO `shops` VALUES ('10003', '2082002');
INSERT INTO `shops` VALUES ('10004', '2082002');
INSERT INTO `shops` VALUES ('10005', '2082002');
INSERT INTO `shops` VALUES ('10006', '2082002');
INSERT INTO `shops` VALUES ('10007', '2082002');
INSERT INTO `shops` VALUES ('10008', '2082002');
INSERT INTO `shops` VALUES ('10009', '2082002');
INSERT INTO `shops` VALUES ('10010', '2082002');
INSERT INTO `shops` VALUES ('10011', '2082002');
INSERT INTO `shops` VALUES ('10012', '2082002');
INSERT INTO `shops` VALUES ('10013', '2082002');
INSERT INTO `shops` VALUES ('10014', '2082002');
INSERT INTO `shops` VALUES ('10015', '2082002');
INSERT INTO `shops` VALUES ('10016', '2082002');
INSERT INTO `shops` VALUES ('10017', '2082002');
INSERT INTO `shops` VALUES ('10018', '2082002');
INSERT INTO `shops` VALUES ('10019', '2082002');
INSERT INTO `shops` VALUES ('10020', '2082002');
INSERT INTO `shops` VALUES ('10021', '2082002');
INSERT INTO `shops` VALUES ('10022', '2082002');
INSERT INTO `shops` VALUES ('10023', '2082002');
INSERT INTO `shops` VALUES ('10024', '2082002');
INSERT INTO `shops` VALUES ('10025', '2082002');
INSERT INTO `shops` VALUES ('10026', '2082002');
INSERT INTO `shops` VALUES ('10027', '2082002');
INSERT INTO `shops` VALUES ('10028', '2082002');
INSERT INTO `shops` VALUES ('10029', '2082002');
INSERT INTO `shops` VALUES ('10030', '2082002');
INSERT INTO `shops` VALUES ('10031', '2082002');
INSERT INTO `shops` VALUES ('10032', '2082002');
INSERT INTO `shops` VALUES ('10033', '2082002');
INSERT INTO `shops` VALUES ('10034', '2082002');
INSERT INTO `shops` VALUES ('10035', '2082002');
INSERT INTO `shops` VALUES ('10037', '2082002');
INSERT INTO `shops` VALUES ('10038', '2082002');
INSERT INTO `shops` VALUES ('10039', '2082002');
INSERT INTO `shops` VALUES ('10040', '2082002');
INSERT INTO `shops` VALUES ('10041', '2082002');
INSERT INTO `shops` VALUES ('10042', '2082002');
INSERT INTO `shops` VALUES ('10043', '2082002');
INSERT INTO `shops` VALUES ('10044', '2082002');
INSERT INTO `shops` VALUES ('10045', '2082002');
INSERT INTO `shops` VALUES ('10046', '2082002');
INSERT INTO `shops` VALUES ('10047', '2082002');
INSERT INTO `shops` VALUES ('10048', '2082002');
INSERT INTO `shops` VALUES ('10049', '2082002');
INSERT INTO `shops` VALUES ('10050', '2041024');
INSERT INTO `shops` VALUES ('10051', '2082002');
INSERT INTO `shops` VALUES ('10052', '2082002');
INSERT INTO `shops` VALUES ('10053', '2082002');
INSERT INTO `shops` VALUES ('10054', '2082002');
INSERT INTO `shops` VALUES ('10055', '2082002');
INSERT INTO `shops` VALUES ('10056', '2082002');
INSERT INTO `shops` VALUES ('10057', '2082002');
INSERT INTO `shops` VALUES ('10058', '2082002');
INSERT INTO `shops` VALUES ('10059', '2082002');
INSERT INTO `shops` VALUES ('10060', '2082002');
INSERT INTO `shops` VALUES ('10061', '2082002');
INSERT INTO `shops` VALUES ('10062', '2082002');
INSERT INTO `shops` VALUES ('10063', '2082002');
INSERT INTO `shops` VALUES ('10064', '2082002');
INSERT INTO `shops` VALUES ('10065', '2082002');
INSERT INTO `shops` VALUES ('10066', '2082002');
INSERT INTO `shops` VALUES ('10067', '2082002');
INSERT INTO `shops` VALUES ('10068', '2082002');
INSERT INTO `shops` VALUES ('10069', '2082002');
