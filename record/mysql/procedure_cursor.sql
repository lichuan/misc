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



/*
tbl_gold_get
*/

delimiter $$
DROP PROCEDURE IF EXISTS pc_tbl_gold_get;
create procedure pc_tbl_gold_get()
BEGIN
    DECLARE id1 INT(4);
    DECLARE name1 varchar(50);    
    DECLARE id2 INT(4);
    DECLARE no_more INT(4);
    DECLARE name2 char(50);    
    DECLARE curs1 CURSOR FOR SELECT id, charname from tbl_gold_get;
    DECLARE CONTINUE HANDLER FOR NOT FOUND set no_more = 1;
    OPEN curs1;
    REPEAT
        FETCH curs1 into id1, name1;
        SELECT id into id2 from tbl_character_info where name = name1 limit 1;
        update tbl_gold_get set charname = cast(id2 as char(50)) where id = id1;
        UNTIL no_more = 1
    END REPEAT;
    close curs1;
END $$
delimiter ;
UPDATE tbl_gold_get SET charname = REPLACE(REPLACE(charname, CHAR(10), ''), CHAR(13), '');
call pc_tbl_gold_get();
drop procedure pc_tbl_gold_get;

ALTER TABLE tbl_gold_get CHANGE charname charid int(4) UNSIGNED DEFAULT '0';



/*
tbl_guild
*/
delimiter $$
DROP PROCEDURE IF EXISTS pc_tbl_guild;
create procedure pc_tbl_guild()
BEGIN
    DECLARE id1 INT(4);
    DECLARE name1 char(50);    
    DECLARE id2 INT(4);
    DECLARE no_more INT(4);
    DECLARE name2 char(50);
    DECLARE name3 char(50);
    DECLARE curs1 CURSOR FOR SELECT name, master from tbl_guild;
    DECLARE CONTINUE HANDLER FOR NOT FOUND set no_more = 1;
    OPEN curs1;
    REPEAT
        FETCH curs1 into name1, name2;
        SELECT id, guildname into id1, name3 from tbl_character_info where name = name2 limit 1;

        if(name3 <> name1) THEN        
            delete from tbl_guild_member where guild = name1;
            delete from tbl_guild_request where guild = name1;
            delete from tbl_guild where name = name1;
        else
            update tbl_guild set master = cast(id1 as char(50)) where name = name1;
        end if;
        UNTIL no_more = 1
    END REPEAT;
    close curs1;
END $$
delimiter ;
UPDATE tbl_guild SET master = REPLACE(REPLACE(master, CHAR(10), ''), CHAR(13), '');
call pc_tbl_guild();
drop procedure pc_tbl_guild;

update tbl_guild set master1 = '0', master2 = '0';
ALTER TABLE tbl_guild CHANGE master master int(4) UNSIGNED DEFAULT '0';
ALTER TABLE tbl_guild CHANGE master1 master1 int(4) UNSIGNED DEFAULT '0';
ALTER TABLE tbl_guild CHANGE master2 master2 int(4) UNSIGNED DEFAULT '0';



/*
tbl_gold_member
*/
delimiter $$
DROP PROCEDURE IF EXISTS pc_tbl_guild_member;
create procedure pc_tbl_guild_member()
BEGIN
    DECLARE id1 INT(4);
    DECLARE name1 char(50);    
    DECLARE id2 INT(4);
    DECLARE no_more INT(4);
    DECLARE name2 char(50);
    DECLARE name3 char(50);
    DECLARE curs1 CURSOR FOR SELECT username from tbl_guild_member;
    DECLARE CONTINUE HANDLER FOR NOT FOUND set no_more = 1;
    OPEN curs1;
    REPEAT
        FETCH curs1 into name1;
        SELECT id into id1 from tbl_character_info where name = name1 limit 1;
        update tbl_guild_member set username = cast(id1 as char(50)) where username = name1;
        UNTIL no_more = 1
    END REPEAT;
    close curs1;
END $$
delimiter ;
UPDATE tbl_guild_member SET username = REPLACE(REPLACE(username, CHAR(10), ''), CHAR(13), '');
call pc_tbl_guild_member();
drop procedure pc_tbl_guild_member;

ALTER TABLE tbl_guild_member CHANGE username charid int(4) UNSIGNED DEFAULT '0';



/*
tbl_guild_request
*/
delete from tbl_guild_request;
ALTER TABLE tbl_guild_request CHANGE requester charid int(4) UNSIGNED DEFAULT '0';
ALTER TABLE tbl_log_level_up DROP COLUMN name;



/*
tbl_log_money
*/

delete from tbl_log_money;
ALTER TABLE tbl_log_money CHANGE name charid int(4) UNSIGNED DEFAULT '0';
update tbl_system_mailbox set fromname = '' WHERE mailfrom <> 0;
ALTER TABLE tbl_system_mailbox DROP COLUMN toname;



