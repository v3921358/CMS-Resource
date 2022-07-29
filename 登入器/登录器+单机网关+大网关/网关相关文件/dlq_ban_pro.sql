/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50553
Source Host           : localhost:3306
Source Database       : v079

Target Server Type    : MYSQL
Target Server Version : 50553
File Encoding         : 65001

Date: 2020-12-02 08:13:49
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for dlq_ban_pro
-- ----------------------------
DROP TABLE IF EXISTS `dlq_ban_pro`;
CREATE TABLE `dlq_ban_pro` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `md5` varchar(255) NOT NULL,
  `remarks` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=48 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of dlq_ban_pro
-- ----------------------------
INSERT INTO `dlq_ban_pro` VALUES ('4', 'eba545fafbec841ad158a167b0a0a4b9', '大作战');
INSERT INTO `dlq_ban_pro` VALUES ('5', '39ab885d8d787259676294437de05eae', 'Dzz');
INSERT INTO `dlq_ban_pro` VALUES ('6', '673d94eb44f236f033bc3d07fd7051a0', '游侠');
INSERT INTO `dlq_ban_pro` VALUES ('7', 'dd6ec5f4191debc1e5fc2c1a1fb71f31', 'by1');
INSERT INTO `dlq_ban_pro` VALUES ('8', '4a1a52fc5674d0856c9b1be8d900bb24', 'bye');
INSERT INTO `dlq_ban_pro` VALUES ('9', '78c4cc9a86ae583dcfb167d3a801ddd7', 'WZJC');
INSERT INTO `dlq_ban_pro` VALUES ('10', 'a2dc350513213655f55da24599a7ead3', 'Unlocker');
INSERT INTO `dlq_ban_pro` VALUES ('11', '32b82a7c13e6d563ed99af39e14c48fb', '暂停工具');
INSERT INTO `dlq_ban_pro` VALUES ('12', '11f5da8ef33ac7c3d14f4c41fe34de3e', 'PCHunter');
INSERT INTO `dlq_ban_pro` VALUES ('13', '88e877dc2fdefa5f25ee3cc4b6b1c1d5', 'pc hunter');
INSERT INTO `dlq_ban_pro` VALUES ('14', '990fa35efcb9787eb42a1733a0512805', 'PChunter 32');
INSERT INTO `dlq_ban_pro` VALUES ('15', '27e94d77d26aaed9ad7f25a635d5414f', 'PChunter 64');
INSERT INTO `dlq_ban_pro` VALUES ('16', '990fa35efcb9787eb42a1733a0512805', 'PChunter 32');
INSERT INTO `dlq_ban_pro` VALUES ('17', '7cfaf6d38fbe95e3e773b54508dc78a2', 'xx');
INSERT INTO `dlq_ban_pro` VALUES ('18', 'faa99befd9bd63340beb104951116103', '丸子辅助');
INSERT INTO `dlq_ban_pro` VALUES ('19', 'd1e4f5a1ccb9e7cdd464ae35b7900bdb', 'wpe');
INSERT INTO `dlq_ban_pro` VALUES ('20', 'beca277533e6e89c9dfc71e7762c06b5', '小豪辅助');
INSERT INTO `dlq_ban_pro` VALUES ('21', 'ee37c7c29e33a0bf169a5742d1fb355a', '小豪外挂');
INSERT INTO `dlq_ban_pro` VALUES ('22', 'f1f86a499eab69b7a77cf5aac5733ed5', '非法程序');
INSERT INTO `dlq_ban_pro` VALUES ('23', '5658db123bf29ec5124299fa1634ddb3', '非法程序1');
INSERT INTO `dlq_ban_pro` VALUES ('24', 'ccbabe3b0435ff91d13d76e7487abcee', '非法程序2');
INSERT INTO `dlq_ban_pro` VALUES ('25', '3596c9579814344ecc73871c6916bded', 'dzz');
INSERT INTO `dlq_ban_pro` VALUES ('26', '1ec176e4823b9112d6b9c854c4acca77', 'sq');
INSERT INTO `dlq_ban_pro` VALUES ('27', 'fd8bb9f0ba8144a44c4dfb19e6c0ba27', '新游侠');
INSERT INTO `dlq_ban_pro` VALUES ('28', '122e7384a89f60f543bb39eb0ff402e3', '王牌辅助');
INSERT INTO `dlq_ban_pro` VALUES ('29', '35dae13452320cd2f2fad8f2c3f0118e', '1辅助');
INSERT INTO `dlq_ban_pro` VALUES ('30', '15e4d4b59357a6de3e60cfc62af5bb24', '游侠3.9');
INSERT INTO `dlq_ban_pro` VALUES ('32', '5c338243f328f9886e5c3dab0776ea46', '家族过检测');
INSERT INTO `dlq_ban_pro` VALUES ('33', '8a9634d5a4d0430ea2f200d2cc99f916', '修正第十五版');
INSERT INTO `dlq_ban_pro` VALUES ('34', '20a9c63d104dba76e270401d1daa15e3', '最新079辅助');
INSERT INTO `dlq_ban_pro` VALUES ('35', '1468b0db856fee5841ee63284f75cd27', '小豪新辅助');
INSERT INTO `dlq_ban_pro` VALUES ('36', 'eb20db1034c8c13c5f78dacb2014c60f', '游侠4.5');
INSERT INTO `dlq_ban_pro` VALUES ('37', '987b65cd9b9f4e9a1afd8f8b48cf64a7', '隐藏程序64位');
INSERT INTO `dlq_ban_pro` VALUES ('38', '228dd0c2e6287547e26ffbd973a40f14', '隐藏程序32位');
INSERT INTO `dlq_ban_pro` VALUES ('39', 'd787b64be5d49fc8d258b63f8804a622', '大作战1');
INSERT INTO `dlq_ban_pro` VALUES ('40', 'ecdfcb16997c99a271be0be081036307', '小豪1.62');
INSERT INTO `dlq_ban_pro` VALUES ('41', 'bdc349024467f0564f253f0dade9fd25', '1.2');
INSERT INTO `dlq_ban_pro` VALUES ('42', '3662fb7a3b2dffab2b33efda090853dc', '外挂079');
INSERT INTO `dlq_ban_pro` VALUES ('43', 'd454d951668b41df4fdb2679a30c80cb', '长久');
INSERT INTO `dlq_ban_pro` VALUES ('44', '82d1fbab72a2abb2ef1578e95c295a29', '牛头');
INSERT INTO `dlq_ban_pro` VALUES ('45', '789ddf38afa9771f9343cb16cc67604a', 'deMSwZ1');
INSERT INTO `dlq_ban_pro` VALUES ('46', 'a559018a0067fbe5ff1868ddeb0ed114', '端口转发');
INSERT INTO `dlq_ban_pro` VALUES ('47', 'a01a517099c76654ff20be385f396073', '小豪第14版');
