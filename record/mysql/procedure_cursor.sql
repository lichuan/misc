-- ----------------------------
-- Table structure for `tbl_version`
-- ----------------------------
CREATE TABLE IF NOT EXISTS `tbl_version` (
  `versionid` int(4) unsigned NOT NULL DEFAULT '0',
  `date` datetime DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`versionid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tbl_version
-- ----------------------------
insert into tbl_version(versionid, date) values(0, now());



delimiter $$
DROP PROCEDURE IF EXISTS update_version;
create procedure update_version(in cur_version int, out ret int)
uv:begin
	DECLARE last_version int(4);
	SELECT max(versionid) from tbl_version into last_version;
	
	if(cur_version is NULL) THEN
	set ret = 0;
	leave uv;
	end if;

	if (last_version + 1 <> cur_version) THEN
	set ret = 0;
	LEAVE uv;	
	end IF;

	set ret = 1;
	insert into tbl_version(versionid, date) values(cur_version, now());
end uv$$
delimiter ;



/*
下面是测试用的例子，以后更新脚本的时候， 改动下面的升级sql
delimiter $$
DROP PROCEDURE IF EXISTS update_sql;
create procedure update_sql()
us:begin
	DECLARE ret int(4);
	call update_version(1, ret);

	if(ret <> 1) THEN
	LEAVE us;
	end if;

	CREATE TABLE IF NOT EXISTS `tbl_test1` (
	  `id` int(4) unsigned NOT NULL AUTO_INCREMENT,
	  `account` char(50) DEFAULT '',
	  `name` char(50) DEFAULT '',
	  `date` datetime DEFAULT '0000-00-00 00:00:00',
	  `how` char(50) DEFAULT '',
	  `moneytype` char(50) DEFAULT '',
	  `money` int(4) unsigned DEFAULT '0',
	  `moneyremain` int(4) unsigned DEFAULT '0',
	  `reason` varchar(256) DEFAULT '',
	  PRIMARY KEY (`id`),
	  KEY `account` (`account`),
	  KEY `name` (`name`)
	) ENGINE=MyISAM DEFAULT CHARSET=utf8;
end us$$
delimiter ;
call update_sql();
DROP PROCEDURE update_sql;
*/




delimiter $$
DROP PROCEDURE IF EXISTS update_pay;
create procedure update_pay()
BEGIN
	DECLARE gold INT;
	DECLARE no_more INT;
	DECLARE acc varchar(32);
	DECLARE paycus CURSOR FOR SELECT paygold, account from tbl_gold;
	DECLARE CONTINUE HANDLER FOR NOT FOUND set no_more=1;  
	OPEN paycus;
	REPEAT
		FETCH  paycus into gold, acc;
		update tbl_character_info set paygold = gold, lastpaygold = 100 where account=acc;
		UNTIL no_more = 1
	END REPEAT;
	CLOSE paycus;
END $$
delimiter ;
alter TABLE tbl_character_info add COLUMN paygold int(4) DEFAULT 0;
alter TABLE tbl_character_info add COLUMN lastpaygold int(4) DEFAULT 0;
call update_pay();
drop procedure update_pay;


