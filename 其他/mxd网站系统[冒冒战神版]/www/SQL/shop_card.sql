/*
MySQL Data Transfer
Source Host: localhost
Source Database: odinms
Target Host: localhost
Target Database: odinms
Date: 2008-9-12 20:41:53
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for shop_card
-- ----------------------------
DROP TABLE IF EXISTS `shop_card`;
CREATE TABLE `shop_card` (
  `id` int(11) NOT NULL auto_increment,
  `card_user` varchar(128) NOT NULL default '0',
  `card_pass` varchar(128) NOT NULL default '0',
  `card_money` int(11) NOT NULL default '0',
  `card_info` int(11) NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `shop_card` VALUES ('1', 'Test', 'Test', '100', '1');
INSERT INTO `shop_card` VALUES ('2', 'card_user_2', '7e5d2f03250a1b73bcfb86531682746f', '100', '0');
INSERT INTO `shop_card` VALUES ('3', 'card_user_3', '45846ec940bd8a53558b6fa6ac124a2e', '1000', '0');
INSERT INTO `shop_card` VALUES ('4', 'card_user_4', 'c11f577685cc8973746323acde940e26', '1000', '0');
INSERT INTO `shop_card` VALUES ('5', 'card_user_5', 'e350972f363f46d0373069b3fa431a72', '1000', '0');
INSERT INTO `shop_card` VALUES ('6', 'card_user_6', '5c7ab269b4b24be99927d1adb2e900e5', '1000', '0');
INSERT INTO `shop_card` VALUES ('7', 'card_user_7', '7c0f2de2163e7688947a461873a06fb0', '1000', '0');
INSERT INTO `shop_card` VALUES ('8', 'card_user_8', 'bd1b73974edcfe954391860d2f58aef4', '1000', '0');
INSERT INTO `shop_card` VALUES ('9', 'card_user_9', 'd0d32a983b76c804a4cb9d642fff870f', '1000', '0');
INSERT INTO `shop_card` VALUES ('10', 'card_user_10', '1e90455a5750fb9747d81fe013964be7', '1000', '0');
INSERT INTO `shop_card` VALUES ('11', 'card_user_11', 'c4a1d177b47a77fb5acf25a0e2feeeea', '1000', '0');
INSERT INTO `shop_card` VALUES ('12', 'card_user_12', '93496aec3bee6fe2332066e6dd66fb5d', '1000', '1');
INSERT INTO `shop_card` VALUES ('13', 'card_user_13', '4949a874d9d326bcd78804c9dc9f595c', '10', '1');
