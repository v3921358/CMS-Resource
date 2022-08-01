/*
MySQL Data Transfer
Source Host: localhost
Source Database: odinms
Target Host: localhost
Target Database: odinms
Date: 2008-9-12 20:41:49
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for shop_cardlog
-- ----------------------------
DROP TABLE IF EXISTS `shop_cardlog`;
CREATE TABLE `shop_cardlog` (
  `id` int(11) NOT NULL auto_increment,
  `card_have` int(11) NOT NULL default '0',
  `card_money` int(11) NOT NULL default '0',
  `card_date` date NOT NULL default '0000-00-00',
  `card_admin` varchar(16) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `shop_cardlog` VALUES ('1', '1', '100', '0000-00-00', 'Test');
INSERT INTO `shop_cardlog` VALUES ('2', '2', '100', '2008-09-10', 'test');
INSERT INTO `shop_cardlog` VALUES ('3', '12', '1000', '2008-09-10', 'EternalLove');
INSERT INTO `shop_cardlog` VALUES ('4', '13', '10', '2008-09-10', 'haha');
