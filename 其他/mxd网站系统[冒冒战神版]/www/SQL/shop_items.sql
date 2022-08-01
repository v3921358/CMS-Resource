/*
MySQL Data Transfer
Source Host: localhost
Source Database: odinms
Target Host: localhost
Target Database: odinms
Date: 2008-9-12 20:41:40
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for shop_items
-- ----------------------------
DROP TABLE IF EXISTS `shop_items`;
CREATE TABLE `shop_items` (
  `id` int(11) NOT NULL auto_increment,
  `itemid` int(11) NOT NULL,
  `itemname` mediumtext character set gbk NOT NULL,
  `iteminfo` mediumtext character set gbk NOT NULL,
  `itemmoney` int(11) NOT NULL,
  `itemtype` int(11) NOT NULL,
  `itemhave` int(11) NOT NULL,
  `upgradeslots` int(11) NOT NULL,
  `level` int(11) NOT NULL,
  `str` int(11) NOT NULL,
  `dex` int(11) NOT NULL,
  `int` int(11) NOT NULL,
  `luk` int(11) NOT NULL,
  `hp` int(11) NOT NULL,
  `mp` int(11) NOT NULL,
  `watk` int(11) NOT NULL,
  `matk` int(11) NOT NULL,
  `wdef` int(11) NOT NULL,
  `mdef` int(11) NOT NULL,
  `acc` int(11) NOT NULL,
  `avoid` int(11) NOT NULL,
  `hands` int(11) NOT NULL,
  `speed` int(11) NOT NULL,
  `jump` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
