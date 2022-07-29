/*
MySQL Data Transfer
Source Host: localhost
Source Database: chaoyue
Target Host: localhost
Target Database: chaoyue
Date: 2009-9-26 19:26:38
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for Gagelog
-- ----------------------------
DROP TABLE IF EXISTS `fsblog`;
CREATE TABLE `fsblog` (
  `bosslogid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `accountid` int(10) NOT NULL DEFAULT '0',
  `characterid` int(10) unsigned NOT NULL,
  `account` varchar(20) NOT NULL,
  `charactername` varchar(50) CHARACTER SET gbk COLLATE gbk_bin NOT NULL,
  `fsbtype` varchar(20) NOT NULL,
  `lastattempt` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`bosslogid`)
) ENGINE=MyISAM AUTO_INCREMENT=164 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Gagetgy
-- ----------------------------
DROP TABLE IF EXISTS `fsbtgy`;
CREATE TABLE `fsbtgy` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `charid` int(11) NOT NULL,
  `characterid` int(11) NOT NULL,
  `money` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `charid` (`charid`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for Gagetgyed
-- ----------------------------
DROP TABLE IF EXISTS `fsbtgyed`;
CREATE TABLE `fsbtgyed` (
  `bosslogid` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `characterid` int(10) unsigned NOT NULL,
  `bossid` varchar(20) NOT NULL,
  `lastattempt` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`bosslogid`)
) ENGINE=MyISAM AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
