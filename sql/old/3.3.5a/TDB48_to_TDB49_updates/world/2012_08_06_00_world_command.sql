DELETE FROM `command` WHERE `name` IN ('serveur togglequerylog', 'serveur set loglevel');

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('serveur set loglevel',4,'Syntax: .serveur set loglevel $facility $name $loglevel. $facility can take the values: appender (a) or logger (l). $loglevel can take the values: disabled (0), trace (1), debug (2), info (3), warn (4), error (5) or fatal (6)');
